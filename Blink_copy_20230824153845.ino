#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 4                          //D2 pin of nodemcu
#define RELAY_PIN 5                             //D1 pin of nodemcu

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);            // Pass the oneWire reference to Dallas Temperature.
boolean relay = true;
void setup(void)
{
  Serial.begin(9600); 
  sensors.begin();

  pinMode(RELAY_PIN, OUTPUT);                     // Set the relay pin as an output
  digitalWrite(RELAY_PIN, LOW);                  // Ensure the relay is initially off
}

void loop(void)
{ 
  sensors.requestTemperatures();                // Send the command to get temperatures  
  float temperature = sensors.getTempCByIndex(0);

     
  
  if (temperature > 28.0 && relay == true) {
    // Temperature exceeds desired(90*) degrees Celsius, turn off the relay
    Serial.println("Temperature is: ");
    Serial.println(temperature);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Turning off relay.");
    relay = false ;
  } 
  else if (relay == true) {
    // Temperature is below desired(90*)degrees Celsius, turn on the relay
    Serial.println("Temperature is: ");
    Serial.println(temperature);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Relay is on.");
  }
  else{
    Serial.println("relay is off");
    int start = 0;
    Serial.println("Enter 1 to start the relay");
    while (Serial.available() == 0) {
    }
    start = Serial.parseInt();
    if(start == 1){
      relay = true;
      Serial.println("Turning on relay.");

    }

  }

delay(5000);
}
