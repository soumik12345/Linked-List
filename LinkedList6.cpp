//Program to reverse a linked list using recursion 

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

void Print()//method to print the list
{
	Node* temp=head;//creating a new node pointin to head
	cout<<"The list is: ";
	while(temp!=NULL)//the loop runs till the end of the list
	{
		cout<<temp->data<<" ";//the data for the current node is printed
		temp=temp->next;//we move the pointer to the next node
	}
	cout<<endl;
}

void Reverse(Node* p)
{
	if(p->next==NULL)
	{
		head=p;
		return;
	}
	Reverse(p->next);
	Node* q=p->next;
	q->next=p;
	p->next=NULL;
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
		Print();//method call to print the list
	}
	Reverse(head);
	cout<<"List in reverse order: "<<endl;
	Print();
	return 0;
}
