/*

Fontes:

    Configuração - Display LCD: https://www.youtube.com/watch?v=hnpjYx-MJPM

    Configuração - Sensor de temperatura: https://www.tinkercad.com/things/3d3j3aMWl8O-sensor-de-temperatura

*/

/*

Display LCD:

    Solo: referente a energia negativa.
    Potência referente a energia positiva.
    Contraste: refere-se ao nível de intensidade do brilho dos campos do display.
    Led Anódico: referente a energia positiva.
    Led Catódico: referente a energia negativa.

    Os outros pinos referem-se somente a parâmetros de configuração do display.

    Observação: no projeto, foi usado um potenciômetro para definir o nível
    do contraste do display. A diferença é muito mais perceptível em um projeto físico.

*/

/*

LEDs:

    Laranja: acima da temperatura máxima permitida.

    Azul: abaixo da temperatura mínima permitida.

*/

// Variável que será usada no Monitor Serial:

int indice = 0;

// Variáveis para o Sensor de temperatura:

    // As temperaturas encontram-se em graus Celsius:

    const int temperatura_maxima = 35;

    const int temperatura_minima = 15;

const int led_temperatura_maxima = 8;

const int led_temperatura_minima = 7;

/* Variável que será usada pelo pino central do sensor. Ela pode ter somente o número, sem
 * a letra A, pois será usada dentro de um método que só detecta entradas analógicas. */

const int pino_sensor = 0;

// Biblioteca usada para manipular o Display LCD:

# include <LiquidCrystal.h>

/* Variáveis que referenciam as portas necessárias para os pinos do Display LCD. No projeto, no Tinkercad, 
 * essas variáveis referem-se aos jumpers que não sejam verdes, vermelhos ou pretos. Veja abaixo: */

const int RS = 12, E = 11, DB4 = 5, DB5 = 4, DB6 = 3, DB7 = 2;

// Criando o componente do display:

LiquidCrystal display_lcd(RS, E, DB4, DB5, DB6, DB7);

void setup()
{

    // Iniciando o Monitor Serial:

    Serial.begin(57600);

    // Iniciando e configurando o número de caracteres e de linhas, respectivamente, do display:

    display_lcd.begin(16, 2);

    /* Especificando que o display deverá exibir a mensagem no primeiro campo na primeira linha. Nesse
    * caso, é opcional, pois esse já é o valor padrão da propriedade. Veja abaixo: */

    display_lcd.setCursor(0, 0);

    // Exibindo uma mensagem:

    display_lcd.print("Desenvolvimento");

    // Especificando que o display deverá exibir a mensagem no primeiro campo na segunda linha:

    display_lcd.setCursor(0, 1);

    // Exibindo uma mensagem:

    display_lcd.print("de Sistemas!");

    delay(8000);

    // Limpando o conteúdo do display:

    display_lcd.clear();

    // Criando uma estrutura de exibição para as temperaturas:

    display_lcd.setCursor(0, 1);

    display_lcd.print("      C        F");

}

void loop()
{

    Serial.print("\n\n");

    int tensao_sensor = analogRead(pino_sensor);

    float tensao = tensao_sensor * 5;

    tensao /= 1024;

    // Temperatura em graus Celsius:

    float temperatura_C = (tensao - 0.5) * 100;

    // Temperatura em graus Farenheit:

    float temperatura_F = (temperatura_C * 1.8) + 32;

    // Exibindo os dados calculados:

        // Título:

        display_lcd.setCursor(2, 0);

        display_lcd.print("Temperatura:");

        // Celsius:

        display_lcd.setCursor(0, 1);

        display_lcd.print(temperatura_C);

        // Farenheit:

        display_lcd.setCursor(9, 1);

        display_lcd.print(temperatura_F);

    // Mostrando qual a verificação atual:

    indice++;

    Serial.print("Verificando (");
    Serial.print(indice);
    Serial.print("):\n\n");

    // Criando as condições dos LEDs:

    if(temperatura_C >= temperatura_maxima)
    {

        Serial.print("-> Temperatura atual acima do(s) ");
        Serial.print(temperatura_maxima);
        Serial.print(" grau(s) Celsius! Deve-se ligar o ventilador imediatamente.");

        digitalWrite(led_temperatura_maxima, HIGH);
        digitalWrite(led_temperatura_minima, LOW);

    }
    
    else if(temperatura_C <= temperatura_minima)
    {

        Serial.print("-> Temperatura atual abaixo do(s) ");
        Serial.print(temperatura_minima);
        Serial.print(" grau(s) Celsius! Deve-se desligar o ventilador imediatamente.");

        digitalWrite(led_temperatura_maxima, LOW);
        digitalWrite(led_temperatura_minima, HIGH);

    }

    else
    {

        Serial.print("-> Temperatura atual permitida. Nada a se fazer.");

        digitalWrite(led_temperatura_maxima, LOW);
        digitalWrite(led_temperatura_minima, LOW);

    }

    delay(5000);

}