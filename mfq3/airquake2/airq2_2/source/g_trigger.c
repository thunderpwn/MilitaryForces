#include "g_local.h"


void InitTrigger (edict_t *self)
{
	if (!VectorCompare (self->s.angles, vec3_origin))
		G_SetMovedir (self->s.angles, self->movedir);

	self->solid = SOLID_TRIGGER;
	self->movetype = MOVETYPE_NONE;
	gi.setmodel (self, self->model);
	self->svflags = SVF_NOCLIENT;
}


// the wait time has passed, so set back up for another activation
void multi_wait (edict_t *ent)
{
	ent->nextthink = 0;
}


// the trigger was just activated
// ent->activator should be set to the activator so it can be held through a delay
// so wait for the delay time before firing
void multi_trigger (edict_t *ent)
{
	if (ent->nextthink)
		return;		// already been triggered

	G_UseTargets (ent, ent->activator);

	if (ent->wait > 0)	
	{
		ent->think = multi_wait;
		ent->nextthink = level.time + ent->wait;
	}
	else
	{	// we can't just remove (self) here, because this is a touch function
		// called while looping through area links...
		ent->touch = NULL;
		ent->nextthink = level.time + FRAMETIME;
		ent->think = G_FreeEdict;
	}
}

void Use_Multi (edict_t *ent, edict_t *other, edict_t *activator)
{
	ent->activator = activator;
	multi_trigger (ent);
}

void Touch_Multi (edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
/*	if(other->client)
	{
		if (self->spawnflags & 2)
			return;
	}
	else if (other->svflags & SVF_MONSTER)
	{
		if (!(self->spawnflags & 1))
			return;
	}
	else
		return;*/

	if( strcmp(other->classname,"plane") != 0 &&
		strcmp(other->classname,"helo") != 0 &&
		strcmp(other->classname,"ground") != 0 &&
		strcmp(other->classname,"LQM") != 0 )
		return;

	if (!VectorCompare(self->movedir, vec3_origin))
	{
		vec3_t	forward;

		AngleVectors(other->s.angles, forward, NULL, NULL);
		if (_DotProduct(forward, self->movedir) < 0)
			return;
	}

	self->activator = other;
	multi_trigger (self);
}

/*QUAKED trigger_multiple (.5 .5 .5) ? MONSTER NOT_PLAYER TRIGGERED
Variable sized repeatable trigger.  Must be targeted at one or more entities.
If "delay" is set, the trigger waits some time after activating before firing.
"wait" : Seconds between triggerings. (.2 default)
sounds
1)	secret
2)	beep beep
3)	large switch
4)
set "message" to text string
*/
void trigger_enable (edict_t *self, edict_t *other, edict_t *activator)
{
	self->solid = SOLID_TRIGGER;
	self->use = Use_Multi;
	gi.linkentity (self);
}

void SP_trigger_multiple (edict_t *ent)
{
	if (ent->sounds == 1)
		ent->noise_index = gi.soundindex ("misc/secret.wav");
	else if (ent->sounds == 2)
		ent->noise_index = gi.soundindex ("misc/talk.wav");
	else if (ent->sounds == 3)
		ent->noise_index = gi.soundindex ("misc/trigger1.wav");
	
	if (!ent->wait)
		ent->wait = 0.2;
	ent->touch = Touch_Multi;
	ent->movetype = MOVETYPE_NONE;
	ent->svflags |= SVF_NOCLIENT;


	if (ent->spawnflags & 4)
	{
		ent->solid = SOLID_NOT;
		ent->use = trigger_enable;
	}
	else
	{
		ent->solid = SOLID_TRIGGER;
		ent->use = Use_Multi;
	}

	if (!VectorCompare(ent->s.angles, vec3_origin))
		G_SetMovedir (ent->s.angles, ent->movedir);

	gi.setmodel (ent, ent->model);
	gi.linkentity (ent);
}


/*QUAKED trigger_once (.5 .5 .5) ? x x TRIGGERED
Triggers once, then removes itself.
You must set the key "target" to the name of another object in the level that has a matching "targetname".

If TRIGGERED, this trigger must be triggered before it is live.

sounds
 1)	secret
 2)	beep beep
 3)	large switch
 4)

"message"	string to be displayed when triggered
*/

void SP_trigger_once(edict_t *ent)
{
	// make old maps work because I messed up on flag assignments here
	// triggered was on bit 1 when it should have been on bit 4
	if (ent->spawnflags & 1)
	{
		vec3_t	v;

		VectorMA (ent->mins, 0.5, ent->size, v);
		ent->spawnflags &= ~1;
		ent->spawnflags |= 4;
		gi.dprintf("fixed TRIGGERED flag on %s at %s\n", ent->classname, vtos(v));
	}

	ent->wait = -1;
	SP_trigger_multiple (ent);
}

