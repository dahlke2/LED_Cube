/*

 
 Created by Ethan Dahlke, May 16, 2014
 */

#include <micrel.h>
#include <Cube_4x4.h>

#ifndef DATA
#define DATA 2
#define CLK 3
#define ENABLE 4
#endif
#define CUBE 4

#define serial

Micrel output;
Cube_Effect effects;

Cube_4x4 data;
Layer *layer_ptr= &(data.a);
//String_36 string;

ISR (TIMER1_OVF_vect){
//  digitalWrite(13, HIGH);
  output.shiftOut_mult(&data, 0x1);
//  output.Clear();
}

void setup(){
  TCCR1A = 0x0; //Timer 1 Counter Comopare A clear on compare match
  TCCR1B = 0x1; //Timer 1 1 prescaler
  TCCR1C = 0x0;
  TIMSK1 = 0x01; //Timer 1 overflow
  OCR1A = 0xFFFF; //Timer 1 output compare register set to 0xff
  //  TIMSK0 = 0; // turn off timer0 for lower jitter
  //  ADCSRA = 0xe5; // set the adc to free running mode
  //  ADMUX = 0x01; // use adc1
  //  DIDR0 = 0x02; // turn off the digital input for adc1
  //  analogReference(EXTERNAL);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  output.disable();
  Layer *layer_ptr = &(data.a);
  int i;
  for (i=0; i<CUBE; i++){
    layer_ptr->a = 0x0;
    layer_ptr->b = 0x0;
    layer_ptr->c = 0x0;
    layer_ptr->d = 0x0;
    layer_ptr++;
  }
}

void loop(){
 #ifndef serial
  effects.single_scan(&data, &output);
  delay(200);
  effects.Box(&data);
delay(1500);
  effects.Full(&data);
delay(1500);
#endif
}

void serialEvent(){
  //  Serial.println(data.a.a);
  Display_Comm serial_display;
  #ifdef serial
  cli();
  serial_display.Display(serial_display.Read(&data));
  /*
  char buffer;
  char *pixel_ptr;
  char pixel;
  String_36 serial_string;
  while(Serial.available()){
//        digitalWrite(13, HIGH);
    Serial.readBytes(&buffer,1);
//    Serial.println(buffer,HEX);
  
    Layer *layer_ptr = &(data.a);
  
  layer_ptr+=(buffer & 0x3);          //Select layer
  pixel_ptr = &layer_ptr->a;
  pixel_ptr+=(buffer>>2 & 0x3);       //Select row
  pixel=(buffer>>4 & 0x3);            //Select pixel
  if(buffer>>5 & 0x1)
    *pixel_ptr |= (0x1<<pixel);       //Turn pixel on
  else
    *pixel_ptr &= ~(0x1<<pixel);      //Turn pixel off
//    Serial.write(*pixel_ptr);
  }
  */
    sei();
    #endif
}

