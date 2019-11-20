#include <SoftwareSerial.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <DHT.h>

// CO2
SoftwareSerial SerialCO2(6, 5); // TX, RX
byte cmd[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
unsigned char response[9];

// TFT
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF
#define BORDO   0x6820 // pievieno savas krāsas

#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8
Adafruit_SSD1331 display = Adafruit_SSD1331(&SPI, cs, dc, rst);

// DHT
DHT dht(2, DHT22);

void setup() {
  SerialCO2.begin (9600);
  Serial.begin (9600);
  display.begin();
  dht.begin();

  Serial.println("init");
  display.fillScreen(BLACK);
  uint16_t time = millis();
  time = millis() - time;
  Serial.println(time, DEC);
  delay(500);
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
  
    display.setCursor(0, 0);
    display.setTextColor(YELLOW, BLACK); 
    display.setTextSize(2);
    display.print(t, 1);
    display.setTextColor(WHITE, BLACK);
    display.setTextSize(1);
    display.print("O"); 
    display.setTextSize(2);
    display.println("C");
    display.setCursor(0, 18);
    display.setTextColor(BLUE, BLACK); 
    display.setTextSize(2);
    display.print(h, 1);
    display.setTextColor(WHITE, BLACK); 
    display.setTextSize(2);
    display.println("%");
    display.setCursor(68, 26);
    display.setTextColor(WHITE);  
    display.setTextSize(2);
    display.print("co");
    display.setCursor(90, 38);
    display.setTextSize(1);
    display.println("2");  
    display.setCursor(76, 55);
    display.setTextColor(WHITE);  
    display.setTextSize(1);
    display.print("ppm");
    
    if (cipars < 1000) {
      display.fillCircle(82, 13, 13, GREEN);
      display.setTextColor(GREEN, BLACK);
      display.fillRect(50, 40, 18, 22, BLACK);
      display.setCursor(55, 45);
      display.setTextSize(1);
      display.print("Labs!");
    } 
    else if (cipars < 1500) {
      display.fillCircle(82, 13, 13, YELLOW);
      display.setTextColor(YELLOW, BLACK);
    }
    else{
      display.fillCircle(82, 13, 13, RED);
      display.setTextColor(RED, BLACK);
    }
    display.setCursor(0, 40);
    display.setTextSize(3);
    display.println(co2ppm);
    
  }
  
  delay(10000);
}
