#include <PS4Controller.h>
#include <smorphi.h>

String Robo_Name = "SmorphiR3";//Enter Robot Name Here
String Joy_Mac = "1a:2b:3c:99:99:50";//Enter Joystick MAC 

Smorphi my_robot;
int stop;
int still;
int x=50;
int WASD_speed=x;
int Rot_speed=x;
int Dia_speed=x;
int future=0;
int past=0;



void onConnect()
{
  Serial.println("Connected!.");
  showData();
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}
void showData()
{
  Serial.println("Robot:" + Robo_Name);
  Serial.println("MAC:" + Joy_Mac);
  Serial.printf("Battery Level : %d\n", PS4.Battery());

}

void setup() 
{
  Serial.begin(115200);
  my_robot.BeginSmorphi();
  Wire.begin();
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  char code[20];
  Joy_Mac.toCharArray(code,Joy_Mac.length() +1);
  PS4.begin(code);
  Serial.println("Ready.");
}
void analog(){
  int rightX = 0;
  int rightY = 0;
  int leftX = 0;
  int leftY = 0;

  

  rightX = PS4.RStickX();
  rightY = -PS4.RStickY();
  leftX = PS4.LStickX();
  leftY = -PS4.LStickY();
 
 
        if( rightX < -15){
          my_robot.CenterPivotLeft(Rot_speed);
        Serial.println("Left Turn");
        stop=1;
        }
        else if( rightX > 15){
          my_robot.CenterPivotRight(Rot_speed);
        Serial.println("Right Turn");
        stop=1;
        }
        else if(leftY > 15&& leftX <35&& leftX > -35)
        {
            my_robot.MoveBackward(WASD_speed);
            Serial.println("backward");
            stop=1;  
        }
        else if(leftY < -15 && leftX <35 && leftX > -35)
        {
            my_robot.MoveForward(WASD_speed);
            Serial.println("forward");
            stop=1;
            
        }
        else if(leftX > 15&& leftY <15&& leftY > -15)
        {
            my_robot.MoveRight(WASD_speed);
            Serial.println("Right");
            stop=1;
            
        }
         else if(leftX < -15&& leftY <15&& leftY > -15)
        {
            my_robot.MoveLeft(WASD_speed);
            Serial.println("Left");
            stop=1;
            
        }
         else if(leftX < -35&& leftY >35)
        {
            my_robot.MoveDiagDownLeft(Dia_speed);
            Serial.println("DownLeft");
            stop=1;
            
        }
         else if(leftX < -35&& leftY < -35)
        {
            my_robot.MoveDiagUpLeft(Dia_speed);
            Serial.println("UpLeft");
            stop=1;
            
        }
        else if(leftX > 35&& leftY > 35)
        {
            my_robot.MoveDiagDownRight(Dia_speed);
            Serial.println("DownRight");
            stop=1;
            
        }
         else if(leftX > 35&& leftY < -35)
        {
            my_robot.MoveDiagUpRight(Dia_speed);
            Serial.println("UpRight");
            stop=1;
            
        }
  
  else
  { 
      if( -15<leftX<15&& -15<rightX<15 && -15<leftY<15) {
    {
      if(stop==1){
      my_robot.stopSmorphi();
      Serial.println("stop");
      stop=0;
    } 
    }  
  }    
  }
}


