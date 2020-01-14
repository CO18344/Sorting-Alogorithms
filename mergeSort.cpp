#include<iostream>
#include<stdlib.h>
using namespace std;

int final = 0;
void display(int arr[],int lower,int upper)
{

	for(int i= lower; i<=upper;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<"\n\n";
}
void merge(int arr[],int lower,int mid,int upper)
{
	static int count = 0;
	static int comparisons = 0;
	int sizeFirstHalf = mid - lower + 1;
	int sizeSecondHalf = upper - mid;

	int firstHalf[10000];
	int secondHalf[10000];

	firstHalf[sizeFirstHalf] = RAND_MAX;
	secondHalf[sizeSecondHalf] = RAND_MAX;

	for(int i=0;i<sizeFirstHalf;i++)
	{
		firstHalf[i]=arr[lower + i];
	}

	for(int i=0;i<sizeSecondHalf;i++)
	{
		secondHalf[i]=arr[ (mid+1) + i ];
	}

	int j=0,k=0;
	for(int i = lower; i <= upper ; i++)
	{
		if(firstHalf[j]<secondHalf[k])
		{
			arr[i] = firstHalf[j++];
		}

		else
		{
			arr[i] = secondHalf[k++];
		}
	}
	comparisons = comparisons + upper - lower + 1;
	final = comparisons;
	cout<<comparisons<<endl;
	cout<<"\n\tArray after merging "<<++count<<": ";
	display(arr,lower,upper);

}


void mergeSort(int arr[],int lower,int upper)
{
	static int count = 0;
	cout<<"\nArray at recursion "<<++count<<": ";
	display(arr,lower,upper);
	if(lower<upper)
	{
		int mid = (lower + upper)/2;
		mergeSort(arr,lower,mid);
		mergeSort(arr,mid+1,upper);
		merge(arr,lower,mid,upper);
	}
	
}
int main()
{
	int arr[10000];
	int num;	//size 

	cout<<"\nSize of problem: ";
	cin>>num;

	for(int i = 0;i < num ; i++ )
	{
		//cin>>arr[i];
		arr[i]=i;
	}
	cout<<"\n";
	mergeSort(arr,0,num-1);

	//Sorted Array
	cout<<"\nSorted Array: ";
	display(arr,0,num-1);

	cout<<"\nNumber of comparisons: "<<final<<endl;
	return 0;
}
