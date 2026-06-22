/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "led_rgb.h"
#include "multiple_button.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
	STATE_OFF,
	STATE_FADE_IN_OUT,
	STATE_RAINBOW_BLINK,
	STATE_RAINBOW_FOLLOW,
	
} ledStatus;

ledStatus led_state;


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

GPIO_TypeDef *port_led1[] = {R1_GPIO_Port,B1_GPIO_Port,G1_GPIO_Port};
GPIO_TypeDef *port_led2[] = {R2_GPIO_Port,B2_GPIO_Port,G2_GPIO_Port};
GPIO_TypeDef *port_led3[] = {R3_GPIO_Port,B3_GPIO_Port,G3_GPIO_Port};
GPIO_TypeDef *port_led4[] = {R4_GPIO_Port,B4_GPIO_Port,G4_GPIO_Port};
uint16_t pin_led1[]={R1_Pin,B1_Pin,G1_Pin};
uint16_t pin_led2[]={R2_Pin,B2_Pin,G2_Pin};
uint16_t pin_led3[]={R3_Pin,B3_Pin,G3_Pin};
uint16_t pin_led4[]={R4_Pin,B4_Pin,G4_Pin};


BUTTON button;
RGB led1,led2,led3,led4;

uint8_t btn;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void btn_pressing_callback(BUTTON *button)
	
{
	switch (led_state)
	{
		case STATE_OFF:
			led_state=STATE_FADE_IN_OUT;
			break;
		case STATE_FADE_IN_OUT:
			led_state=STATE_RAINBOW_BLINK;
			break;
		case STATE_RAINBOW_BLINK:
			led_state=STATE_RAINBOW_FOLLOW;
			break;
		case STATE_RAINBOW_FOLLOW:
			led_state=STATE_OFF;
			break;
		default:
			break;
	}
	

}

void state_off()
{
	rgb_setcolor(&led1, OFF);
	rgb_setcolor(&led2, OFF);
	rgb_setcolor(&led3, OFF);
	rgb_setcolor(&led4, OFF);
}


typedef enum
{
	led1on,
	led2on, 
	led3on,
	led4on,
	led4off,
	led3off,
	led2off,
	led1off,
}EFFECT1;
EFFECT1 effect1;

void state_fade_in_out()
{
	
	if (HAL_GetTick() - led1.last_time_on >= 300)
	{
		switch (effect1)
		{
			case led1on:
				rgb_setcolor(&led1,RED);
				break;
			case led2on:
				rgb_setcolor(&led2,GREEN);
				break;
			case led3on:
				rgb_setcolor(&led3,BLUE);
				break;
			case led4on:
				rgb_setcolor(&led4,WHITE);
				break;
			case led4off:
				rgb_setcolor(&led4,OFF);
				break;
			case led3off:
				rgb_setcolor(&led3,OFF);
				break;
			case led2off:
				rgb_setcolor(&led2,OFF);
				break;
			case led1off:
				rgb_setcolor(&led1,OFF);
				break;
		}
		switch(effect1)
		{
			case led1on:
				effect1=led2on;
				break;
			case led2on:
				effect1=led3on;
				break;
			case led3on:
				effect1=led4on;
				break;
			case led4on:
				effect1=led4off;
				break;
			case led4off:
				effect1=led3off;
				break;
			case led3off:
				effect1=led2off;
				break;
			case led2off:
				effect1=led1off;
				break;
			case led1off:
				effect1=led1on;
				break;
		}
		
		led1.last_time_on=HAL_GetTick();
	}	
}


	
Color color1;




void state_rainbow_blink()
{
	
	
	///
	if (HAL_GetTick() - led1.last_time_on >= 500)
	{
		rgb_setcolor(&led1,OFF);
		rgb_setcolor(&led2,OFF);
		rgb_setcolor(&led3,OFF);
		rgb_setcolor(&led4,OFF);
		switch (color1)
		{
				case RED:
					rgb_setcolor(&led1,color1);
					rgb_setcolor(&led2,color1);
					rgb_setcolor(&led3,color1);
					rgb_setcolor(&led4,color1);
					break;
				case GREEN:
					rgb_setcolor(&led1,color1);
					rgb_setcolor(&led2,color1);
					rgb_setcolor(&led3,color1);
					rgb_setcolor(&led4,color1);
					break;
				case BLUE:
					rgb_setcolor(&led1,color1);
					rgb_setcolor(&led2,color1);
					rgb_setcolor(&led3,color1);
					rgb_setcolor(&led4,color1);
					break;
				case PURPLE:
					rgb_setcolor(&led1,color1);
					rgb_setcolor(&led2,color1);
					rgb_setcolor(&led3,color1);
					rgb_setcolor(&led4,color1);
					break;
				case YELLOW:
					rgb_setcolor(&led1,color1);
					rgb_setcolor(&led2,color1);
					rgb_setcolor(&led3,color1);
					rgb_setcolor(&led4,color1);
					break;
				case WHITE:
					rgb_setcolor(&led1,color1);
					rgb_setcolor(&led2,color1);
					rgb_setcolor(&led3,color1);
					rgb_setcolor(&led4,color1);
					break;
				case OFF:
					break;
		}
		
		
		switch (color1)
		{
			case RED:
				color1=GREEN;
				break;
			case GREEN:
				color1=BLUE;
				break;
			case BLUE:
				color1=PURPLE;
				break;
			case PURPLE:
				color1=YELLOW;
				break;
			case YELLOW:
				color1=WHITE;
				break;
			case WHITE:
				color1=RED;
				break;
			case OFF:
				break;

		}
		led1.last_time_on=HAL_GetTick();
	}	
}


