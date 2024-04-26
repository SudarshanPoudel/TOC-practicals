// Simulating DFA that accepts strings ending with 01.

#include <stdio.h>

int main()
{
    char str[20], state = 'a';
    int i;
    printf("Enter the string to be checked : ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        switch (state)
        {
        case 'a':
            if (str[i] == '0')
                state = 'b';
            else if (str[i] == '1')
                state = 'a';
            break;

        case 'b':
            if (str[i] == '0')
                state = 'b';
            else if (str[i] == '1')
                state = 'c';
            break;

        case 'c':
            if (str[i] == '0')
                state = 'b';
            else if (str[i] == '1')
                state = 'a';
            break;
        }
    }
    if (state == 'c')
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}