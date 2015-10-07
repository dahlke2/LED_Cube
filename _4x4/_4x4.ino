/*


Created by Ethan Dahlke, May 16, 2014
*/

#include <micrel.h>

#ifndef DATA
#define DATA 2
#define CLK 3
#define ENABLE 4
#endif

#define CUBE 4

Micrel output;

Cube_4x4 data;
//Layer *layer_ptr= &(data.a);
//String_36 string;

ISR (TIMER1_OVF_vect){
//  Serial.println("ISR");
//  output.shiftOut_mult(&data, 0x1);
//  Serial.println("ISR Done");
//  output.Clear();
}

void setup(){
  TCCR1A = 0x0; //Timer 1 Counter Comopare A clear on compare match
  TCCR1B = 0x1; //Timer 1 1 prescaler
  TCCR1C = 0x0;
  TIMSK1 = 0x1; //Timer 1 overflow
  OCR1A = 0xff; //Timer 1 output compare register set to 0xff
//  TIMSK0 = 0; // turn off timer0 for lower jitter
//  ADCSRA = 0xe5; // set the adc to free running mode
//  ADMUX = 0x01; // use adc1
//  DIDR0 = 0x02; // turn off the digital input for adc1
//  analogReference(EXTERNAL);
Serial.begin(9600);
Layer *layer_ptr = &(data.a);
int i;
for (i=0; i<CUBE; i++){
  layer_ptr->a = 0xf;
  layer_ptr->b = 0xf;
  layer_ptr->c = 0xf;
  layer_ptr->d = 0xf;
  layer_ptr++;
}
//data.a.a = 0xf;
//data.a.b = 0xf;
//data.a.c = 0xf;
//data.a.d = 0xf;
//data.b.a = 0xf;
//data.b.b = 0x5;
//data.b.c = 0x5;
//data.b.d = 0x5;
//data.c.a = 0x5;
//data.c.b = 0x5;
//data.c.c = 0x5;
//data.c.d = 0x5;
//data.d.a = 0x5;
//data.d.b = 0x5;
//data.d.c = 0x5;
//data.d.d = 0x5;

}

void loop(){
  Layer *layer_ptr = &(data.a);
  int i;
//data.a.a = 0x5;
//data.a.b = 0x5;
//data.a.c = 0x5;
//data.a.d = 0x5;
//data.b.a = 0x5;
//data.b.b = 0x5;
//data.b.c = 0x5;
//data.b.d = 0x5;
//data.c.a = 0x5;
//data.c.b = 0x5;
//data.c.c = 0x5;
//data.c.d = 0x5;
//data.d.a = 0x5;
//data.d.b = 0x5;
//data.d.c = 0x5;
//data.d.d = 0x5;
//for (i=0; i<CUBE; i++){
//  layer_ptr->a = 0x5;
//  layer_ptr->b = 0x5;
//  layer_ptr->c = 0x5;
//  layer_ptr->d = 0x5;
//  layer_ptr++;
//}
data = Box_4x4;
  output.shiftOut_mult(&data, 0x1);
//delay(10);
}

//void serialEvent(){
//  Serial.println(data.a.a);
//  while(Serial.available()){
//    data = (long long int)Serial.read();
//  }
//}