typedef enum 
{
	led1_2,
	led2_3,
	led3_4,
	led4_1,
} EFFECT3;

EFFECT3 effect3;
Color color2;
void switch_effect3()
{
	color2=RED;
	switch (effect3)
		{
			case led1_2:
				effect3=led2_3;
				break;
			case led2_3:
				effect3=led3_4;
				break;
			case led3_4:
				effect3=led4_1;
				break;
			case led4_1:
				effect3=led1_2;
				break;
		}
}

void state_rainbow_follow()
{
		if (HAL_GetTick() - led3.last_time_on >= 500)
	{
		rgb_setcolor(&led1,OFF);
		rgb_setcolor(&led2,OFF);
		rgb_setcolor(&led3,OFF);
		rgb_setcolor(&led4,OFF);
		


		switch (effect3)
		{
				case led1_2:
					rgb_setcolor(&led1,OFF);
					rgb_setcolor(&led1,color2);
					rgb_setcolor(&led2,OFF);
					rgb_setcolor(&led2,color2);
					
					break;
				case led2_3:
					rgb_setcolor(&led2,OFF);
					rgb_setcolor(&led2,color2);
					rgb_setcolor(&led3,OFF);
					rgb_setcolor(&led3,color2);
					break;
				case led3_4:
					rgb_setcolor(&led3,OFF);
					rgb_setcolor(&led3,color2);
					rgb_setcolor(&led4,OFF);
					rgb_setcolor(&led4,color2);
					break;
				case led4_1:
					rgb_setcolor(&led1,OFF);
					rgb_setcolor(&led1,color2);
					rgb_setcolor(&led4,OFF);
					rgb_setcolor(&led4,color2);
					break;
		}
		
		switch (color2)
		{
			case RED:
				color2=GREEN;
				break;
			case GREEN:
				color2=BLUE;
				break;
			case BLUE:
				color2=PURPLE;
				break;
			case PURPLE:
				color2=YELLOW;
				break;
			case YELLOW:
				color2=WHITE;
				break;
			case WHITE:
				switch_effect3();
				break;
			case OFF:
				
				break;
			
		}
		
		
		
		
		
		led3.last_time_on=HAL_GetTick();
	}
}	
	

	
void led_handle()
{
	switch(led_state)
	{
		case STATE_OFF:
			state_off();
			break;
		case STATE_FADE_IN_OUT:
			state_fade_in_out();
			break;
		case STATE_RAINBOW_BLINK:
			state_rainbow_blink();
			break;
		case STATE_RAINBOW_FOLLOW:
			state_rainbow_follow();
			break;
		default:
			break;
			
	}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	button_init(&button,BT_GPIO_Port,BT_Pin);
	rgb_init(&led1,port_led1,pin_led1);
	rgb_init(&led2,port_led2,pin_led2);
	rgb_init(&led3,port_led3,pin_led3);
	rgb_init(&led4,port_led4,pin_led4);
	
	
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		
		button_handle(&button);
		
		led_handle();
		
		
		
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, R4_Pin|B3_Pin|B4_Pin|G4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, G3_Pin|R2_Pin|B1_Pin|G1_Pin
                          |R1_Pin|B2_Pin|G2_Pin|R3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : BT_Pin */
  GPIO_InitStruct.Pin = BT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : R4_Pin B3_Pin B4_Pin G4_Pin */
  GPIO_InitStruct.Pin = R4_Pin|B3_Pin|B4_Pin|G4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : G3_Pin R2_Pin B1_Pin G1_Pin
                           R1_Pin B2_Pin G2_Pin R3_Pin */
  GPIO_InitStruct.Pin = G3_Pin|R2_Pin|B1_Pin|G1_Pin
                          |R1_Pin|B2_Pin|G2_Pin|R3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