/*QUAKED trigger_relay (.5 .5 .5) (-8 -8 -8) (8 8 8)
This fixed size trigger cannot be touched, it can only be fired by other events.
*/
void trigger_relay_use (edict_t *self, edict_t *other, edict_t *activator)
{
	G_UseTargets (self, activator);
}

void SP_trigger_relay (edict_t *self)
{
	self->use = trigger_relay_use;
}



/*
==============================================================================

trigger_counter

==============================================================================
*/

/*QUAKED trigger_counter (.5 .5 .5) ? nomessage
Acts as an intermediary for an action that takes multiple inputs.

If nomessage is not set, t will print "1 more.. " etc when triggered and "sequence complete" when finished.

After the counter has been triggered "count" times (default 2), it will fire all of it's targets and remove itself.
*/

void trigger_counter_use(edict_t *self, edict_t *other, edict_t *activator)
{
	if (self->count == 0)
		return;
	
	self->count--;

	if (self->count)
	{
		if (! (self->spawnflags & 1) && !(other->HASCAN & HASCAN_DRONE) && (other->ONOFF & ONOFF_PILOT_ONBOARD) )
		{
			gi.centerprintf(activator, "%i more to go...", self->count);
			gi.sound (activator, CHAN_AUTO, gi.soundindex ("misc/talk1.wav"), 1, ATTN_NORM, 0);
		}
		return;
	}
	
	if (! (self->spawnflags & 1) && !(other->HASCAN & HASCAN_DRONE) && (other->ONOFF & ONOFF_PILOT_ONBOARD) )
	{
		gi.centerprintf(activator, "Sequence completed!");
		gi.sound (activator, CHAN_AUTO, gi.soundindex ("misc/talk1.wav"), 1, ATTN_NORM, 0);
	}
	self->activator = activator;
	multi_trigger (self);
}

void SP_trigger_counter (edict_t *self)
{
	self->wait = -1;
	if (!self->count)
		self->count = 2;

	self->use = trigger_counter_use;
}


/*
==============================================================================

trigger_always

==============================================================================
*/

/*QUAKED trigger_always (.5 .5 .5) (-8 -8 -8) (8 8 8)
This trigger will always fire.  It is activated by the world.
*/
void SP_trigger_always (edict_t *ent)
{
	// we must have some delay to make sure our use targets are present
	if (ent->delay < 0.2)
		ent->delay = 0.2;
	G_UseTargets(ent, ent);
}


/*
==============================================================================

trigger_push

==============================================================================
*/

#define PUSH_ONCE		1

static int windsound;

void trigger_push_touch (edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	if (other->health > 0)
	{
		VectorScale (self->movedir, self->speed * 10, other->velocity);
	}
	if (self->spawnflags & PUSH_ONCE)
		G_FreeEdict (self);
}


/*QUAKED trigger_push (.5 .5 .5) ? PUSH_ONCE
Pushes the player
"speed"		defaults to 1000
*/
void SP_trigger_push (edict_t *self)
{
	InitTrigger (self);
	windsound = gi.soundindex ("misc/windfly.wav");
	self->touch = trigger_push_touch;
	if (!self->speed)
		self->speed = 1000;
	gi.linkentity (self);
}


/*
==============================================================================

trigger_hurt

==============================================================================
*/

/*QUAKED trigger_hurt (.5 .5 .5) ? START_OFF TOGGLE SILENT NO_PROTECTION SLOW
Any entity that touches this will be hurt.

It does dmg points of damage each server frame

SILENT			supresses playing the sound
SLOW			changes the damage rate to once per second
NO_PROTECTION	*nothing* stops the damage

"dmg"			default 5 (whole numbers only)

*/
void hurt_use (edict_t *self, edict_t *other, edict_t *activator)
{
	if (self->solid == SOLID_NOT)
		self->solid = SOLID_TRIGGER;
	else
		self->solid = SOLID_NOT;
	gi.linkentity (self);

	if (!(self->spawnflags & 2))
		self->use = NULL;
}


void hurt_touch (edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	int		dflags;

	if (!other->takedamage)
		return;

	if (self->timestamp > level.time)
		return;

	if (self->spawnflags & 16)
		self->timestamp = level.time + 1;
	else
		self->timestamp = level.time + FRAMETIME;

	if (!(self->spawnflags & 4))
	{
		if ((level.framenum % 10) == 0)
			gi.sound (other, CHAN_AUTO, self->noise_index, 1, ATTN_NORM, 0);
	}

	if (self->spawnflags & 8)
		dflags = DAMAGE_NO_PROTECTION;
	else
		dflags = 0;
	T_Damage (other, self, self, vec3_origin, other->s.origin, vec3_origin, self->dmg, self->dmg, dflags, MOD_TRIGGER_HURT);
}

