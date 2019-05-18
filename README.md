# esp8266-brake
Conversor de señal para sustituir potenciometro mecánico por sensor de presión en pedal de freno de simulador. El programa está diseñado para el uso del microcontrolador Wemos D1 R2 & Mini. Para detectar la presión del pedal se utiliza un sensor de carga HX711 con una célula de carga de 20 kilos. Para simular la salida analógica se utiliza un digipot AD5231 que nos da una resolución de 1024 bits. Además se ha añadido una pantalla oled 128x64 para visualizar el sistema de calibración.

Esquema de conexionado:

HX711         Wemos D1
VCC           3.3v
DAT           D3
CLK           D4
GND           GND

AD5231        Wemos D1
PIN 2  ------ D5
PIN 3  ------ D7
PIN 4  ------ D6
PIN 5  ------ GND
PIN 6  ------ GND
PIN 7  ------ GND

PIN 8  -----> DigiPot A
Pin 9  -----> Wiper
Pin 10 -----> DigiPot B

PIN 11 ------ 3.3v
PIN 12 ------ 3.3v
PIN 13 ------ 3.3v
PIN 14 ------ D8

SH1106      Wemos D1
GND  ------ GND
VCC  ------ 3.3v
SCL  ------ D1
SDA  ------ D2

Uso:

Paso 1: Pantalla de bienvenida.
Paso 2: Calibración de mínimo. Dejamos el freno sin pulsar hasta que se obtenga la calibración de mínimo.
Paso 3: Calibración de máximo. Pulsamos el freno hasta el fondo y volvemos a dejarlo en reposo.
Paso 4: El programa comenzará a emular la salida analógica en función del valor de presión leído.

Si el programa en algún momento deja de detectar la señal del sensor de carga entrará en estado de error, dejando la salida analógica en su valor mínimo.
