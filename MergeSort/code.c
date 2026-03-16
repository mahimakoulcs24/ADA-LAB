#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int c[100000];

void merge(int low, int mid, int high, int a[])
{
    int i= low;
    int j= mid+1;
    int k= low;

    while(i<= mid && j<= high)
    {
        if(a[i]< a[j])
        {
            c[k]= a[i];
            k++;
            i++;
        }
        else
        {
            c[k]= a[j];
            k++;
            j++;
        }
    }
    while(i<= mid){
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<= high){
        c[k]=a[j];
        k++;
        j++;
    }
    for(int m= low; m<= high; m++){
        a[m]=c[m];
    }
}

void merge_sort(int low, int high, int a[])
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sort(low, mid,a);
        merge_sort(mid+1, high, a);
        merge(low, mid, high, a);
    }
}

int main()
{
    int a[100000], n, i;
    clock_t start, end;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        //printf("\nEnter element %d: ", i+1);
        //scanf("%d", &a[i]);
        a[i]= rand()%10000;
    }
    start=clock();
    merge_sort(0, n-1, a);
    end=clock();
    double time= (double)(end-start)*1000/CLOCKS_PER_SEC;
    //printf("Sorted array is: \n");
    //for(int i=0; i<n; i++){
    //    printf("%d\t",a[i] );
    //}
    printf("\nTime taken in ms : %f", time);
}
