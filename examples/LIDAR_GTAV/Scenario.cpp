#include "Scenario.h"
#include "lib/utils.h"
#include "defaults.h"
#include <time.h>


void Scenario::buildScenario() {
	while (!ENTITY::DOES_ENTITY_EXIST(ped)) {
		ped = PLAYER::PLAYER_PED_ID();
		WAIT(0);
	}

	player = PLAYER::PLAYER_ID();

	//CAM::DESTROY_ALL_CAMS(TRUE);
	//camera = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", TRUE);
	camera = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", TRUE);

	//if (strcmp(_vehicle, "packer") == 0) CAM::ATTACH_CAM_TO_ENTITY(camera, vehicle, 0, 2.35, 1.7, TRUE);
	//else CAM::ATTACH_CAM_TO_ENTITY(camera, vehicle, 0, 0.5, 0.8, TRUE);
	// ed: 카메라 초기 위치 설정
	
	CAM::ATTACH_CAM_TO_ENTITY(camera, ped, 0, 0, 0, TRUE);
	CAM::SET_CAM_FOV(camera, 60);
	CAM::SET_CAM_ACTIVE(camera, TRUE);
	//CAM::SET_CAM_ROT(camera, rotation.x, rotation.y, rotation.z, 1);
	CAM::SET_CAM_INHERIT_ROLL_VEHICLE(camera, TRUE);
	CAM::RENDER_SCRIPT_CAMS(FALSE, FALSE, 0, TRUE, TRUE);

	//lidar.Init3DLiDAR_FOV(50.0f,180.0f,2.0f,180.0f,4.0f);

	lidar.Init3DLiDAR_SmplNum(50.0f, 360 ,90.0f,90.1f, 20 ,80.0f,120.0f);
	lidar.AttachLiDAR2Camera(camera, ped);

}

