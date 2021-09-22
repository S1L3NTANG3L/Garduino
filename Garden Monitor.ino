//Written By Rechard Preston 22/09/2021
#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);
const int soilSensor1 = A0;
const int soilSensor2 = A1;
const int soilSensor3 = A2;
const int solanoid = 7;
int sensorValue1;
int sensorValue2;
int sensorValue3;
double sensorAvg;

void solanoidTrigger()
{
    digitalWrite(solanoid, HIGH);
    delay(300000);//5 minutes
    digitalWrite(solanoid, LOW);
}
void screenClear()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Garden Monitor");
}

void setup()
{
    pinMode(soilSensor1, INPUT);
    pinMode(soilSensor2, INPUT);
    pinMode(soilSensor3, INPUT);
    pinMode(solanoid, OUTPUT);
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop()
{
    sensorValue1 = analogRead(soilSensor1);
    screenClear();
    lcd.setCursor(0, 1);
    lcd.print("Sensor1: ");
    lcd.setCursor(9, 1);
    lcd.print(sensorValue1);
    Serial.println("S1: " + (String)sensorValue1);
    delay(800);
    sensorValue2 = analogRead(soilSensor2);
    screenClear();
    lcd.setCursor(0, 1);
    lcd.print("Sensor2: ");
    lcd.setCursor(9, 1);
    Serial.println("S2: " + (String)sensorValue2);
    lcd.print(sensorValue2);
    delay(800);
    sensorValue3 = analogRead(soilSensor3);
    screenClear();
    lcd.setCursor(0, 1);
    lcd.print("Sensor3: ");
    lcd.setCursor(9, 1);
    lcd.print(sensorValue3);
    Serial.println("S3: " + (String)sensorValue3);
    delay(800);
    sensorAvg = (sensorValue1 + sensorValue2 + sensorValue3) / 3;
    screenClear();
    lcd.setCursor(0, 1);
    lcd.print("Average: ");
    lcd.setCursor(9, 1);
    lcd.print(sensorAvg);
    Serial.println("Average: " + (String)sensorAvg);
    delay(800);
    if(sensorAvg > 1000)
    {
        screenClear();
        lcd.setCursor(0, 1);
        lcd.print("Solanoid Open");
        Serial.println("Solanoid Open");
        solanoidTrigger();
    }
}
