// DOJO - SPD 2023 - DIV B - GRUPO H
//- Franco Ferrari 
//- Diego Leonard Gloria Salas
//- Adrian Filippelli
//- Quimey Alejo Fontan

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
    prender(LED_VERDE_UNO,LED_VERDE_DOS,5000);
    apagar(LED_VERDE_UNO,LED_VERDE_DOS,0);

    prender(LED_AMARILLO_UNO,LED_AMARILLO_DOS,3000);
    apagar(LED_AMARILLO_UNO,LED_AMARILLO_DOS,0);

    prender(LED_ROJO_UNO,LED_ROJO_DOS,0);
    apagar(LED_ROJO_UNO,LED_ROJO_DOS,0);

    prender(LED_AMARILLO_UNO,LED_AMARILLO_DOS,3000);
    apagar(LED_AMARILLO_UNO,LED_AMARILLO_DOS,0);
    
}

void prender(int led_prender,int led_prender2,int demora_prender)
{

    if(led_prender == LED_ROJO_UNO && led_prender2 == LED_ROJO_DOS)
    {

        digitalWrite(led_prender, HIGH);
        digitalWrite(led_prender2, HIGH);
        sonar(BUZZER, 500);
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

void apagar(int led_apagar,int led_apagar2,int demora_apagar)
    {
    Serial.println("Apagando leds");
    digitalWrite(led_apagar, LOW);
    digitalWrite(led_apagar2, LOW);
    delay(demora_apagar);
    }

void sonar(int piezo, int demora_sonar)
    { 
    const int NUM_REPETICIONES = 10;
    
    for (int i = 0; i < NUM_REPETICIONES; i++) {
        tone(piezo, 600, 250);
        delay(demora_sonar);
    }
}