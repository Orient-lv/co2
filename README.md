Projektā izmantots CO2 NDIR (nondispersive infrared) tehnoloģijas sensors MH-Z14A.
Sensora specifikācijā uzrādītā precizitāte mērījumiem 0 ~ 5000ppm ±(50ppm +3% reading value).

Āra gaisā CO2 koncentrācija ir ap 400ppm. Labs gaiss iekštelpās ir līdz CO2 koncentrācijai 1000ppm,
virs tā iespējama ietekme uz veselību un pašsajūtu, bet pie lielām koncentrācijām galvassāpes un darba spēju zudums).

DETAĻU SARAKSTS:

1) MH-Z14A NDIR CO2 Sensor
2) Ekrāns 1.44″ SPI TFT 128×128
3) NANO 3.0
4) Mini USB kabelis
5) Savienošanas vadi 10cm – MM, MF
6) Temperatūras un mitruma sensors DHT22 (vai DHT11)

SLĒGUMS

MH-Z14A

19 TX – 6
18 RX – 5
17 – 5V
16 – GND

EKRĀNS 1.44″ SPI TFT 128×128

LED ->3.3V
SCK (SCK) -> D13
SDA (MOSI) -> D11
A0 (DC) – D9
RESET (RST) -> D8
CS -> D10
GND -> Ground
VCC -> 5V

DHT22 (skatoties no restotās priekšas)

VCC – 5V
Data – Pin2
NC – tukšs
Ground – GND

BIBLIOTĒKAS

Arduino IDE programmā jāielādē bibliotēkas:

TFT_ILI9163C.h (SPI.h ir jau programmā)
Labojumi bibliotēkā un piemēros:
TFT_ILI9163C bibliotēkas failā _settings/TFT_ILI9163C_settings.h teksta redaktorā jālabo OFFSET no 32 uz 0.
Piemēros jāieraksta Reset pins rindā “TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);” , to papildinot ar “8,”, jāizskatās šādi: .. (__CS, 8,__DC);
DHT.h

SoftwareSerial.h un SPI.h jau ir Arduino IDE programmā

KALIBRĒŠANA

Svaigā gaisā CO2 sensora kontakts Nr.8 (3. otrajā rindā no otra gala) ir jāsavieno uz 7 sekundēm ar Ground.
Jāatstāj svaigā gaisā uz 5-6 minūtēm. Sensors ir nokalibrēts.
Vienmēr var pārbaudīt kalibrāciju, iznesot sensoru svaigā gaisā. Tam ir jārāda 390 – 410ppm.

Specifikācijā norādīts uzsilšanas laiks 3 min., tātad korekti rādījumi būs līdz 3 minūtēm pēc ieslēgšanas.
