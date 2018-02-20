# A-virtual-LiDAR-for-DeepGTAV  

## Preview:
![image](https://github.com/gdpinchina/A-virtual-LiDAR-for-DeepGTAV/blob/master/20180215130213.png)



## Usage:
### Configure DeepGTAV
1. Get DeepGTAV source code from `https://github.com/aitorzip/DeepGTAV` and build it;
2. Copy `LiDAR.h` and `LiDAR.cpp` to DeepGTAV source code folder;
3. (Optional)Place the following piece of code below `DeepGTAV/Scenario.cpp/void Scenario::buildScenario()/CAM::RENDER_SCRIPT_CAMS(TRUE, FALSE, 0, TRUE, TRUE);`(Reason: Wait the camera initated. If camera isn't initiated, the first frame of LiDAR is wrong)
```	
	isCamInit = false;  
	while (!isCamInit)//Wait the camera initated. If camera isn't initiated, the first frame of LiDAR is wrong.   
	{  
		Vector3 source = CAM::GET_CAM_COORD(camera);  
		if (abs(source.x - 128000.0) < 1e-5 && abs(source.y - 128000.0) < 1e-5)  
			scriptWait(1);  
		else  
			isCamInit = true;  
	}
  ```
### Initialize LiDAR 
You can initialize LiDAR in two ways:
1. Use APIs `Init2DLiDAR_SmplNum` or `Init3DLiDAR_SmplNum` to initialize LiDAR as 2D or 3D mode. These two APIs can configure LiDAR FOVs more specifically;
2. APIs `Init2DLiDAR_FOV` or `Init3DLiDAR_FOV` also work;
3. Meanings of parameters of APIs above can be found in `LiDAR.cpp`;
4. Example: Place the following piece of code to the bottom of `DeepGTAV/Scenario.cpp/void Scenario::buildScenario()`. 
```
  //setup LiDAR
	if (liDAR) //flag if activate the LiDAR
	{
		if (liDARDevice == NULL) liDARDevice = new LiDAR();
		if (strcmp("2D", liDARType) == 0) {
			if (abs(liDARParams[0]) < 1e-5)
				liDARDevice->Init2DLiDAR_SmplNum();//use default configuration
			else
				liDARDevice->Init2DLiDAR_SmplNum(liDARParams[0], liDARParams[1], liDARParams[2], liDARParams[3]);
		}
		else if (strcmp("3D", liDARType) == 0) {
			if (abs(liDARParams[0]) < 1e-5)
				liDARDevice->Init3DLiDAR_SmplNum();//use default configuration
			else
				liDARDevice->Init3DLiDAR_SmplNum(liDARParams[0], liDARParams[1], liDARParams[2], liDARParams[3],
					liDARParams[4], liDARParams[5], liDARParams[6]);
		}
		liDARDevice->AttachLiDAR2Camera(camera, vehicle);//Attach the LiDAR to the camera
	}
```

### Attach LiDAR to the entity camera
Attach a LiDAR device to a vehicle. Two params are needed, camera ID and vehicle ID which both can be found in DeepGTAV. 
1. Use API `AttachLiDAR2Camera` to attach LiDAR to the entity. 

### Get point clouds
Once API `GetPointClouds` is called, points are sampled. 
1. Get the LiDAR range results from the return of API `GetPointClouds`, which is a float array with `length == getTotalSmplNum()`. 
2. If you want to get point(Cartesian coordinate) results, a solution can be found in `A-virtual-LiDAR-for-DeepGTAV/examples/LIDAR_GTAV`


## Please tell me the bugs, thanks!
