#include<iostream>
#include<vector>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node *prev;
		node(){
			next = NULL;
			prev = NULL;
		}
};

class LinkedList{
	node *head,*tail;
	int count=0;
	public:
		
		LinkedList(){
			head = tail = NULL;
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
		
		bool empty()
		{
			return (head == NULL || tail == NULL);
		}
		
		void insert_at_beginning(int data)
		{
			if (count==0)
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				head = tail = temp;
			}
			else if(count ==1)
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				temp->prev = head;
				head->next = temp;
				head->prev = temp;
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
				head->prev = temp;
				ptr->next = temp;
				temp->prev = ptr;
				head = temp;
			}
					
			count++;
		}
		
		
		
		void insert_at_given_position(int data, int p){
			node *temp = new node();
			temp->data = data;
			if (p == 0){
				
				insert_at_beginning(data);
			}
			else{
				node *ptr = head;
				
				while(p>1) {
					ptr = ptr->next;
					--p;
				}
				
				temp->next = ptr->next;
				temp->prev = ptr;
				ptr->next->prev= temp;
				ptr->next = temp;
				
			}
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
				head->prev = ptr;
				delete(temp);
			}
			count--;
		}
		
		
		
		void delete_at_given_position(int p){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else{
				node *temp, *ptr;
				if (p == 0) {
					delete_at_beginning();
				}
				else{
					temp = ptr = head;
					while(p>0){
						--p;
						temp = ptr;
						ptr = ptr->next;
					}
					cout<<"Element Deleted: "<<ptr->data<<endl;
					temp->next = ptr->next;
					ptr->next->prev = temp;
					delete(ptr);
				}
			}
		
		}
		
		void search(int p){
			if (empty()){
				cout<<"List is Empty....."<<endl;
			}
			else if(p==head->data)
			{
				cout<<"match Found at index (Start 0) 0";
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
						cout<<"Match found at index (start = 0)"<<pos;
						break;
					}	
					pos++;
					temp=temp->next;
				}while(temp!=head);
				if (a==false)
				{
					cout<<"Item not found in List....";
				}
				
			}
		cout<<endl;
		}
		
		void print(){
			if (empty()){ 
				cout<<"List is empty"<<endl;
			}
			else{
				node *temp = head;
				cout<<"Linked List: <-> ";
				do {
					cout<<temp->data<<" <-> ";
					temp = temp->next;
				}while (temp != head);
				cout<<endl;
			}
		}	
			
};


int main() {
	
	cout<<("1 to Insert at the beginning");
	cout<<("\n2 to Insert at mid");
	cout<<("\n3 to Delete from beginning");
	cout<<("\n4 to Delete from mid");
	cout<<("\n5 to Search Item");
	cout<<("\n6 to Display");
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
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.insert_at_given_position(data,p);
				break;
				
			case 3:
				ll.delete_at_beginning();
				break;
		
			case 4:
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.delete_at_given_position(p);
				break;
				
			case 5:
				cout<<"Enter Element to search : ";
				cin>>p;
				ll.search(p);
				break;
				
			case 6:
				ll.print();
				break;
			
			default :
				cout<<"Enter Correct Choice...";
		}
	} while (choice != 0);
	
}
