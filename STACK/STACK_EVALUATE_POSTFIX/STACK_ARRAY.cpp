#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

const int size=1000;

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
	int pop();
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

int stack::pop()
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
	return p;
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

///////////////////////////////////////////////////////////////////

int isOperator(char ch)
	{
   if(ch == '+'|| ch == '-'|| ch == '*'|| ch == '/' || ch == '^')
      return 1;//character is an operator
    return -1;//not an operator
   }
      
float operation(int a, int b, char op)
   	{
      //Perform operation
      if(op == '+')
         return b+a;
      else if(op == '-')
         return b-a;
      else if(op == '*')
         return b*a;
      else if(op == '/')
         return b/a;
      else if(op == '^')
         return pow(b,a); //find b^a
      else
   return 0; //return negative infinity
}



int evalu(string w)
{
	stack s;
	string::iterator it;
	for (it=w.begin(); it!=w.end(); it++)
	{
			if (isdigit(*it))
			{s.push((*it) -'0'); }
			else
			{
				if (isOperator(*it) == -1)
					{cout<<"You Have Inserted an Invalid operator - "<<*it<<endl;break;}
				else
				{
					int val1 = s.pop();
					int val2 = s.pop();
					int a = operation(val1,val2,*it);
					s.push(a);
				}
			}
	}	
	return s.pop();
}


int main() {
	
	string w;
	cout<<"Enter the PostFix Expression - ";
	cin>>w;
	cout<<"The Solution is - "<<evalu(w);
	
	cin>>w;
}
