/* USER CODE BEGIN Header */
/* USER CODE END Header */

#include "main.h"

/* =========================
 * Exercise selection
 * ========================= */
#define CURRENT_EXERCISE 10

/* =========================
 * GPIO labels from IOC
 * ========================= */
#define L0_Pin          GPIO_PIN_4
#define L0_GPIO_Port    GPIOA
#define L1_Pin          GPIO_PIN_5
#define L1_GPIO_Port    GPIOA
#define L2_Pin          GPIO_PIN_6
#define L2_GPIO_Port    GPIOA
#define L3_Pin          GPIO_PIN_7
#define L3_GPIO_Port    GPIOA
#define L4_Pin          GPIO_PIN_8
#define L4_GPIO_Port    GPIOA
#define L5_Pin          GPIO_PIN_9
#define L5_GPIO_Port    GPIOA
#define L6_Pin          GPIO_PIN_10
#define L6_GPIO_Port    GPIOA
#define L7_Pin          GPIO_PIN_11
#define L7_GPIO_Port    GPIOA
#define L8_Pin          GPIO_PIN_12
#define L8_GPIO_Port    GPIOA
#define L9_Pin          GPIO_PIN_13
#define L9_GPIO_Port    GPIOA
#define L10_Pin         GPIO_PIN_14
#define L10_GPIO_Port   GPIOA
#define L11_Pin         GPIO_PIN_15
#define L11_GPIO_Port   GPIOA

#define a_Pin           GPIO_PIN_0
#define a_GPIO_Port     GPIOB
#define b_Pin           GPIO_PIN_1
#define b_GPIO_Port     GPIOB
#define c_Pin           GPIO_PIN_2
#define c_GPIO_Port     GPIOB
#define d_Pin           GPIO_PIN_3
#define d_GPIO_Port     GPIOB
#define e_Pin           GPIO_PIN_4
#define e_GPIO_Port     GPIOB
#define f_Pin           GPIO_PIN_5
#define f_GPIO_Port     GPIOB
#define g_Pin           GPIO_PIN_6
#define g_GPIO_Port     GPIOB

#define GREEN1_Pin      GPIO_PIN_10
#define GREEN1_GPIO_Port GPIOB
#define YELLOW1_Pin     GPIO_PIN_11
#define YELLOW1_GPIO_Port GPIOB
#define RED1_Pin        GPIO_PIN_12
#define RED1_GPIO_Port  GPIOB

#define GREEN2_Pin      GPIO_PIN_13
#define GREEN2_GPIO_Port GPIOB
#define YELLOW2_Pin     GPIO_PIN_14
#define YELLOW2_GPIO_Port GPIOB
#define RED2_Pin        GPIO_PIN_15
#define RED2_GPIO_Port  GPIOB

/* Aliases matching the original source */
#define G1_Pin          GREEN1_Pin
#define G1_GPIO_Port    GREEN1_GPIO_Port
#define Y1_Pin          YELLOW1_Pin
#define Y1_GPIO_Port    YELLOW1_GPIO_Port
#define R1_Pin          RED1_Pin
#define R1_GPIO_Port    RED1_GPIO_Port

#define G2_Pin          GREEN2_Pin
#define G2_GPIO_Port    GREEN2_GPIO_Port
#define Y2_Pin          YELLOW2_Pin
#define Y2_GPIO_Port    YELLOW2_GPIO_Port
#define R2_Pin          RED2_Pin
#define R2_GPIO_Port    RED2_GPIO_Port

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

static void Ex1(void);
static void Ex2(void);
static void Ex3(void);
static void Ex4(void);
static void Ex5(void);
static void Ex6(void);
static void Ex7(void);
static void Ex8(void);
static void Ex9(void);
static void Ex10(void);

static void display7SEG(int num);
static void clearAllClock(void);
static void setNumberOnClock(int num);
static void clearNumberOnClock(int num);

/* =========================
 * Main
 * ========================= */
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    switch (CURRENT_EXERCISE)
    {
        case 1:  Ex1();  break;
        case 2:  Ex2();  break;
        case 3:  Ex3();  break;
        case 4:  Ex4();  break;
        case 5:  Ex5();  break;
        case 6:  Ex6();  break;
        case 7:  Ex7();  break;
        case 8:  Ex8();  break;
        case 9:  Ex9();  break;
        case 10: Ex10(); break;
        default: Ex10(); break;
    }

    while (1)
    {
    }
}

/* =========================
 * Ex1
 * ========================= */
static void Ex1(void)
{
    int STATUS = 3;

    while (1)
    {
        switch (STATUS)
        {
            case 0:
                HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
                STATUS = 3;
                break;

            case 1:
                STATUS--;
                break;

            case 2:
                HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
                STATUS--;
                break;

            case 3:
                STATUS--;
                break;

            default:
                STATUS = 3;
                break;
        }

        HAL_Delay(1000);
    }
}

