#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 256

int findFirstOccurrence(char str[], char aChar)
{
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == aChar)
        {
            printf("'%c' found at index %i.\n", aChar, i);
            return i;
        }
    }
    printf("'%c' not found in string.\n", aChar);
    return -1;
}

void insertChar(char str[], char aChar, int index)
{
    for(int i = strlen(str); i >= index; i--) 
    {
        str[i+1] = str[i];
    }
    str[index] = aChar;
}

void replaceChars(char str[], char sChar[], char rChar)
{
    for(int i = 0; i < strlen(sChar); i++)
    {
        for(int j = 0; j < strlen(str); j++)
        {
            if(sChar[i] == str[j])
            {
                str[j] = rChar;
            }
        }
    }
}

void DoubleDutch(char str[])
{
    char result[SIZE] = "";
    for(int i = 0; i < strlen(str); i++)
    {
        if (strchr("aeiou", str[i]) != NULL) // strchr(const char *str, int c) returns a pointer to the first occurrence of character
        {
            strcat(result, "E");             // appends E to the end of string result
        }
        else if(str[i] == ' ')
        {
            strcat(result, "-ay");          // appends the string "-ay" to the end of result
        }
        else
        {
            strncat(result, &str[i], 1);    // appends one character from str[i] to the end of result
        }
    }
    strcpy(str, result);
}

int main(void)
{
    printf("** Welcome to the Double Dutch game **\n");
    
    char cmd;
    char myString[SIZE] = "charcharcharchar";
    char letter;
    char insert;
    int position = 0;
    
    char sString[SIZE] = "";
    char rCharacter;
    
    do
    {
        printf("Command? ");
        scanf(" %c", &cmd);
        
        switch(cmd)
        {
            case 'p':
            printf("String: %s\n", myString);
            break;
            
            case 's':
            printf("Please enter a string: ");
            scanf(" %[^\n]s", myString);
            break;
            
            case 'f':
            printf("Please enter a character: ");
            scanf(" %c", &letter);
            findFirstOccurrence(myString, letter);
            break;
            
            case 'i':
            printf("Which character to insert: ");
            scanf(" %c", &insert);
            do
            {
                printf("At which position: ");
                scanf(" %i", &position); 
            } 
            while(position > strlen(myString) || position < 0);
            insertChar(myString, insert, position);
            break;
            
            case 'r':
            printf("Which characters to replace: ");
            scanf(" %[^\n]s", sString);
        
            printf("Replace with character: ");
            scanf(" %c", &rCharacter); 
            for (int i = 0; i < strlen(sString); i++) 
            {
                if (sString[i] == rCharacter)
                {
                    do
                    {
                        printf("Replace with character: ");
                        scanf(" %c", &rCharacter); 
                    }
                    while(sString[i] == rCharacter);
                }
            }
            replaceChars(myString, sString, rCharacter);
            break;
            
            case 'g':
            DoubleDutch(myString);
            /*char white[] = {' '};
            char vowels[] = {'a', 'e', 'i', 'o', 'u'};
            replaceChars(myString, vowels, 'E');
            replaceChars(myString, white, '-');
            
            for(int i = 0; i < strlen(myString); i++)
            {
                if(myString[i] == '-')
                {
                    insertChar(myString, 'a', i+1);
                    insertChar(myString, 'y', i+2);
                    i += 2;
                }
            }*/
            break;
        }
    }
    while(cmd != 'p');
    
    return 0;
}
