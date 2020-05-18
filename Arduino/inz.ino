#define ST          A1    //Start
#define CLK         A2    //CLOCK
#define VIDEO       A3    //VIDEO
#define PIXELS    288
int values[PIXELS];      //wartość pixeli
int n=3;                //integracja

void setup(){
  pinMode(CLK, OUTPUT);     
  pinMode(ST, OUTPUT);
  digitalWrite(CLK, HIGH);     
  digitalWrite(ST, LOW); 
  for (int i = 0; i < PIXELS; i++){
    values[i] = 0;
  }
  Serial.begin(115200);  // częstotliowść komunikacji
}

void odczyt(){
  int delayTime = 1; // 1us
  // Rozpoczęcie pracy zegara i ustawienie pulsu startu na stan wysoki
  digitalWrite(CLK, HIGH);
  delayMicroseconds(delayTime);
  digitalWrite(CLK, LOW);
  delayMicroseconds(delayTime);
  digitalWrite(ST, HIGH);
  //rozpoczęcie integracji n + 48cykli //min 3
  for(int i = 0; i < n; i++){
      digitalWrite(CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(CLK, LOW);
      delayMicroseconds(delayTime); 
  }
  //ustawienie pulsu startu na niski, zakończenie startu
  digitalWrite(ST, LOW);

  //po 89 cyklu niskiego startu, rozpocznie się wysył danych
  for(int i = 0; i < 88; i++){
      digitalWrite(CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(CLK, LOW);
      delayMicroseconds(delayTime); 
  }

  //rozpoczęcie odczytu
  for(int i = 0; i < PIXELS; i++){
      values[i] = analogRead(VIDEO);
      digitalWrite(CLK, HIGH);
      delayMicroseconds(delayTime);
      digitalWrite(CLK, LOW);
      delayMicroseconds(delayTime);    
  }
  digitalWrite(CLK, HIGH);
  delayMicroseconds(delayTime);
}

void wypisz(){ //wysyłanie szeregowo wartości pikseli
  for (int i = 0; i < PIXELS; i++){
    Serial.print(values[i]);
    Serial.print(',');  
  }
  Serial.print('\n');
}

void loop(){
  odczyt();
  wypisz();
  delay(4000);   //pomiary co 1s
}

//dodać processing do wykreślania
