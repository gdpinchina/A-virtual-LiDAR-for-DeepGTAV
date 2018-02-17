#pragma once

#include <stdlib.h>
#include <ctime>

#include "lib/script.h"
#include "lib/utils.h"

// ed: header added
#include "LiDAR.h"

#define DEBUG


class Scenario {
public:
	Vehicle vehicle = NULL;
	Player player = NULL;
	Ped ped = NULL;
	Cam camera = NULL;
	Vector3 dir;

public:
	// ed: code added
	LiDAR lidar;

public:
	void buildScenario();

};