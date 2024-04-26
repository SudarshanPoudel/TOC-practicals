// Turing machine That accepts strings with WW^r

#include <stdio.h>
#define MAX 100

char tape[MAX];
int head = 0;
char state = 'A';

void fillTape()
{
    char str[MAX];
    int i = 0;
    printf("Enter the string to be checked : ");
    scanf("%s", str);
    while (str[i] != '\0')
    {
        tape[i] = str[i];
        i++;
    }
    while (i < MAX)
    {
        tape[i] = 'b';
        i++;
    }
}

void transition(char nestState, char writeChar, char direction)
{
    state = nestState;
    tape[head] = writeChar;
    if (direction == 'R')
        head++;
    else
        head--;
}

int main()
{
    fillTape();
    int i, flag = 1;
    while (state != 'G' && flag != 0)
    {
        switch (state)
        {
        case 'A':
            if (tape[head] == '0')
                transition('B', 'X', 'R');
            else if (tape[head] == '1')
                transition('E', 'Y', 'R');
            else if (tape[head] == 'b' || tape[head] == 'X' || tape[head] == 'Y')
                transition('G', tape[head], 'R');
            else
                flag = 0;
            break;

        case 'B':
            if (tape[head] == '0' || tape[head] == '1')
                transition('B', tape[head], 'R');
            else if (tape[head] == 'b' || tape[head] == 'X' || tape[head] == 'Y')
                transition('C', tape[head], 'L');
            else
                flag = 0;
            break;

        case 'C':
            if (tape[head] == '0')
                transition('D', 'X', 'L');
            else if (tape[head] == 'X')
                transition('G', 'X', 'L');
            else
                flag = 0;
            break;

        case 'D':
            if (tape[head] == '0' || tape[head] == '1')
                transition('D', tape[head], 'L');
            else if (tape[head] == 'X' || tape[head] == 'Y')
                transition('A', tape[head], 'R');
            else
                flag = 0;
            break;

        case 'E':
            if (tape[head] == '0' || tape[head] == '1')
                transition('E', tape[head], 'R');
            else if (tape[head] == 'b' || tape[head] == 'X' || tape[head] == 'Y')
                transition('F', tape[head], 'L');
            else
                flag = 0;
            break;

        case 'F':
            if (tape[head] == '1')
                transition('D', 'Y', 'L');
            else if (tape[head] == 'Y')
                transition('G', 'Y', 'L');
            else
                flag = 0;
            break;
        }
    }

    if (state == 'G' && flag == 1)
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}