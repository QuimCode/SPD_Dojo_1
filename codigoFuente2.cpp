// C++ code
//
#define LED_ROJO1 13
#define LED_ROJO2 12
#define LED_AMARILLO1 11
#define LED_AMARILLO2 10
#define LED_VERDE1 9
#define LED_VERDE2 8
#define BUZZER 3

void setup()
{
  pinMode(LED_ROJO1, OUTPUT);
  pinMode(LED_ROJO2, OUTPUT);
  pinMode(LED_AMARILLO1, OUTPUT);
  pinMode(LED_AMARILLO2, OUTPUT);
  pinMode(LED_VERDE1, OUTPUT);
  pinMode(LED_VERDE2, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
	titilar(LED_ROJO1, LED_ROJO2, 0);
}


void prender(int led_prender,int led_prender2,int demora_prender)
{
  	digitalWrite(led_prender, HIGH);
  	digitalWrite(led_prender2, HIGH);
  
   if(led_prender == LED_ROJO1 && led_prender == LED_ROJO2 && 
      led_prender == LED_AMARILLO1 && led_prender2 == LED_AMARILLO2 && 
      led_prender == LED_VERDE1 && led_prender == LED_VERDE2 )
    {
      digitalWrite(led_prender, HIGH);
      digitalWrite(led_prender2, HIGH);
      delay(demora_prender);
      Serial.println("Encendiendo leds y suena el buzzer");
    }
  
      else
      {
        digitalWrite(led_prender, HIGH);
        digitalWrite(led_prender2, HIGH);
        delay(demora_prender);
        Serial.println("Encendiendo leds");
      }
}


void apagar(int led_apagar, int led_apagar2, int demora_apagar)
{  
  Serial.println("Apagado de Leds");
  digitalWrite(led_apagar, LOW);
  digitalWrite(led_apagar2, LOW);
  delay(demora_apagar);
}


void titilar_rojo(int led_prender1, int led_prender2, int demora_prender) 
{
    int titilar_contador = 3;
    int i;

    for ( i = 0; i < titilar_contador; i++)
    {
        prender(LED_ROJO1, LED_ROJO2, 400);
        apagar(LED_ROJO1, LED_ROJO2, 300);
    }
}

void titilar_amarillo(int led_prender1, int led_prender2, int demora_prender) 
{
    int titilar_contador = 3;
    int i;

    for ( i = 0; i < titilar_contador; i++)
    {
      	tone(BUZZER, 800, 100);
        prender(LED_AMARILLO1, LED_AMARILLO2, 700);
        apagar(LED_AMARILLO1, LED_AMARILLO2, 300);
    }
}

void titilar_verde(int led_prender1, int led_prender2, int demora_prender) 
{
    int titilar_contador = 3;
    int i;

    for ( i = 0; i < titilar_contador; i++)
    {
        prender(LED_VERDE1, LED_VERDE2, 200);
        apagar(LED_VERDE1, LED_VERDE2, 300);
    }
}

void mantener_verde(int led_prender1, int led_prender2, int demora_prender)
{
  prender(LED_VERDE1, LED_VERDE2, 2000);
  apagar(LED_VERDE1, LED_VERDE2, 500); 
}

void mantener_rojo(int led_prender1, int led_prender2, int demora_prender)
{
  tone(BUZZER, 100, 2000);
  prender(LED_ROJO1, LED_ROJO2, 2000);
  apagar(LED_ROJO1, LED_ROJO2, 500); 
}


void titilar(int led_prender1, int led_prender2, int tiempo_demora)
{
  	mantener_verde(LED_VERDE1, LED_VERDE2, 100);
    titilar_verde(LED_VERDE1, LED_VERDE2, 100);
  	titilar_amarillo(LED_AMARILLO1, LED_AMARILLO2, 100);
  	mantener_rojo(LED_ROJO1, LED_ROJO2, 100);
  	titilar_rojo(LED_ROJO1, LED_ROJO2, 100);
  	titilar_amarillo(LED_AMARILLO1, LED_AMARILLO2, 100);
}

























// void titilarBuzzerYLuz() {
//   for (int i = 0; i < 3; i++) {
//     tone(3, 1000);
//     digitalWrite(11, HIGH);
//     digitalWrite(10, HIGH);
//     delay(500);
//     noTone(3); 
//     digitalWrite(11, LOW);
//     digitalWrite(10, LOW);
//     delay(500); 
//   }
//   delay(1700); 
// }

// void titilar(int led_titilar,int led_titilar2)
// {
//   if(led_titilar == LED_ROJO1 && led_titilar2 == LED_ROJO1)
// {
//     sonar(BUZZER, 500, 250, 10, 600); ///rojo
//     prender(led_titilar, led_titilar2, 1500);
//     apagar(led_titilar, led_titilar2, 500);
//     prender(led_titilar, led_titilar2, 300);
//     apagar(led_titilar, led_titilar2, 500);
//     prender(led_titilar, led_titilar2, 300);
//     apagar(led_titilar, led_titilar2, 500);
//     prender(led_titilar, led_titilar2, 300);
//     apagar(led_titilar, led_titilar2, 500);
// } else if(led_titilar == LED_AMARILLO1 && led_titilar2 == LED_AMARILLO2)
//     {
//       sonar(BUZZER, 1000, 250, 3, 200);
//       prender(led_titilar, led_titilar2, 1500);
//       apagar(led_titilar, led_titilar2, 500);
//       prender(led_titilar, led_titilar2, 300);
//       apagar(led_titilar, led_titilar2, 500);
//       prender(led_titilar, led_titilar2, 300);
//       apagar(led_titilar, led_titilar2, 500);
//       prender(led_titilar, led_titilar2, 300);
//       apagar(led_titilar, led_titilar2, 500);
//     } else
//       {
//         prender(led_titilar, led_titilar2, 1500);
//         apagar(led_titilar, led_titilar2, 500);
//         prender(led_titilar, led_titilar2, 300);
//         apagar(led_titilar, led_titilar2, 500);
//         prender(led_titilar, led_titilar2, 300);
//         apagar(led_titilar, led_titilar2, 500); 
//         prender(led_titilar, led_titilar2, 300);
//         apagar(led_titilar, led_titilar2, 500); 
//       }
// }

// void sonar(int piezo, int demora_sonar, int tiempo_sonar, int cantidad_sonar, int frecuencia)
// { 
//   const int NUM_REPETICIONES = cantidad_sonar;
//   unsigned long tiempoActual;
//   unsigned long tiempoInicio = millis();
 
//   for (int i = 0; i < NUM_REPETICIONES; i++) {
//     tone(BUZZER, frecuencia, tiempo_sonar);
//     tiempoActual = millis();
//     while (tiempoActual - tiempoInicio < demora_sonar) {
//       tiempoActual = millis();
//     }
//     tiempoInicio = millis();
//   }