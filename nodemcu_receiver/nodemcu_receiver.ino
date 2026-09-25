#include <ESP8266WiFi.h>
#include <espnow.h>

typedef struct struct_message {
  int id;
  float value;
} struct_message;

struct_message myData;

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  
  Serial.print("Bytes received: ");
  Serial.println(len);
  Serial.print("ID: ");
  Serial.println(myData.id);
  Serial.print("Value: ");
  Serial.println(myData.value);
}

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Set NodeMCU as a receiver (Slave)
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
  
  Serial.println("NodeMCU ESP-NOW Receiver Ready");
}

void loop() {
  // ESP-NOW works on interrupts, no need to poll in loop
}
