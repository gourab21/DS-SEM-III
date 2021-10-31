#include <iostream>
#include <stdlib.h> 
using namespace std;

class BST
{
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Inorder(BST*);
	void Preorder(BST*);
	void Postorder(BST*);
	
};

BST ::BST()
{
	data=0;
	left=NULL;
	right=NULL;
}

BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

BST* BST ::Insert(BST* root, int value)
{
	if (!root)
	{
		//cout<<"New";
		return new BST(value);
	}
	
	if (value > root->data)
	{
		//cout<<"Right";
		root->right = Insert(root->right, value);
	}
	
	else
	{
		//cout<<"Left";
		root->left = Insert(root->left, value);
	}
	
	return root;
}


void BST ::Inorder(BST* root)
{
	if (!root)
	{
		return ;
	}
	Inorder(root->left);
	cout << root->data<<" " ;
	Inorder(root->right);
}

void BST ::Preorder(BST* root)
{
	if (!root)
	{
		return ;
	}
	cout << root->data <<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void BST ::Postorder(BST* root)
{
	if (!root)
	{
		return ;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout << root->data <<" ";
}



// Driver code
int main()
{
	BST b, *root = NULL;
	int x,choice;
	cout<<"Enter The Root : ";
	cin>>x;
	root = b.Insert(root, x);
	do
	{
		cout<<("\n1 to Insert");
		cout<<("\n2 to In-Order");		
		cout<<("\n3 to Pre-Order");
		cout<<("\n4 to Post-Order");
		cout<<("\n0 to Exit");
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter Element : ";
				cin>>x;
				b.Insert(root, x);
				break;
			
			case 2:
				b.Inorder(root);
				break;
			case 3:
				b.Preorder(root);
				break;
			case 4:
				b.Postorder(root);
		}
		cout<<endl;
		//system("CLS");
	}while(choice!=0);
	return 0;
	
}

// This code is contributed by pkthapa

