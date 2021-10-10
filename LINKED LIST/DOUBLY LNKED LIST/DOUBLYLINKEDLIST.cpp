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
		
		LinkedList operator+();
		friend LinkedList operator+(LinkedList l1,LinkedList l2);
		
		bool empty()
		{
			return (head == NULL || tail == NULL);
		}
		
		void insert_at_beginning(int data){
			if (empty())
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				temp->prev = NULL;
				head = tail = temp;
			}
			else
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				temp->prev = NULL;
				head->prev = temp;
				head = temp;
			}
		}
		
		void insert_at_end(int data){
			node *temp = new node();
			temp->data = data;
			if (empty()){
				head = tail = temp;
			}
			else{
				node *ptr = head;
				while (ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = temp;
				temp->prev = ptr;
				tail = temp;
			}
		}
		
		void insert_at_given_position(int data, int p){
			node *temp = new node();
			temp->data = data;
			if (p == 0){
				insert_at_beginning(data);
			}
			else{
				node *ptr2,*ptr1 = head;
				
				while(p>1) {
					ptr1 = ptr1->next;
					--p;
				}
				ptr2 = ptr1->next;
				ptr1->next = temp;
				temp->prev = ptr1;
				temp->next = ptr2;
				ptr2->prev = temp;
			}
		}
		
		void delete_at_beginning(){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else{
				cout<<"Element Deleted: "<<head->data<<endl;
				
				node *temp = head;
				
				head = head->next;
				head->prev = NULL;
				delete(temp);
			}
		}
		
		void delete_at_end(){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else if (head->next == NULL){
				
				cout<<"Element Deleted: "<<head->data<<endl;
				delete(head);
				head = tail = NULL;
			}
			else{
				
				node *temp = tail;
				cout<<"Element Deleted: "<<temp->data<<endl;
				temp->prev->next = NULL;
				tail = temp->prev;
				delete(temp);
				
			}					
		
		}
		
		void delete_at_given_position(int p){
			if (empty()){
				cout<<"List is Empty"<<endl;
			}
			else{
				node *temp, *ptr,*ptr2;
				if (p == 0) {
					delete_at_beginning();
				}
				else{
					temp = ptr = head;
					while(p>0){
						--p;
						temp = ptr;
						ptr = ptr->next;
						ptr2= ptr->next;
					}
					cout<<"Element Deleted: "<<ptr->data<<endl;
					temp->next = ptr2;
					ptr2->prev = temp;
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
				}while(temp!=NULL);
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
				cout<<"Linked List: ";
				while (temp != NULL){
					cout<<temp->data<<"<->";
					//cout<<"aa"<<temp->prev<<"aa";
					temp = temp->next;
					
				}
				cout<<"NULL"<<endl;
			}
		}	
			
};

LinkedList operator+(LinkedList ll,LinkedList l2)
		{
			if (!ll.empty() && !l2.empty())
			{
				l2.head->prev=ll.tail;
				ll.tail->next=l2.head;
				ll.tail=l2.tail;
				cout<<"The Concatinated list is : "<<endl;
				ll.print();
				return ll;		
			}
			else
			{
				cout<<"One Of the List is Empty.... Cant Concatiate....";
				return ll;
			}	
		}







int main() {
	
	cout<<("1 to Insert at the beginning");
	cout<<("\n2 to Insert at the end");
	cout<<("\n3 to Insert at mid");
	cout<<("\n4 to Delete from beginning");
	cout<<("\n5 to Delete from the end");
	cout<<("\n6 to Delete from mid");
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
				//ll.print();
				break;
				
			case 2:
				cout<<"Enter Element: ";
				cin>>data;
				ll.insert_at_end(data);
				break;
				
			case 3:
				cout<<"Enter Element: ";
				cin>>data;
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.insert_at_given_position(data,p);
				break;
				
			case 4:
				ll.delete_at_beginning();
				break;
				
			case 5:
				ll.delete_at_end();
				break;
				
			case 6:
				cout<<"Enter Position ( zero-indexed ): ";
				cin>>p;
				ll.delete_at_given_position(p);
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
				cout<<endl;
				break;
			 	
		}
	} while (choice != 0);
	
}
