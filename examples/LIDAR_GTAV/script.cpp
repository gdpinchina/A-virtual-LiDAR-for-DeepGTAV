/*
	THIS FILE IS A PART OF GTA V SCRIPT HOOK SDK
				http://dev-c.com
			(C) Alexander Blade 2015
*/

#include "lib/script.h"
#include "Scenario.h"

void ScriptMain() {
	Scenario scenario;

	scenario.buildScenario();
	scenario.lidar.InitFOUT();

	while (true) {
		scenario.lidar.GetPointClouds();
		scriptWait(0);
	}
}
