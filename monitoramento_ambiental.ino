int led1 = 11;
int led2 = 9;

const int ldr = A0; //Atribui A0 a variável ldr
int valorLDR = 0;   //Declara a variável valorldr como inteiro

const int LM35 = A1;//Atribui A1 a variável LM35
float celsius = 0.0;

void setup()
{
pinMode(ldr, INPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
Serial.begin(9600);

}

void loop()
{
  int luzPadrao = 450; // luminosidade aceitável para considerar claro
  
  celsius = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura:  ");
  Serial.println(celsius);
  
  valorLDR = analogRead(ldr);//Lê o valor do sensor ldr e armazena na variável valorldr
  Serial.print("intensiddade:  ");
  Serial.println(valorLDR);//Imprime na serial os dados de valorldr
  
  int hora; // Guardar o tempo em que foi modificado o estado dos leds
  int contador; // contador de modificações
  
  delay(1000);
  
  //Condição do led verde
  if (celsius >= 20 && celsius <= 28 && valorLDR >= luzPadrao) 
  {
    digitalWrite(led1, HIGH);
    
    hora = millis();
    Serial.print("Hora:  ");
    Serial.println(hora);
    
    contador = 1;
    contador ++;
    Serial.print("Modificações:  ");
    Serial.println(contador);
  }
  else
  {
    digitalWrite(led1, LOW);
  }
  
  //Condição do led vermelho
  if (celsius > 30 && valorLDR < luzPadrao)
  {
    digitalWrite(led2, HIGH);
    
    hora = millis();
    Serial.print("Hora:  ");
    Serial.println(hora);
    
    contador ++;
    Serial.print("Modificações:  ");
    Serial.println(contador);
  }
  else
  {
    digitalWrite(led2, LOW);
  }
}