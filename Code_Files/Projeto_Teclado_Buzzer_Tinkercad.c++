/*

Fontes:

    Código - Teclado membrana: https://www.tinkercad.com/things/1lHp4mDAEr2

    Ideia do if / else para introdução das músicas: https://www.tinkercad.com/things/jZ12b5C2b4g

    Site das músicas: https://dragaosemchama.com/2019/02/musicas-para-arduino/

*/

/*

Teclado membrana - Pinos:

    Pino 1: referente a primeira linha do teclado.
    Pino 2: referente a segunda linha do teclado.
    Pino 3: referente a terceira linha do teclado.
    Pino 4: referente a quarta linha do teclado.

    Pino 5: referente a primeira coluna do teclado.
    Pino 6: referente a segunda coluna do teclado.
    Pino 7: referente a terceira coluna do teclado.
    Pino 8: referente a quarta coluna do teclado.

    Observação 1: a numeração acima está no sentido esquerda-direita.

    Observação 2: podemos perceber que desses 8 pinos, metade deles tem uma parte, de sua extremidade/ponta,
    preta (Veja no Tinkercad.). Os pinos com essa característica, são usados para as linhas, e os que não possuem, para as colunas.

*/

/*

Músicas disponíveis:

    A -> Pink Panther Theme.

    B -> Keyboard Cat.

Observação: para as outras teclas, é apenas mostrado o seu valor no Monitor Serial.

*/

// Definindo as notas musicais:

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

// Definindo as variáveis públicas:

int lins[4] = { 9, 8, 7, 6 };
int cols[4] = { 5, 4, 3, 2 };

// Porta referente ao Buzzer:

int buzzer = 13;

// Definindo as teclas do teclado:

char mapa[4][4] = {

  {'1', '2', '3', 'A' }, 
  {'4', '5', '6', 'B' },
  {'7', '8', '9', 'C' },
  {'*', '0', '#', 'D' }

};

// Métodos:

char readKey()
{

    for(int l = 0; l < 4; l++)
    {

        digitalWrite(lins[l], LOW);

        for(int c = 0; c < 4; c++)
        {

            if(digitalRead(cols[c]) == LOW)
            {  

                digitalWrite(lins[l], HIGH);

                return mapa[l][c];

            }

        }

        digitalWrite(lins[l], HIGH);

    }

    return 0;

}

void setup()
{

    Serial.begin(57600);

    for(int i = 0; i < 4; i++)
    {

        pinMode(lins[i], OUTPUT);

        pinMode(cols[i], INPUT_PULLUP);

        digitalWrite(lins[i], HIGH);

    }

    pinMode(buzzer, OUTPUT);

}

char last = 0;

void loop()
{
  
    char key = readKey();

    if(key && key != last)
    {

        Serial.print("\n\n");

        // Músicas Temáticas:

        if(key == 'A')
        {

            Serial.print("-> Pink Panther Theme");

            int tempo = 150;

            int melody[] = {

                // Pink Panther theme
                // Score available at https://musescore.com/benedictsong/the-pink-panther
                // Theme by Masato Nakamura, arranged by Teddy Mason

                    REST,2, REST,4, REST,8, NOTE_DS4,8, 
                    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
                    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
                    NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
                    NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4,

                    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
                    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8,
                    NOTE_DS5,1,   
                    NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8, 
                    NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8,
                    NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8,   
                    
                    NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, 
                    NOTE_E4,-4, REST,4,
                    REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8,
                    NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8,   
                    NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2,
            
            };

            int notes = sizeof(melody) / sizeof(melody[0]) / 2;

            int wholenote = (60000 * 4) / tempo;

            int divider = 0, noteDuration = 0;

            for(int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
            {

                divider = melody[thisNote + 1];

                if(divider > 0)
                {

                    noteDuration = (wholenote) / divider;

                }
                
                else if(divider < 0)
                {

                    noteDuration = (wholenote) / abs(divider);
                    noteDuration *= 1.5;

                }

                tone(buzzer, melody[thisNote], noteDuration * 0.9);

                delay(noteDuration);

                noTone(buzzer);

            }

        }

        else if(key == 'B')
        {

            Serial.print("-> Keyboard Cat");

            int tempo = 200;

            int melody[] = {

                // Keyboard cat
                // Score available at https://musescore.com/user/142788/scores/147371

                    REST,1,
                    REST,1,
                    NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
                    NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
                    NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
                    NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
                    NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
                    NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,

                    NOTE_G3,4, NOTE_G3,8, NOTE_G3,-4, NOTE_G3,8, NOTE_G3,4, 
                    NOTE_G3,4, NOTE_G3,4, NOTE_G3,8, NOTE_G3,4,
                    NOTE_C4,4, NOTE_E4,4, NOTE_G4,4, NOTE_E4,4, 
                    NOTE_C4,4, NOTE_E4,8, NOTE_G4,-4, NOTE_E4,4,
                    NOTE_A3,4, NOTE_C4,4, NOTE_E4,4, NOTE_C4,4,
                    NOTE_A3,4, NOTE_C4,8, NOTE_E4,-4, NOTE_C4,4,
                    NOTE_G3,4, NOTE_B3,4, NOTE_D4,4, NOTE_B3,4,
                    NOTE_G3,4, NOTE_B3,8, NOTE_D4,-4, NOTE_B3,4,

                    NOTE_G3,-1, 
            
            };

            int notes = sizeof(melody) / sizeof(melody[0]) / 2;

            int wholenote = (60000 * 4) / tempo;

            int divider = 0, noteDuration = 0;

            for(int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
            {

                divider = melody[thisNote + 1];

                if(divider > 0) 
                {

                    noteDuration = (wholenote) / divider;

                }
                
                else if(divider < 0)
                {

                    noteDuration = (wholenote) / abs(divider);
                    noteDuration *= 1.5;

                }

                tone(buzzer, melody[thisNote], noteDuration * 0.9);

                delay(noteDuration);

                noTone(buzzer);

            }

        }

        else
        {

            Serial.print("Tecla Comum: ");

            Serial.print(key);

        }

    }

    last = key;

}