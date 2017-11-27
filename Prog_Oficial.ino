/*
  Servo giro garra porta 5

  Servo 6 ????

  Servo 9    garra   110 - 180

  Servo 10 Junta principal

  Servo 11 Junta Secundaria

  Servo 7 Base



*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <RotaryEncoder.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

RotaryEncoder encoder(A2, A3);

Servo GiroGarra;
Servo Garra;
Servo Base;
Servo JuntaPrincipal;
Servo Secundaria;


void apitar() {

  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(4, LOW);
  delay(50);
}

void inicio() {
  pinMode(4, OUTPUT);
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Inicializando");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("#");
  int t = 10;
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("##");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("###");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("####");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("#####");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("######");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("#######");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("########");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("#########");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("##########");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("###########");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("############");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("#############");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("##############");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("###############");
  delay(t);
  apitar();
  lcd.setCursor(0, 1);
  lcd.print("################");
  delay(t);
  apitar();


}

void settings() {



}

void menu() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("MaxX Robot");
  lcd.setCursor(6, 1);
  lcd.print("V2.2");
  delay(3000);
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Modo");
  lcd.setCursor(2, 1);
  lcd.print("Demonstracao");

}

void posinit() {

}

void abrirgarra() {
  Garra.write(160);
  delay(2000);
}

void fechargarra() {
  Garra.write(100);
  delay(2000);
}

void setup() {
  inicio();


  settings();

  GiroGarra.attach(6);
  delay(1000);
  Garra.attach(9);
  delay(1000);
  Base.attach(7);
  delay(1000);
  Secundaria.attach(11);
  delay(1000);
  JuntaPrincipal.attach(10);
  delay(1000);

  menu();






}

void loop() {

  // COMEÇO

  JuntaPrincipal.write(78);
  delay(2000);
  Base.write(110);
  delay(2000);
  Base.write(180);
  delay(2000);
  JuntaPrincipal.write(140);
  delay(2500);
  Garra.write(160);
  delay(2000);
  GiroGarra.write(60);
  delay(2000);
  Secundaria.write(31);
  delay(2500);
  Garra.write(100);
  delay(2000);

  // FECHOU GARRA COM ARGOLA


  Secundaria.write(90);
  delay(2500);
  JuntaPrincipal.write(90);
  delay(2000);
  Base.write(5);
  delay(2000);

  // VIROU BASE COM ARGOLA
 /* JuntaPrincipal.write(135);
  delay(2000);
  Secundaria.write(17);
  delay(2000);
  abrirgarra();
*/
JuntaPrincipal.write(140);
  delay(2500);
 // Garra.write(160);
  //delay(2000);
  //GiroGarra.write(60);
  //delay(2000);
  Secundaria.write(31);
  delay(2500);
  abrirgarra();
  
  // LARGOU ARGOLA
 
  JuntaPrincipal.write(80);
  delay(2000);
  Base.write(110);
  delay(2000);
  apitar();
  apitar();
  apitar();

  // VOLTA PARA POSICAO
  Base.write(5);
  delay(2000);
  JuntaPrincipal.write(140);
  delay(2000);
  Secundaria.write(31);
  delay(2000);
  fechargarra();

  // PEGOU ARGOLA
  JuntaPrincipal.write(78);
  delay(2000);
  Base.write(180);
  delay(2000);
  JuntaPrincipal.write(140);
  delay(2500);
  Secundaria.write(31);
  delay(2500);
  abrirgarra();

  // LARGOU ARGOLA
  Secundaria.write(90);
  delay(2000);
  JuntaPrincipal.write(90);
  delay(2000);
  Base.write(110);
  delay(2000);








}
