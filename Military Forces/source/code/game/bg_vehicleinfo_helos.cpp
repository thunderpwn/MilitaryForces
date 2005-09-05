#include "bg_datamanager.h"
#include "bg_vehicleinfo.h"
#include "q_shared.h"
#include "../qcommon/qfiles.h"
#include "bg_public.h"

void
DataManager::createAllHelos()
{
	VehicleInfo* veh = 0;

	// UH-1
	veh = createVehicle();
	veh->descriptiveName_ =	"UH-1 \"Huey\"";
	veh->tinyName_ = "UH-1";
	veh->modelName_ = "UH-1";
	veh->gameSet_ = MF_GAMESET_MODERN;
	veh->category_ = CAT_HELO;
	veh->class_ = CLASS_HELO_RECON;
	veh->flags_ = 0;
	veh->caps_ = 0;
	veh->renderFlags_ = 0;	
    VectorSet( veh->turnSpeed_, 50, 125, 70 );		
	VectorSet( veh->camDist_, 0, 100, 80 );
	VectorSet( veh->camHeight_ , 0, 100, 25);		
    veh->maxHealth_ = 170;		
	veh->shadowShader_ = SHADOW_DEFAULT;	
	Vector4Set( veh->shadowCoords_, 4, 0, 34, 24 );	
	Vector4Set( veh->shadowAdjusts_, 0, 0, 0, 0 );	
	VectorSet( veh->gunoffset_, 3, 1, 6 );		
	VectorSet( veh->cockpitview_, 19, 0, 5 );	
	veh->airRadar_ = new VehicleRadarInfo(0, 8000, CAT_PLANE|CAT_HELO);		
	veh->groundRadar_ = new VehicleRadarInfo(-1, 5000, CAT_GROUND|CAT_BOAT);			
	veh->minThrottle_ = -5;
	veh->maxThrottle_ = 10;
	veh->acceleration_ = 100;
	veh->maxFuel_ = 160;
	veh->wheels_ = 0;		
	veh->wheelCF_ = 0.0f;		
	veh->engines_ = 1;		
	veh->bayAnim_ = 0;		
	veh->gearAnim_ = 0;		
	veh->tailAngle_ = 0;		
	veh->abEffectModel_ = 0;	
    veh->stallSpeed_ = 0;	
	veh->swingAngle_ = 0;	
	veh->sonarInfo_ = 0; 		
    veh->maxSpeed_ = 250;		
	veh->animations_ = 0;	
	allVehicles_.push_back(veh);
	//285,						// max gun pitch (upwards = negative) <- gearheight
	//5,							// min gun pitch (downwards = positive) <- tailangle

}







