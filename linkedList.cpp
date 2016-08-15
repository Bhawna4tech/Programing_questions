#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node* next;
};


void print(struct node* start){
	if(start==NULL){
		cout<<"No Data";
		return;
	}
	struct node* temp;
	temp=start;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void print_reverse(struct node* start){
	if(start==NULL){
		return;
	}
	print_reverse(start->next);
	cout<<start->data<<" ";
}

void reverse(struct node** start,struct node* current){
	if(current==NULL)
		return;
	else if(current->next==NULL){
		*start=current;
		return;
	}
	reverse(start,current->next);
	current->next->next=current;
	current->next=NULL;
}

void insert(struct node** start,int key){
	cout<<"\ninserting at last"<<key<<" ";
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	if(*start==NULL){
		*start=temp;
		return;
	}
	struct node* temp1 = *start;
	while(temp1->next!=NULL){
		temp1=temp1->next;
	}
	temp1->next=temp;
}

void insert_at_pos(struct node** start,int key,int pos){
	
	if(*start==NULL){
		cout<<"No data in linked list";
		return;
	}
	
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	
	
	struct node* temp1 = *start;
	for(int i=0;i<pos-2;i++){
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
}
void insert_at_beg(struct node** start,int key){

	struct node* temp;
	temp=new node();
	temp->data=key;
	temp->next=NULL;
	
	if(*start==NULL){
		*start=temp;
		return;
	}

	temp->next=*start;
	*start=temp;
}

void delete_at_beg(struct node** start){
	if(*start==NULL){
		cout<<"No data in linked list";
		return;
	}
	struct node* temp=*start;
	*start=temp->next;
	temp->next=NULL;
}


void delete_at_pos(struct node** start,int pos){
	if(start==NULL){
		cout<<"No data in linked list";
		return;
	}

	struct node* temp1, *temp2;
	temp1=*start;
	for(int i=0;i<pos-2;i++){
		temp1=temp1->next;
	}
	temp2=temp1->next;
	temp1->next=temp2->next;
	temp2->next=NULL;
}

int main(){
	int key;
	struct node* start;
	start=NULL;
	
	cout<<"Insertion (at last)";
	
	insert(&start,1);
	insert(&start,2);
	insert(&start,3);
	insert(&start,4);
	insert(&start,5);
	cout<<"\n Printing ";
	print(start);
	
	cout<<"\nInsertion at beg \n";
	insert_at_beg(&start,6);
	cout<<"\n Printing ";
	print(start);
	
	cout<<"\nDeletion at beg\n";
	delete_at_beg(&start);
	cout<<"\n Printing ";
	print(start);

	cout<<"\nInsertion at Position 2 \n";
	insert_at_pos(&start,0,2);
	insert_at_pos(&start,0,2);
	cout<<"\n Printing ";
	print(start);	
	
	cout<<"\nDeletion at Position 2\n";
	delete_at_pos(&start,2);
	cout<<"\n Printing ";
	print(start);
	
	cout<<"\n Only printing reversal of linked list\n";
	print_reverse(start);
	cout<<"original linked list is";
	print(start);
	
	
	cout<<"\nReversal of linked list";
	reverse(&start,start);
	cout<<"\n Printing ";
	print(start);
	
}
