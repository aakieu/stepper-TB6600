
// create stepper object 
StepperTB myStepper(en, dir, pulse);


// setup function: runs once
// -----------------------------------------------------------------------------
void setup(){
	// initialize pins
	myStepper.initPins();
}


// loop function: repeats indefinitely
// -------------------------------------------------------------------------------
void loop(){
  test_rotate(); 
}


void test_step(){
  
  // Set speed
  myStepper.setSpeed(120);  //rpm
  
  // set direction
  myStepper.setDirection(ccw);

  // 1 full revolution 
  int numStep = 200;

  // step function to spin motor 
  myStepper.step(numStep);
  delay(2000);  // in mS 
}


void test_rotate(){
  // Set speed
  myStepper.setSpeed(120);  //rpm
  
  // set direction
  myStepper.setDirection(ccw);
  
  myStepper.rotate(90);
  delay(1000); 
}
