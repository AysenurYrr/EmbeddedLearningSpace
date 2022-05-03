#include "stm32f10x.h"                  // Device header

void gpioConfig(){

	GPIO_InitTypeDef GPIOInitStructure; //GPIOInitStructure yi GPIO_InitTypeDef klassi adi altinda tanimladik.
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); //Clock ve GPIOB kanalini aktif etme
	
	
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP; //PushPull AçmaKapama
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_Speed= GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIOInitStructure); //Tanimlari Initilaze ediyoruz
}

int main(){
	gpioConfig(); //gpioConfig çalistirarak yapi olusturuluyor
	while(1){
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		for(int i=0; i<360000; i++);		//delay 
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
		for(int i=0; i<36000; i++);			//delay
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		for(int i=0; i<720000; i++);		//delay 
		GPIO_ResetBits(GPIOB, GPIO_Pin_0);
		for(int i=0; i<36000; i++);			//delay
	}
	
}
