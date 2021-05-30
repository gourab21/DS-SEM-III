#include <bits/stdc++.h>
using namespace std;

int calcNodes(int m, int i)
{
	int result = 0;

	result = i * (m - 1) + 1;

	return result;
}

int main()
{
	int m = 5, i = 2;
	cout<<"Enter the value of m for m-ary tree   : ";
	cin>>m;
	cout<<"Enter the number of internal vertices : ";
	cin>>i;
	cout << "Leaf nodes = " << calcNodes(m, i);

	return 0;
}

