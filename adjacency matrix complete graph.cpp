#include<iostream>>
using namespace std;

int read_graph ( int adj_mat[50][50], int n )
{
    int i, j;
    int reply;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            cout<<"\n How many paths are there from Vertice "<<i<<" to "<<j<<" ? :";
            cin>>reply;
            adj_mat[i][j] =reply;
	}
    } 
    return 0;
}


int read_graph2 ( int adj_mat[50][50], int n )
{
    int i, j;
    int reply;
    for ( i = 1 ; i <= n ; i++ )
    {
        for ( j = 1 ; j <= n ; j++ )
        {
            if ( i > j  )
            {
                adj_mat[i][j] = adj_mat[j][i];
				continue;
            } 
            cout<<"\n Vertices "<<i<<" and "<<j<<" have how many edges in common? :";
            cin>>reply;
            adj_mat[i][j]=reply;
	}
    } 
    return 0;
}


int dir_graph(int s)
{
    int adj_mat[50][50];
    int n,in_deg=0,out_deg=0;
    bool test=true;
    char c,f[50];;
    cout<<("\n How Many Vertices ? : ");
    cin>>n;
    if (s==1)
    	read_graph(adj_mat, n);
    else
    	read_graph2(adj_mat, n);
    for (int i=97;i<(97+n);i++)
    {
    	c=(char)i;
    	f[i-97]=c;
		cout<<"\t"<<c;
	}	
    for (int i = 1; i <= n ; i++ )
    {
    	cout<<"\n"<<f[i-1]<<"\t";
        for (int j = 1 ; j <= n ; j++ )
        {
        	int temp=adj_mat[i][j];
        	cout<<temp<<"\t";
        	if (i==j & temp>=1)
        	{
				test=false;
			}
        	if (i!=j & temp==0)
        	{
				test=false;
    		}
		}
    }
    if (test==true)
    	cout<<"\n \n it is a complete Graph. \n";
    else
    	cout<<"\n\nit is not a complete Graph. \n";
    return 0;
}






int main()
{    	
    cout<<("\n A Program to represent a Graph by using an ");
	cout<<("Adjacency Matrix method \n ");
	int s;
	cout<<"Enter	1.Directed	2.Undirected :- ";
	cin>>s;
	dir_graph(s);
	return 0;	
}



