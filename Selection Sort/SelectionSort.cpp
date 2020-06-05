#include<iostream>

using namespace std;
int main()
{
    int n,a[100],temp,mini,i,j;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        mini=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[mini])
            {
              mini=j;         //selecting the minimum element in an array
            }
        }
        temp=a[i];
        a[i]=a[mini];
        a[mini]=temp;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }

    return 0;

}

