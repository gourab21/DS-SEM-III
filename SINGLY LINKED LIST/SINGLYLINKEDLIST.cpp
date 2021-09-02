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
	public:
		
		LinkedList(){
			head = NULL;
		}
		
		void insert_at_beginning(int data){
			node *temp = new node();
			temp->data = data;
			temp->next = head;
			head = temp;
		}
		
		void insert_at_end(int data){
			node *temp = new node();
			temp->data = data;
			if (head == NULL){
				head = temp;
			}
			else{
				node *ptr = head;
				
				while (ptr->next != NULL){
					ptr = ptr->next;
				}
				
				ptr->next = temp;
			}
		}
		
		void insert_at_given_position(int data, int p){
			node *temp = new node();
			temp->data = data;
			if (p == 0){
				
				temp->next = head;
				head = temp;
			}
			else{
				node *ptr = head;
				
				while(p>1) {
					ptr = ptr->next;
					--p;
				}
				
				temp->next = ptr->next;
				ptr->next = temp;
			}
		}
		
		void delete_at_beginning(){
			if (head == NULL){
				cout<<"List is Empty"<<endl;
			}
			else{
				cout<<"Element Deleted: "<<head->data<<endl;
				
				node *temp = head;
				
				head = head->next;
			
				delete(temp);
			}
		}
		
		void delete_at_end(){
			if (head == NULL){
				cout<<"List is Empty"<<endl;
			}
			else if (head->next == NULL){
				
				cout<<"Element Deleted: "<<head->data<<endl;
				delete(head);
				head = NULL;
			}
			else{
				
				node *temp = head;
				while (temp->next->next != NULL) {
					temp = temp->next;
				}
				cout<<"Element Deleted: "<<temp->next->data<<endl;
				delete(temp->next);
				temp->next = NULL;
			}					
		
		}
		
		void delete_at_given_position(int p){
			if (head == NULL){
				cout<<"List is Empty"<<endl;
			}
			else{
				node *temp, *ptr;
				if (p == 0) {
					cout<<"Element Deleted: "<<head->data<<endl;
					ptr = head;
					head = head->next;
					delete(ptr);
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
					delete(ptr);
				}
			}
		
		}
		
		void search(int p){
			if (head == NULL){
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
		
		
		void reverse()  {
		node* current = head;
        node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            next = current->next;
 
            current->next = prev;
 
            prev = current;
            current = next;
        }
        head = prev;
        cout<<"List reversed..."<<endl;
    	}
		
		
		
		void print(){
			if (head == NULL){ 
				cout<<"List is empty"<<endl;
			}
			else{
				node *temp = head;
				cout<<"Linked List: ";
				while (temp != NULL){
					cout<<temp->data<<"->";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}	
			
};


int main() {
	
	cout<<("1 to Insert at the beginning");
	cout<<("\n2 to Insert at the end");
	cout<<("\n3 to Insert at mid");
	cout<<("\n4 to Delete from beginning");
	cout<<("\n5 to Delete from the end");
	cout<<("\n6 to Delete from mid");
	cout<<("\n7 to Search Item");
	cout<<("\n8 to Reverse the List");
	cout<<("\n9 to Display");
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
				ll.reverse();
				break;	
				
			case 9:
				ll.print();
				break;
			 	
		}
	} while (choice != 0);
	
}
