
/*
  AAA
 F   B
 F   B
  GGG
 E   C
 E   C
  DDD  H

Change the preset constants below to how you set up your Arduino

To Hide/Show the dot or decimal point add H to the numbers array (int numbers[])
*/


const int A = 7;
const int B = 8;
const int C = 12;
const int D = 11;
const int E = 10;
const int F = 6;
const int G = 5;
const int H = 13;


int numbers[] = {A, B, C, D, E, F, G};
int mySize = sizeof(numbers)/sizeof(int);

void writeNumber(int n, int time);
void reset();
/* 
 

*/
void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < mySize; i++){
    pinMode(numbers[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 10; i++)
    writeNumber(i, 1000);
  
}

void writeNumber(int n, int time){
  for(int i = 0; i < mySize; i++){
    digitalWrite(numbers[i], HIGH);
  }
  if(n == 0 || n == 1 || n == 7) {
    digitalWrite(G, LOW);
    if(n == 1 || n == 7) {
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      if(n == 1) {
        digitalWrite(A, LOW);
      }
    }  
  } else if(n == 3 || n == 4 || n == 5 || n == 9) {
      digitalWrite(E, LOW);
      if(n == 4 || n == 9) {
        digitalWrite(D, LOW);
        if(n == 4) digitalWrite(A, LOW);
      } else if(n == 5)  digitalWrite(B, LOW);
      else digitalWrite(F, LOW);
  } else if(n == 6) digitalWrite(B, LOW);
  else if(n == 2){
    digitalWrite(C, LOW);
    digitalWrite(F, LOW);
  }
  delay(time);
  reset();

}

void reset() {
  for(int i = 0; i < mySize; i++){
    digitalWrite(numbers[i], LOW);
  }
}


