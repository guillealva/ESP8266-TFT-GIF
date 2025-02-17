# ESP8266 12E + TFT ST7735 - Mostrar GIF Animado

Este proyecto muestra cómo programar un ESP8266 12E con una pantalla TFT ST7735 para mostrar un GIF animado.

## 📷 Ejemplo del Resultado Final

---

## 🛠 Requisitos

### Hardware

- ESP8266 12E (chip directamente, no NodeMCU)
- Pantalla TFT ST7735
- Cables de conexión
- Fuente de alimentación 3.3V (o regulador de voltaje)

### Software

- [Arduino IDE](https://www.arduino.cc/en/software)
- Biblioteca [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI)

---

## 🔌 Conexión (Wiring)

Conectar los pines de la pantalla TFT ST7735 al ESP8266 12E siguiendo esta tabla:

CS  - GPIO0
SDA - GPIO13
CSK - GPIO14
A0  - GPIO2
RST - RESET
VCC - Vin
LED - Vin
GND - GND


📷 **Sugerencia de imagen:** Un diagrama de conexión con el ESP8266 12E y la pantalla TFT.

---

## 🚀 Pasos para Programar el ESP8266

### 1️⃣ Convertir el GIF a Imágenes

1. Accede a [EZGIF](https://ezgif.com/split).
2. Sube el GIF y ajusta el número de frames para optimizar el rendimiento.
3. Divide el GIF en imágenes JPEG y descárgalas.

📷 **Sugerencia de imagen:** Captura de pantalla del proceso en EZGIF.

---

### 2️⃣ Convertir las Imágenes a Código

Cada imagen debe convertirse en un array de colores en formato `uint16_t`. Usa un conversor de imágenes a código como [LCD Image Converter](https://www.riuson.com/lcd-image-converter/).

Formato esperado:

```cpp
int frames = 29;
int animation_width = 67;
int animation_height = 100;
const unsigned short PROGMEM walk[][6700] = {
  {0xFFFF, 0xFFFF, 0xFFFF, ...}, // Frame 1
  {0xFFDF, 0xFFFF, 0xFFFF, ...}, // Frame 2
  // ...
};
```
Guarda el resultado como animation.h.

📷 Sugerencia de imagen: Ejemplo de archivo animation.h generado.

### 3️⃣ Programar el ESP8266

Instala la biblioteca TFT_eSPI desde el Administrador de Bibliotecas de Arduino.

## Configura User_Setup.h de la biblioteca TFT_eSPI:

Define los pines correctos de conexión con #define.

Ajusta la configuración del controlador ST7735.

## Carga el siguiente código en el ESP8266:

```
#include <TFT_eSPI.h>
#include "animation.h"

TFT_eSPI tft = TFT_eSPI();

void setup() {
    tft.init();
    tft.setRotation(1);
}

void loop() {
    for (int i = 0; i < frames; i++) {
        tft.pushImage(0, 0, animation_width, animation_height, walk[i]);
        delay(100);
    }
}
```

📷 Sugerencia de imagen: Captura de pantalla de la configuración en Arduino IDE.

### 4️⃣ Subir y Ejecutar

Conecta el ESP8266 al PC mediante un adaptador USB-Serial (si es necesario).

Selecciona la placa y el puerto en Arduino IDE.

Sube el código al ESP8266.

Una vez completado, la animación debería mostrarse en la pantalla TFT.

📷 Sugerencia de imagen: Foto real del ESP8266 con la pantalla mostrando el GIF.

### 🎯 Notas Finales

Puedes ajustar la velocidad de la animación cambiando delay(100); en el loop().

Asegúrate de definir correctamente los pines en User_Setup.h de la librería TFT_eSPI.

Prueba reducir la cantidad de frames para mejorar el rendimiento.

Revisa que el ESP8266 esté bien alimentado con 3.3V para evitar problemas de estabilidad.

📷 Sugerencia de imagen: Esquema de alimentación del ESP8266 12E.

📜 Licencia

Este proyecto está bajo The Unlicense, lo que significa que es completamente de dominio público. Puedes usar, modificar y distribuir el código sin restricciones. Para más detalles, revisa el archivo LICENSE en el repositorio.

📷 Sugerencia de imagen: Logo de The Unlicense o captura del archivo LICENSE.

¡Disfruta programando tu ESP8266 con una pantalla TFT! 🚀

