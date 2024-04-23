#include "main.h"
#include "lemlib/api.hpp"

pros::Motor left_front_motor(1, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox, not reversed
pros::Motor left_back_motor(2, pros::E_MOTOR_GEARSET_06, false); // port 2, green gearbox, not reversed
pros::Motor right_front_motor(3, pros::E_MOTOR_GEARSET_06, true); // port 3, red gearbox, reversed
pros::Motor right_back_motor(4, pros::E_MOTOR_GEARSET_06, true); // port 4, red gearbox, reversed
pros::Imu inertial_sensor(2);

pros::MotorGroup left_side_motors({left_front_motor, left_back_motor});
pros::MotorGroup right_side_motors({right_front_motor, right_back_motor});

lemlib::Drivetrain_t drivetrain {
    &left_side_motors, // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    10, // track width
    3.25, // wheel diameter
    360 // wheel rpm
};

lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
	nullptr, // horizontal tracking wheel 1
    nullptr, //  horizontal tracking wheel 2
    &inertial_sensor // inertial sensor
};
lemlib::ChassisController_t lateralController { //lateral
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 lemlib::ChassisController_t angularController { //turning
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

void screen() {
    // loop forever
    while (true) {
        pros::lcd::print(0, "Blahaj Bot - Greene_y - %s",VERSION);
        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(1, "x: %f", pose.x); // print the x position
        pros::lcd::print(2, "y: %f", pose.y); // print the y position
        pros::lcd::print(3, "heading: %f", pose.theta); // print the heading
        float average_temp = ((
            ( left_front_motor.get_temperature())+
            ( left_back_motor.get_temperature())+
            (right_back_motor.get_temperature())+
            (right_front_motor.get_temperature())
            )/4);
        pros::lcd::print(4, "Average Temprature: %f*C", pose.theta); // print the heading
        pros::delay(10);
    }
}

void initialize() {
	pros::lcd::initialize();
    chassis.calibrate(); //calibrate sensors in robot
    pros::Task screenTask(screen);
}


void disabled() {}

void competition_initialize() {}

void autonomous() {
    chassis.follow("path.txt",(60+30)*1000,3);
}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	
	while (true) {
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		pros::lcd::print(5, "Input: %d %d", left,right);		

		pros::delay(20);
	}
}
