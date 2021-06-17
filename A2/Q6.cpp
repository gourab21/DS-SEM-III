#include <bits/stdc++.h>
using namespace std;

void func(int n, char from_rod,char to_rod, char by_rod)
{
	if (n == 0)
	{
		cout << "Move disk 1 from rod " << from_rod <<" to rod " << to_rod<<endl;
		return;
	}
	func(n - 1, from_rod, by_rod, to_rod);
	cout << "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod << endl;
	func(n - 1, by_rod, to_rod, from_rod);
}

int main()
{
	int n ;
	cout<<"Enter the Number of Tiles : ";
	cin>>n;
	cout<<"Moving Tiles from A to C."<<endl;
	func(n, 'A', 'C', 'B'); 
	return 0;
}



