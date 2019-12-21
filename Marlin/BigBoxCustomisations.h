//BigBox Custom Menu String commands
#ifndef BIGBOX_CUSTOMISATIONS_H
#define BIGBOX_CUSTOMISATIONS_H


#if ENABLED(BIGBOX_CUSTOMISATIONS)

	//
	// Customised Menus
	//

	#define BIGBOX_CUSTOMISED_MENUS
	#if ENABLED(BIGBOX_CUSTOMISED_MENUS)
		//
		// XY Loop  useful for testing full coverage of XY plane
		//
		#define BB_CUSTOM_MENU_XYLOOP_MENU 	"XY Loop"
		#define BB_CUSTOM_MENU_XYLOOP_HOMED 	"G91\nT0\nG1 Z1 F1000\nG90\nT0\nG1 X5 Y5 F3000\nG1 Y195 F3000\nG1 X295 F3000\nG1 Y5 F3000\nG1 X5 F3000\nG91\nG1 Z-1 F1000"
		#define BB_CUSTOM_MENU_XYLOOP_NOTHOMED "G28\nG91\nT0\nG1 Z1 F1000\nG90\nT0\nG1 X5 Y5 F3000\nG1 Y195 F3000\nG1 X295 F3000\nG1 Y5 F3000\nG1 X5 F3000\nG91\nG1 Z-1 F1000"

		//
		// Dock Extruder to waste box // 20170106 PB 
		//
		#define BB_CUSTOM_MENU_DOCK_MENU 		"Dock Head"
		#define BB_CUSTOM_MENU_DOCK_HOMED      "G91\nT0\nG1 Z1 F1000\nG90\nT0\nG1 X70 Y200 F3000\nG1 Y238 F2000\nG91\nG1 Z-1 F1000"
		#define BB_CUSTOM_MENU_DOCK_NOTHOMED   "G28\nG91\nT0\nG1 Z1 F1000\nG90\nG1 X70 Y200 F3000\nG1 Y238 F2000\nG1 Z-1 F1000"

		//
		// Wipe/Clean nozzle in dock
		// 
		#define BB_CUSTOM_MENU_NOZZLECLEAN_MENU 	  "Clean Nozzles"
		#define BB_CUSTOM_MENU_NOZZLECLEAN_HOMED     "G91\nT0\nG1 Z1 F1000\nG90\nT0\nG1 X60 Y200 F3000\nG1 Y238 F2000\nG1 X90 F2000\nG1  Y200 F2000\nG91\nG1 Z-1 F1000"
		#define BB_CUSTOM_MENU_NOZZLECLEAN_NOTHOMED  "G28\nG91\nT0\nG1 Z1 F1000\nG90\nT0\nG1 X60 Y200 F3000\nG1 Y238 F2000\nG1 X90 F2000\nG1 Y200 F2000\nG91\nG1 Z-1 F1000"

		//
		// Drop Bed to 295
		// 
		#define BB_CUSTOM_MENU_DROPBED_MENU 	"Move Z to 295"
		#define BB_CUSTOM_MENU_DROPBED_HOMED 	"G90\nG1 Z295 F3000"
		#define BB_CUSTOM_MENU_DROPBED_NOTHOMED "G90\nG28\nG1 Z295 F3000"


		//
		// Corner Level positions
		//
		#define BB_CUSTOM_LEVEL_BED_CORNERS_X_MIN (abs(X_PROBE_OFFSET_FROM_EXTRUDER) + 5)
		#define BB_CUSTOM_LEVEL_BED_CORNERS_X_MAX (X_BED_SIZE-38.60-5 )  //HOTEND_OFFSET_X   X_PROBE_OFFSET_FROM_EXTRUDER
		#define BB_CUSTOM_LEVEL_BED_CORNERS_Y_MIN 10
		#define BB_CUSTOM_LEVEL_BED_CORNERS_Y_MAX (Y_BED_SIZE-10)

	#endif




	//
	// Tool Change Behaviour
	//
	// By default, Issuing t1,T0 etc will keep current co-ordinate active by repositioning the head
	#define BB_CUSTOM_TOOL_CHANGE_BEHAVIOUR_NOMOVE

	//
	// Nozzel Park behaviour, change head to t0.  Based location on head 0 postition
	//
	#define BB_CUSTOM_NOZZLE_PARK_BEHAVIOUR_T0



	//
	// trouble shooting - https://github.com/MarlinFirmware/Marlin/issues/10446
	//
	#define BB_CUSTOM_DEBUG_LAYERSHIFT_20180424

	//
	// Custom Dock position - G27 
	//
	#define BB_CUSTOM_DOCK_G27
	#if ENABLED(BB_CUSTOM_DOCK_G27)
	  #define BB_CUSTOM_NOZZLE_PARK_POINT2 {70,238,20} 
	#endif //BB_CUSTOM_DOCK_G27


    //
    // G26 Use custom Nozzle 
    // 
    // Use one of the following, 
    #define BB_CUSTOM_G26_NOZZLE 1				// Hardcoded
    #define BB_CUSTOM_G26_NOZZLE_USE_ACTIVE 1   // or currently active









#endif //BIGBOX_CUSTOMISATIONS

#endif // BIGBOX_CUSTOMISATIONS_H
