# esp8266-brake
Conversor de señal para sustituir potenciometro mecánico por sensor de presión en pedal de freno de simulador. El programa está diseñado para el uso del microcontrolador Wemos D1 R2 & Mini. Para detectar la presión del pedal se utiliza un sensor de carga HX711 con una célula de carga de 20 kilos. Para simular la salida analógica se utiliza un digipot AD5231 que nos da una resolución de 1024 bits. Además se ha añadido una pantalla oled SH1106 128x64 para visualizar el sistema de calibración.

Esquema de conexionado:

HX711         Wemos D1<br>
VCC --------- 3.3v<br>
DAT --------- D3<br>
CLK --------- D4<br>
GND --------- GND<br>
<br>
AD5231        Wemos D1<br>
PIN 2  ------ D5<br>
PIN 3  ------ D7<br>
PIN 4  ------ D6<br>
PIN 5  ------ GND<br>
PIN 6  ------ GND<br>
PIN 7  ------ GND<br>
PIN 11 ------ 3.3v<br>
PIN 12 ------ 3.3v<br>
PIN 13 ------ 3.3v<br>
PIN 14 ------ D8<br>
<br>
Salida del AD5231 a resistencia variable del pedal de freno<br>
PIN 8  -----> DigiPot A<br>
PIN 9  -----> Wiper<br>
PIN 10 -----> DigiPot B<br>
<br>
SH1106      Wemos D1<br>
GND  ------ GND<br>
VCC  ------ 3.3v<br>
SCL  ------ D1<br>
SDA  ------ D2<br>
<br>
Uso:
<br>
Paso 1: Pantalla de bienvenida.<br>
Paso 2: Calibración de mínimo. Dejamos el freno sin pulsar hasta que se obtenga la calibración de mínimo.<br>
Paso 3: Calibración de máximo. Pulsamos el freno hasta el fondo y volvemos a dejarlo en reposo.<br>
Paso 4: El programa comenzará a emular la salida analógica en función del valor de presión leído.<br>
<br>
Si el programa en algún momento deja de detectar la señal del sensor de carga entrará en estado de error, dejando la salida analógica en su valor mínimo.
