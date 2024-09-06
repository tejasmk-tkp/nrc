// // Inclusion of necessary libraries
#include<smorphi.h>
#include<Pixy2ICSP_ESP32.h>
Pixy2ICSP_ESP32 pixy;

// Smorphi is instantiated as my_robot
Smorphi my_robot;

// // Setting up variables and required flags
int front_sensor_status ;
int right_sensor_status ;
int rear_sensor_status ;
int left_sensor_status ;
String last_action = "";
String I_shape_done = "false";
String O_shape_done = "false";
String red_color_done = "false";
String yellow_color_done = "false";

void setup() {
//   // put your setup code here, to run once:
  Serial.begin(115200);
  my_robot.BeginSmorphi();
  Serial.print("Starting...\n");
  
  pixy.init();
}

void loop() {

  int i;
  sensor_initialisation();
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      pixy.ccc.blocks[i].print();
    }
  }  

//     if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
//   else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
//   else if(!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
//   else
//   {
//       Serial.println(F("###########"));
//       while (huskylens.available())
//       {
//           HUSKYLENSResult result = huskylens.read();
// //          color_signature=result.ID;
// //          command_block = result.command;
//           if (result.ID == 1 && result.command == COMMAND_RETURN_BLOCK && my_robot.sm_getShape() != 'i') //If the learned face is detected and recognized as ID 1
//           {
//               Serial.println("This is green colour"); //Display in serial monitor
//               my_robot.sm_reset_M1();
//               my_robot.sm_reset_M2();
//               my_robot.sm_reset_M3();
//               my_robot.sm_reset_M4();
//               my_robot.I();
//               front_sensor_status = my_robot.module1_sensor_status(0);
//               right_sensor_status = my_robot.module1_sensor_status(4);
//               rear_sensor_status = my_robot.module3_sensor_status(0);
//               left_sensor_status = my_robot.module1_sensor_status(10);
// //                my_robot.O(); //If the learned face is detected and recognized, Smorphi will reconfigure to 'O' shape.
//           } 
//           else if (result.ID == 2 && result.command == COMMAND_RETURN_BLOCK && my_robot.sm_getShape() != 'o') //If the learned face is detected and recognized as ID 1
//           {
//               Serial.println("This is red colour"); //Display in serial monitor
//               my_robot.sm_reset_M1();
//               my_robot.sm_reset_M2();
//               my_robot.sm_reset_M3();
//               my_robot.sm_reset_M4();
//               my_robot.O();
//               front_sensor_status = my_robot.module1_sensor_status(0);
//               right_sensor_status = my_robot.module1_sensor_status(4);
//               rear_sensor_status = my_robot.module3_sensor_status(6);
//               left_sensor_status = my_robot.module4_sensor_status(0);
// //                my_robot.O(); //If the learned face is detected and recognized, Smorphi will reconfigure to 'O' shape.
//           }
//           else  
//           {
//               Serial.println("There is no colour present"); //Display in serial monitor
// //                my_robot.O(); //If the learned face is detected and recognized, Smorphi will reconfigure to 'O' shape.
//           } 
// //          break;
 
//       }    
//   }
// //  if (front_sensor_status==0 && red_color_done != "True" && color_signature == 1 && command_block == COMMAND_RETURN_BLOCK){ // 1 is red color
// //    if (I_shape_done != "True" && my_robot.sm_getShape() != 'i'){
// //      my_robot.sm_reset_M1();
// //      my_robot.sm_reset_M2();
// //      my_robot.sm_reset_M3();
// //      my_robot.sm_reset_M4();
// //      my_robot.I();
// //      front_sensor_status = my_robot.module1_sensor_status(0);
// //      right_sensor_status = my_robot.module1_sensor_status(4);
// //      rear_sensor_status = my_robot.module3_sensor_status(0);
// //      left_sensor_status = my_robot.module1_sensor_status(10);
// //      I_shape_done = "True";
// //      red_color_done = "True";
// //      
// //    }
// //  }
// //  if (front_sensor_status==0 && yellow_color_done != "True" && color_signature == 2 && command_block == COMMAND_RETURN_BLOCK){ // 2 is yellow color
// //    if (O_shape_done != "True" && my_robot.sm_getShape() != 'o'){
// //      my_robot.sm_reset_M1();
// //      my_robot.sm_reset_M2();
// //      my_robot.sm_reset_M3();
// //      my_robot.sm_reset_M4();
// //      my_robot.O();
// //      front_sensor_status = my_robot.module1_sensor_status(0);
// //      right_sensor_status = my_robot.module1_sensor_status(4);
// //      rear_sensor_status = my_robot.module3_sensor_status(6);
// //      left_sensor_status = my_robot.module4_sensor_status(0);
// //      O_shape_done = "True";
// //      yellow_color_done = "True";
// //      
// //    }
// //  }
  
// // These conditions never execute as robot always falls under else condition    
// //  my_robot.stopSmorphi();
// //  my_robot.sm_reset_M1();
// //  my_robot.sm_reset_M2();
// //  my_robot.sm_reset_M3();
// //  my_robot.sm_reset_M4();
 
}