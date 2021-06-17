#include<iostream> 
using namespace std; 
int binsearch(int arr[], int p, int r, int num) { 
   if (p <= r) { 
      int mid = (p + r)/2; 
      if (arr[mid] == num)   
         return mid ; 
      if (arr[mid] > num)  
         return binsearch(arr, p, mid-1, num);            
      if (arr[mid] < num)
         return binsearch(arr, mid+1, r, num); 
   } 
   return -1; 
} 
int main(void) { 
   int arr[]={6,22,33,55,23,4,3,12,76,89,65,9,87,45,34}; 
   int num;
   cout<<"Enter the element to search - ";
   cin>>num;
   int n = sizeof(arr)/ sizeof(arr[0]); //because size of array allso contains the size of each element. hence no. of elements is euqal to total size of array divide by size of each element.
   int index = binsearch (arr, 0, n-1, num); 
   if(index == -1)
      cout<< num <<" is not present in the array";
   else
      cout<< num <<" is present at index "<< index <<" in the array"; 
   return 0; 
}
