#include <iostream>
using namespace std;
int func(int x) 
{
   if((x==1)||(x==0)) 
   {
      return(x);
   }
   else 
   {
      return(func(x-1)+func(x-2));
   }
}

int main() 
{
   int x , i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series : ";
   while(i < x) 
   {
      cout << " " << func(i);
      i++;
   }
   return 0;
}