/* =========================
 * Ex2
 * ========================= */
static void Ex2(void)
{
    int STATUS = 10;

    while (1)
    {
        switch (STATUS)
        {
            /* RED: 5 seconds */
            case 10:
                HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
                STATUS = 9;
                break;

            case 9:
            case 8:
            case 7:
            case 6:
                STATUS--;
                break;

            /* YELLOW: 2 seconds */
            case 5:
                HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
                STATUS = 4;
                break;

            case 4:
                STATUS--;
                break;

            /* GREEN: 3 seconds */
            case 3:
                HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
                STATUS = 13;
                break;

            case 13:
            case 12:
            case 11:
                STATUS--;
                break;

            default:
                STATUS = 10;
                break;
        }

        HAL_Delay(1000);
    }
}

/* =========================
 * Ex3
 * ========================= */
static void Ex3(void)
{
    int STATUS = 10;

    while (1)
    {
        switch (STATUS)
        {
            /* R1 + G2 */
            case 10:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
                STATUS--;
                break;

            case 9:
            case 8:
                STATUS--;
                break;

            /* Y1 + R2 */
            case 7:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
                STATUS--;
                break;

            case 6:
                STATUS--;
                break;

            /* R1 + G2 */
            case 5:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);
                STATUS = 4;
                break;

            case 4:
            case 3:
                STATUS--;
                break;

            /* R1 + Y2 */
            case 2:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);
                STATUS = 10;
                break;

            case 1:
                STATUS--;
                break;

            default:
                STATUS = 10;
                break;
        }

        HAL_Delay(1000);
    }
}

/* =========================
 * Ex4
 * ========================= */
static void display7SEG(int num)
{
    switch (num)
    {
        case 0:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
            break;

        case 1:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
            break;

        case 2:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        case 3:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        case 4:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        case 5:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        case 6:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        case 7:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
            break;

        case 8:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        case 9:
            HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
            break;

        default:
            break;
    }
}

static void Ex4(void)
{
    int counter = 0;

    while (1)
    {
        if (counter >= 10)
        {
            counter = 0;
        }

        display7SEG(counter++);
        HAL_Delay(1000);
    }
}

/* =========================
 * Ex5
 * ========================= */
static void Ex5(void)
{
    int counter = 3;
    int STATUS = 0;

    while (1)
    {
        switch (STATUS)
        {
            /* GROUP 1 GREEN - GROUP 2 RED */
            case 0:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_RESET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);

                counter = 3;
                display7SEG(counter);
                STATUS++;
                break;

            case 1:
                counter = 2;
                display7SEG(counter);
                STATUS++;
                break;

            case 2:
                counter = 1;
                display7SEG(counter);
                STATUS++;
                break;

            /* GROUP 1 YELLOW - GROUP 2 RED */
            case 3:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);

                counter = 2;
                display7SEG(counter);
                STATUS++;
                break;

            case 4:
                counter = 1;
                display7SEG(counter);
                STATUS++;
                break;

            /* GROUP 1 RED - GROUP 2 GREEN */
            case 5:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_RESET);

                counter = 3;
                display7SEG(counter);
                STATUS++;
                break;

            case 6:
                counter = 2;
                display7SEG(counter);
                STATUS++;
                break;

            case 7:
                counter = 1;
                display7SEG(counter);
                STATUS++;
                break;

            /* GROUP 1 RED - GROUP 2 YELLOW */
            case 8:
                HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(Y1_GPIO_Port, Y1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(G1_GPIO_Port, G1_Pin, GPIO_PIN_SET);

                HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(Y2_GPIO_Port, Y2_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(G2_GPIO_Port, G2_Pin, GPIO_PIN_SET);

                counter = 2;
                display7SEG(counter);
                STATUS++;
                break;

            case 9:
                counter = 1;
                display7SEG(counter);
                STATUS = 0;
                break;

            default:
                STATUS = 0;
                break;
        }

        HAL_Delay(1000);
    }
}

/* =========================
 * Ex6
 * ========================= */
