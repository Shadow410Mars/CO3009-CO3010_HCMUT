/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define TICK 10;
enum INDEX {EN0, EN1, EN2, EN3, DOT, SEC, MATRIX, SHIFT};
int counter[8] = {0};
int flag[8] = {0};

void timerRun(){
	for (int i=0;i<8;i++){
		if (counter[i] > 0) counter[i]--;
		if (counter[i] <= 0) flag[i] = 1;
	}
}
void setTimer(int timer, int index){
	counter[index] = timer/TICK;
	flag[index] = 0;
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim->Instance == TIM2) timerRun();
}
int led_status = RESET;
void toggle(){
	led_status = (led_status == RESET) ? SET : RESET;
	HAL_GPIO_WritePin(DOT_GPIO_Port, DOT_Pin, led_status);
}
void display7SEG(int num)
{
    switch (num)
    {
    case 0:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
        break;

    case 1:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
        break;

    case 2:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    case 3:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    case 4:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    case 5:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    case 6:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    case 7:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_SET);
        break;

    case 8:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    case 9:
        HAL_GPIO_WritePin(GPIOB, SEG0_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG3_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG4_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, SEG5_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, SEG6_Pin, GPIO_PIN_RESET);
        break;

    default:
        break;
    }
}
const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
void update7SEG(int index){
	switch (index){
		case 0:
			display7SEG(led_buffer[0]);
			break;
		case 1:
			display7SEG(led_buffer[1]);
			break;
		case 2:
			display7SEG(led_buffer[2]);
			break;
		case 3:
			display7SEG(led_buffer[3]);
			break;
		default:
			break;

	}
}
int hour=0, min=0, sec=0;
void updateClock(){
	sec++;
	if (sec >= 60) {
		min++;
		sec = 0;
	}
	if (min >= 60) {
		hour++;
		min = 0;
	}
	if (hour >= 24) {
		hour = 0;
	}
	led_buffer[EN0] = hour/10;
	led_buffer[EN1] = hour%10;
	led_buffer[EN2] = min/10;
	led_buffer[EN3] = min%10;
}
void setClock(int h, int m, int s) {
	hour = h;
	min = m;
	sec = s;
}

// ================= PHẦN LED MATRIX (EX 9 & 10) =================
const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
// Buffer chứa mã Hex của chữ 'A'
uint8_t matrix_buffer[8] = {0x00, 0xFE, 0x11, 0x11, 0x11, 0xFE, 0x00, 0x00};

void updateLEDMatrix(int index){
	// Tắt toàn bộ các cột (kéo xuống mức THẤP) để ULN2803 ngắt
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin |
                             ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin, GPIO_PIN_RESET);

	// Cấp dữ liệu cho các hàng (ROW) - Mức SET (HIGH) để cấp nguồn
	uint8_t data = matrix_buffer[index];
	HAL_GPIO_WritePin(GPIOB, ROW0_Pin, (data & 0x01) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW1_Pin, (data & 0x02) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW2_Pin, (data & 0x04) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW3_Pin, (data & 0x08) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW4_Pin, (data & 0x10) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW5_Pin, (data & 0x20) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW6_Pin, (data & 0x40) ? SET : RESET);
	HAL_GPIO_WritePin(GPIOB, ROW7_Pin, (data & 0x80) ? SET : RESET);

	// Bật cột (ENM) tương ứng bằng mức CAO (SET) để ULN2803 kéo xuống GND
	switch (index){
		case 0: HAL_GPIO_WritePin(GPIOA, ENM0_Pin, SET); break;
		case 1: HAL_GPIO_WritePin(GPIOA, ENM1_Pin, SET); break;
		case 2: HAL_GPIO_WritePin(GPIOA, ENM2_Pin, SET); break;
		case 3: HAL_GPIO_WritePin(GPIOA, ENM3_Pin, SET); break;
		case 4: HAL_GPIO_WritePin(GPIOA, ENM4_Pin, SET); break;
		case 5: HAL_GPIO_WritePin(GPIOA, ENM5_Pin, SET); break;
		case 6: HAL_GPIO_WritePin(GPIOA, ENM6_Pin, SET); break;
		case 7: HAL_GPIO_WritePin(GPIOA, ENM7_Pin, SET); break;
		default: break;
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* EX1, 2 BEGIN.
  setTimer(100, EN0);
  setTimer(225, EN1);
  setTimer(350, EN2);
  setTimer(475, EN3);
  EX1, 2 END. */
  // EX3, 4, 5, 6, 7, 8 BEGIN.
  	setClock(12, 27, 35);
  	setTimer(1, SEC);
	setTimer(100, EN0);
	setTimer(350, EN1);
	setTimer(600, EN2);
	setTimer(850, EN3);
  // EX3, 4, 5, 6, 7, 8 END.
	setTimer(100, DOT);
	setTimer(10, MATRIX);
	  setTimer(500, SHIFT);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if (flag[SEC]) {
		  flag[SEC] = 0;
		  updateClock();
		  setTimer(1000, SEC);
	  }
	  if (flag[EN0]) {
	  		  flag[EN0] = 0;
	  		  // 1. Tắt TẤT CẢ các LED (Mức SET)
	  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_SET);

	  		  // 2. Cập nhật dữ liệu số mới
	  		  update7SEG(EN0);

	  		  // 3. Bật đúng LED cần hiển thị (Mức RESET)
	  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);

	  		  // 4. Giữ nguyên 1000ms theo mốc thời gian của đề
	  		  setTimer(1000, EN0);
	  	  }

	  	  if (flag[EN1]) {
	  		  flag[EN1] = 0;
	  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_SET);
	  		  update7SEG(EN1);
	  		  HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
	  		  setTimer(1000, EN1);
	  	  }

	  	  if (flag[EN2]) {
	  		  flag[EN2] = 0;
	  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_SET);
	  		  update7SEG(EN2);
	  		  HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
	  		  setTimer(1000, EN2);
	  	  }

	  	  if (flag[EN3]) {
	  		  flag[EN3] = 0;
	  		  HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_SET);
	  		  update7SEG(EN3);
	  		  HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
	  		  setTimer(1000, EN3);
	  	  }
	  	  if (flag[DOT]) {
	  		  flag[DOT] = 0;
	  		  toggle();
	  		  setTimer(1000, DOT);
	  	  	  }
	  	// EX 9: Quét sáng lần lượt các cột của LED Matrix
	  		  if (flag[MATRIX]) {
	  			  flag[MATRIX] = 0;
	  			  updateLEDMatrix(index_led_matrix);
	  			  index_led_matrix = (index_led_matrix + 1) % MAX_LED_MATRIX;
	  			  setTimer(10, MATRIX);
	  		  }

	  		  // EX 10: Dịch vòng mảng sang trái để tạo Animation
	  		  if (flag[SHIFT]) {
	  			  flag[SHIFT] = 0;
	  			  uint8_t temp = matrix_buffer[0];
	  			  for (int i = 0; i < MAX_LED_MATRIX - 1; i++) {
	  				  matrix_buffer[i] = matrix_buffer[i+1];
	  			  }
	  			  matrix_buffer[MAX_LED_MATRIX - 1] = temp;
	  			  setTimer(500, SHIFT);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
  };
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
