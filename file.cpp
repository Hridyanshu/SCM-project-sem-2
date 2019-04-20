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
