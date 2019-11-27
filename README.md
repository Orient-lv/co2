Āra gaisā CO2 koncentrācija ir ap 400ppm. Labs gaiss iekštelpās ir līdz CO2 koncentrācijai 1000ppm,
virs tā iespējama ietekme uz veselību un pašsajūtu, bet pie lielām koncentrācijām galvassāpes un darba spēju zudums).
Tāpat svarīgs arī relatīvais gaisa mitrums, kam jābūt 30-70% robežās, bet vislabāk 50-60%.

Projektā izmantots CO2 NDIR (nondispersive infrared) tehnoloģijas sensors MH-Z14A, MH-Z19B vai Senseair S8.

• DETAĻU SARAKSTS:

1) CO2 NDIR sensors MH-Z14A / MH-Z19B / SenseAir S8
2) Ekrāns a - "1.44″ TFT 128×128 SPI" vai b - "0.95″ OLED SSD1331 96×64 SPI"
3) NANO 3.0 vai UNO R3 + atbilstošs USB kabelis
4) Savienošanas vadi 
5) Temperatūras un mitruma sensors DHT22 (vai DHT11)

![Foto un shēma](https://www.orient.lv/wp-content/uploads/2019/11/co2-mhz14-dht22-tft128x128-nano.jpg)


• SLĒGUMS ar NANO/UNO

1) CO2 sensors MH-Z14A / MH-Z19B / Senseair S8: 
TX - 6, RX - 5, Vin - 5V (3.6V-5.5V), GND - Ground. 
2) a - EKRĀNS 1.44″ TFT 128×128 SPI - https://www.orient.lv/veikals/displays/spi-tft-144-st7735/
LED ->3.3V | SCK (SCK) -> 13 | SDA (MOSI) -> 11 | A0 (DC) – 8 | RESET (RST) -> 9 | CS -> 10 | GND -> Ground | VCC -> 5V. 
*** b - EKRĀNS 0.95″ OLED SSD1331 96×64 SPI - https://www.orient.lv/veikals/displays/oled-ssd1331/
GND  - Ground | VCC – 5V | SCL (Clock Line) – 13 | SDA (Mosi) – 11 | RES (Reset) – 9 | DC (Data/Demand) – 8 | CS (Chip Select) – 10. 
3) DHT22 (skatoties no restotās priekšas, kājām uz leju):
VCC – 5V | Data – 2 | NC – tukšs | Ground – GND. 


![CO2 sensor pinout](https://www.orient.lv/wp-content/uploads/2019/11/co2_ndir_pinout.jpg)

• BIBLIOTĒKAS

Arduino IDE programmā jāielādē bibliotēkas:
1) DHT.h - pielikt Arduino IDE programmā (Rīki - Pārvaldīt bibliotēkas - Meklēt dht - DHT sensor library by Adafruit - Instalēt)
2) Bibiliotēkas SoftwareSerial.h un SPI.h jau ir Arduino IDE programmā.
3) a - TFT_ILI9163C.h - https://github.com/sumotoy/TFT_ILI9163C - Lejuplādēt, atzipot un ielikt mapi Arduino/Libraries mapē.
! Labojums bibliotēkā:
Bibliotēkas TFT_ILI9163C failā _settings/TFT_ILI9163C_settings.h teksta redaktorā jālabo cipari: 
TFTWIDTH 131, GRAMWIDTH 131, OFFSET 1. Pārstartēt programmu. 
b - Adafruit_SSD1331.h un Adafruit_GFX.h - lejuplādējamas Arduino IDE programmā (Rīki – Pārvaldīt bibliotēkas – Meklēt – Instalēt).


• KALIBRĒŠANA

Automātiskā kalibrēšana darbojas visiem 3 sensoru modeļiem - ABC funkcija reizi 24 stundās kalibrē zemāko vērtību, kāda bijusi pēdējās dienās, uz 400ppm, tuvojoties tai par 30-50ppm vienā reizē. Lai tas notiktu precīzi, sensoram ir nedēļas laikā uz 1 stundu jāatrodas svaigā gaisā.

Manuālā kalibrēšana - Svaigā gaisā sensora Pin8 (MH-Z14A) vai HD (MH-Z19B) ir jāsavieno ar Ground uz vairāk kā 7 sekundēm un jāatstāj lā svaigā gaisā vairāk kā uz 20 minūtēm - tad sensors ir nokalibrēts.
Vienmēr var pārbaudīt kalibrāciju, iznesot sensoru svaigā gaisā. Tam ir jārāda 395 – 410ppm.

Specifikācijā norādīts uzsilšanas laiks 3 min., tātad korekti rādījumi būs līdz 3 minūtēm pēc ieslēgšanas.
