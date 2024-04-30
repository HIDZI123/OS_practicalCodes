#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5;
int x = 0;

void Producer(void)
{
    --mutex;

    ++full;
    --empty;

    x++;
    printf("Producer prodeuced item no :%d ", x);

    ++mutex;
}

void Consumer(void)
{
    --mutex;

    --full;
    ++empty;

    printf("Cosnumer coonsumed item no :%d ", x);
    x--;
    ++mutex;
}

int main()
{
#pragma omp critical

int n;

 printf("\n1.Produce \n2.Consume \n3.Exit \n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if (mutex == 1 && empty != 0)
            {
                Producer();
            }
            else
            {
                printf("The buffer is full\n ");
            }
            break;

        case 2:
            if (mutex == 1 && full != 0)
            {
                Consumer();
            }
            else
            {
                printf("The buffer is empty");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
}