void SP_trigger_hurt (edict_t *self)
{
	InitTrigger (self);

	self->noise_index = gi.soundindex ("world/electro.wav");
	self->touch = hurt_touch;

	if (!self->dmg)
		self->dmg = 5;

	if (self->spawnflags & 1)
		self->solid = SOLID_NOT;
	else
		self->solid = SOLID_TRIGGER;

	if (self->spawnflags & 2)
		self->use = hurt_use;

	gi.linkentity (self);
}


/*
==============================================================================

trigger_gravity

==============================================================================
*/

/*QUAKED trigger_gravity (.5 .5 .5) ?
Changes the touching entites gravity to
the value of "gravity".  1.0 is standard
gravity for the level.
*/

void trigger_gravity_touch (edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	other->gravity = self->gravity;
}

void SP_trigger_gravity (edict_t *self)
{
	if (st.gravity == 0)
	{
		gi.dprintf("trigger_gravity without gravity set at %s\n", vtos(self->s.origin));
		G_FreeEdict  (self);
		return;
	}

	InitTrigger (self);
	self->gravity = atoi(st.gravity);
	self->touch = trigger_gravity_touch;
}


/*
==============================================================================

trigger_recharge
(AQ2 only)
==============================================================================
*/

/*QUAKED trigger_recharge (0 1 1) ?
Recharges the vehicle standing
"inside" it.

key-values:
-----------
sounds - 0,1,2,3
	0 = all vehicles
	1 = planes only
	2 = helos only
	3 = ground only
*/


