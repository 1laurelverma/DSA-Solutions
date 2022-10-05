#include <iostream>
using namespace std;
void merge(int a[],int p,int q,int r) 
{
    int m=q-p+1;
    int n=r-q;
    int A[m],B[n];
    for(int i=0;i<m;i++)
    {
        A[i]=a[p+i];
    }
    for(int i=0;i<n;i++)
    {
        B[i]=a[q+1+i];
    }
    int i, j, k;
    i=0;j=0;k=p;
    cout<<p<<"\n";
    while(i<m&&j<n) 
    {
    if(A[i]<=B[j]) 
    {
        a[k]=A[i];
        i++;
    } 
    else 
    {
        a[k]=B[j];
        j++;
    }
    k++;
  }
    while(i<m) 
    {
        a[k]=A[i];
        i++;
        k++;
    }

    while(j<n) 
    {
        a[k]=B[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int l,int r) {
  if (l < r) {
    int m =l+(r-l)/2;
    mergeSort(a,l,m);
    mergeSort(a,m + 1,r);
    merge(a,l,m,r);
  }
}

void display(int n,int a[]){
    for (int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}
int main() {
    int n;
    cout<<"Enter size:";
    cin>>n;
    int a[n];
    cout<<"Enter value:";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    cout<<"Sorted array:";
    display(n,a);
    return 0;
}
