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





int dir_graph()
{
    int adj_mat[50][50];
    int n,in_deg=0,out_deg=0;
    bool test=true;
    char c,f[50];;
    cout<<("\n How Many Vertices ? : ");
    cin>>n;
    read_graph(adj_mat, n);
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
		}
	}
	int ind[50],outd[50];
	for (int i=1;i<=n;i++)
	{
		int temp1=0,temp2=0;
		for (int z=1;z<=n;z++)
			{
				temp1+=adj_mat[i][z];
			}
		outd[i]=temp1;
		for (int z=1;z<=n;z++)
			{
				temp2+=adj_mat[z][i];
			}
		ind[i]=temp2;
	}
	cout<<endl<<endl<<endl;
	cout<<"Vertex	InDeg.	OutDeg.";
    for (int i=97;i<(97+n);i++)
    {
    	c=(char)i;
    	cout<<endl;
		cout<<c<<"	"<<ind[i-96]<<"	"<<outd[i-96];
	}	
    
    
    
    
    return 0;
}





int main()
{    	
    cout<<"";
	dir_graph();
	return 0;	
}



