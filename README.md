# synaptive-arduino-sketch
Sketch arduino corriendo en dispositivos [Synaptive](https://synaptiverehab.com/).

## Software

Los dispositivos físicos son orquestados por una aplicación móvil desarrollada para dispositivos Android, que envía las órdenes para ejecutar las diferentes rutinas mediante luces, sonidos y sensores.

La aplicación móvil se comunica con los dispositivos físicos utilizando un protocolo Bluetooth RFCOMM (Comunicación por radio frecuencia).

En dichos dispositivos se ejecuta el [sketch arduino](https://github.com/Synaptive-Rehabilitation/synaptive-arduino-sketch/blob/master/sketch.ino) presente en este repositorio.

## Hardware

Los dispositivos de la plataforma están compuestos por los componentes detallados a continuación:

| Descripción                                 | Cantidad | Detalle                                                                                                                                                                                                                          |
|---------------------------------------------|----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Arduino Nano ATMEGA328P V3                  | 1        | Es el cerebro de cada dispositivo físico y se encarga de manejar la lógica de ejecución de ejercicios mediante luces y sensores de movimiento. Recibirá órdenes de la aplicación móvil Android para llevar adelante las rutinas. |
| Modulo Bluetooth Hc05                       | 1        | Permite hacer efectiva la comunicación entre la placa Arduino y la aplicación móvil Android.                                                                                                                                     |
| Sensor Ultrasónico Hc-sr04                  | 1        | Mediante este el paciente podrá interactuar con los dispositivos, pasando su mano por el color, letra, número o forma correspondiente para que la plataforma defina la acción como un acierto por parte del usuario.             |
| Matriz Adafruit NeoPixel CJMCU-8*8          | 1        | A través de esta se representarán los diferentes colores, números, letras o figuras, para cada uno de los ejercicios de rehabilitación.                                                                                          |
| Bateria LIPO de 7,4 volt ACELP1800-2S1P-20C | 1        | Otorga a los dispositivos una autonomía suficiente como para ser utilizados sin conexión a la red eléctrica por hasta 4 horas.                                                                                                   |
| Regulador de Tension L7805CV                | 1        |                                                                                                                                                                                                                                  |
| Interruptor                                 | 1        |                                                                                                                                                                                                                                  |
| Resistencia de 1K                           | 1        |                                                                                                                                                                                                                                  |
| Resistencia de 2K                           | 1        |                                                                                                                                                                                                                                  |
| Capacitor 100 nf                            | 1        |                                                                                                                                                                                                                                  |
| Capacitor 10 uf                             | 1        |                                                                                                                                                                                                                                  |
| Capacitor 100 uf                            | 1        |                                                                                                                                                                                                                                  |


El empaquetado de los dispositivos inalámbricos se realiza diseñando los planos correspondientes e imprimiéndolos en impresoras 3D con material ABS (plástico ecológico, económico y resistente). Para darles una mejor terminación se utiliza pintura “Primer” en aerosol.

Se realiza el diseño de los dispositivos físicos de manera tal que sean escalables, ejecutando las diferentes ejercitaciones que se vayan sumando al set inicial que ofrece la solución. Además, sus componentes podrán ser reemplazados fácilmente por proveedores diferentes a los elegidos en primera instancia, como las matrices led, sensores de proximidad, baterías y módulos bluetooth, entre otros. Inicialmente el sistema permite conectar desde 1 hasta 4 dispositivos de hardware, pero esta cantidad podría ser incrementada sin inconvenientes, por ejemplo debido al diseño de nuevas ejercitaciones que requieran una mayor cantidad de interacciones. 

Se llevó adelante el desarrollo de la lógica de la placa Arduino Nano utilizando el entorno de desarrollo integrado (IDE) [propio de Arduino](https://www.arduino.cc/en/Guide/ArduinoNano).
