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
        pros::delay(10);
    }
}

void initialize() {
	pros::lcd::initialize();
    chassis.calibrate(); //calibrate sensors in robot
    pros::Task screenTask(screen);
}


void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    chassis.follow("path.txt",(60+30)*1000,3);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	
	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		

		pros::delay(20);
	}
}
