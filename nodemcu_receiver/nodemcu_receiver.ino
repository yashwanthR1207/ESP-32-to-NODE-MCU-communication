#include <ESP8266WiFi.h>
#include <espnow.h>

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  Serial.print("Bytes received: ");
  Serial.println(len);
  
  // Create a null-terminated string to print
  char message[len + 1];
  memcpy(message, incomingData, len);
  message[len] = '\0';
  
  Serial.print("Message: ");
  Serial.println(message);
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
