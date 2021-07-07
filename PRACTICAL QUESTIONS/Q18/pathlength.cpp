
#include <iostream>
using namespace std;

#define V 4

int check(int g[][V], int u, int v, int k)
{

	if (k == 0 && u == v)
		return 1;
	if (k == 1 && g[u][v])
		return 1;
	if (k <= 0)
		return 0;

	int count = 0;

	for (int i = 0; i < V; i++)
		if (g[u][i] == 1) 
			count += check(g, i, v, k - 1);

	return count;
}

int main()
{
	int g[V][V] = { { 0, 1, 1, 1 },
						{ 0, 0, 0, 1 },
						{ 0, 0, 0, 1 },
						{ 0, 0, 0, 0 } };
	int u = 0, v = 3, k = 2;
	cout<<"Enter the Source : ";
	cin>>u;
	cout<<"Enter the End    : ";
	cin>>v;
	cout<<"Enter the Length : ";
	cin>>k;
	cout << check(g, u, v, k);
	return 0;
}

