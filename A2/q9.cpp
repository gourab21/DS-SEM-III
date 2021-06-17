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

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    int swaps=0,comp=0;
    for (i = 1; i < n; i++)
    {
    	swaps=0;
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
        	swaps+=1;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        cout<<"After iteration "<<i+1<<" - ";
		show(arr,n);
		//cout<<"No. of Comparison - "<<comp<<endl;
		cout<<"No. of Swaps      - "<<swaps<<endl;
    }
}


int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	insertionSort(arr, n);
	cout<<"Sorted array: \n";
	show(arr, n);
	return 0;
}



