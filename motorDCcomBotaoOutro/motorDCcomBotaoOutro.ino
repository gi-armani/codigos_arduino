int in1pin = 6;
int in2pin = 7; // h bridge pins

int leftButton = 8;
int rightButton = 9; // buttons

void setup() {

  pinMode(in1pin, OUTPUT);
  pinMode(in2pin, OUTPUT); // outputs

  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP); // inputs w internal pullup resistors
  
}

void loop() {

  int leftPinState = digitalRead(leftButton);
  int rightPinState = digitalRead(rightButton); // set value names for read data

  if (leftPinState == LOW) { // if left button is pressed ... 

    digitalWrite(in1pin, HIGH); // make motor go one way
    digitalWrite(in2pin, LOW);
    
  }

  else if (rightPinState == LOW) { // if right button is pressed ...

    digitalWrite(in1pin, LOW);
    digitalWrite(in2pin, HIGH); // make motor go other way

    
  }

  else { // if neither button is pressed ...

    digitalWrite(in1pin, LOW); // nothing happens
    digitalWrite(in2pin, LOW); 
    
  }
  
}
