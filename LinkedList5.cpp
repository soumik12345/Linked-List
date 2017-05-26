//Program to print elements of a linked list in forward and reverse order using recursion 

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void Insert_beg(int x)//method to insert at the beginning of the list
{
	Node* temp=(Node*)(malloc(sizeof(Node)));//we create a new node temp
	temp->data=x;//we set the data of the node to the data entered by the user
	temp->next=head;//We point the next node to temp as the previous head
	head=temp;//We set temp as the new head
}

void Print(Node* p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		Print(p->next);
	}
	else
		cout<<endl;
}

void reversePrint(Node* p)
{
	if(p!=NULL)
	{
		reversePrint(p->next);
		cout<<p->data<<" ";
	}
	else
		cout<<endl;
}

int main()
{
	cout<<"Enter the number of inputs: ";
	int n,i,x;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the data to be inserted: ";
		cin>>x;
		Insert_beg(x);//method call to insert at the beginning of the list
		Print(head);//method call to print the list
	}
	cout<<"List in reverse order: ";
	reversePrint(head);
}
