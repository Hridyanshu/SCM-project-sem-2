#include<iostream>
using namespace std;
class Stack
{
	int data[50],size,i,top;
	public:
	Stack()
	{
		top=-1;
		cout<<"Enter the size of stack"<<endl;
		cin>>size;
	}
	void push()
	{
		if (top==size-1)
		{
			cout<<"\nOverflow condition!\n No element can be inserted!!"<<endl;
		}
		else
		{
			cout<<"Enter the element to be inserted"<<endl;
			cin>>data[top+1];
			top++;
		}
	}	
	void pop()
	{
		if(top==-1)
		{
			cout<<"\nUnderflow condition!\n Stack is already empty!!"<<endl;
		}
		else
		{
			top--;
		}
	}
	void display()
	{
		for(i=0;i<=top;i++)
		{
			cout<<data[i]<<endl;
		}
	}
};

/*****************Singly Linklist - Ingit***************/

class List:public Node
{

    Node *first,*last;
public:
    List()
    {
        first=NULL;
        last=NULL;
    }
    void create();
    void insert();
    void delet();
    void display();
    void search();
};

void List::create()
{
    Node *temp;
    temp=new Node;
    int n;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    if(first==NULL)
    {
        first=temp;
        last=first;
    }
 
    else
    {
        last->next=temp;
        last=temp;
    }
}
void List::insert()
{
    Node *prev,*cur;
    prev=NULL;
    cur=first;
    int count=1,pos,ch,n;
    Node *temp=new Node;
    cout<<"\nEnter an Element:";
    cin>>n;
    temp->info=n;
    temp->next=NULL;
    cout<<"\nINSERT AS\n1:FIRSTNODE\n2:LASTNODE\n3:IN BETWEEN FIRST&LAST NODES";
    cout<<"\nEnter Your Choice:";
    cin>>ch;
    switch(ch)
    {
    case 1:
        temp->next=first;
        first=temp;
        break;
    case 2:
        last->next=temp;
        last=temp;
        break;
    case 3:
        cout<<"\nEnter the Position to Insert:";
        cin>>pos;
        while(count!=pos)
        {
            prev=cur;
            cur=cur->next;
            count++;
        }
        if(count==pos)
        {
            prev->next=temp;
            temp->next=cur;
        }
        else
            cout<<"\nNot Able to Insert";
        break;
 
    }
}

int main()
{
	Stack obj;
	int choice;
	do
	{
		cout<<"\nEnter your choice\n1.Push\n2.Pop\n3.Display\n4.Exit"<<endl;
		cin>>choice;
		switch (choice)
		{
			case 1: obj.push();
			break;
			case 2: obj.pop();
			break;
			case 3: obj.display();
			break;
			default: cout<<"PROGRAM TERMINATED."<<endl;
		}
	}while(choice!=4);
	return 0;
}
