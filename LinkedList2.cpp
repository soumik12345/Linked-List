//Program to insert a node at the nth position

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

void Insert(int x, int n)
{
	Node* temp1=new Node();//newly created node temp1 which is to be inserted
	temp1->data=x;//we set the data of the node to the data entered by the user
	temp1->next=NULL;
	if(n==1)//If the node is to be positioned at the beginning
	{
		temp1->next=head;//We point the next node to temp as the previous head
		head=temp1;//We set temp as the new head
		return;
	}
	Node* temp2=head;
	for(int i=0;i<n-2;i++)//we move to the n-1 th node in the list
		temp2=temp2->next;
	//temp2 is now the n-1th node in the list
	temp1->next=temp2->next;//temp1 points to the next of n-1 th node
	temp2->next=temp1;//temp1 becomes next of n-1 th node
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

int Length()
{
	int c=0;//counter to count no of elements in the list
	Node* temp=head;//creating a new node pointin to head
	while(temp!=NULL)//the loop runs till the end of the list
	{
		c++;//updating the counter;
		temp=temp->next;//we move the pointer to the next node
	}
	return c;
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
	int N,X;
	cout<<"Enter the position of the list followed by the data: ";
	cin>>N>>X;
	if(N>=Length())
		cout<<"Sorry, the link of the list is "<<Length()<<".";
	else
	{
		Insert(X,N);
		Print();
	}
	return 0;
}
