// file to intialise the sensors according to the shape of the robot
void sensor_initialisation() {
  if(my_robot.sm_getShape() == 'i'){
    front_sensor_status = my_robot.module1_sensor_status(0);
    right_sensor_status = my_robot.module2_sensor_status(2);
    rear_sensor_status = my_robot.module4_sensor_status(1);
    left_sensor_status = my_robot.module2_sensor_status(5);
    movements();
  }

  if(my_robot.sm_getShape() == 'o'){
    front_sensor_status = my_robot.module2_sensor_status(2);
    right_sensor_status = my_robot.module3_sensor_status(3);
    rear_sensor_status = my_robot.module4_sensor_status(5);
    left_sensor_status = my_robot.module1_sensor_status(0);
    movements();
  }

  if(my_robot.sm_getShape() == 'j'){
    front_sensor_status = my_robot.module1_sensor_status(0);
    right_sensor_status = my_robot.module4_sensor_status(1);
    rear_sensor_status = my_robot.module3_sensor_status(0);
    left_sensor_status = my_robot.module2_sensor_status(5);
    movements();
  }

  if(my_robot.sm_getShape() == 't'){
    front_sensor_status = my_robot.module1_sensor_status(3);
    right_sensor_status = my_robot.module2_sensor_status(2);
    rear_sensor_status = my_robot.module3_sensor_status(3);
    left_sensor_status = my_robot.module4_sensor_status(2);
    movements();
  }

  if(my_robot.sm_getShape() == 'l'){
    front_sensor_status = my_robot.module2_sensor_status(0);
    right_sensor_status = my_robot.module2_sensor_status(2);
    rear_sensor_status = my_robot.module4_sensor_status(1);
    left_sensor_status = my_robot.module1_sensor_status(3);
    movements();
  }

  if(my_robot.sm_getShape() == 's'){
    front_sensor_status = my_robot.module2_sensor_status(0);
    right_sensor_status = my_robot.module2_sensor_status(2);
    rear_sensor_status = my_robot.module3_sensor_status(6); //doesn't exist
    left_sensor_status = my_robot.module4_sensor_status(1);
    movements();
  }

  if(my_robot.sm_getShape() == 'z'){
    front_sensor_status = my_robot.module2_sensor_status(0);
    right_sensor_status = my_robot.module4_sensor_status(2);
    rear_sensor_status = my_robot.module3_sensor_status(0);
    left_sensor_status = my_robot.module1_sensor_status(3);
    movements();
  }
}