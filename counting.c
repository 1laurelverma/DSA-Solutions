#include<stdio.h>


int countingsort(int arr[], int size,int range)
{
    int indexarr[range];
    int cumalativesum[range];
    for(int i=0;i<range;i++)
    {
        indexarr[i]=0;
        cumalativesum[i]=0;
    }

    for(int i=0;i<size;i++)
    {
        int value=arr[i];
        indexarr[value]=indexarr[value]+1;
    }

    

    for(int i=0;i<range;i++)
    {
        cumalativesum[i]=cumalativesum[i-1]+indexarr[i];
    }

    int ray=size;

    int outputarray[ray];
    
    for(int i=ray-1;i>=0;i--)
    {
        int key=arr[i];
        int findex=cumalativesum[key];
        outputarray[findex-1]=key;
        --cumalativesum[key];
    }

    displayarray(outputarray,size);
}















int displayarray(int arr[],int size)
{
    printf("the output array is\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

}





void main()
{
    printf("enter size\n");
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("enter elements\n");
    for(int i=0;i<size;i++)
    {
        int val;
        scanf("%d",&val);
        arr[i]=val;
    }

    int range;

    printf("enter the range\n");
    scanf("%d",&range);

    countingsort(arr , size,range);



}