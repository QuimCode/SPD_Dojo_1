// DOJO - SPD 2023 - DIV B - GRUPO H
//- Franco Ferrari 
//- Diego Leonard Gloria Salas
//- Adrian Filippelli
//- Quimey Alejo Fontan
//
#define LED_ROJO_UNO 13
#define LED_ROJO_DOS 12
#define LED_AMARILLO_UNO 11
#define LED_AMARILLO_DOS 10
#define LED_VERDE_UNO 9
#define LED_VERDE_DOS 8
#define BUZZER 14
#define LED_ROJO_TRES 7
#define LED_ROJO_CUATRO 6
#define LED_AMARILLO_TRES 5
#define LED_AMARILLO_CUATRO 4
#define LED_VERDE_TRES 3
#define LED_VERDE_CUATRO 2
#define BOTON 15
bool extender_tiempo = false;

void setup()
{
  pinMode(LED_ROJO_UNO, OUTPUT);
  pinMode(LED_ROJO_DOS, OUTPUT);
  pinMode(LED_AMARILLO_UNO, OUTPUT);
  pinMode(LED_AMARILLO_DOS, OUTPUT);
  pinMode(LED_VERDE_UNO, OUTPUT);
  pinMode(LED_VERDE_DOS, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_ROJO_TRES, OUTPUT);
  pinMode(LED_ROJO_CUATRO, OUTPUT);
  pinMode(LED_AMARILLO_TRES, OUTPUT);
  pinMode(LED_AMARILLO_CUATRO, OUTPUT);
  pinMode(LED_VERDE_TRES, OUTPUT);
  pinMode(LED_VERDE_CUATRO, OUTPUT);
  pinMode(BOTON, INPUT);
  Serial.begin(9600);
}

void loop()
{
  extender_luz_verde(digitalRead(BOTON));
  iniciar_secuencia(LED_VERDE_UNO,LED_VERDE_DOS,LED_ROJO_TRES,LED_ROJO_CUATRO,2000);//led1,led2,led3,led4,delay  
  extender_luz_verde(digitalRead(BOTON));
  iniciar_secuencia(LED_AMARILLO_UNO,LED_AMARILLO_DOS,LED_AMARILLO_TRES,LED_AMARILLO_CUATRO,0);
  extender_luz_verde(digitalRead(BOTON));
  iniciar_secuencia(LED_ROJO_UNO,LED_ROJO_DOS,LED_VERDE_TRES,LED_VERDE_CUATRO,0);
  extender_luz_verde(digitalRead(BOTON));
  iniciar_secuencia(LED_AMARILLO_UNO,LED_AMARILLO_DOS,LED_AMARILLO_TRES,LED_AMARILLO_CUATRO,0);
}

void iniciar_secuencia(int led_prender,int led_prender2,int led_prender3,int led_prender4,int delay)
{
  if(led_prender == LED_ROJO_UNO && led_prender2 == LED_ROJO_DOS)
  {
    Serial.println("Prendiendo leds");
    prender(led_prender,led_prender2,led_prender3,led_prender4,0);
    sonar(BUZZER, 500, 200, 4, 500);//pieza,frecuencia,tiempo,vueltas,delay
    titilar_y_sonar(led_prender,led_prender2,led_prender3,led_prender4,BUZZER,500,200,3,500);//led1,led2,led3,led4,pieza,frecuencia,tiempo,vueltas,delay  
    apagar(led_prender,led_prender2,led_prender3,led_prender4);
    Serial.println("Apagando leds");
  }
  else
  {
    if(led_prender == LED_AMARILLO_UNO && led_prender2 == LED_AMARILLO_DOS)
    {
      Serial.println("Prendiendo leds");
      titilar_y_sonar(led_prender,led_prender2,led_prender3,led_prender4,BUZZER,300,200,3,500); 
      Serial.println("Apagando leds");
    }
    else
    {
      Serial.println("Prendiendo leds");
      if(extender_tiempo == true)
      {
        delay = 7000; 
        extender_tiempo = false;
      }
      prender(led_prender,led_prender2,led_prender3,led_prender4,delay);
      titilar(led_prender,led_prender2,led_prender3,led_prender4,500);//led1,led2,delay
      apagar(led_prender,led_prender2,led_prender3,led_prender4);
      Serial.println("Apagando leds");
    }
  }
}

void prender(int led_prender,int led_prender2,int led_prender3,int led_prender4,int demora_prender)
{
  digitalWrite(led_prender, HIGH);
  digitalWrite(led_prender2, HIGH);
  digitalWrite(led_prender3, HIGH);
  digitalWrite(led_prender4, HIGH);
  delay(demora_prender);
}

void apagar(int led_apagar,int led_apagar2,int led_apagar3,int led_apagar4)
{
  digitalWrite(led_apagar, LOW);
  digitalWrite(led_apagar2, LOW);
  digitalWrite(led_apagar3, LOW);
  digitalWrite(led_apagar4, LOW);
}

void titilar(int led_titilar,int led_titilar2,int led_titilar3,int led_titilar4,int delay_titilar)
{
  Serial.println("Titilando leds");
  for (int i = 0; i < 3; i++) {        
    apagar(led_titilar,led_titilar2,led_titilar3,led_titilar4);  
    delay(delay_titilar);  
    prender(led_titilar,led_titilar2,led_titilar3,led_titilar4,0);
    delay(delay_titilar);
  }
}

void sonar(int piezo,int frecuencia,int tiempo,int cantidad_vueltas,int delay_sonar )
{  
  Serial.println("Sonando buzzer");
  for (int i = 0; i < cantidad_vueltas; i++) {
    tone(piezo, frecuencia, tiempo);
    delay(delay_sonar);
  }
}

void titilar_y_sonar(int led_titilar,int led_titilar2,int led_titilar3,int led_titilar4,int piezo,int frecuencia,int tiempo,int cantidad_vueltas,int delay_titilar_sonar)
{  
  Serial.println("Titilando leds y sonando buzzer");
  if(led_titilar == 11 && led_titilar2 == 10)
  {
    for (int i = 0; i < cantidad_vueltas; i++) {  
   	 tone(piezo, frecuencia, tiempo);
     prender(led_titilar,led_titilar2,led_titilar3,led_titilar4,0);
     delay(delay_titilar_sonar);
      
     apagar(led_titilar,led_titilar2,led_titilar3,led_titilar4);
     delay(delay_titilar_sonar);
	}
  }  
  else
  {
    if(led_titilar == 13 && led_titilar2 == 12)
    {
      for (int i = 0; i < cantidad_vueltas; i++) {   
       tone(piezo, frecuencia, tiempo);
       apagar(led_titilar,led_titilar2,led_titilar3,led_titilar4);
       delay(delay_titilar_sonar); 
        
       tone(piezo, frecuencia, tiempo);
       prender(led_titilar,led_titilar2,led_titilar3,led_titilar4,0);
       delay(delay_titilar_sonar);
  	  }   
    }
  } 
}

void extender_luz_verde(int boton)
{
  if(boton == 1)
  {
    extender_tiempo = true;
    Serial.println("La proxima luz verde durara el doble");
  }
}