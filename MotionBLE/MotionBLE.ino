#include <ArduinoBLE.h>
#include <Arduino_LSM6DSOX.h>

// Services and characteristics
BLEService ledService("cd48409a-f3cc-11ed-a05b-0242ac120003"); // Custom LED service
BLEByteCharacteristic ledStatusCharacteristic("cd48409b-f3cc-11ed-a05b-0242ac120003", BLEWrite);

BLEService accelerometerService("12345678-1234-5678-1234-56789abcdef0"); // Custom accelerometer service
BLECharacteristic accelerometerCharacteristic(
  "12345678-1234-5678-1234-56789abcdef1", 
  BLERead | BLENotify, 
  12 // 4 bytes por float * 3 eixos
);

void setup() {
  Serial.begin(9600);

  // LED pin initialization
  pinMode(LED_BUILTIN, OUTPUT);

  // while (!Serial);

  // Inicializa o acelerômetro
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  // Inicializa o módulo BLE
  if (!BLE.begin()) {
    Serial.println("Failed to initialize BLE module!");
    while (1);
  }

  // Configurações BLE
  BLE.setLocalName("AccelerometerLED_BLE");
  BLE.setAdvertisedService(ledService);

  // Adiciona características aos serviços
  ledService.addCharacteristic(ledStatusCharacteristic);
  accelerometerService.addCharacteristic(accelerometerCharacteristic);

  // Adiciona serviços à pilha BLE
  BLE.addService(ledService);
  BLE.addService(accelerometerService);

  // Inicia a publicidade BLE
  BLE.advertise();

  Serial.println("BLE device is now advertising...");

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}

void loop() {
  // Verifica se há conexão com um dispositivo central
  BLEDevice central = BLE.central();

  if (central) {
    Serial.print("Connected to central: ");
    Serial.println(central.address());

    while (central.connected()) {
      // Controle do LED via BLE
      if (ledStatusCharacteristic.written()) {
        if (ledStatusCharacteristic.value()) {
          digitalWrite(LED_BUILTIN, HIGH);
          Serial.println("LED is ON");
        } else {
          digitalWrite(LED_BUILTIN, LOW);
          Serial.println("LED is OFF");
        }
      }

      // Leitura do acelerômetro
      if (IMU.accelerationAvailable()) {
        float x, y, z;
        IMU.readAcceleration(x, y, z);

        // Serial output
        Serial.print("X: ");
        Serial.print(x);
        Serial.print(" g, Y: ");
        Serial.print(y);
        Serial.print(" g, Z: ");
        Serial.println(z);

        // Prepara os dados do acelerômetro para envio
        float accelData[3] = {x, y, z};
        accelerometerCharacteristic.writeValue((byte *)accelData, sizeof(accelData));

        delay(100); // Envia dados a cada 100ms (ajustável)
      }
    }

    Serial.println("Disconnected from central.");
  }
}


