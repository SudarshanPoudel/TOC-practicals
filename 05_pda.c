// Simulating PDA that accepts strings a^n b^n.

#include <stdio.h>

char stack[50];
int top = -1;

void push(char *c)
{
    top++;
    stack[top] = c;
}

void pop()
{
    top--;
}

int main()
{
    char str[50], state = 'p';
    int i, flag = 1;
    printf("Enter the string to be checked : ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0' && flag != 0; i++)
    {
        switch (state)
        {
        case 'p':
            push('Z');
            state = 'q';
            break;
        case 'q':
            if (str[i] == 'a' && (stack[top] == 'Z' || stack[top] == 'a'))
                push('a');

            else if (str[i] == 'b')
            {
                pop();
                state = 'q';
            }
            else
                flag = 0;
            break;
        case 'r':
            if (str[i] == 'b' && stack[top] == 'a')
                pop();
            else
                flag = 0;
            break;
        }
    }
    if (stack[top] == 'Z' && flag == 1)
        printf("String is accepted\n");
    else
        printf("String is not accepted\n");
    return 0;
}
