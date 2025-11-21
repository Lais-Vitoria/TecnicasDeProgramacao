#include <stdio.h>

int main()
{
    int N;

    scanf("%d", &N);

    for (int i = 0; i <= N; i++)
    {
        int Num;
        scanf("%d", &Num);

        if (Num % 2 == 0)
        {
            printf("\nEVEN");
        }
        else
        {
            printf("\nODD");
        }
        if (Num > 0 )
        {
            printf("POSITIVE\n");
        }
        else
        {
            Printf("NEGATIVE\n");
        }
        
        
    }
    
}