// +BD AQ2 recharge
void recharge_vehicle( edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf )
{
	int type = 0;
	int repair = 32768;
	int done = 0;
	int i;

	if( strcmp( other->classname, "plane" ) != 0 &&
		strcmp( other->classname, "helo" ) != 0 &&
		strcmp( other->classname, "ground" ) != 0 &&
		strcmp( other->classname, "LQM" ) != 0 )
		return;

	if( other->deadflag )
		return;

	if( other->speed > 1 )
		return;

	if( other->HASCAN & HASCAN_DRONE )
		return;

	if( teamplay->value && self->aqteam )
	{
		if( self->aqteam != other->aqteam )
			return;
	}

	if( other->thrust != THRUST_IDLE )
		return;

	if( !(other->ONOFF & ONOFF_PILOT_ONBOARD) && strcmp(other->classname, "LQM") != 0 )	// only recharge with pilot on board
		return;

	if( strcmp( other->classname, "plane" ) == 0 )
		type = CAT_PLANE;
	else if( strcmp( other->classname, "helo" ) == 0 )
		type = CAT_HELO;
	else if( strcmp( other->classname, "ground" ) == 0 )
		type = CAT_GROUND;
	else if( strcmp( other->classname, "LQM" ) == 0 )
		type = CAT_LQM;

	if( (other->ONOFF & ONOFF_LANDED_NOGEAR) || (other->ONOFF & ONOFF_LANDED_TERRAIN_NOGEAR)
			|| (other->ONOFF & ONOFF_LANDED_WATER_NOGEAR) || (other->ONOFF & ONOFF_AIRBORNE) ||
			(other->ONOFF & ONOFF_AUTOROTATION) )
		return;

//	gi.bprintf( PRINT_HIGH, "%d (type), %d(cat)\n", type, self->sounds );

	other->ONOFF |= ONOFF_IS_CHANGEABLE;
	other->teammaster = self;

	if( level.time < other->recharge_time )
		return;

	if( !self->sounds )
		self->sounds = CAT_ALL;

	if( !(type & self->sounds) )
		return;

//	gi.cprintf( self->owner, PRINT_MEDIUM, "Recharging.\n" );

	if( other->health < other->max_health )
	{
		other->health += (10*other->max_health/100);
		if( other->health > other->max_health )
			other->health = other->max_health;
	}

	for( i = 0; i < MAX_WEAPONS; i++ )
	{
		if( other->weapon[i] == WEAPON_NONE )
			continue;
//		gi.bprintf( PRINT_HIGH, "ammo %d %d\n", other->ammo[i], other->maxammo[i] );
		if( other->ammo[i] < other->maxammo[i] )
		{
			other->ammo[i] += (other->maxammo[i]<=10 ? 1 : other->maxammo[i]/10);
			if( other->ammo[i] > other->maxammo[i] )
				other->ammo[i] = other->maxammo[i];
		}
	}
	if( other->flares < other->maxflares )
	{
		other->flares += 5;
		if( other->flares > other->maxflares )
			other->flares = other->maxflares;
	}

	if( other->DAMAGE )
	{
		while( !done )
		{
			if( other->DAMAGE & repair )
			{
				other->DAMAGE ^= repair;
				done = 1;
				if( repair & DAMAGE_WEAPON_0 )
				{
					other->ammo[0] = 0;
				}
				else if( repair & DAMAGE_WEAPON_1 )
				{
					other->ammo[1] = 0;
				}
				else if( repair & DAMAGE_WEAPON_2 )
				{
					other->ammo[2] = 0;
				}
				else if( repair & DAMAGE_WEAPON_3 )
				{
					other->ammo[3] = 0;
				}
				else if( repair & DAMAGE_WEAPON_4 )
				{
					other->ammo[4] = 0;
				}
			}
			else
				repair /= 2;
		}
	}

	if( !other->DAMAGE && strcmp( other->classname, "LQM" ) != 0 )
	{
		if( other->health == other->max_health )
			gi.cprintf( other->owner, PRINT_MEDIUM, "All systems OK!\n" );
		repair = 0;
	}
	else
	{
		switch( repair )
		{
			case DAMAGE_WEAPONBAY:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Weaponbay repaired.\n" );
				break;
			case DAMAGE_ENGINE_DESTROYED:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Engine 20 percent workable.\n" );
				break;
			case DAMAGE_ENGINE_20:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Engine 40 percent workable.\n" );
				break;
			case DAMAGE_ENGINE_40:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Engine 60 percent workable.\n" );
				break;
			case DAMAGE_ENGINE_60:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Engine 80 percent workable.\n" );
				break;
			case DAMAGE_ENGINE_80:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Engine 100 percent workable.\n" );
				break;
			case DAMAGE_AFTERBURNER:
				if( strcmp( other->classname,"ground") == 0 )
					gi.cprintf( other->owner, PRINT_MEDIUM, "Reverse repaired.\n" );
				else
					gi.cprintf( other->owner, PRINT_MEDIUM, "Afterburner repaired.\n" );
				break;
			case DAMAGE_BRAKE:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Brakes repaired.\n" );
				break;
			case DAMAGE_GEAR:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Gear repaired.\n" );
				break;
			case DAMAGE_AUTOPILOT:
				gi.cprintf( other->owner, PRINT_MEDIUM, "Autopilot repaired.\n" );
				break;
			case DAMAGE_GPS:
				gi.cprintf( other->owner, PRINT_MEDIUM, "GPS repaired.\n" );
				break;
			case DAMAGE_WEAPON_0:
				if( other->weapon[0] != WEAPON_NONE )
					gi.cprintf( other->owner, PRINT_MEDIUM, "%s repaired.\n", other->weaponname[0] );
				break;
			case DAMAGE_WEAPON_1:
				if( other->weapon[1] != WEAPON_NONE )
					gi.cprintf( other->owner, PRINT_MEDIUM, "%s launch system repaired.\n", other->weaponname[1] );
				break;
			case DAMAGE_WEAPON_2:
				if( other->weapon[2] != WEAPON_NONE )
					gi.cprintf( other->owner, PRINT_MEDIUM, "%s launch system repaired.\n", other->weaponname[2] );
				break;
			case DAMAGE_WEAPON_3:
				if( other->weapon[3] != WEAPON_NONE )
					gi.cprintf( other->owner, PRINT_MEDIUM, "%s launch system repaired.\n", other->weaponname[3] );
				break;
			case DAMAGE_WEAPON_4:
				if( other->weapon[4] != WEAPON_NONE )
					gi.cprintf( other->owner, PRINT_MEDIUM, "%s launch system repaired.\n", other->weaponname[4] );
				break;
		}
	}

	other->recharge_time = level.time + 1.6;

}


void SP_trigger_recharge (edict_t *self)
{
	InitTrigger(self);
	self->classname = "trigger_recharge";
	self->touch = recharge_vehicle;
	gi.linkentity (self);
}








/*
==============================================================================

trigger_radio

==============================================================================
*/

/*QUAKED trigger_radio (0 1 1) ?
Used to trigger anything controlled
by the tower (elvators, catapults etc)
target is the entity triggered
sound if for special category only
*/

void radio_tower( edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf )
{
	if( strcmp( other->classname, "plane" ) != 0 &&
		strcmp( other->classname, "helo" ) != 0 &&
		strcmp( other->classname, "ground" ) != 0 &&
		strcmp( other->classname, "LQM" ) != 0 )
		return;
	if( teamplay->value && self->aqteam )
	{
		if( self->aqteam != other->aqteam )
			return;
	}
	other->radio_target = self;
}


void SP_trigger_radio (edict_t *self)
{
	InitTrigger(self);
	self->classname = "trigger_radio";
	self->touch = radio_tower;
	gi.linkentity (self);
}

