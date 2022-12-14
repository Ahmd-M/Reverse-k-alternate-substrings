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
    // Reverse "portion"
    char aux;
    int i = 0, k = length(portion), j = k - 1;

    while (i < j)
    {
        aux = portion[j];
        portion[j--] = portion[i];
        portion[i++] = aux;
    }

    // Copy "portion" to S - (replaces substring with its reverse)
    int start = loc - k, end = loc;
    for (i = start; i < end; i++)
        S[i] = portion[i - start];
}

void treatment(char S[], int k)
{
    char portion[k]; // substring
    for (int i = 0, u=0; S[i]; i++)
    {
        portion[i % k] = S[i];
        u = i+1;
        if (u % k == 0 || S[u] == '\0')
        {
            treatment_2(portion, S, u); // Reverses "portion" & copies it to "S" from index u-k to u-1
            clear(portion);
        }
    }
}

int read(char S[]) // Takes input (string S + integer K)
{
    gets(S);
    int K;
    do
    {
        scanf("%d", &K);
    } while (K >= length(S) || K <= 0);
    return K;
}

int length(char S[]) // Returns length of a string
{
    int i = 0;
    while (S[i])
        i++;
    return i;
}

void clear(char S[]) // Clears a string <==> all elements = '\0'
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
