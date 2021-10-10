#include<iostream>
#include<vector>
#include<process.h>
using namespace std;


class stack
{
	public:
		int size;
		int s[100];
		int top;
		stack(int n)
		{
			size=n;
			top = -1;
		}
	
	void push(int);
	int pop(int);
	void display_last(int);
	void clear();
	bool isempty();
	void print(int);
};

void stack::print(int w=1)
{
	if (isempty())
		cout<<"Queue Empty...";
	else if(w==2)
	{
	for(int i=0;i<=top;i++)
		cout<<s[i]<<" <- ";
	cout<<endl;
	}
	else
	{
		for(int i=top;i>=0;i--)
			cout<<s[i]<<" <- ";
		cout<<endl;
	}
}

void stack::push(int p)
{
	if (top == size-1)
	{
		cout<<"The Queue is Full...";
	}
	else
	{
		s[++top] = p;
	}
}

int stack::pop(int a=0)
{
	int p=NULL;
	if (top == -1)
	{
		if (a==0){cout<<"Queue is Empty...";}
	}
	else
	{
		p = s[top--];		
	}
	if(a==0){cout<<"Element Popped is "<<p;}
	return p;
}

void stack::display_last(int oppo)
{
	if (isempty())
		cout<<"Empty Queue...";
	else if (oppo==1)
		cout<<"The Top Element is : "<<s[top];
	else
		cout<<"The Top Element is : "<<s[0];
}

bool stack::isempty()
{
	return (top == -1);
}

void stack::clear()
{
	top=-1;
	cout<<"Queue Cleared...";
}



int main(void)
{
	int n,oppo, el, res, choice;
	cout << "Enter Variation of : (1)Enqueue (2)Dequeue   - ";
	cin >>oppo;
	if (oppo <1 || oppo>2)
		{cout<<"Invalid Entry...";exit(0);}
	cout << "Enter Size of Queue: ";
	cin >> n;
	stack s1(n);
	stack s2(n);
	
  do
  {
    cout << "(1) Enqueue (2) Dequeue (3) Front  (4) Clear (5) Display  (0) Exit\n";
    cout << "Enter Choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter Element: ";
      cin >> el;
      if (oppo==1)
      {
      	if (s1.top==n-1)
      		cout<<"Queue Full...";
      	else if(s1.top==-1)
      		{s1.push(el);}
      	else
		{
		int t1=s1.top;
      	for (int i=0;i<=t1;i++)
      		{int t=s1.pop(1); s2.push(t);}
      	s1.push(el);
      	int t2=s2.top;
      	for (int i=0;i<=t2;i++)
      		s1.push(s2.pop(1));			
      	}
	  }
	  else
	  {
	  	s1.push(el);
	  }
	  
      break;
    case 2:
		if (oppo==1)
      {
      	s1.pop();
	  }
	  else
	  {
	  	if (s1.top==-1)
      		cout<<"Queue Empty...";
      	else
		{
		int t1=s1.top;
      	for (int i=0;i<=t1;i++)
      		{int t=s1.pop(1); s2.push(t);}
      	s2.pop();
      	int t2=s2.top;
      	for (int i=0;i<=t2;i++)
      		s1.push(s2.pop(1));			
      	}
	  }
      break;
    case 3:
      s1.display_last(oppo);
      break;
    case 4:
      s1.clear();
      break;
    case 5:
      cout << "Queue : ";
      s1.print(oppo);
      break;
    default:
      break;
    }
    cout<<endl;
  } while (choice != 0);
  return 0;
}


