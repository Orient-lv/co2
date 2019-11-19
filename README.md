Projektā izmantots CO2 NDIR (nondispersive infrared) tehnoloģijas sensors MH-Z14A.
Sensora specifikācijā uzrādītā precizitāte mērījumiem 0 ~ 5000ppm ±(50ppm +3% reading value).

Āra gaisā CO2 koncentrācija ir ap 400ppm. Labs gaiss iekštelpās ir līdz CO2 koncentrācijai 1000ppm,
virs tā iespējama ietekme uz veselību un pašsajūtu, bet pie lielām koncentrācijām galvassāpes un darba spēju zudums).

• DETAĻU SARAKSTS:

1) MH-Z14A NDIR CO2 Sensor
2) Ekrāns 1.44″ SPI TFT 128×128
3) NANO 3.0
4) Mini USB kabelis
5) Savienošanas vadi female-female
6) Temperatūras un mitruma sensors DHT22 (vai DHT11)

![Foto un shēma](https://www.orient.lv/wp-content/uploads/2019/11/co2_mhz14_dht22_tft128x128_nano.jpg)

• SLĒGUMS ar NANO 3.0

1) CO2 sensors MH-Z14A:
19 TX – 6 | 18 RX – 5 | 17 – 5V | 16 – GND
2) EKRĀNS 1.44″ SPI TFT 128×128:
LED ->3.3V | SCK (SCK) -> D13 | SDA (MOSI) -> D11 | A0 (DC) – D8 | RESET (RST) -> D9 | CS -> D10 | GND -> Ground | VCC -> 5V
3) DHT22 (skatoties no restotās priekšas):
VCC – 5V | Data – Pin2 | NC – tukšs | Ground – GND

• BIBLIOTĒKAS

Arduino IDE programmā jāielādē bibliotēkas:
1) DHT.h - pielikt Arduino IDE programmā (Rīki - Pārvaldīt bibliotēkas - Meklēt dht - DHT sensor library by Adafruit - Instalēt)
2) TFT_ILI9163C.h - github.com/sumotoy/TFT_ILI9163C - Lejuplādēt un ielikt mapi Arduino/Libraries mapē.
! Labojums bibliotēkā:
TFT_ILI9163C bibliotēkas failā _settings/TFT_ILI9163C_settings.h teksta redaktorā jālabo OFFSET no 32 uz 0. Pārstartēt programmu.
3) Bibiliotēkas SoftwareSerial.h un SPI.h jau ir Arduino IDE programmā.

• KALIBRĒŠANA

Svaigā gaisā CO2 sensora kontakts Nr.8 (3. otrajā rindā no otra gala) ir jāsavieno uz 7 sekundēm ar Ground.
Jāatstāj svaigā gaisā uz 5-6 minūtēm. Sensors ir nokalibrēts.
Vienmēr var pārbaudīt kalibrāciju, iznesot sensoru svaigā gaisā. Tam ir jārāda 390 – 410ppm.

Specifikācijā norādīts uzsilšanas laiks 3 min., tātad korekti rādījumi būs līdz 3 minūtēm pēc ieslēgšanas.
