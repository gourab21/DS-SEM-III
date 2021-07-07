#include <bits/stdc++.h>
using namespace std;

void show(int arr[],int n)
{
	int a=0;
	while (a<n)
	{
	cout<<" "<<arr[a];
	a++;
	}
	cout<<endl;
}



void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)	
	{
		int swaps=0,comp=0;
	for (j = 0; j < n-i-1; j++)
	{
		comp+=1;
		if (arr[j] > arr[j+1])
		{	
			swaps+=1;
			int w=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=w;
		}
	}
	cout<<"After iteration "<<i+1<<" - ";
	show(arr,n);
	cout<<"No. of Comparison - "<<comp<<endl;
	cout<<"No. of Swaps      - "<<swaps<<endl;
	}
	
}


int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr, n);
	cout<<"Sorted array: \n";
	show(arr, n);
	return 0;
}



