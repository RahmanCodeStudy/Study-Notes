#include <stdio.h>
#include <string.h>

void printValues(float values[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf(" %.3f", values[i]);
    }
    printf("\n");
}

int findLastIndexOfValue(float values[], int size, float v)
{
    for(int i = size - 1; i > 0 ; i--)
    {
        if(values[i] == v)
        {
            printf("Value found at index %i in array.\n", i);
            return i;
        }
    }
    printf("Value not found in array!\n");
    return -1;
}

float maxElement(float values[], int size)
{
    float max = values[0];
    
    for(int i = 0; i < size; i++)
    {
        if(values[i] > max)
        {
            max = values[i];
        }
    }
    printf("Max: %.3f\n", max);
}

void replaceElement(float values[], int i, float v)
{
    values[i] = v;
}

void sortOnValue(float values[], int size)
{
    float temp = 0;
    int swap = 0;
    
    do
    {
        swap = 0;
        for(int i = 0; i < size; i++)
        {
            if(values[i] > values[i+1])
            {
                temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swap = 1;
            }
        }
    }
    while(swap != 0);
}

int main(void)
{
    char cmd;
    float find = 0.0;
    int index = 0;
    float value = 0.0;
    
    float var[10] = {1.5, 2.2, 7.3, 9.2, 7.4, 7.5, -8.0, 1.5, 12};
    
    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        switch(cmd)
        {
            case 'q':
            break;
            
            case 'p':
            printf("Values:");
            printValues(var, 10);
            break;
            
            case 'f':
            printf("Find value: ");
            scanf(" %f", &find);
            findLastIndexOfValue(var, 10, find);
            break;
            
            case 'm':
            maxElement(var, 10);
            break;
            
            case 'r':
            printf("Replace (index): ");
            scanf(" %i", &index);
            if(index < 0 || index > 9)
            {
              do
              {
                printf("Error: index exceeds bound of array.\n");
                printf("Replace (index): ");
                scanf(" %i", &index);
                  
              }
              while(index < 0 || index > 9);  
            }
            printf("Replace (value): ");
            scanf(" %f", &value);
            replaceElement(var, index, value);
            break;
            
            case 's':
            sortOnValue(var, 10);
            break;
            
        }
    }
    while(cmd != 'q');
    return 0;
}
