#include "my_pwm.h"
#include "pwm.h"
#include "timer.h"

//PWM0 PB6
//PWM1 PB7
//PWM2 PB4
//PWM3 PB5

void pwm_init(void){
	
  SysCtlPWMClockSet(SYSCTL_PWMDIV_2);//pwm的时钟不分频，25Mhz，
	SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//pwm使用PB6 PB7
	GPIOPinConfigure(GPIO_PB6_M0PWM0);
  GPIOPinConfigure(GPIO_PB7_M0PWM1);
	GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
  GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
	GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_6|GPIO_PIN_7,GPIO_STRENGTH_8MA,GPIO_PIN_TYPE_STD);
	//配置定时器程序
	PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_UP_DOWN |PWM_GEN_MODE_NO_SYNC);//pwm产生的模式
	PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 66666);//设置PWM产生的周期，25000是1k 
	//pwm发生器的设置，设置分频值
//  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 5000);
// PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,
//                     (PWMGenPeriodGet(PWM0_BASE, PWM_OUT_0)-1)0);
	
	//初始占空比的设置
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,0);//这里除以0代表着占空,其实输入应该是计数时钟的计数值
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1,0);//这里除以0代表着占空,其实输入应该是计数时钟的计数值
		PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT | PWM_OUT_0_BIT, true);
		PWMGenEnable(PWM0_BASE, PWM_GEN_0);
//其他两个通道的设置
    SysCtlPWMClockSet(SYSCTL_PWMDIV_2);//pwm的时钟不分频，25Mhz，
		SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
	  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//pwm使用PB6 PB7
		GPIOPinConfigure(GPIO_PB4_M0PWM2);
    GPIOPinConfigure(GPIO_PB5_M0PWM3);
		GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);
	  GPIOPadConfigSet(GPIO_PORTB_BASE, GPIO_PIN_4|GPIO_PIN_5,GPIO_STRENGTH_8MA,GPIO_PIN_TYPE_STD);
	  PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN |PWM_GEN_MODE_NO_SYNC);//pwm产生的模�
	  PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 66666);//设置PWM产生的周期
	
	  PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,0);//这里除以0代表着占空,其实输入应该是计数时钟的计数值
		PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,0);//这里除以0代表着占空,其实输入应该是计数时钟的计数值
		PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT | PWM_OUT_3_BIT, true);
		PWMGenEnable(PWM0_BASE, PWM_GEN_1);
}



////设置占空比的函数，该函数的带入参数就是占空比的值
void set_compare(u16 motor1,u16 motor2,u16 motor3,u16 motor4){
   PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,66666/2000*motor1);//最后一个参数表示正点位的宽度
	 PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1,66666/2000*motor2);
	 PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,66666/2000*motor3);
	 PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,66666/2000*motor4);
}

//这个是测试的当前PWM满值时候的计数值：64000
u32 my_test(void){
  u32 temp;
	temp=PWMGenPeriodGet(PWM0_BASE, PWM_OUT_0);
	return temp;
}


void motor_driver(void){
  pwm_init();
	set_compare(2000,2000,2000,2000);//测试油门
	delay_ms(2000);
	set_compare(1000,1000,1000,1000);
  delay_ms(2000);
	set_compare(1100,1100,1100,1100);
  delay_ms(2000);
	

  
	
}



