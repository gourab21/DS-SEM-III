#include<iostream>
#include<vector>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node(){
			next = NULL;
		}
};

class LinkedList{
	node *head;
	int count=0;
	public:
		
		LinkedList(){
			head = NULL;
		}
		
		~LinkedList()
		{
			for (node *p; head !=0;)
			{
				p = head->next;
				delete head;
				head = p;
			}
		}
		
		LinkedList operator+();
		friend LinkedList operator+(LinkedList ll,LinkedList l2);
		
		
		bool empty()
		{
			return (head == NULL);
		}
		
		void insert_at_beginning(int data)
		{
			if (count==0)
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				head = temp;
			}
			else if(count ==1)
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				head->next = temp;
				head = temp;
			}
			else
			{
				node *ptr,*temp = new node();
				temp->data = data;
				ptr = head->next;
				while (ptr->next != head)
				{
					ptr=ptr->next;
				}
				temp->next = head;
				ptr->next = temp;
				head = temp;
			}
					
			count++;
		}
		
		void insert_at_end(int data)
		{
			if (count==0)
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				head = temp;
			}
			else if(count ==1)
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				head->next = temp;
			}
			else
			{
				node *ptr,*temp = new node();
				temp->data = data;
				ptr = head->next;
				while (ptr->next != head)
				{
					ptr=ptr->next;
				}
				temp->next = head;
				ptr->next = temp;
			}		
			count++;
		}
		
		void insert_at_given_position(int x, int d){
			node *temp = new node();
			temp->data = d;
			node *ptr = head;
				
			while(ptr->data!=x) {
				ptr = ptr->next;
			}
			temp->next = ptr->next;
			ptr->next = temp;
			count++;
		}
		
		void delete_at_beginning(){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else{
				cout<<"Element Deleted: "<<head->data<<endl;
				node *ptr,*temp = head;
				ptr = head->next;
				while (ptr->next != head)
				{
					ptr=ptr->next;
				}
				head = temp->next;
				ptr->next = head;
				delete(temp);
			}
			count--;
		}
		
		void delete_at_end(){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else{
				cout<<"Element Deleted: "<<head->data<<endl;
				node *ptr,*temp = head;
				ptr = head->next;
				while (ptr->next != head)
				{
					ptr=ptr->next;
				}
				head = temp->next;
				ptr->next = head;
				delete(temp);
			}
			count--;
		}
		
		
		void delete_element(int p){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else{
				node *pr, *ptr,*post;
				pr = ptr = post = head;
				if (p==head->data)
					this->delete_at_beginning();
				else{
					do{
						pr=ptr;
						ptr = ptr->next;
						post=ptr->next;
						
					}while(ptr->data!=p);
					cout<<"Element Deleted: "<<ptr->data<<endl;
					pr->next=post;
					delete(ptr);
				}
			}
		
		}
		
		int search(int p,int q=0){
			string s;
			int ret=0;
			if (empty()){
				s="List is Empty.....";
			}
			else if(p==head->data)
			{
				s="match Found at index (Start 0) 0";
				ret= 1;
			}
			else {
				node *temp;
				int pos;
				bool a=false;
				temp=head;
				pos=0;
				do
				{
					if (p==temp->data)
					{
						a=true;
						s="Match found at index (start = 0)";
						ret= 1;
						break;
					}	
					pos++;
					temp=temp->next;
				}while(temp!=head);
				if (a==false)
				{
					s="Item not found in List....";
				}
				if (q==0)
				{
					cout<<s<<endl;
				}
			}
		return ret;
		}
		
		void print(){
			if (empty()){ 
				cout<<"List is empty"<<endl;
			}
			else{
				node *temp = head;
				cout<<"Linked List: ->";
				do {
					cout<<temp->data<<"->";
					temp = temp->next;
				}while (temp != head);
				cout<<endl;
			}
		}	
			
};

LinkedList operator+(LinkedList ll,LinkedList l2)
		{
			if (!ll.empty() && !l2.empty()){
				
				node *tail1,*tail2;
				tail1=ll.head;
				
				while (tail1->next != ll.head)
				{
					tail1=tail1->next;
				}
				tail2=l2.head;
				while(tail2->next != l2.head)
				{
					tail2=tail2->next;
				}
				cout<<tail1->data<<tail2->data<<endl;
				tail1->next=l2.head;
				tail2->next=ll.head;
				ll.print();
			}
			else{
				cout<<"List is Empty"<<endl;
			}
			cout<<"end";
			return ll;	
		}





int main() {
	
	cout<<("1 to Insert at the beginning");
	cout<<("\n2 to Insert at the end");
	cout<<("\n3 to Insert at back of X");
	cout<<("\n4 to Delete from beginning");
	cout<<("\n5 to Delete from End");
	cout<<("\n6 to Delete element X");
	cout<<("\n7 to Search Item");
	cout<<("\n8 to Display");
	cout<<("\n9 to Concat");
	cout<<("\n0 to Exit");
	
	int choice,data,p;
	LinkedList ll;
	do {
		cout<<"\nEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				cout<<"Enter Element: ";
				cin>>data;
				ll.insert_at_beginning(data);
				break;
				
		
			case 2:
				cout<<"Enter Element: ";
				cin>>data;
				ll.insert_at_end(data);
				break;
				
			case 3:
				cout<<"Enter value of element X : ";
				cin>>p;
				cout<<"Enter Element : ";
				cin>>data;
				if(ll.search(p,1)==0)
					cout<<"   X not in List";
				else
					ll.insert_at_given_position(p,data);
					cout<<"Inserted Successfully...";
				break;
			
		
			case 4:
				ll.delete_at_beginning();
				break;
				
				
				
			case 5:
				ll.delete_at_end();
				break;
				
			case 6:
				cout<<"Enter Element: ";
				cin>>p;
				ll.delete_element(p);
				break;
			
			case 7:
				cout<<"Enter Element to search : ";
				cin>>p;
				ll.search(p);
				break;
			
			case 8:
				ll.print();
				break;
				
			case 9:
				LinkedList l2;
				int nn,yo;
				cout<<"Enter Number of elements o be inserted on List 2 : ";
				cin>>nn;
				while(nn>0)
				{
					cout<<"Enter Element : ";
					cin>>yo;
					l2.insert_at_end(yo);
					nn--;
				}
				cout<<"List 2 is : "<<endl;
				l2.print();
				ll=ll+l2;
				cout<<"The Concatinated list is : "<<endl;
				ll.print(); 
				break;	
				
		}
	} while (choice != 0);
	
}
