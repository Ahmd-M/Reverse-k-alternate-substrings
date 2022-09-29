#include <stdio.h>

int read(char S[]);
void clear(char S[]);
int length(char S[]);
void treatment(char S[], int k);
void treatment_2(char portion[], char S[], int loc);

void main()
{
    char S[100];
    int K = read(S);
    treatment(S, K);
    puts(S);
}

void treatment_2(char portion[], char S[], int loc)
{
    // Reverse portion
    char aux;
    int i = 0, k = length(portion), j = k - 1;

    while (i < j)
    {
        aux = portion[j];
        portion[j--] = portion[i];
        portion[i++] = aux;
    }

    // Copy portion to S - (replace old portion with new portion)
    int start = loc - k, end = loc;
    for (i = start; i < end; i++)
        S[i] = portion[i - start];
}

void treatment(char S[], int k)
{
    char por[k]; // portion
    for (int i = 0; S[i]; i++)
    {
        por[i % k] = S[i];
        if ((i + 1) % k == 0 || S[i + 1] == '\0')
        {
            treatment_2(por, S, i + 1); // Reverse portion & copy it to S}
            clear(por);
        }
    }
}

int read(char S[])
{
    gets(S);
    int K;
    do
    {
        scanf("%d", &K);
    } while (K >= length(S) || K <= 0);
    return K;
}

int length(char S[])
{
    int i = 0;
    while (S[i])
        i++;
    return i;
}

void clear(char S[])
{
    for (int i = 0; S[i]; i++)
        S[i] = '\0';
}

/*

Input:
------
S = My name is Antoun Yaacoub
k = 4

S = My name is Antoun Yaacoub
k = 5


Output:
-------
n yM emaA siuotnaY nuocab

an yMsi emotnA aY nubuoca

*/
