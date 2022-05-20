
#include <Servo.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_MOTOR_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define CHARACTERISTIC_ST_UUID "fea9e75c-d298-11ec-9d64-0242ac120002"

// GPIO pro ovladani svetel
const int frontLightPin = 23;

// GPIO piny pro ovladani motoru
// Levy motor
const int motorLeftFwPin = 26;
const int motorLeftBackPin = 27;

// Provy motor
const int motorRightFwPin = 12;
const int motorRightBackPin = 14;

// Rizeni prednich kol
const int servoPin = 13;

class MotorCallbackHandler: public BLECharacteristicCallbacks {
  
  void onWrite(BLECharacteristic *pCharacteristic) {
      
      std::string value = pCharacteristic->getValue();
    
    if (value.length() > 0) {
      Serial.print("New value: ");
      for (int i = 0; i < value.length(); i++) {
        Serial.print(String(value[i]));
      }
      Serial.println();

      if ( value == "stop"){

        digitalWrite(motorLeftBackPin, LOW);
        digitalWrite(motorLeftFwPin, LOW);
    
        digitalWrite(motorRightBackPin, LOW);
        digitalWrite(motorRightFwPin, LOW);
        
      } else if ( value == "vpred"){
    
        digitalWrite(motorLeftBackPin, LOW);
        digitalWrite(motorLeftFwPin, HIGH);
    
        digitalWrite(motorRightBackPin, LOW);
        digitalWrite(motorRightFwPin, HIGH);
        
      } else if ( value == "vzad"){
    
        digitalWrite(motorLeftFwPin, LOW);
        digitalWrite(motorLeftBackPin, HIGH);
    
        digitalWrite(motorRightFwPin, LOW);
        digitalWrite(motorRightBackPin, HIGH);
      }
    }
  }
};

class VolantCallbackHandler: public BLECharacteristicCallbacks {

  public:
    int pos = 90;

  public:
    
  void onWrite(BLECharacteristic *pCharacteristic) {
      
      std::string value = pCharacteristic->getValue();
    
    if (value.length() > 0) {
      Serial.print("New value: ");
      String stringPos = "";
      for (int i = 0; i < value.length(); i++) {
        stringPos += String(value[i]);
      }

      Serial.println(stringPos);
      
      pos = stringPos.toInt();
      //if ( pos > 0 && pos < 180 ) {
      //  Serial.println("Nastaveni volantu");
      //  servo.write(pos);
      //}
    }
  }
};

Servo servo;
BLECharacteristic *pCharacteristicDrive;
BLECharacteristic *pCharacteristicSt;
VolantCallbackHandler *pVolantCallbackHandler;

// the setup function runs once when you press reset or power the board
void setup() {
  
  Serial.begin(115200);
  
  servo.attach(servoPin);
  
  pinMode(frontLightPin, OUTPUT);
  digitalWrite(frontLightPin, LOW);

  // Initialize the output variables as outputs
  pinMode(motorLeftFwPin, OUTPUT);
  pinMode(motorLeftBackPin, OUTPUT);
  pinMode(motorRightFwPin, OUTPUT);
  pinMode(motorRightBackPin, OUTPUT);
  // Set outputs to LOW
  digitalWrite(motorLeftFwPin, LOW);
  digitalWrite(motorLeftBackPin, LOW);
  digitalWrite(motorRightFwPin, LOW);
  digitalWrite(motorRightBackPin, LOW);

  Serial.println("Starting BLE");

  BLEDevice::init("Auto Poskolak");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  
  pCharacteristicDrive = pService->createCharacteristic(
                                         CHARACTERISTIC_MOTOR_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristicDrive->setValue("stop");
  pCharacteristicDrive->setCallbacks(new MotorCallbackHandler());

 pCharacteristicSt = pService->createCharacteristic(
                                         CHARACTERISTIC_ST_UUID,
                                         BLECharacteristic::PROPERTY_READ |
                                         BLECharacteristic::PROPERTY_WRITE
                                       );

  pCharacteristicSt->setValue("90");
  pVolantCallbackHandler = new VolantCallbackHandler();
  pCharacteristicSt->setCallbacks(pVolantCallbackHandler);
  
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  
  Serial.println("Characteristic defined!");
}

// the loop function runs over and over again forever
void loop() {

  servo.write(pVolantCallbackHandler->pos);
  delay(25);
}
