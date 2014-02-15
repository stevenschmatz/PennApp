
 //setup up accerleation variables
 int xAcc;
 int yAcc;
 int zAcc;
 
 int zero = 282;//this was the zero point value for my accelerometer, your board may be slightly different.  see the comment below for calculating this with your own board.

void setup(){
  Serial.begin(9600);//set up serial
}

void loop(){
  
  //read values
  xAcc = analogRead(A0);
  yAcc = analogRead(A1);
  zAcc = analogRead(A2);
  
  /**
  if you want to determine the zero point value of your board, 
  comment out the last eight lines of this loop and uncomment the lines below.
  Hold the board parallel to the ground and watch the serial monitor, 
  the xAcc and yAcc values will hover around a common value, 
  this is your "zero" value.  Change the value of the variable "zero" above.
  **/
  //print values
  Serial.print("xAcc ");
  Serial.println(xAcc);
  Serial.print("yAcc ");
  Serial.println(yAcc);
  Serial.print("zAcc ");
  Serial.println(zAcc);
  Serial.println(" ");
  delay(500);//wait

}

