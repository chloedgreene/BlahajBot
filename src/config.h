//
// Created by chloe on 4/23/24.
//

#pragma once

/////////////////////////////////////////////////////
// PORTS PORTS PORTS PORTS PORTS PORTS PORTS PORTS //
/////////////////////////////////////////////////////


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


//You need an inertial Sensor for the PID to do error correction properly, set that port here
#define BLAHAJ_INERT 5

//Neumatics are used for the arms on the side of the robot, set what port is used for that here!
#define BLAHAJ_NEUMATIC_PORT 'A'

////////////////////////////////////////////////////////
// PID CALCULATIONS PID CALCULATIONS PID CALCULATIONS //
////////////////////////////////////////////////////////

//Choose what gear set to use (06 = blue,18 = greene,36 = red)
#define BLAHAJ_GEAR_SET pros::v5::MotorGears::green

//NOW we define the Length and width of the robot
#define BLAHAJ_WHEELBASE 48 //Messure From LF->LB or RF->RB, in inchz
#define BLAHAJ_TRACK 16.141 //Messure from LB->RB or LF->RF, in inchs

//Now the type of wheel being used
#define BLAHAJ_WHEELTYPE lemlib::Omniwheel::OLD_4_HALF


/////////////////////////////////////////////////////////////////
// AUTONOUMOUS AUTONOUMOUS AUTONOUMOUS AUTONOUMOUS AUTONOUMOUS //
/////////////////////////////////////////////////////////////////

//Now we declare what assets we want, the file names must not include spaces, and any time there is a . put a _ as a replacement because c++ will accidently think its a keyword and AAAAHH this took hours to figure out
ASSET(cali_txt);
ASSET(path_jerryio_txt)

//   ____    _    _     ___ ____  ____      _  _____ ___ ___  _   _ 
//  / ___|  / \  | |   |_ _| __ )|  _ \    / \|_   _|_ _/ _ \| \ | |
// | |     / _ \ | |    | ||  _ \| |_) |  / _ \ | |  | | | | |  \| |
// | |___ / ___ \| |___ | || |_) |  _ <  / ___ \| |  | | |_| | |\  |
//  \____/_/   \_\_____|___|____/|_| \_\/_/   \_\_| |___\___/|_| \_|


//#define ANGULAR_CALI
//#define LATERAL_CALI

// DO NOT TOUCH PLEASEEEE
// PLEASEEEEEEE without talking to greene, i know how to calibrate it :3

//Dont touch this pls, its internal stuff not mend for team members, only change for debugging
#ifdef ANGULAR_CALI
#define NOT_FOR_PRODUCTION
#endif
#ifdef LATERAL_CALI
#define NOT_FOR_PRODUCTION
#endif
