// 28/02/2023 dd/mm/yy

// Exercício 1: Piscar
// Tarefa: Piscar um LED em uma frequência de 2 Hz.
// Tempo estimado: 10 minutos.
// Dica: use HIGH para acender o LED, e LOW para apagá-lo.
// Ex.: digitalWrite(led, HIGH);

// Resposta: piscar(int pin, int count, double delayy);

#define D2 2

int count = 0;
int delayy = 250;

void setup()
{
  pinMode(D2, OUTPUT);
}

void loop()
{
  count = piscar(D2, count, delayy);
}

int piscar(int pin, int count, int delayy)
{
  digitalWrite(pin, count % 2);
  delay(delayy);
  return count % 2 + 1;
}

// Exercício 2: Piscar 3 leds
// Tarefa: Piscar led vermelho, amarelo e verde nesta sequência um de cada vez. Ao piscar o
// led verde, iniciar novamente a sequência.
// Tempo estimado: 15 minutos.
// Dica: utilize For, e outra função (void x ();) para praticar mais de uma forma de
// programação.

#define D14 14
#define D26 26
#define D32 32

int Leds[] = {D14, D26, D32};

void setup()
{
  pinMode(D14, OUTPUT);
  pinMode(D26, OUTPUT);
  pinMode(D32, OUTPUT);
}

void loop()
{

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(Leds[i], HIGH);
    delay(500);
    digitalWrite(Leds[i], LOW);
  }
}
