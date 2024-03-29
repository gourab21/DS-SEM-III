#include <iostream>
#define max 100

using namespace std;

class Queue
{

  

public:
	int arr[max];
  int f, r, s;
  
  Queue(int s = 5)
  {
    this->f = -1;
    this->r = -1;
    this->s = s;
  }

  void enqueue(int ele)
  {
    if (isFull())
    {
    	cout<<"Queue Full...\n";
	}
	else if (this->r==this->s-1 || this->r==-1)
	{
		this->arr[0]=ele;
		this->r=0;
		if (this->f==-1)
		{
			this->f=0;
		}
	}
	else
	{
		this->r=this->r+1;
		this->arr[this->r]=ele;
	}
  }

  void dequeue()
  {
    if (this->f >= this->s)
    {
      cout << "Queue Finished...\n";
    }
    else if (this->isEmpty())
    {
      cout << "Queue Empty...\n";
    }
    else if (this->f == this->r)
    {
      int temp = this->arr[this->f];
      cout<<"ELement Dequeued is - "<<temp<<endl;
      this->clear();
    }
    else
	{
    	cout<<"ELement Dequeued is - "<<this->arr[this->f]<<endl;
		this->f++;	
	}
  }

  void front()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty...\n";
      
    }
    else
    {
    	cout<<"The Front element is - "<<this->arr[this->f];
	}
  }

  bool isEmpty()
  {
    return (this->f == -1);
  }
  
	bool isFull()
	{
		return ((this->f==0 && this->r==this->s-1) || (this->f==(this->r+1)));
	}
  
  void clear()
  {
    this->f = this->r = -1;
    cout<<"Queue Cleared...\n";
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty...\n";
    }
    else if (this->f <= this->r)
	{
    	for (int i = this->f; i < this->r +1; i++)
      		cout << this->arr[i] << " <- ";
   		cout<<endl;
	}
	else
	{
      	for (int i = this->f; i < this->s ; i++)
      		cout << this->arr[i] << " <- ";
      	for (int i = 0; i < this->r +1; i++)
      		cout << this->arr[i] << " <- ";
    cout<<endl;
	}
  }
};

int main(void)
{
  int n, el, res, choice;
  cout << "Enter Size of Queue: ";
  cin >> n;
  Queue q(n);
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
      q.enqueue(el);
      break;
    case 2:
		q.dequeue();
        
        
      break;
    case 3:
      q.front();
      break;
    case 4:
      q.clear();
      break;
    case 5:
      cout << "Queue : ";
      q.display();
      break;
    default:
      break;
    }
    cout<<endl;
  } while (choice != 0);
  return 0;
}


