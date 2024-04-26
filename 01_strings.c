// Program to generate all Prefix, Suffix and Substrings of given string

#include <stdio.h>
#include <string.h>

void printAllPrefix(char *str, int len)
{
    int i, j;
    printf("\nPrefixes\n");
    for (i = 0; i < len; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%c", str[j]);
        }
        printf("\t");
    }
}
void printAllSuffix(char *str, int len)
{
    int i, j;
    printf("\nSuffixes\n");
    for (i = len - 1; i >= 0; i--)
    {
        for (j = i; j < len; j++)
        {
            printf("%c", str[j]);
        }
        printf("\t");
    }
}
void printAllSubstrings(char *str, int len)
{
    int i, j, k;
    printf("\nSubstrings\n");
    for (i = 0; i < len; i++)
    {
        for (j = i; j < len; j++)
        {
            for (k = i; k <= j; k++)
            {
                printf("%c", str[k]);
            }
            printf("\t");
        }
        printf("\n");
    }
}

int main()
{
    char str[20];
    printf("Enter any string : ");
    scanf("%s", str);
    int len = strlen(str);
    printAllPrefix(str, len);
    printAllSuffix(str, len);
    printAllSubstrings(str, len);
    return 0;
}