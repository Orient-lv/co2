#include <SoftwareSerial.h>
#include <SPI.h>
#include <TFT_ILI9163C.h>
#include <DHT.h>

// CO2
SoftwareSerial SerialCO2(6, 5); // TX, RX
byte cmd[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
unsigned char response[9];

// TFT
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0  
#define WHITE   0xFFFF
#define BORDO   0x6820 // pievieno savas krāsas
#define __CS 10
#define __RS 9
#define __DC 8
TFT_ILI9163C tft = TFT_ILI9163C(__CS,__DC,__RS);

// DHT
DHT dht(2, DHT22);

void setup() {
  SerialCO2.begin (9600);
  Serial.begin (9600);
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(BLACK);
  dht.begin();
}

void loop() 
{
  SerialCO2.write(cmd, 9); // nosūta komandu sensoram
  memset(response, 0, 9);
  SerialCO2.readBytes(response, 9); // saņem atbildi
  
  uint8_t crc = 0;
  for (int i = 1; i < 8; i++) crc+=response[i]; // nolasa kontrolsummu
  crc = ~crc;
  crc++;

  if ( !(response[0] == 0xFF && response[1] == 0x86 && response[8] == crc) ) // salīdzina atbildi ar kontrolsummu
  {
    Serial.println("CRC error: " + String(crc) + " / "+ String(response[8])); // izvada kļūdu
  } 
  else 
  {
    uint8_t responseHigh = (uint8_t) response[2];
    uint8_t responseLow = (uint8_t) response[3];
    String(co2ppm) = (String((256*responseHigh) + responseLow));
    int cipars = co2ppm.toInt();
    
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    Serial.print("CO2 ");
    Serial.print(cipars);
    Serial.print(" Temp. ");
    Serial.print(t, 1);
    Serial.print(" Mitr. ");
    Serial.println(h, 1);
  
    tft.setCursor(32, 10);
    tft.setTextColor(YELLOW, BLACK); 
    tft.setTextSize(2);
    tft.print(t, 1);
    tft.setTextColor(WHITE, BLACK);
    tft.setTextSize(1);
    tft.print(" o"); 
    tft.setTextSize(2);
    tft.println("C");
    tft.setCursor(35, 30);
    tft.setTextColor(GREEN, BLACK); 
    tft.setTextSize(2);
    tft.print(h, 1);
    tft.setTextColor(WHITE, BLACK);
    tft.setTextSize(1);
    tft.print(" "); 
    tft.setTextSize(2);
    tft.println("%");
    tft.setCursor(22, 62);
    tft.setTextColor(WHITE);  
    tft.setTextSize(2);
    tft.print("CO");
    tft.setCursor(46, 70);
    tft.setTextSize(1);
    tft.println("2");  
    tft.setCursor(90, 115);
    tft.setTextColor(WHITE);  
    tft.setTextSize(1);
    tft.print("ppm");
    tft.setCursor(17, 83);
    
    tft.setTextSize(4);
    if (cipars < 1000) {
      tft.fillCircle(70, 65, 13, GREEN);
      tft.setTextColor(GREEN, BLACK);
      tft.fillRect(89, 81, 25, 32, BLACK);
    } 
    else if (cipars < 1500) {
      tft.fillCircle(70, 65, 13, YELLOW);
      tft.setTextColor(YELLOW, BLACK);
    }
    else{
      tft.fillCircle(70, 65, 13, RED);
      tft.setTextColor(RED, BLACK);
    }
    tft.println(co2ppm);
    
  }
  
  delay(10000);
}
