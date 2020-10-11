#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class mer
{
    int low,high;
    public: void m_sort(int *,int,int);
            void s_merge(int *,int,int,int);
};
void mer::m_sort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        m_sort(a,low,mid);
        m_sort(a,mid+1,high);
        s_merge(a,low,mid,high);
    }
}
void mer::s_merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low,c[10000];

    while(i<=mid && j<=high)
    {
        if(a[j]>a[i])


            c[k]=a[i];
            i=i+1;
            k=k+1;
        }
        else
        {
            c[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(i=low;i<=high;i++)
        a[i]=c[i];
}
int main()
{
    int *a,n,i;
    clock_t start,stop;
    mer m;
    
    cout<<"Enter the size of array\n";
    cin>>n;
    
    a=new int[n];
    
    cout<<"Enter the array elements are\n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    start=clock();
    m.m_sort(a,0,n-1);
    stop=clock();
    
    cout<<"\nThe sorted elements are\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"\n\ntime taken="<<(stop-start)/CLK_TCK<<" sec\n";
    cout<<"space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(m)<<" bytes\n";

    return 0;
}
