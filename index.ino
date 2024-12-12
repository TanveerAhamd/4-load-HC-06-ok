

char junk;
String inputString = "";

void setup()                    // run once, when the sketch starts
{
  Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void loop()
{
  if (Serial.available()) {
    while (Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)
    {
      junk = Serial.read() ;  // clear the serial buffer
    }
    if (inputString == "a") {       //in case of 'a' turn the LED on
      digitalWrite(10, HIGH);

    } else if (inputString == "A") { //incase of 'A' turn the LED off
      digitalWrite(10, LOW);
    }
    else if (inputString == "b") {       //in case of 'b' turn the LED on
      digitalWrite(11, HIGH);
    }
    else if (inputString == "B") {       //in case of 'B' turn the LED on
      digitalWrite (11, LOW);
    }
    else if (inputString == "c") {       //in case of 'c' turn the LED on
      digitalWrite(12, HIGH);
    }
    else if (inputString == "C") {       //in case of 'C' turn the LED on
      digitalWrite (12, LOW);
    }
    else if (inputString == "d") {       //in case of 'd' turn the LED on
      digitalWrite(13, HIGH);
    }
    else if (inputString == "D") {       //in case of 'D' turn the LED on
      digitalWrite (13, LOW);
    }
    inputString = "";
  }
}
