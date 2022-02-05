#include<iostream>
using namespace std;
class node {
public:
	 int data;
	 node * next;
	 node * prev;
	 node() {
		 data = 0;
		 next = NULL;
		 prev = NULL;
	 }
	
	node(int d) {
		 data = d;
	}
};
class DoublyLinkedList {
 public:
  node * head;
  node * tail;
   DoublyLinkedList() {
       head = NULL;
       tail = NULL;
   }
   DoublyLinkedList(node * n) {
     head = n;
   }
   void traverse(){
	node *ptr = head;
	if(head==NULL){
			cout<<"\nALERT : Linked list is empty!!!!\n";
	}
	else{
		cout<<"\nNODES :   ";
        while (ptr!= NULL)
        {
            cout << ptr->data;
            if(ptr->next!=NULL){
            	cout<<"->";
			}
            ptr = ptr->next;
        }
        tail=ptr;
        cout<<endl;
    }
	}
	void appendnode(){        //attheend
		int n=0,k=0;
		cout<<"Enter data of node to insert at the end\n";
		cin>>n;
		node *temp=new node;
		node *ptr=head;
		temp->data=n;
		temp->prev=NULL;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
		}
		else{
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->prev=ptr;
		}
		cout<<"\nALERT : Node appended!!\n";
	}
	int prependnode(){         //atthestart
		int n=0;
		cout<<"Enter data of node to insert at the start\n";
		cin>>n;
		node *temp=new node;
		temp->data=n;
		temp->next=NULL;
		if(head==NULL){
			head=temp;	
		}
		else{
			temp->next=head;
			head->prev=temp;
			head=temp;
	    }
	    cout<<"\nALERT : Node prepended!!\n";
	}
	node* getHead()
	{
		return head;
	}
	void Merge(){
		DoublyLinkedList M;
		cout<<"\n******************DOUBLY LINKED LIST FOR M********************\n";
		M.appendnode();
		M.prependnode();
		M.prependnode();
		M.appendnode();
		cout<<"Node for M : ";
		M.traverse();
		node *ptr=head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		node *Mptr=M.getHead();
		ptr->next=Mptr;
		Mptr->prev=ptr;
		cout<<"\n****************Merged List********************\n";
		traverse();
	}
};
int main(){
	DoublyLinkedList L;
	DoublyLinkedList M;
	int c;
	cout<<"\n******************DOUBLY LINKED LIST FOR L********************\n";
	L.appendnode();
	L.prependnode();
	L.prependnode();
	L.appendnode();
	cout<<"Node of L : ";
	L.traverse();
	L.Merge();
	
}
