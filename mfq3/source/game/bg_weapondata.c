/*
 * $Id: bg_weapondata.c,v 1.5 2002-01-07 00:06:02 thebjoern Exp $
*/

#include "q_shared.h"
#include "bg_public.h"


// just contains data of all the available weapons
completeWeaponData_t availableWeapons[] = 
{
	// empty entry
	{ 
		0,									// type
		0,									// gameset
		"",									// descriptiveName
		"",									// modelName
		"",									// iconName
		0,									// iconHandle
		0,									// cat
		0,									// non cat mod
		0,									// muzzleVelocity
		0,									// range
		0,									// fuelrange
		0,									// fire interval
		0,									// damage
		0,									// damageRadius
		0,									// spread
		0,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		0,									// crosshair
		0,									// crosshair track
		0,									// crosshair lock
		0									// crosshair lock friend
	},

	// machinegun: WW1, cal .303, 2 barrels
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_WW1,						// gameset
		"2x cal.303 MG",					// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		2000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		150,								// fire interval
		10,									// damage
		0,									// damageRadius
		8,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		8,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: WW1, cal .312, 2 barrels
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_WW1,						// gameset
		"2x cal.312 MG",					// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		2000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		150,								// fire interval
		10,									// damage
		0,									// damageRadius
		8,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		8,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: WW2, cal 50, 8 barrels
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_WW2,						// gameset
		"8x cal.50 MG",						// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		3000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		150,								// fire interval
		18,									// damage
		0,									// damageRadius
		8,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		8,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: WW2, cal 50, 6 barrels
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_WW2,						// gameset
		"6x cal.50 MG",						// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		3000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		150,								// fire interval
		18,									// damage
		0,									// damageRadius
		8,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		6,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: any set, 12.7mm, 1 barrel
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_ANY,						// gameset
		"12.7mm MG",						// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		3000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		100,								// fire interval
		12,									// damage
		0,									// damageRadius
		14,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		1,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: any set, 14.5mm, 1 barrel
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_ANY,						// gameset
		"Dual 14.5mm MG",					// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		3000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		120,								// fire interval
		14,									// damage
		0,									// damageRadius
		14,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		2,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: modern, 20mm, 1 barrel
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_MODERN,					// gameset
		"20mm MG",							// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		3000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		100,								// fire interval
		20,									// damage
		0,									// damageRadius
		14,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		1,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// machinegun: modern, 20mm, 2 barrel
	{ 
		WT_MACHINEGUN,						// type
		MF_GAMESET_MODERN,					// gameset
		"Dual 20mm MG",						// descriptiveName
		"",									// modelName
		"hud/iconw_mg.tga",					// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		3000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		100,								// fire interval
		20,									// damage
		0,									// damageRadius
		10,									// spread (in 0.1 deg; ie 60 means +- 3 degrees)
		2,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_GUNMODE,							// crosshair
		CH_GUNMODE,							// crosshair track
		CH_GUNMODE,							// crosshair lock
		CH_GUNMODE							// crosshair lock friend
	},

	// FFAR
	{ 
		WT_ROCKET,							// type
		MF_GAMESET_ANY,						// gameset
		"FFAR",								// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		1500,								// muzzleVelocity
		0,									// range
		8000,								// fuelrange
		160,								// fire interval
		40,									// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_ROCKETMODE,						// crosshair
		CH_ROCKETMODE,						// crosshair track
		CH_ROCKETMODE,						// crosshair lock
		CH_ROCKETMODE						// crosshair lock friend
	},

	// tank gun
	{ 
		WT_BALLISTICGUN,					// type
		MF_GAMESET_ANY,						// gameset
		"100mm Gun",						// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		2000,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		1500,								// fire interval
		140,								// damage
		80,									// damageRadius
		1,									// spread
		1,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_ROCKETMODE,						// crosshair
		CH_ROCKETMODE,						// crosshair track
		CH_ROCKETMODE,						// crosshair lock
		CH_ROCKETMODE						// crosshair lock friend	
	},

	// tank gun
	{ 
		WT_BALLISTICGUN,					// type
		MF_GAMESET_ANY,						// gameset
		"125mm Gun",						// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		2500,								// muzzleVelocity
		0,									// range
		0,									// fuelrange
		1500,								// fire interval
		200,								// damage
		100,								// damageRadius
		1,									// spread
		1,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_ROCKETMODE,						// crosshair
		CH_ROCKETMODE,						// crosshair track
		CH_ROCKETMODE,						// crosshair lock
		CH_ROCKETMODE						// crosshair lock friend	
	},

	// iron bombs
	{ 
		WT_IRONBOMB,						// type
		MF_GAMESET_ANY,						// gameset
		"Mk82",								// descriptiveName
		"models/weapons/ag_800_d.md3",		// modelName
		"hud/iconw_bmb.tga",				// iconName
		0,									// iconHandle
		CAT_ANY,							// cat
		0,									// non cat mod
		0,									// muzzleVelocity
		0,									// range
		0,									// fuelrange
		150,								// fire interval
		200,								// damage
		120,								// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0,									// trackcone
		0,									// lockcone
		0,									// followcone
		0,									// locktime
		CH_BOMBMODE,						// crosshair
		CH_BOMBMODE,						// crosshair track
		CH_BOMBMODE,						// crosshair lock
		CH_BOMBMODE							// crosshair lock friend
	},

	// Sidewinder
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AIM-9 Sidewinder",					// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		1000,								// muzzleVelocity
		5000,								// range
		8000,								// fuelrange
		500,								// fire interval
		100,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.35f,								// trackcone (dot) (0.7)
		0.985f,								// lockcone (dot)
		0.985f,								// followcone (dot) (0.996)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// AMRAAM
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AIM-120 AMRAMM",							// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		1600,								// muzzleVelocity
		10000,								// range
		8000,								// fuelrange
		500,								// fire interval
		100,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Sparrow
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AIM-7 Sparrow",					// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		1600,								// muzzleVelocity
		8000,								// range
		8000,								// fuelrange
		500,								// fire interval
		100,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Phoenix
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AIM-54 Phoenix",					// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		2500,								// muzzleVelocity
		14000,								// range
		8000,								// fuelrange
		500,								// fire interval
		120,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Stinger
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"Stinger",							// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		1500,								// muzzleVelocity
		4000,								// range
		8000,								// fuelrange
		1000,								// fire interval
		80,									// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Atoll
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AA-2 Atoll",						// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		1000,								// muzzleVelocity
		5000,								// range
		8000,								// fuelrange
		500,								// fire interval
		100,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.35f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.985f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Archer
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AA-11 Archer",						// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		1800,								// muzzleVelocity
		8000,								// range
		8000,								// fuelrange
		500,								// fire interval
		100,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Alamo
	{ 
		WT_ANTIAIRMISSILE,					// type
		MF_GAMESET_ANY,						// gameset
		"AA-10 Alamo",						// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_PLANE|CAT_HELO,					// cat
		0.3f,								// non cat mod
		2500,								// muzzleVelocity
		10000,								// range
		8000,								// fuelrange
		500,								// fire interval
		100,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Hellfire
	{ 
		WT_ANTIGROUNDMISSILE,				// type
		MF_GAMESET_ANY,						// gameset
		"Hellfire",							// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_GROUND,							// cat
		0.3f,								// non cat mod
		1000,								// muzzleVelocity
		6000,								// range
		5000,								// fuelrange
		500,								// fire interval
		300,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// Maverick
	{ 
		WT_ANTIGROUNDMISSILE,				// type
		MF_GAMESET_ANY,						// gameset
		"Maverick",							// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"hud/iconw_rkt.tga",				// iconName
		0,									// iconHandle
		CAT_GROUND,							// cat
		0.3f,								// non cat mod
		1000,								// muzzleVelocity
		8000,								// range
		5000,								// fuelrange
		500,								// fire interval
		400,								// damage
		50,									// damageRadius
		1,									// spread
		2,									// barrels
		0,									// barrelDistance
		0.7f,								// trackcone (dot)
		0.985f,								// lockcone (dot)
		0.996f,								// followcone (dot)
		1500,								// locktime
		CH_MISSILEMODE,						// crosshair
		CH_MISSILEMODE,						// crosshair track
		CH_MISSILEMODELOCK,					// crosshair lock
		CH_MISSILEMODE						// crosshair lock friend
	},

	// flares
	{ 
		WT_FLARE,							// type
		MF_GAMESET_ANY,						// gameset
		"Flare",							// descriptiveName
		"models/weapons/ffar.md3",			// modelName
		"",									// iconName
		0,									// iconHandle
		0,									// cat
		0,									// non cat mod
		0,									// muzzleVelocity
		0,									// range
		2000,								// fuelrange
		100,								// fire interval
		0,									// damage
		0,									// damageRadius
		1,									// spread
		0,									// barrels
		0,									// barrelDistance
		0,									// trackcone (dot)
		0,									// lockcone (dot)
		0,									// followcone (dot)
		0,									// locktime
		0,									// crosshair
		0,									// crosshair track
		0,									// crosshair lock
		0									// crosshair lock friend
	}
};

int bg_numberOfWeapons = sizeof(availableWeapons) / sizeof(availableWeapons[0]);