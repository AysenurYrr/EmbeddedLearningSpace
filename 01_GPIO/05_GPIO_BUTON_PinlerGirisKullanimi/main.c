#include "stm32f10x.h"                  // Device header
//Uygulamada buton ile led yakacagiz. Basinca yanacak cekince sonecek.

uint16_t buttonState; //Buton durumu
void gpioConfig(){
	
	GPIO_InitTypeDef GPIOInitStructure;
// Iki adet clock acmamiz lazim 1.buton ve 2.led dolayisiyla
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); //for led
	//Ledimiz B portuna bagli olsun. 
	
	//Datasheet Bloack diagramdan baz hattina bakabisirsiniz.
	//Datasheette A B ve C portunun APB2 Baz hattina bagli oldugunu gördük.
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); //for button
	
	//LED
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIOInitStructure);
	
	
	//BUTTON
	//MOde IPD: (Input PullDown) GND kismina bagli direnc 
	//Mode IPU: (Input PullUp) VDD yani 3.3 kismina baglicaksaniz
	GPIOInitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIOInitStructure);
}


int main() {
	gpioConfig();
	while(1){
		buttonState=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		
		if(buttonState==1){
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
		
		}else{
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);
			
			
			
		}
	
	
	
	}

}
