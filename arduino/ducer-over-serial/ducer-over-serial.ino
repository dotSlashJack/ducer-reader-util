/**
  * sends data from pressure ducer to device over serial
  * by Jack Hester
**/
void setup() {
  // Start the serial communication with a baud rate of 9600
  Serial.begin(9600);
}

void loop() {
  // Send a packet (a simple string followed by a newline) every second
  Serial.println("Hello, Pi!");
  delay(1000); // wait for a second
}
