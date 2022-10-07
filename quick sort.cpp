#include <iostream>  
using namespace std;  
int partition (int a[],int start,int end)  
{  
    int pivot=a[end];
    int i=(start-1);  
    for (int j=start;j<=end-1;j++)  
    {  
        if (a[j]<pivot)  
        {  
            i++;
            int t=a[i];  
            a[i]=a[j];  
            a[j]=t;  
        }  
    }  
    int t=a[i+1];  
    a[i+1]=a[end];  
    a[end]=t;  
    return(i+1);  
}  
void quick_sort(int a[],int start,int end)
{  
    if(start<end)  
    {  
        int p=partition(a,start,end);
        quick_sort(a,start,p-1);  
        quick_sort(a,p+1,end);  
    }  
}  
void display(int n,int a[])
{
    for (int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
int main()  
{  
    int n;
    cout<<"Enter size:";
    cin>>n;
    int a[n];
    cout<<"Enter value:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);  
    cout<<"Sorted array:";    
    display(n,a);  
    return 0;  
} 
