#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int16_t counter;

void gpioConfig(){
	GPIO_InitTypeDef GPIOInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //for leds

	//LED STRUCTURE
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_10;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOInitStructure);

}
void delay(uint32_t time){
	while(time--);
	
}




int main(){
	char name[5];
	gpioConfig();
	int ledArray[8]={GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_4, GPIO_Pin_5, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_9, GPIO_Pin_10};
	
	int led1[2]={GPIO_Pin_4, GPIO_Pin_6};
	int led2[5]={GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_10, GPIO_Pin_12};
	int led3[5]={GPIO_Pin_2, GPIO_Pin_4, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_10};
	int led4[4]={GPIO_Pin_4, GPIO_Pin_6, GPIO_Pin_9, GPIO_Pin_10};
	int led5[5]={GPIO_Pin_2, GPIO_Pin_4, GPIO_Pin_7, GPIO_Pin_9, GPIO_Pin_10};
	int led6[6]={GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_4, GPIO_Pin_7, GPIO_Pin_9, GPIO_Pin_10};
	int led7[3]={GPIO_Pin_4, GPIO_Pin_6, GPIO_Pin_7};
	int led8[7]={GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_4, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_9, GPIO_Pin_10};
	int led9[6]={GPIO_Pin_2, GPIO_Pin_4, GPIO_Pin_6, GPIO_Pin_7, GPIO_Pin_9, GPIO_Pin_10};
	
	while(1){
	
	//ILERI
	for(int i=1;i<10;i++){
		
		for(int k=1;k<10;k++){
		GPIO_ResetBits(GPIOB, ledArray[k]);} //Close All Leds
		
		sprintf(name,"%s%d","led",i);
		size_t n = sizeof(name)/sizeof(name[0]);
			for (int j=0; j<n; j++){
				GPIO_SetBits(GPIOB,name[j]);}
		delay(320000);
	}
	
	//GERI
	for(int i=8;i>0;i--){
		
		for(int k=1;k<10;k++){
		GPIO_ResetBits(GPIOB, ledArray[k]);} //Close All Leds
		
		sprintf(name,"%s%d","led",i);
		size_t n = sizeof(name)/sizeof(name[0]);
			for (int j=0; j<n; j++){
				GPIO_SetBits(GPIOB,name[j]);}
		delay(320000);
	}
	
	
		
}
}
