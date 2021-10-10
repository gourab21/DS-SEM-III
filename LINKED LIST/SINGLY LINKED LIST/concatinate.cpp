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
	node *head,*tail;
	public:
		
		LinkedList(){
			head = tail = NULL;
		}
		
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
				head = tail = temp;
			}
			else
			{
				node *temp = new node();
				temp->data = data;
				temp->next = head;
				head = temp;
			}
		}
		
		void print(){
			if (empty()){ 
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
		
		LinkedList operator+();
		friend LinkedList operator+(LinkedList l1,LinkedList l2);
		
};

LinkedList operator+(LinkedList l1,LinkedList l2)
		{
			node *tmp=l1.tail;
			tmp->next=l2.head;
			return l1;
		
		}



int main() {
	LinkedList list1;
    LinkedList list2;
    LinkedList list3;
    


    list1.insert_at_beginning(2);
	list2.insert_at_beginning(4);
    list1.insert_at_beginning(1);
	list2.insert_at_beginning(3);
	list1.print();
    list2.print();
    
	
	list1 = list1 + list2;
	list1.print();
	
	
}
