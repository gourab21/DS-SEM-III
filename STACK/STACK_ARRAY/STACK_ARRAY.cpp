#include<iostream>
#include<vector>
#include<process.h>
using namespace std;

const int size=40;

class stack
{
	int s[size];
	int top;

	public:
		stack()
		{
			top = -1;
		}
	
	void push(int);
	void pop();
	void display_last();
	void clear();
	bool isempty();
};

void stack::push(int p)
{
	if (top == size-1)
	{
		cout<<"The Stack is Full...";
	}
	else
	{
		s[++top] = p;
	}
}

void stack::pop()
{
	int p=NULL;
	if (top == -1)
	{
		cout<<"Stack is Empty...";
	}
	else
	{
		p = s[top--];		
	}
	cout<<"Element Popped is "<<p;
}

void stack::display_last()
{
	cout<<"The Top Element is : "<<s[top];
}

bool stack::isempty()
{
	return (top == -1);
}

void stack::clear()
{
	top=-1;
	cout<<"Stack Cleared...";
}



int main() {
	
	int choice,data,p;
	stack ll;
	
	do {
		cout<<("1 to Push");
		cout<<("\n2 to Pop");
		cout<<("\n3 to Clear");
		cout<<("\n4 to Top Element");
		cout<<("\n5 to IsEmpty");
		cout<<("\n0 to Exit");
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter Element: ";
				cin>>data;
				ll.push(data);
				break;
				
			case 2:
				ll.pop();
				break;
				
			case 3:
				ll.clear();
				break;
				
			case 4:
				ll.display_last();
				break;
			
			case 5:
				string s=(ll.isempty())? "Yes":"NO"; 
				cout<<s;		
				break;
		
		}
		cout<<endl<<endl;	 	
	} while (choice != 0);
	
}