void loop() 
{
if (PS4.isConnected()) {
  
  if(still==1){
      my_robot.stopSmorphi();
      Serial.println("still");
      still=0;
      }  
    if (PS4.Right()) {
      future=1;
        if (past!=future){
          my_robot.S();
        Serial.println("Shape S transform");
        past=future;
        }
        }
    if (PS4.Down()) {
      future=2;
        if (past!=future){
          my_robot.T();
        Serial.println("Shape T transform");
       past=future;
        }
        }
   
    if (PS4.Left()){
      future=3;
        if (past!=future){
          my_robot.Z();
        Serial.println("Shape Z transform");
        past=future;
        }
        }

    if (PS4.Square()) {
      future=4;
        if (past!=future){
          my_robot.J();
        Serial.println("Shape J transform");
        past=future;
        }
        }
    if (PS4.Cross()) 
    {   
      future=5;
      if (past!=future){
          my_robot.O();
        Serial.println("Shape O transform");
        past=future;
        }
        }
    if (PS4.Circle()) {
      future=6;
      if (past!=future){
          my_robot.L();
        Serial.println("Shape L transform");
        past=future;
        }
        }
    if (PS4.Triangle()) {
      future=7;
      if (past!=future){
          my_robot.I();
        Serial.println("Shape I transform");
        past=future;
        }
        }
    while(PS4.L1()) {
          my_robot.CenterPivotLeft(x);
        Serial.println("Left Turn");
        still=1;
        }
    while(PS4.R1()){
          my_robot.CenterPivotRight(x);
        Serial.println("Right Turn");
        still=1;
        }
      while(PS4.Up()) {
          my_robot.MoveForward(x);
        Serial.println("forward");
        still=1;
        
        }
      analog(); 
    }
    

    
    /*
    if( PS4.event.button_down.cross){
          my_robot.J();
        Serial.println("Shape J transform");
         
        }
        if( PS4.event.button_down.triangle){
          my_robot.I();
        Serial.println("Shape I transform");
        }
         if( PS4.event.button_down.square){
            my_robot.O();
        Serial.println("Shape O transform");
        }
        if( PS4.event.button_down.circle){
          my_robot.L();
        Serial.println("Shape L transform");
        }
        if( PS4.event.button_down.left){
          my_robot.Z();
        Serial.println("Shape Z transform");
        }
        if( PS4.event.button_down.right){
          my_robot.S();
        Serial.println("Shape S transform");
        }
        if( PS4.event.button_down.down){
          my_robot.T();
        Serial.println("Shape T transform");
        }
        if( PS4.event.button_down.up){
          my_robot.MoveForward(50);
        Serial.println("forward");
        }
        if( PS4.event.button_up.up){
          my_robot.stopSmorphi();
        Serial.println("stop");
        }
        if( PS4.event.button_down.r1){
         my_robot.CenterPivotRight(50);
        Serial.println("Right Turn");
        }
        if( PS4.event.button_up.r1){
          my_robot.stopSmorphi();
        Serial.println("stop");
        }
        if( PS4.event.button_down.l1){
          my_robot.CenterPivotLeft(50);
        Serial.println("Left Turn");
        }
        if( PS4.event.button_up.l1){
          my_robot.stopSmorphi();
        Serial.println("Stop");
        }
    
    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {
      Serial.printf("L2 button at %d\n", PS4.L2Value());
    }
    if (PS4.R2()) {
      Serial.printf("R2 button at %d\n", PS4.R2Value());
    }

    if (PS4.LStickX()) {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    }
    if (PS4.LStickY()) {
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
    }
    if (PS4.RStickX()) {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    }
    if (PS4.RStickY()) {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
    }

    if (PS4.Charging()) Serial.println("The controller is charging");
    if (PS4.Audio()) Serial.println("The controller has headphones attached");
    if (PS4.Mic()) Serial.println("The controller has a mic attached");

    Serial.printf("Battery Level : %d\n", PS4.Battery());

    Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
    delay(500);
     if(stop==1){
      my_robot.stopSmorphi();
      Serial.println("stop");
      stop=0;
      }  
    if (PS4.Right()) {
          my_robot.S();
        Serial.println("Shape S transform");
        stop=1;
        }
    if (PS4.Down()) {
          my_robot.T();
        Serial.println("Shape T transform");
        stop=1;
        }
    if (PS4.Up()) {
          my_robot.MoveForward(50);
        Serial.println("forward");
        stop=1;
        
        }
    if (PS4.Left()){
          my_robot.Z();
        Serial.println("Shape Z transform");
        stop=1;
        }

    if (PS4.Square()) {
          my_robot.J();
        Serial.println("Shape J transform");
        stop=1;
        }
    if (PS4.Cross()) 
    {
          my_robot.O();
        Serial.println("Shape O transform");
        stop=1;
        }
    if (PS4.Circle()) {
          my_robot.L();
        Serial.println("Shape L transform");
        stop=1;
        }
    if (PS4.Triangle()) {
          my_robot.I();
        Serial.println("Shape I transform");
        stop=1;
        }
    if (PS4.L1()) {
          my_robot.CenterPivotLeft(50);
        Serial.println("Left Turn");
        stop=1;
        }
    if (PS4.R1()){
          my_robot.CenterPivotRight(50);
        Serial.println("Right Turn");
        stop=1;
        }*/
  
    my_robot.sm_reset_M1();
    my_robot.sm_reset_M2();
    my_robot.sm_reset_M3();
    my_robot.sm_reset_M4();
}
