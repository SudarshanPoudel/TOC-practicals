// NFA Accepting string starting with 01

#include <stdio.h>

int main()
{
    char str[50], state = 'a';
    int i, flag = 1;
    printf("Enter the string to be checked : ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0' && flag != 0; i++)
    {
        switch (state)
        {
        case 'a':
            if (str[i] == '0')
                state = 'b';
            else
                flag = 0;
            break;
        case 'b':
            if (str[i] == '1')
                state = 'c';
            else
                flag = 0;
            break;
        case 'c':
            if (str[i] == '0' || str[i] == '1')
                state = 'c';
            else
                flag = 0;
            break;
        }
    }
    if (state == 'c' && flag == 1)
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}