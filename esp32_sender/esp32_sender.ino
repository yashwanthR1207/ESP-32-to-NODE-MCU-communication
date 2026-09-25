#include <WiFi.h>
#include <esp_now.h>

uint8_t receiverMAC[] = {0x2C, 0xF4, 0x32, 0x30, 0xCD, 0xD2};

void setup()
{
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK)
  {
    Serial.println("ESP-NOW INIT FAILED");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK)
  {
    Serial.println("FAILED TO ADD ESP8266");
    return;
  }

  Serial.println("ESP32 ESP-NOW READY");
}

void loop()
{
  const char message[] = "HELLO FROM ESP32";

  esp_err_t result = esp_now_send(
    receiverMAC,
    (uint8_t *)message,
    sizeof(message)
  );

  if (result == ESP_OK)
  {
    Serial.println("MESSAGE SENT");
  }
  else
  {
    Serial.println("SEND FAILED");
  }

  delay(2000);
}
