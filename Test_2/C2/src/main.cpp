#include "vex.h"

using namespace vex;

int main() {
    // 初始化VEX V5硬件
    vex::brain Brain;

    // 创建控制器对象
    controller Controller1 = controller(primary);  // primary表示主控制器

    // 创建驱动电机对象
    motor leftMotor(0);
    motor rightMotor(1);

    while (true) {
        // 使用控制器的Axis2来控制两个电机的前进和后退
        int forwardBackwardSpeed = Controller1.Axis2.position(); // 获取右操纵杆的位置
        leftMotor.spin(vex::directionType::fwd, forwardBackwardSpeed, vex::velocityUnits::pct);
        rightMotor.spin(vex::directionType::fwd, forwardBackwardSpeed, vex::velocityUnits::pct);

        // 使用控制器的Axis1来控制两个电机的左转和右转
        int leftRightSpeed = Controller1.Axis1.position(); // 获取左操纵杆的位置
        leftMotor.spin(vex::directionType::fwd, leftRightSpeed, vex::velocityUnits::pct);
        rightMotor.spin(vex::directionType::rev, leftRightSpeed, vex::velocityUnits::pct);

        vex::task::sleep(20); // 防止循环过于频繁
    }
}
