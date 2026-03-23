#include<stdio.h>
#include<time.h>

void swap(int *a , int *b)
{
    int *temp= a;
    *a=*b;
    *b= *temp;

}

int partition(int low, int high, int a[])
{
    int i= low;
    int j= high+1;
    int pivot = a[low];
    while(i<j)
    {
        do
        {
            i=i+1;
        }while(pivot>=a[i]);
        do
        {
            j=j-1;
        }while(pivot < a[j]);

        if(i<j)
        {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}

void quick_sort(int low, int high, int a[])
{
    if(low< high)
    {
        int j= partition(low, high, a);
        quick_sort(low, j-1, a);
        quick_sort(j+1, high, a);
    }
}

int main()
{
    int a[100000], n, i;
    clock_t start, end;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &a[i]);
        //a[i]= rand()%10000;
    }
    start=clock();
    quick_sort(0, n-1, a);
    end=clock();
    double time= (double)(end-start)*1000/CLOCKS_PER_SEC;
    printf("Sorted array is: \n");
    for(int i=0; i<n; i++){
        printf("%d\t",a[i] );
    }
    printf("\nTime taken in ms : %f", time);
}
