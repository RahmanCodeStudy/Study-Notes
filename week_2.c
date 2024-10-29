#include <stdio.h>
#include <math.h>

float absolute(float a)
{
    return sqrt(a*a);
}

int rounding(float a)
{
    return (int)roundf(a);
}

float power(float x, float y)
{
    return pow(x,y);
}

int main(void)
{
    char cmd;
    int value = 0.0;
    float result = 0.0;
    
    printf("** Calculator **\n");
    
    do
    {
        printf("Operation? ");
        scanf(" %c", &cmd);
        switch(cmd)
        {
            case '=':
            printf("Result = %.2f\n", result);
            break;
            
            case '+':
            printf("Value? ");
            scanf(" %d", &value);
            printf("Input: %d\n", value);
            result = result + value;
            printf("Result = %.2f\n", result);
            break;
            
            case '-':
            printf("Value? ");
            scanf(" %d", &value);
            printf("Input: %d\n", value);
            result = result - value;
            printf("Result = %.2f\n", result);
            break;
            
            case '*':
            printf("Value? ");
            scanf(" %d", &value);
            printf("Input: %d\n", value);
            result = result * value;
            printf("Result = %.2f\n", result);
            break;
            
            case '/':
            printf("Value? ");
            scanf(" %d", &value);
            printf("Input: %d\n", value);
            result = result / value;
            printf("Result = %.2f\n", result);
            break;
            
            case 'a':
            result = absolute(value);
            printf("Result = %.2f\n", result);
            break;
            
            case 'r':
            result = rounding(result);
            printf("Result = %.2f\n", result);
            break;
            
            case 'p':
            printf("Value? ");
            scanf(" %d", &value);
            printf("Input: %d\n", value);
            result = power(result, value);
            printf("Result = %.2f\n", result);
            break;
            
        }
        
    } while(cmd != '=');
    
    return 0;
}