static void Ex6(void)
{
    int STATUS = 0;

    HAL_GPIO_WritePin(GPIOA,
                      L0_Pin | L1_Pin | L2_Pin | L3_Pin |
                      L4_Pin | L5_Pin | L6_Pin | L7_Pin |
                      L8_Pin | L9_Pin | L10_Pin | L11_Pin,
                      GPIO_PIN_SET);

    while (1)
    {
        switch (STATUS)
        {
            case 0:
                HAL_GPIO_WritePin(GPIOA, L0_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 1:
                HAL_GPIO_WritePin(GPIOA, L0_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L1_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 2:
                HAL_GPIO_WritePin(GPIOA, L1_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L2_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 3:
                HAL_GPIO_WritePin(GPIOA, L2_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L3_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 4:
                HAL_GPIO_WritePin(GPIOA, L3_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L4_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 5:
                HAL_GPIO_WritePin(GPIOA, L4_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L5_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 6:
                HAL_GPIO_WritePin(GPIOA, L5_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L6_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 7:
                HAL_GPIO_WritePin(GPIOA, L6_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L7_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 8:
                HAL_GPIO_WritePin(GPIOA, L7_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L8_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 9:
                HAL_GPIO_WritePin(GPIOA, L8_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L9_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 10:
                HAL_GPIO_WritePin(GPIOA, L9_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L10_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 11:
                HAL_GPIO_WritePin(GPIOA, L10_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L11_Pin, GPIO_PIN_RESET);
                STATUS++;
                break;

            case 12:
                HAL_GPIO_WritePin(GPIOA, L11_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOA, L0_Pin, GPIO_PIN_RESET);
                STATUS = 1;
                break;

            default:
                STATUS = 0;
                break;
        }

        HAL_Delay(1000);
    }
}

/* =========================
 * Ex7 / Ex8 / Ex9 helpers
 * ========================= */
static void clearAllClock(void)
{
    HAL_GPIO_WritePin(GPIOA,
                      L0_Pin | L1_Pin | L2_Pin | L3_Pin |
                      L4_Pin | L5_Pin | L6_Pin | L7_Pin |
                      L8_Pin | L9_Pin | L10_Pin | L11_Pin,
                      GPIO_PIN_SET);
}

static void setNumberOnClock(int num)
{
    switch (num)
    {
        case 0:  HAL_GPIO_WritePin(L0_GPIO_Port,  L0_Pin,  GPIO_PIN_RESET); break;
        case 1:  HAL_GPIO_WritePin(L1_GPIO_Port,  L1_Pin,  GPIO_PIN_RESET); break;
        case 2:  HAL_GPIO_WritePin(L2_GPIO_Port,  L2_Pin,  GPIO_PIN_RESET); break;
        case 3:  HAL_GPIO_WritePin(L3_GPIO_Port,  L3_Pin,  GPIO_PIN_RESET); break;
        case 4:  HAL_GPIO_WritePin(L4_GPIO_Port,  L4_Pin,  GPIO_PIN_RESET); break;
        case 5:  HAL_GPIO_WritePin(L5_GPIO_Port,  L5_Pin,  GPIO_PIN_RESET); break;
        case 6:  HAL_GPIO_WritePin(L6_GPIO_Port,  L6_Pin,  GPIO_PIN_RESET); break;
        case 7:  HAL_GPIO_WritePin(L7_GPIO_Port,  L7_Pin,  GPIO_PIN_RESET); break;
        case 8:  HAL_GPIO_WritePin(L8_GPIO_Port,  L8_Pin,  GPIO_PIN_RESET); break;
        case 9:  HAL_GPIO_WritePin(L9_GPIO_Port,  L9_Pin,  GPIO_PIN_RESET); break;
        case 10: HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_RESET); break;
        case 11: HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_RESET); break;
        default: break;
    }
}

static void clearNumberOnClock(int num)
{
    switch (num)
    {
        case 0:  HAL_GPIO_WritePin(L0_GPIO_Port,  L0_Pin,  GPIO_PIN_SET); break;
        case 1:  HAL_GPIO_WritePin(L1_GPIO_Port,  L1_Pin,  GPIO_PIN_SET); break;
        case 2:  HAL_GPIO_WritePin(L2_GPIO_Port,  L2_Pin,  GPIO_PIN_SET); break;
        case 3:  HAL_GPIO_WritePin(L3_GPIO_Port,  L3_Pin,  GPIO_PIN_SET); break;
        case 4:  HAL_GPIO_WritePin(L4_GPIO_Port,  L4_Pin,  GPIO_PIN_SET); break;
        case 5:  HAL_GPIO_WritePin(L5_GPIO_Port,  L5_Pin,  GPIO_PIN_SET); break;
        case 6:  HAL_GPIO_WritePin(L6_GPIO_Port,  L6_Pin,  GPIO_PIN_SET); break;
        case 7:  HAL_GPIO_WritePin(L7_GPIO_Port,  L7_Pin,  GPIO_PIN_SET); break;
        case 8:  HAL_GPIO_WritePin(L8_GPIO_Port,  L8_Pin,  GPIO_PIN_SET); break;
        case 9:  HAL_GPIO_WritePin(L9_GPIO_Port,  L9_Pin,  GPIO_PIN_SET); break;
        case 10: HAL_GPIO_WritePin(L10_GPIO_Port, L10_Pin, GPIO_PIN_SET); break;
        case 11: HAL_GPIO_WritePin(L11_GPIO_Port, L11_Pin, GPIO_PIN_SET); break;
        default: break;
    }
}

/* =========================
 * Ex7
 * ========================= */
static void Ex7(void)
{
    clearAllClock();

    while (1)
    {
        for (int i = 0; i < 12; ++i)
        {
            clearAllClock();
            setNumberOnClock(i);
            HAL_Delay(1000);
        }
    }
}

/* =========================
 * Ex8
 * ========================= */
static void Ex8(void)
{
    clearAllClock();

    while (1)
    {
        for (int i = 0; i < 12; ++i)
        {
            setNumberOnClock(i);
            HAL_Delay(1000);
            clearNumberOnClock(i);
        }
    }
}

/* =========================
 * Ex9
 * ========================= */
static void Ex9(void)
{
    clearAllClock();

    while (1)
    {
        for (int i = 0; i < 12; ++i)
        {
            clearAllClock();
            setNumberOnClock(i);
            HAL_Delay(500);
        }
    }
}

/* =========================
 * Ex10
 * 12 LED analog clock
 *   - second hand: 5 seconds/LED
 *   - minute hand: 5 minutes/LED
 *   - hour hand: 1 hour/LED
 * Three LEDs are allowed to be ON at once.
 * ========================= */
static void Ex10(void)
{
    int hour = 0;
    int minute = 0;
    int second = 0;

    while (1)
    {
        clearAllClock();

        /* Hour hand */
        setNumberOnClock(hour);

        /* Minute hand: one LED represents 5 minutes */
        setNumberOnClock(minute / 5);

        /* Second hand: one LED represents 5 seconds */
        setNumberOnClock(second / 5);

        HAL_Delay(1000);

        second++;

        if (second >= 60)
        {
            second = 0;
            minute++;

            if (minute >= 60)
            {
                minute = 0;
                hour++;

                if (hour >= 12)
                {
                    hour = 0;
                }
            }
        }
    }
}

/* =========================
 * System Clock
 * From IOC:
 *   SYS clock = 8 MHz
 *   APB1 = 8 MHz
 *   APB2 = 8 MHz
 *   no PLL
 * ========================= */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    __HAL_RCC_AFIO_CLK_ENABLE();

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK |
        RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 |
        RCC_CLOCKTYPE_PCLK2;

    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}

/* =========================
 * GPIO initialization
 * All configured as push-pull outputs.
 * Initial state: SET = OFF.
 * ========================= */
static void MX_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /* Initial OFF state */
    HAL_GPIO_WritePin(GPIOA,
                      L0_Pin | L1_Pin | L2_Pin | L3_Pin |
                      L4_Pin | L5_Pin | L6_Pin | L7_Pin |
                      L8_Pin | L9_Pin | L10_Pin | L11_Pin,
                      GPIO_PIN_SET);

    HAL_GPIO_WritePin(GPIOB,
                      a_Pin | b_Pin | c_Pin | d_Pin |
                      e_Pin | f_Pin | g_Pin |
                      GREEN1_Pin | YELLOW1_Pin | RED1_Pin |
                      GREEN2_Pin | YELLOW2_Pin | RED2_Pin,
                      GPIO_PIN_SET);

    /* PA4..PA15 */
    GPIO_InitStruct.Pin = L0_Pin | L1_Pin | L2_Pin | L3_Pin |
                          L4_Pin | L5_Pin | L6_Pin | L7_Pin |
                          L8_Pin | L9_Pin | L10_Pin | L11_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /* PB0..PB6 */
    GPIO_InitStruct.Pin = a_Pin | b_Pin | c_Pin | d_Pin |
                          e_Pin | f_Pin | g_Pin;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* PB10..PB15 */
    GPIO_InitStruct.Pin = GREEN1_Pin | YELLOW1_Pin | RED1_Pin |
                          GREEN2_Pin | YELLOW2_Pin | RED2_Pin;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /*
     * IOC contains No_Debug, so these JTAG-related pins are intentionally
     * used as GPIO outputs:
     *   PA13, PA14, PA15, PB3, PB4
     *
     * AFIO remap is disabled by the normal No_Debug configuration.
     */
    __HAL_RCC_AFIO_CLK_ENABLE();
#ifdef __HAL_AFIO_REMAP_SWJ_DISABLE
    __HAL_AFIO_REMAP_SWJ_DISABLE();
#endif
}

/* =========================
 * Error handler
 * ========================= */
void Error_Handler(void)
{
    __disable_irq();

    while (1)
    {
        /* Stay here on initialization failure. */
    }
}
