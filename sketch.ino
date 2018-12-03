#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h> // use the software uart
#include <NewPing.h>


#ifdef __AVR__
  #include <avr/power.h>
#endif

//DEFINES
#define PIN_NEOPIXEL 10
#define PIN_BLUETOOTH_RX 4
#define PIN_BLUETOOTH_TX 5
#define PIN_SENSOR_MOVIMIENTO 12

#define COUNT_PIXELS 64

#define NEOPIXEL_BRILLO 10

#define CODIGO_RETORNO 124

//#define DELIMITADOR ":"

#define DEBUG

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define DISTANCIA_MAXIMA_PING 10
#define DISTANCIA_MAXIMA_MANO 10
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, DISTANCIA_MAXIMA_PING);

struct Accion {
  unsigned char color_cod;
  unsigned char figura_cod;
  unsigned char sensar;
  unsigned char iteracion;
};


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino PIN_NEOPIXEL number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel matrixled = Adafruit_NeoPixel(COUNT_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

SoftwareSerial bluetooth(PIN_BLUETOOTH_RX, PIN_BLUETOOTH_TX); // RX, TX

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

/*//Indice de led que representaran a los numeros
uint8_t cero[] = {10,11,12,13,17,18,21,22,25,26,29,30,33,34,36,37,38,41,42,43,45,46,49,50,53,54,58,59,60,61};
uint8_t uno[] = {12,19,20,26,27,28,35,36,43,44,51,52,58,59,60,61};
uint8_t dos[] = {10,11,12,13,17,18,21,22,29,30,36,37,43,44,50,51,52,57,58,59,60,61,62};
uint8_t tres[] = {10,11,12,13,17,18,21,22,29,30,36,37,45,46,49,50,53,54,58,59,60,61};
uint8_t cuatro[] = {10,17,18,25,26,28,29,33,34,36,37,41,42,43,44,45,46,52,53,60,61};
uint8_t cinco[] = {9,10,11,12,13,14,17,18,25,26,33,34,35,36,37,45,46,49,50,53,54,58,59,60,61};
uint8_t seis[] = {10,11,12,13,17,18,21,22,25,26,33,34,35,36,37,41,42,45,46,49,50,53,54,58,59,60,61};
uint8_t siete[] = {9,10,11,12,13,14,21,22,29,30,36,37,43,44,51,52,59,60};
uint8_t ocho[] = {10,11,12,13,17,18,21,22,25,26,29,30,34,35,36,37,41,42,45,46,49,50,53,54,58,59,60,61};
uint8_t nueve[] = {10,11,12,13,17,18,21,22,25,26,29,30,34,35,36,37,45,46,49,50,53,54,58,59,60,61};
uint8_t suma[] = {11,12,19,20,25,26,27,28,29,30,33,34,35,36,37,38,43,44,51,52};
uint8_t resta[] = {25,26,27,28,29,30,33,34,35,36,37,38};
uint8_t multiplicacion[] = {9,13,17,18,21,22,27,28,35,36,41,42,45,46,49,54};
uint8_t division[] = {3,4,11,12,25,26,27,28,29,30,33,34,35,36,37,38,51,52,59,60};

//Indice de led que representaran a las letras
uint8_t la[] = {10,11,12,13,17,18,21,22,25,26,29,30,33,34,37,38,41,42,43,44,45,46,49,50,53,54,57,58,61,62};
uint8_t lb[] = {9,10,11,12,13,17,18,21,22,25,26,29,30,33,34,35,36,37,41,42,45,46,49,50,53,54,57,58,59,60,61};
uint8_t lc[] = {10,11,12,13,17,18,21,22,25,26,33,34,41,42,49,50,53,54,58,59,60,61};
uint8_t ld[] = {9,10,11,12,13,17,18,21,22,25,26,29,30,33,34,37,38,41,42,45,46,49,50,53,54,57,58,59,60,61};
uint8_t le[] = {9,10,11,12,13,14,17,18,25,26,33,34,35,36,37,41,42,49,50,57,58,59,60,61,62};
uint8_t lf[] = {9,10,11,12,13,14,17,18,25,26,33,34,35,36,37,41,42,49,50,57,58};
uint8_t lg[] = {10,11,12,13,17,18,21,22,25,26,33,34,41,42,44,45,46,49,50,53,54,58,59,60,61,62};
uint8_t lh[] = {9,10,13,14,17,18,21,22,25,26,29,30,33,34,35,36,37,38,41,42,45,46,49,50,53,54,57,58,61,62};
uint8_t li[] = {10,11,12,13,19,20,27,28,35,36,43,44,51,52,58,59,60,61};
uint8_t lj[] = {13,14,21,22,29,30,37,38,45,46,49,50,53,54,58,59,60,61};
uint8_t lk[] = {9,10,13,14,17,18,20,21,25,26,27,28,33,34,35,41,42,43,44,49,50,52,53,57,58,61,62};
uint8_t ll[] = {9,10,17,18,25,26,33,34,41,42,49,50,57,58,59,60,61,62};
uint8_t lm[] = {8,9,13,14,16,17,18,20,21,22,24,25,26,27,28,29,30,32,33,35,37,38,40,41,45,46,48,49,53,54,56,57,61,62};
uint8_t ln[] = {9,10,13,14,17,18,21,22,25,26,27,29,30,33,34,35,36,37,38,41,42,44,45,46,48,50,53,54,57,58,61,62};
uint8_t lo[] = {10,11,12,13,17,18,21,22,25,26,29,30,33,34,37,38,41,42,45,46,49,50,53,54,58,59,60,61};
uint8_t lp[] = {9,10,11,12,13,17,18,21,22,25,26,29,30,33,34,37,38,41,42,43,44,45,49,50,57,58};
uint8_t lq[] = {10,11,12,13,17,18,21,22,25,26,29,30,33,34,37,38,41,42,45,46,49,50,53,54,58,59,60,61,62,63};
uint8_t lr[] = {9,10,11,12,13,17,18,21,22,25,26,29,30,33,34,35,36,37,41,42,43,44,49,50,52,53,57,58,61,62};
uint8_t ls[] = {10,11,12,13,17,18,21,22,25,26,34,35,36,37,45,46,49,50,53,54,58,59,60,61};
uint8_t lt[] = {9,10,11,12,13,14,19,20,27,28,35,36,43,44,51,52,59,60};
uint8_t lu[] = {9,10,13,14,17,18,21,22,25,26,29,30,33,34,37,38,41,42,45,46,49,50,53,54,58,59,60,61};
uint8_t lv[] = {9,10,13,14,17,18,21,22,25,26,29,30,33,34,37,38,41,42,45,46,50,53,59,60};
uint8_t lw[] = {8,9,13,14,16,17,21,22,24,25,29,30,32,33,37,38,40,41,43,45,46,49,50,51,52,53,58,60};
uint8_t lx[] = {9,10,13,14,17,18,21,22,26,27,28,29,35,36,42,43,44,45,49,50,53,54,57,58,61,62};
uint8_t ly[] = {9,10,13,14,17,18,21,22,25,26,29,30,34,35,36,37,43,44,51,52,59,60};
uint8_t lz[] = {9,10,11,12,13,14,17,18,21,22,28,29,35,36,42,43,49,50,53,54,57,58,59,60,61,62};*/

/*uint64_t figuras[] = {0,  //Reservado
4352287579331509248, // 0
4330237533546352640, // 1
9082661144554257408, // 2
4352271850792172544, // 3
3472414084002350080, // 4
4352271909405490688, // 5
4352278506481531904, // 6
868082126202895872, // 7
4352278499502210048, // 8
4352272177310350336, // 9
543279808512, // -
6782331001509888, // +
7378651114283361792, // *
1736138199631140888, // /

72056494543077120, // =
1736137656351326208, // .
1155177719714285584, // (
1161999348561616912, // )
18446744073709551615, // CUADRADO
18446459269879480448, // TRIANGULO
4359202964317929020, // CIRCULO


// No estan definidas aun las letras minusculas
7378724017762876416, // a
4496393696168001024, // b
4352172712847096832, // c
4496393867966692864, // d
9080952562098011648, // e
434041277546659328, // f
8963981876576795648, // g
7378697732563035648, // h
4330237533479255040, // i
4352272056950218752, // j
7365107287133152768, // k
9080952321579812352, // l
7161677145800401664, // m
14115393920226609091, // n
4352278679890836480, // o
434103023613394432, // p
18187336735173000192, // q
7365107493965807104, // r
4352271900821830656, // s
1736164148113866240, // t
4352278679890847232, // u
1739627946062538240, // v
1458721403928011520, // w
7378651114283361792, // x
1736164304046417408, // y
9107980594434178560, // z

// letras mayusculas
7378724017762876416, // A
4496393696168001024, // B
4352172712847096832, // C
4496393867966692864, // D
9080952562098011648, // E
434041277546659328, // F
8963981876576795648, // G
7378697732563035648, // H
4330237533479255040, // I
4352272056950218752, // J
7365107287133152768, // K
9080952321579812352, // L
7161677145800401664, // M
14115393920226609091, // N
4352278679890836480, // O
434103023613394432, // P
18187336735173000192, // Q
7365107493965807104, // R
4352271900821830656, // S
1736164148113866240, // T
4352278679890847232, // U
1739627946062538240, // V
1458721403928011520, // W
7378651114283361792, // X
1736164304046417408, // Y
9107980594434178560, // Z
};*/


uint64_t figuras[] = {0,  //Reservado
17591470085062144, // 0
1646030553088, // 1
13925646675943680, // 2
15339601348731392, // 3
1160117986540544, // 4
19790424553781760, // 5
10818409671376384, // 6
18138060537937920, // 7
15339601484789248, // 8
17591401298211328, // 9
6781891203569664, // -
6782331001509888, // +
27996985314730752, // *
6782731993749504, // /
7378697629483820646, // =
12935233536, // .
555162009600, // (
16961620420853760, // )
18446744073709551615, // CUADRADO
18410503204342530817, // TRIANGULO
4359202964317896252, // CIRCULO
17872854716464896, // a
15339601484807936, // b
9679281131044352, // c
17591366804537088, // d
18376452600725248, // e
18093873800642304, // f
11091071240977920, // g
35886994521292544, // h
72015851618304, // i
35605489354211840, // j
18422549729738496, // k
282578808438528, // l
35887166583242623, // m
18446478113101643775, // n
17591366804520448, // o
15899231344623360, // p
89930435819159040, // q
13927850079911680, // r
10818409671111168, // s
18085314849423360, // t
35605489362370048, // u
35041439897254912, // v
35041448563015292, // w
27996985314730752, // x
31657203470987264, // y
27992850082259712, // z
17872854716464896, // A
15339601484807936, // B
9679281131044352, // C
17591366804537088, // D
18376452600725248, // E
18093873800642304, // F
11091071240977920, // G
35886994521292544, // H
72015851618304, // I
35605489354211840, // J
18422549729738496, // K
282578808438528, // L
35887166583242623, // M
18446478113101643775, // N
17591366804520448, // O
15899231344623360, // P
89930435819159040, // Q
13927850079911680, // R
10818409671111168, // S
18085314849423360, // T
35605489362370048, // U
35041439897254912, // V
35041448563015292, // W
27996985314730752, // X
31657203470987264, // Y
27992850082259712, // Z
8140533946698758256, //CORAZON 7421932183729477632 (74)
288919782885097988, //CARITA SONRIENTE (75)
305936350877007364 // TOPO (76)
};


int colorRGB[][3] = {
  {0, 0, 0}, //
  {255, 0, 0}, //ROJO
  {0, 255, 0}, //VERDE
  {0, 0, 255}, //AZUL
  {200, 40, 0}, //NARANJA
  {255, 230, 0}, //AMARILLO
  {50, 255, 255}, //CELESTE
  {200, 0, 250}, //FUCSIA
  {255, 255, 255} //BLANCO
};
  



int cantidadFiguras = sizeof(figuras) / sizeof (uint64_t);
                      
char buffer; 

Accion accion;

int hayDatos, hayAccionEjecutando = 0;
int movimientoDetectado = 0;
int huboMovimiento = 0;
int umbral = 500;
unsigned long time;
unsigned long difference;

char aux = 1;



void setup() {

  //Configuracion bluetooth
  bluetooth.begin(9600); // start the bluetooth uart at 9600 which is its default
  
  //Configuracion de las luces (NEOPIXEL)
  matrixled.begin();
  matrixled.setBrightness(NEOPIXEL_BRILLO);
  matrixled.show(); // Initialize all pixels to 'off'
  
  //Configuracion de los sensores
  pinMode(PIN_SENSOR_MOVIMIENTO, INPUT_PULLUP);

  #if defined (DEBUG)
    //Configuracion del puerto serial
    Serial.begin(9600);
  #endif
  
  //delay(200); // wait for voltage stabilize
  //bluetooth.print("esta"); // place your name in here to configure the bluetooth name.
                                       // will require reboot for settings to take affect. 
  //delay(3000); // wait for settings to take affect. 

  accion.figura_cod = 62;
  //accion.figura_cod = 75;
  accion.color_cod = 2;
  representarFigura();
  delay(1000);

  accion.figura_cod = 32;
  //accion.figura_cod = 76;
  accion.color_cod = 2;
  representarFigura();
  delay(1000);

  clearMatrix();

  accion.figura_cod = 0;
  accion.color_cod = 0;
  accion.sensar = 0;
}


void loop() {
  int i;
  int cm;

  hayDatos = esperaAccion();

  //Serial.println(sonar.ping_cm());
  //delay(3000);

  //Si devuelve un codigo 74 es porque quiere apagar la matriz pero que no quede sensando
  /*if (hayDatos == 1) {
    clearMatrix();
    //Inicializamos a 0 por las dudas pero no deberia ser necesario
    hayAccionEjecutando = 0;
    accion.figura_cod = 0;
    accion.color_cod = 0;
  } else */
  
  
  
  if (hayDatos) { // check if anything in UART buffer
    if (accion.sensar == 0) {
      hayAccionEjecutando = 0;
    } else {
      hayAccionEjecutando = 1;
    }
    time = millis();
    representarFigura();
  }

  // Leemos si paso la mano (HIGH: MANO NO DETECTADA, LOW: MANO DETECTADA)
  // __INICIO SENSOR ULTRASONICO__
  cm = sonar.ping_cm();
  #if defined (DEBUG)
     /*Serial.println(cm);
     delay(100);*/
  #endif
  if (cm > 0 && cm < DISTANCIA_MAXIMA_MANO) {
    movimientoDetectado = LOW;
  } else {
    movimientoDetectado = HIGH;
  }
  // __ FIN SENSOR ULTRASONICO __

  // __ INICIO SENSOR INFRARROJO__
  //movimientoDetectado = digitalRead(PIN_SENSOR_MOVIMIENTO);
  // __ FIN SENSOR INFRARROJO__
  
  //if (movimientoDetectado >= umbral && huboMovimiento == 0) {
  if (movimientoDetectado == LOW && huboMovimiento == 0) {
    #if defined (DEBUG)
      //Configuracion del puerto serial
      Serial.println("Movimiento Detectado");
    #endif
    if (hayAccionEjecutando == 1) {
      #if defined (DEBUG)
      //Configuracion del puerto serial
      Serial.println("Envio Movimiento detectado");
      #endif
      //difference = millis() - time;
      clearMatrix();
      //bluetooth.write(difference);
      //Mandamos un codigo unico
      bluetooth.write(accion.iteracion);
      hayAccionEjecutando = 0;
    }
    huboMovimiento = 1;
  }

  //if (movimientoDetectado < umbral && huboMovimiento == 1) {
  if (movimientoDetectado == HIGH && huboMovimiento == 1) {
    #if defined (DEBUG)
      //Configuracion del puerto serial
      Serial.println("Movimiento no detectado");
    #endif
    huboMovimiento = 0;
    
    //bluetooth.write("No detectado");
  }
}


void clearMatrix() {
  uint8_t i;
  
  for(i=0; i<COUNT_PIXELS; i++) {
    matrixled.setPixelColor(i, 0);
  }
  
  matrixled.show();
}


/* int esperaAccion () {
  char datoRecibido[2];

  if (hayAccionEjecutando == 0) {
    datoRecibido[0] = aux++;;
    datoRecibido[1] = 2;
  
      
  
    accion.figura_cod = datoRecibido[0];
    accion.color_cod = datoRecibido[1];

    return 1;
  } else {
    return 0;
  }
}*/


//Completa la estructura accion y devuelve 1 o 0 si se recibio o no una accion

int esperaAccion () {
  char datoRecibido[3];


  if (bluetooth.available()) {
    #ifdef DEBUG
    Serial.println("Entro porque se envio un dato");
    #endif
    bluetooth.readBytes(datoRecibido, 4);

    #ifdef DEBUG
    Serial.println("Primer Byte: ");
      Serial.println(datoRecibido[0]);
      Serial.println("Segundo Byte: ");
      Serial.println(datoRecibido[1]);
      Serial.println("Tercer Byte: ");
      Serial.println(datoRecibido[2]);
      Serial.println("Cuarto Byte: ");
      Serial.println(datoRecibido[3]);
    #endif

    accion.figura_cod = datoRecibido[0];
    accion.color_cod = datoRecibido[1];
    accion.sensar = datoRecibido[2];
    accion.iteracion = datoRecibido[3];
    
    return 1;
  }

  return 0;
}

void initAccion() {
  accion.sensar = accion.color_cod = accion.figura_cod = 0;
}

uint32_t devolverColor(int codigo) {
  return matrixled.Color(colorRGB[codigo][0], colorRGB[codigo][1], colorRGB[codigo][2]);
}

/*void representarColor() {
  int i;
  uint32_t color = devolverColor(accion.color_cod);

  clearMatrix();
  
  for(i=0; i<COUNT_PIXELS; i++) {
    matrixled.setPixelColor(i, color);
  }
  
  matrixled.show();
}*/


/**
 * Representa cualquier figura, sea una letra, un cuadrado, un numero, lo que sea
 */

void representarFigura() {
  uint32_t color = devolverColor(accion.color_cod);
  uint64_t figuraARepresentar = 0;
  uint64_t mascara = 1;
  int i;
  

 #ifdef DEBUG
   Serial.println("Cantidad de figuras: ");
   Serial.println(cantidadFiguras);
   Serial.println("figura_cod: ");
   Serial.println((int)accion.figura_cod);   
 #endif

  //Chequeamos que no nos devuelva un número mayor a la cantidad de figuras que podemos representar
  if (accion.figura_cod <= cantidadFiguras) {
    figuraARepresentar = figuras[accion.figura_cod];
  } else {
    return;
  }


  
  //clearMatrix();

  /* TOPO */
  if (accion.figura_cod == 76) {
      for(i=0; i < 64; i++) {
    
           if (( figuraARepresentar & mascara)) {
       #ifdef DEBUG
         //Serial.print("1 Posicion: ");
         //Serial.println(i);
       #endif
              matrixled.setPixelColor(i, devolverColor(4));
            } else {
              matrixled.setPixelColor(i, 0);
       #ifdef DEBUG
         //Serial.print("0 Posicion: ");
         //Serial.println(i);
       #endif
            }
      
            figuraARepresentar = figuraARepresentar >> 1;      
      }

      matrixled.setPixelColor(25, devolverColor(8));
      matrixled.setPixelColor(33, devolverColor(8));
      /*matrixled.setPixelColor(26, devolverColor(8));
      matrixled.setPixelColor(34, devolverColor(8));*/
  } else {
    //Recorremos cada bit
    for(i=0; i < 64; i++) {
  
       if (( figuraARepresentar & mascara)) {
   #ifdef DEBUG
     //Serial.print("1 Posicion: ");
     //Serial.println(i);
   #endif
          matrixled.setPixelColor(i, color);
        } else {
          matrixled.setPixelColor(i, 0);
   #ifdef DEBUG
     //Serial.print("0 Posicion: ");
     //Serial.println(i);
   #endif
        }
  
        figuraARepresentar = figuraARepresentar >> 1;      
    }

  }

  matrixled.show();
}


/* REPRESENTACION DE NUMERO */

/*void representarNumero() {
  uint32_t color = devolverColor(accion.numero_color);
  uint8_t i, k = 0;
  int number = accion.numero_cod;
  uint8_t *puntero;
  int cantidad;


  //clearMatrix();
  if (number == 1) {
    puntero = uno;
    cantidad = sizeof(uno)/sizeof(uint8_t);
  } else if (number == 2) {
    puntero = dos;
    cantidad = sizeof(dos)/sizeof(uint8_t);
  }
  else if (number == 3) {
    puntero = tres;
    cantidad = sizeof(tres)/sizeof(uint8_t);
  }
  else if (number == 4) {
    puntero = cuatro;
    cantidad = sizeof(cuatro)/sizeof(uint8_t);
  }
  else if (number == 5) {
    puntero = cinco;
    cantidad = sizeof(cinco)/sizeof(uint8_t);
  }
  else if (number == 6) {
    puntero = seis;
    cantidad = sizeof(seis)/sizeof(uint8_t);
  } else if (number == 7) {
    puntero = siete;
    cantidad = sizeof(siete)/sizeof(uint8_t);
  } else if (number == 8) {
    puntero = ocho;
    cantidad = sizeof(ocho)/sizeof(uint8_t);
  } else if (number == 9) {
    puntero = nueve;
    cantidad = sizeof(nueve)/sizeof(uint8_t);
  }

  for(i=0; i<COUNT_PIXELS; i++) {
    if (*puntero == i && k < cantidad) { //Si es uno de los pixel del array de numeros entonces escribimos
      matrixled.setPixelColor(*puntero, color);
      puntero++;
      k++;
    } else { //Sino apagamos
      matrixled.setPixelColor(i, 0);
    }
      matrixled.show();
     
      
      //delay(wait);
    }
}*/







//Completa la estructura accion y devuelve 1 o 0 si se recibio o no una accion
/*int esperaAccion () {

  String partes[6];
  int index = 0;
  int from = 0, to = 0;
  int i = 0;
  int cantCaracteres = 0;
  
  
  String datoRecibido;
  
  if (bluetooth.available()) {
    #if defined (DEBUG)
    Serial.println("Entro porque se envio un dato");
    #endif
    datoRecibido = bluetooth.readStringUntil('&');
    cantCaracteres = datoRecibido.length();

#if defined (DEBUG)
    Serial.println(datoRecibido);
#endif
    
    //Inicializamos la estructura a cero
    initAccion();

    //Obtenemos la primer ubicacion de los ":"
    index = datoRecibido.indexOf(':');

    //Se envio cualquier cosa
    if (index == -1)
      return 0;

#if defined (DEBUG)
    Serial.print("Index:");
    Serial.println(index);
#endif

    while (index > 0) {
      to = index;
      partes[i] = datoRecibido.substring(from, to); //Obtenemos la parte
#if defined (DEBUG)
    Serial.print("Indeparte:");
    Serial.println(partes[i]);
#endif
      from = to + 1;
      
      index = datoRecibido.indexOf(':', from); //Obtenemos hasta donde llega la siguiente parte
      i++;
    }

    if (index < cantCaracteres) {
      partes[i] = datoRecibido.substring(from, cantCaracteres);
    }
#if defined (DEBUG)
  Serial.print("partes[0]:");
    Serial.println(partes[0]);
    Serial.println(partes[0].toInt());

    
#endif

    accion.accion_cod = partes[0].toInt();

    if (accion.accion_cod == 10) { //COD_ACCION:COLOR:TIMEOUT&
      #if defined (DEBUG)
       Serial.println("Entro en 10");
      #endif
      accion.color_cod = partes[1].toInt();
      accion.color_timeout = partes[2].toInt();
    } else if (accion.accion_cod == 20) {
      #if defined (DEBUG)
       Serial.println("Entro en 20");
      #endif
      accion.figura_cod = partes[1].toInt();
      accion.figura_color = partes[2].toInt();
    } else if (accion.accion_cod == 30) {
      #if defined (DEBUG)
       Serial.println("Entro en 30");
      #endif
      accion.letra_cod = partes[1].toInt();
      accion.letra_color = partes[2].toInt();
    } else if (accion.accion_cod == 40) {
      #if defined (DEBUG)
       Serial.println("Entro en Numeros");
      #endif
      accion.numero_cod = partes[1].toInt();
      accion.numero_color = partes[2].toInt();
    }

#if defined (DEBUG)
    Serial.println(partes[0]);
    Serial.println(partes[1]);
    Serial.println(partes[2]);

    Serial.print("Accion cod: ");
    Serial.println(accion.accion_cod);    
    Serial.print("Color cod: ");
    Serial.println(accion.color_cod);
    Serial.print("Timeout: ");
    Serial.println(accion.color_timeout);
    Serial.print("Figura Cod: ");
    Serial.println(accion.figura_cod);
    Serial.print("Figura Color: ");
    Serial.println(accion.figura_color);

    Serial.print("Letra Cod: ");
    Serial.println(accion.letra_cod);
    Serial.print("Letra Color: ");
    Serial.println(accion.letra_color);
    Serial.print("Numero Cod: ");
    Serial.println(accion.numero_cod);
    Serial.print("Numero Color: ");
    Serial.println(accion.numero_color);
#endif

    return 1;
  }

  return 0;
}*/
