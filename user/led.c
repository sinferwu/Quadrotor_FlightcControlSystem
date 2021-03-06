#include "led.h"
#include "includes.h"
void led_init(void){  //这个函数的意义相当于使能GPIOF2引脚
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//相当于使能哪个端口GPIOF
	GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,GPIO_STRENGTH_8MA,GPIO_PIN_TYPE_STD);//配置成了推挽输出默认也是
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);//往地址里面写入，，引脚是GPIO_PIN_2
	GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, 0);
}
//第一个led灯开启
void led1_on(void){
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1); //向某个引脚里面写入值�
}

void led1_off(void){
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0); 
}
//第二个led灯的初始化
void led2_on(void){
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2); //向某个引脚里面写入值�
}

void led2_off(void){
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0); 
}
//第三个led灯的初始化
void led3_on(void){
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3); //向某个引脚里面写入值�
}

void led3_off(void){
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0); 
}


//读取io口的测试函数
void test_led(void){
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//相当于使能哪个端口GPIOF
	GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_0,GPIO_STRENGTH_4MA,GPIO_PIN_TYPE_OD);
	ROM_GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0);//往地址里面写入，，引脚是GPIO_PIN_0
}

//如果一个io口需要反复的读取和输出，就要不断的设置其输入输出的状态，这一点在DMP的I2C的配置中很重要
u8 read_pin(void){
	ROM_GPIOPinTypeGPIOInput(GPIO_PORTB_BASE, GPIO_PIN_0);
  return GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_0);
}


