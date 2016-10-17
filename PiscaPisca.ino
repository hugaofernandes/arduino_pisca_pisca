//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Pisca - Pisca
// 
// Made by hugo medeiros fernandes
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/2174693-pisca-pisca


int ledRed = 3;
int ledGreen = 5;
int ledBlue = 6;
int ledYellow = 9;
int pushbutton = 7;
int status = 1;

void intensidade(int led){
  int i;
  for (i = 0; i < 1024; i+=2){
  	analogWrite(led, i/4);
  }
  delay(200);
  for (i = 1024; i > 0; i-=2){
  	analogWrite(led, i/4);
  }
}

void pisca_pisca(int led){
  status += digitalRead(pushbutton);
  if (status == 1){
  	digitalWrite(led, HIGH);
  	delay(200);
  	digitalWrite(led, LOW);
  }
  else if (status == 2){
  	intensidade(led);
  }
  else if (status == 3) {
  	digitalWrite(led, HIGH);
  	delay(200);
  	digitalWrite(led, LOW);
  	delay(200);
    digitalWrite(led, HIGH);
  	delay(200);
  	digitalWrite(led, LOW);
  }
  else {
  	status = 1;
  }
}

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(pushbutton, INPUT);
}

void loop() {
  pisca_pisca(ledRed);
  pisca_pisca(ledGreen);
  pisca_pisca(ledBlue);
  pisca_pisca(ledYellow);
}
