// Global Variables 
const bool ccw = 0; 
const bool cw = 1;
const float motorStepAngle = 1.8; // <-- Motor resolution
const int en = 8, dir = 9, pulse = 10;


// StepperTB class definition
class StepperTB{
public:

	// Data members 
	int enPin, dirPin, pulsePin;
	bool direction;
	float motorSpeed;
	float stepAngle;  

	// Constructor  
	StepperTB(int enPin, int dirPin, int pulsePin){
		this->enPin = enPin;
		this->dirPin = dirPin;
		this->pulsePin = pulsePin;
    this->direction = cw;
    this->motorSpeed = 60;
    this->stepAngle = motorStepAngle; 
	}

	// Initialize Arduino Pins
	void initPins(){
		pinMode(pulsePin,OUTPUT); 
  	pinMode(dirPin,OUTPUT);
  	pinMode(enPin,OUTPUT);
	}

  // to set "direction" attribute
	void setDirection(bool direction){
		this->direction = direction;
	}

	// Set "speed" attribute 
	void setSpeed(float rpm){
		this->motorSpeed = rpm; 
	}

	// Calculations 
	float rpm2PulseSpeed(float rpm){
		float pulseSpeed = (6*rpm)/stepAngle;
		return pulseSpeed;
	}

	void step(int numStep){
		
	  	digitalWrite(this->dirPin, this->direction); // set direction attribute
	  	
	  	float pulseSpeed = rpm2PulseSpeed(this->motorSpeed);  // [steps/sec]

	  	float secPerStep = (1/pulseSpeed); 
	  	float msPerStep = secPerStep* 1000; 
	
	  	for (int x = 0; x < numStep; x++)
	  	{
	    	digitalWrite(this->pulsePin,this->direction); 
	    	delay(msPerStep/2); 
	    	digitalWrite(this->pulsePin,!this->direction); 
	    	delay(msPerStep/2);
    	}
	}


  void rotate(int degrees){
    int numStep = degrees/(this->stepAngle);
    this->step(numStep);
  }

};
