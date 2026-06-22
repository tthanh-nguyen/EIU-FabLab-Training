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

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
GPIO_TypeDef *port_rgb[] = {GPIOB, GPIOB, GPIOB};
uint16_t pin_rgb[] = {LED_R_Pin, LED_B_Pin, LED_G_Pin};

GPIO_TypeDef *port_button[] = {GPIOA, GPIOA};
uint16_t pin_button[] = {BT1_Pin, BT2_Pin};

RGB mau;

BUTTON button1;
BUTTON button2;

uint8_t dem1;
uint8_t dem2;

uint32_t blink_time=0;


typedef enum
{
	LED_OFF,
	LED_RED_BLINK_1HZ,
	LED_GREEN_BLINK_5HZ,
	LED_BLUE_BLINK_10HZ,

} LedStatus;

LedStatus led_status;



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
// actions



void btn_pressing_callback(BUTTON *button)
{
	if(button == &button1)
	{
		
	}
	
	
	
	if(button == &button2)
	{
		
	}
}

void btn_release_callback(BUTTON *button)
{
	//btn2++;
}
void btn_press_short_callback(BUTTON *button)
{
	if (button == &button1)
	{
		//transition
		switch (led_status)
		{
			case LED_OFF:
				led_status = LED_RED_BLINK_1HZ;
				break;
			case LED_RED_BLINK_1HZ:
				led_status = LED_GREEN_BLINK_5HZ;
				break;
			case LED_GREEN_BLINK_5HZ:
				led_status = LED_BLUE_BLINK_10HZ;
				break;
			case LED_BLUE_BLINK_10HZ:
				led_status = LED_OFF;
			default:
				break;
		}
	}
	else if (button == &button2)
	{
		switch (led_status)
		{
			case LED_OFF:
				led_status = LED_RED_BLINK_1HZ;
				break;
			case LED_RED_BLINK_1HZ:
				led_status = LED_GREEN_BLINK_5HZ;
				break;
			case LED_GREEN_BLINK_5HZ:
				led_status = LED_BLUE_BLINK_10HZ;
				break;
			case LED_BLUE_BLINK_10HZ:
				led_status = LED_OFF;
			default:
				break;
		}
	}
}
void btn_press_long_callback(BUTTON *button)
{
	if (button == &button1)
	{
		switch (led_status)
		{
			
			case LED_RED_BLINK_1HZ:
				led_status = LED_OFF;
				break;
			case LED_GREEN_BLINK_5HZ:
				led_status = LED_OFF;
				break;
			case LED_BLUE_BLINK_10HZ:
				led_status = LED_OFF;
			default:
				break;
		}
	}
	else if (button == &button2)
	{
		switch (led_status)
		{
			case LED_RED_BLINK_1HZ:
				led_status = LED_OFF;
				break;
			case LED_GREEN_BLINK_5HZ:
				led_status = LED_OFF;
				break;
			case LED_BLUE_BLINK_10HZ:
				led_status = LED_OFF;
			default:
				break;
		}
	}
}

void led_off()
{
	rgb_setcolor(&mau, OFF);
}
void led_Red_Blink1Hz()
{
	rgb_blink(&mau, RED, 500);
}
void led_Green_Blink5Hz()
{
	rgb_blink(&mau, GREEN, 100);
}
void led_Blue_Blink10Hz()
{
	rgb_blink(&mau, BLUE, 50);
}

// goi action phu hop de tao output
void led_handle()
{
	switch (led_status)
		{
			case LED_OFF:
				led_off();
				break;
			case LED_RED_BLINK_1HZ:
				led_Red_Blink1Hz();
				break;
			case LED_GREEN_BLINK_5HZ:
				led_Green_Blink5Hz();
				break;
			case LED_BLUE_BLINK_10HZ:
				led_Blue_Blink10Hz();
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
	//button_init(BUTTON *button, GPIO_TypeDef *port_button, uint16_t pin_button);
	button_init(&button1, port_button[0], pin_button[0]);
	button_init(&button2, port_button[1], pin_button[1]);

  /* USER CODE BEGIN Init */
	rgb_init(&mau,port_rgb, pin_rgb);
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
	led_status = LED_OFF;
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
//		button_handle(&button1);
//		button_handle(&button2);
//		led_handle();
		
		//rgb_blink1(&mau, RED, GREEN, 1000);
		if (HAL_GetTick() - mau.last_time_on >= 1000)
			{
					rgb_toggle(&mau, RED);
					mau.last_time_on = HAL_GetTick();
			}
	if (HAL_GetTick() - mau.last_time_on1 >= 1000)
			{
					rgb_toggle(&mau, GREEN);
					mau.last_time_on1 = HAL_GetTick();
			}
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

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
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
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_G_Pin|LED_R_Pin|LED_B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_G_Pin LED_R_Pin LED_B_Pin */
  GPIO_InitStruct.Pin = LED_G_Pin|LED_R_Pin|LED_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BT1_Pin BT2_Pin */
  GPIO_InitStruct.Pin = BT1_Pin|BT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
