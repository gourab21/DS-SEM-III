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
    if (this->r >= (this->s - 1))
    {
      cout<< "Queue Full...\n";
    }
    else if (this->isEmpty())
    {
      this->r++;
      this->f++;
      this->arr[this->f] = ele;
    }
    else
    {
    	this->r++;
      this->arr[(this->r)] = ele;
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
    /*else if (this->f == this->r)
    {
      int temp = this->arr[this->f];
      this->clear();
    }*/
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
      cout << "Queue Empty...";
      
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

  void clear()
  {
    this->f = this->r = -1;
  }

  void display()
  {
    if (this->isEmpty())
    {
      cout << "Queue Empty";
    }
    else
	{
    for (int i = this->f; i < this->r +1; i++)
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
    cout << "  (1) Enqueue (2) Dequeue (3) Front  (4) Clear (5) Display  (0) Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "\nEnter Element: ";
      cin >> el;
      q.enqueue(el);
        cout << "Queue: ";
        q.display();
        
      break;
    case 2:
		q.dequeue();
        cout << "Queue: ";
        q.display();
      break;
    case 3:
      q.front();
      break;
    case 4:
      q.clear();
      break;
    case 5:
      cout << "\nQueue: ";
      q.display();
    default:
      break;
    }
    
  } while (choice != 0);
  return 0;
}


