/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include "../../../inc/MarlinConfig.h"

#if ENABLED(NOZZLE_PARK_FEATURE)

#include "../../gcode.h"
#include "../../../libs/nozzle.h"
#include "../../../module/motion.h"

#if ENABLED(BB_CUSTOM_NOZZLE_PARK_BEHAVIOUR_T0)
 #include "../../../module/tool_change.h"
#endif  //BB_CUSTOM_TOOL_CHANGE_BEHAVIOUR_NOMOVE

/**
 * G27: Park the nozzle
 */
void GcodeSuite::G27() {
  // Don't allow nozzle parking without homing first
  if (axis_unhomed_error()) return;


	#if ENABLED(BB_CUSTOM_NOZZLE_PARK_BEHAVIOUR_T0)
	 const uint8_t old_tool_index = active_extruder;
	 tool_change(0, 0, false);
	 Nozzle::park(parser.ushortval('P'));
	 tool_change(old_tool_index, 0, false);
	#else
	 Nozzle::park(parser.ushortval('P'));
	#endif  //BB_CUSTOM_TOOL_CHANGE_BEHAVIOUR_NOMOVE
  //Nozzle::park(parser.ushortval('P'));
}

#endif // NOZZLE_PARK_FEATURE
