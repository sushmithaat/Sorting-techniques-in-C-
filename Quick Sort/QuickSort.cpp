#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

class quick
{
	int low,high,temp;
	public: int partition(int *,int,int);
		      void qsort(int *,int,int);
};
void quick::qsort(int a[],int low,int high)
{
	if(low<high)
	{
		int j=partition(a,low,high);
		qsort(a,low,j-1);
		qsort(a,j+1,high);
	}
}
int quick::partition(int a[],int low,int high)
{
	int i=low+1,j=high,key=a[low];
	while(1)
	{
		while(i<high && a[i]<=key)
			i++;
		while(j>=low && a[j]>key)
			j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
}
int main()
{
	int *a,i,n;
	quick q;

	clock_t start,stop;

	clrscr();

	cout<<"Enter the no of elements\n";
	cin>>n;
	a=new int[n];
  
  cout<<"Enter the array elements";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
  
	start=clock();
	q.qsort(a,0,n-1);
	stop=clock();

	cout<<"\nsorted elements are\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\nTime taken="<<(stop-start)/CLK_TCK<<" sec\n";
	cout<<"Space consumed="<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(q)<<" bytes\n";
  
	return 0;
}
