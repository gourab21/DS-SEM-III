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
	int p;
	if (top == -1)
	{
		p=0;
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



int evalu(long long a, long long b, long long M, long long N)
{
	
	stack s1,s2,s3;
	long long carry = 0,val = 0, m = M, n = N;
	long long P=(M>N)? M:N, p = P;
	while (p>0)
	{
		if (m>0)
		{
			s1.push(a/m);
			//cout<<a<<endl;
			a = a - (a/m)*m;
			m = m / 10;
		}
		if (n>0)
		{
			s2.push(b/n);
			//cout<<b<<endl;
			b = b- ((b/n)*n);
			n = n / 10;
		}
		p = p/10;
	}
	
	p=log10(P)+1;
	
	while (p>0)
	{
			m=s1.pop();
			n=s2.pop();
			val = m + n + carry;
			carry = val / 10;
			val = val - (carry*10);
			s3.push(val);
			//cout<<val;
			p--;
						
	}
	p=log10(P);
	val=0;
	//cout<<p;
	for (int i = p;i>=0; i--)
	{
			m=s3.pop();
			//cout<<i<<"   "<<m<<endl;
			val = val + (m*(pow(10,i)));	
	}
	
	
	
	return val;
}


int main() {
	
	long long a=1115,b=1115;
	long long m,n;
	cout<<"Enter The First Number   - ";
	cin>>a;
	cout<<"Enter The Second Number  - ";
	cin>>b;
	m = pow(10,floor(log10(a)));
	n = pow(10,floor(log10(b)));
	cout<<"The Sum is -  ";
	cout<<evalu(a,b,m,n);

}
