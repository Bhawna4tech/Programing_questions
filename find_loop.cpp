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

void remove_loop(node* start,node **loopnode){
	
	node *ptr1,*ptr2;
	ptr1=start;
	ptr2=*loopnode;
	
	while(1){
		while(ptr2->next!=ptr1 && ptr2->next!=*loopnode){
			ptr2=ptr2->next;
		}
		if(ptr2->next==*loopnode)
			break;
		else 
			ptr1=ptr1->next;
	}
	ptr2->next=NULL;
		
	}

struct node* check_loop(node* start){
	
	node *slow,*fast;
	slow=fast=start;
	
	while(slow && fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			cout<<"Loop Detected";
			return slow;
		}
	}
	return NULL;
}

int main(){
	struct node* start= (struct node*)malloc(sizeof(struct node));
	node *p1,*p2,*p3,*p4,*p5,*p6;
	p1=new node();
	p2=new node();
	p3=new node();
	p4=new node();
	p5=new node();
	p6=new node();
	
	start->data=0;
	p1->data=1;
	p2->data=2;
	p3->data=3;
	p4->data=4;
	p5->data=5;
	p6->data=6;
	
	start->next=p1;
	p1->next=p2;
	p2->next=p3;
	p3->next=p4;
	p4->next=p5;
	p5->next=p3;
	
	//print(start);
	
	struct node* loopNode;
	loopNode = check_loop(start);
	cout<<"loop at position : "<<loopNode<<" and data is : ";
	cout<<loopNode->data;
	cout<<endl;
	remove_loop(start,&loopNode);
	
	cout<<"Linked list after removing loop : ";
	print(start);
	
}
