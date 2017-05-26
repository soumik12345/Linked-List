//Program to reverse a linked list iteratively

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

void Reverse()//method to reverse the list
{
	Node* current;//stores the current node
	Node* prev;//stores the adress of the node previous to current
	Node* next;//stores the address of the node next to current
	current=head;//temp initialised as head
	prev=NULL;//previoud of head is NULL
	while(current!=NULL)//traversing the list
	{
		next=current->next;//next is set to next of the current node
		current->next=prev;//the current node points to the previous one
		prev=current;//the previous node becomes the current node
		current=next;//the current node becomes the next node
	}
	head=prev;//adjusting head
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
	Reverse();//method call to reverse the list
	cout<<"Link in reverse order: "<<endl;
	Print();
	return 0;
}
