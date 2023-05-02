// C++ code
//
#define LED_ROJO1 13
#define LED_ROJO2 12
#define LED_ROJO3 7
#define LED_ROJO4 6
#define LED_AMARILLO1 11
#define LED_AMARILLO2 10
#define LED_AMARILLO3 5
#define LED_AMARILLO4 4
#define LED_VERDE1 9
#define LED_VERDE2 8
#define LED_VERDE3 2
#define LED_VERDE4 A0
#define BUZZER 3 

void setup()
{
    pinMode(LED_ROJO1, OUTPUT);
    pinMode(LED_ROJO2, OUTPUT);
    pinMode(LED_ROJO3, OUTPUT);
    pinMode(LED_ROJO4, OUTPUT);
    pinMode(LED_AMARILLO1, OUTPUT);
    pinMode(LED_AMARILLO2, OUTPUT);
    pinMode(LED_AMARILLO3, OUTPUT);
    pinMode(LED_AMARILLO4, OUTPUT);
    pinMode(LED_VERDE1, OUTPUT);
    pinMode(LED_VERDE2, OUTPUT);
    pinMode(LED_VERDE3, OUTPUT);
    pinMode(LED_VERDE4, OUTPUT);
    pinMode(BUZZER, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
	titilar(LED_VERDE1, LED_VERDE2, LED_VERDE3, LED_VERDE4, 0);
}


void prender(int led_prender, int led_prender2, int led_prender3, int led_prender4, int demora_prender)
{
    Serial.println("Prendido de Leds");
    digitalWrite(led_prender, HIGH);
    digitalWrite(led_prender2, HIGH);
    digitalWrite(led_prender3, HIGH);
    digitalWrite(led_prender4, HIGH);
    delay(demora_prender);
}


void apagar(int led_apagar, int led_apagar2, int led_apagar3, int led_apagar4, int demora_apagar)
{  
    Serial.println("Apagado de Leds");
    digitalWrite(led_apagar, LOW);
    digitalWrite(led_apagar2, LOW);
    digitalWrite(led_apagar3, LOW);
    digitalWrite(led_apagar4, LOW);
    delay(demora_apagar);
}


void titilar_rojo(int led_prender1, int led_prender2, int demora_prender) 
{
    int titilar_contador = 3;
    int i;

    for ( i = 0; i < titilar_contador; i++)
    {
        tone(BUZZER, 100, 100);
        prender(LED_ROJO1, LED_ROJO2, LED_VERDE3, LED_VERDE4, 400);
        apagar(LED_ROJO1, LED_ROJO2, LED_VERDE3, LED_VERDE4, 300);
    }
}

void titilar_amarillo(int led_prender1, int led_prender2, int demora_prender) 
{
    int titilar_contador = 3;
    int i;

    for ( i = 0; i < titilar_contador; i++)
    {
        tone(BUZZER, 800, 100);
        prender(LED_AMARILLO1, LED_AMARILLO2, LED_AMARILLO3, LED_AMARILLO4, 700);
        apagar(LED_AMARILLO1, LED_AMARILLO2,  LED_AMARILLO3, LED_AMARILLO4, 300);
    }
}

void titilar_verde(int led_prender1, int led_prender2, int demora_prender) 
{
    int titilar_contador = 3;
    int i;

    for ( i = 0; i < titilar_contador; i++)
    {
        prender(LED_VERDE1, LED_VERDE2, LED_ROJO3, LED_ROJO4, 200);
        apagar(LED_VERDE1, LED_VERDE2,  LED_ROJO3, LED_ROJO4, 300);
    }
}

void mantener_verde(int led_prender1, int led_prender2, int led_prender3, int led_prender4, int demora_prender)
{
    prender(LED_VERDE1, LED_VERDE2, LED_ROJO3, LED_ROJO4, 2000);
    apagar(LED_VERDE1, LED_VERDE2, LED_ROJO3, LED_ROJO4, 500);
}

void mantener_rojo(int led_prender1, int led_prender2, int demora_prender)
{
    tone(BUZZER, 100, 2000);
    prender(LED_ROJO1, LED_ROJO2, LED_VERDE3, LED_VERDE4, 2000);  
    apagar(LED_ROJO1, LED_ROJO2, LED_VERDE3, LED_VERDE4, 500); 
}


void titilar(int led_prender1, int led_prender2, int led_prender3, int led_prender4, int tiempo_demora)
{
    mantener_verde(LED_VERDE1, LED_VERDE2, LED_ROJO3, LED_ROJO4, 100);
    titilar_verde(LED_VERDE1, LED_VERDE2, 100);
    titilar_amarillo(LED_AMARILLO1, LED_AMARILLO2, 100);
    mantener_rojo(LED_ROJO1, LED_ROJO2, 100);
    titilar_rojo(LED_ROJO1, LED_ROJO2, 100);
    titilar_amarillo(LED_AMARILLO1, LED_AMARILLO2, 100);
}

