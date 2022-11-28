/*

Fontes:

    Esboço de montagem da placa: https://www.tinkercad.com/things/2JPULtfHQeZ-ponte-h-controle-de-velocidade-

    Montagem final da placa e conceito por trás do código de programação: https://www.youtube.com/watch?v=cXwK8PW5_AM

*/

/*

Botões:

    Botão da esquerda: os motores giram no sentido anti-horário.

    Botão da direita: os motores giram no sentido horário.

*/

void setup()
{

    // Pinos usados nos botões:
  
    pinMode(13, INPUT_PULLUP);
    pinMode(12, INPUT_PULLUP);

    // Pinos usados no primeiro motor (O de baixo.):
    
    pinMode(5, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);

    // Pinos usados no segundo motor (O de cima.):
    
    pinMode(6, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
  
}

void loop()
{

    // Se o botão da esquerda for apertado, os motores giram no sentido anti-horário:
  
    if(digitalRead(13) == LOW)
    {
    
        analogWrite(5, 255);
        
        digitalWrite(3, HIGH);
        
        analogWrite(6, 255);
        
        digitalWrite(8, HIGH);
    
    }

    // Senão, param de girar:
    
    else
    {
    
        analogWrite(5, 0);
        
        digitalWrite(3, LOW);
        
        analogWrite(6, 0);
        
        digitalWrite(8, LOW);
    
    }

    // Se o botão da direita for apertado, os motores giram no sentido horário:
    
    if(digitalRead(12) == LOW)
    {
    
        analogWrite(5, 255);
        
        digitalWrite(2, HIGH);
        
        analogWrite(6, 255);
        
        digitalWrite(9, HIGH);
    
    }

    // Senão, param de girar:
    
    else
    {
    
        analogWrite(5, 0);
        
        digitalWrite(2, LOW);
        
        analogWrite(6, 0);
        
        digitalWrite(9, LOW);
    
    }
  
}