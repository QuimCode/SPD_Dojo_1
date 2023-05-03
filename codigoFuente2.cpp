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
#define BUZZER 3

void setup()
{
  pinMode(LED_ROJO_UNO, OUTPUT);
  pinMode(LED_ROJO_DOS, OUTPUT);
  pinMode(LED_AMARILLO_UNO, OUTPUT);
  pinMode(LED_AMARILLO_DOS, OUTPUT);
  pinMode(LED_VERDE_UNO, OUTPUT);
  pinMode(LED_VERDE_DOS, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  iniciar_secuencia(LED_VERDE_UNO,LED_VERDE_DOS,2000);//led1,led2,delay  
  iniciar_secuencia(LED_AMARILLO_UNO,LED_AMARILLO_DOS,0);
  iniciar_secuencia(LED_ROJO_UNO,LED_ROJO_DOS,0);
  iniciar_secuencia(LED_AMARILLO_UNO,LED_AMARILLO_DOS,0);
}

void iniciar_secuencia(int led_prender,int led_prender2,int demora_prender)
{
  if(led_prender == LED_ROJO_UNO && led_prender2 == LED_ROJO_DOS)
  {
    Serial.println("Prendiendo leds");
    prender(led_prender,led_prender2,0);
    sonar(BUZZER, 500, 200, 4, 500);//pieza,frecuencia,tiempo,vueltas,delay
    titilar_y_sonar(led_prender,led_prender2,BUZZER,500,200,3,500);//led1,led2,pieza,frecuencia,tiempo,vueltas,delay  
    apagar(led_prender,led_prender2);
    Serial.println("Apagando leds");
  }
  else
  {
    if(led_prender == LED_AMARILLO_UNO && led_prender2 == LED_AMARILLO_DOS)
    {
      Serial.println("Prendiendo leds");
      titilar_y_sonar(led_prender,led_prender2,BUZZER,300,200,3,500); 
      Serial.println("Apagando leds");
    }
    else
    {
      Serial.println("Prendiendo leds");
      prender(led_prender,led_prender2,demora_prender);
      titilar(led_prender,led_prender2,500);//led1,led2,delay
      apagar(led_prender,led_prender2);
      Serial.println("Apagando leds");
    }
  }
}

void prender(int led_prender,int led_prender2,int demora_prender)
{
  digitalWrite(led_prender, HIGH);
  digitalWrite(led_prender2, HIGH);
  delay(demora_prender);
}

void apagar(int led_apagar,int led_apagar2)
{
  digitalWrite(led_apagar, LOW);
  digitalWrite(led_apagar2, LOW);
}

void titilar(int led_titilar,int led_titilar2,int delay_titilar)
{
  Serial.println("Titilando leds");
  for (int i = 0; i < 3; i++) {        
   apagar(led_titilar,led_titilar2);  
   delay(delay_titilar);  
   prender(led_titilar,led_titilar2,0);
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

void titilar_y_sonar(int led_titilar,int led_titilar2,int piezo,int frecuencia,int tiempo,int cantidad_vueltas,int delay_titilar_sonar)
{  
  Serial.println("Titilando leds y sonando buzzer");
  if(led_titilar == 11 && led_titilar2 == 10)
  {
    for (int i = 0; i < cantidad_vueltas; i++) {  
   	 tone(piezo, frecuencia, tiempo);
     prender(led_titilar,led_titilar2,0);
     delay(delay_titilar_sonar);
      
     apagar(led_titilar,led_titilar2);
     delay(delay_titilar_sonar);
	}
  }  
  else
  {
    if(led_titilar == 13 && led_titilar2 == 12)
    {
      for (int i = 0; i < cantidad_vueltas; i++) {   
       tone(piezo, frecuencia, tiempo);
       apagar(led_titilar,led_titilar2); 
       delay(delay_titilar_sonar); 
        
       tone(piezo, frecuencia, tiempo);
       prender(led_titilar,led_titilar2,0);
       delay(delay_titilar_sonar);
	  }   
    }
  } 
}