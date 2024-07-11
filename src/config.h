//
// Created by chloe on 4/23/24.
//

#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Use the defines below to input what ports are being used
//    ┌┐     ┌┐
//LF─►├┼─┬─┬─┼┤◄─RF
//    └┘ │ │ └┘
//       │C│
//       │D│
//    ┌┐ │G│ ┌┐
//LB─►├┼─┴─┴─┼┤◄─RB
//    └┘     └┘

#define BLAHAJ_LF 1
#define BLAHAJ_RF -2
#define BLAHAJ_LB 3
#define BLAHAJ_RB -4

//Choose what gear set to use (06 = blue,18 = greene,36 = red)
#define BLAHAJ_GEAR_SET pros::v5::MotorGears::green

//You need an inertial Sensor for the PID to do error correction properly, set that port here
#define BLAHAJ_INERT 5

//Neumatics are used for the arms on the side of the robot, set what port is used for that here!
#define BLAHAJ_NEUMATIC_PORT 'A'

//NOW we define the Length and width of the robot
#define BLAHAJ_WHEELBASE 48 //Messure From LF->LB or RF->RB, in inchz
#define BLAHAJ_TRACK 16.141 //Messure from LB->RB or LF->RF, in inchs

//Now the type of wheel being used
#define BLAHAJ_WHEELTYPE lemlib::Omniwheel::NEW_325

//What profile on the SD card to run during autonomous
#define BLAHAJ_PATH "path.txt"