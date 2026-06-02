#include <stdio.h>
#define LEFT 0
#define RIGHT 1

int getMobile(int a[], int dir[], int n)
{
    int mobile = 0;
    int mobileIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (dir[i] == LEFT && i != 0 && a[i] > a[i - 1])
        {
            if (a[i] > mobile)
            {
                mobile = a[i];
                mobileIndex = i;
            }
        }
        if (dir[i] == RIGHT && i != n - 1 && a[i] > a[i + 1])
        {
            if (a[i] > mobile)
            {
                mobile = a[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

void printPermutation(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n)
{
    int a[n];
    int dir[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        dir[i] = LEFT;
    }
    printPermutation(a, n);
    while (1)
    {
        int mobileIndex = getMobile(a, dir, n);
        if (mobileIndex == -1)
            break; // No mobile element left
        int mobile = a[mobileIndex];
        if (dir[mobileIndex] == LEFT)
        {
            int temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex - 1];
            a[mobileIndex - 1] = temp;
            int dtemp = dir[mobileIndex];
            dir[mobileIndex] = dir[mobileIndex - 1];
            dir[mobileIndex - 1] = dtemp;
            mobileIndex--;
        }
        else
        {
            int temp = a[mobileIndex];
            a[mobileIndex] = a[mobileIndex + 1];
            a[mobileIndex + 1] = temp;
            int dtemp = dir[mobileIndex];
            dir[mobileIndex] = dir[mobileIndex + 1];
            dir[mobileIndex + 1] = dtemp;
            mobileIndex++;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] > mobile)
                dir[i] = !dir[i];
        }
        printPermutation(a, n);
    }
}

int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
