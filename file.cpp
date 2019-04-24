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

/*
 * Node Declaration
 */

struct dnode
{
    int info;
    struct dnode *next;
    struct dnode *prev;
}*start;
 
/*
 Class Declaration 
 */

class double_llist
{
    
      public:
        
	void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        
	double_llist()
        {
            start = NULL;  
        }
};

/*
 * Create Double Link List
 */

void double_llist::create_list(int value)
{
    
    struct dnode *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    
    else
    {
        
	    s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }

}
 
/*
 * Insertion at the beginning
 */

void double_llist::add_begin(int value)
{
    
    if (start == NULL)
    {
        
	cout<<"First Create the list."<<endl;
        return;
    
    }
    
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;

}
 
/*
 * Insertion of element at a particular position
 */

void double_llist::add_after(int value, int pos)
{
    
    if (start == NULL)
    {
    
	cout<<"First Create the list."<<endl;
        return;
    
    }
    
    struct node *tmp, *q;
    
    int i;
    
    q = start;
    
    for (i = 0;i < pos - 1;i++)
    {
        
	q = q->next;
        
	if (q == NULL)
        {
           
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        
	}
    
    }
    
    tmp = new(struct node);
    tmp->info = value;
    
    if (q->next == NULL)
    {
        
	q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    
    }
    
    else
    {
        
	tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    
    }
    
    cout<<"Element Inserted"<<endl;

}
 
/*
 * Deletion of element from the list
 */

void double_llist::delete_element(int value)
{
    
     struct node *tmp, *q;
     
     /*first element deletion*/
    
    if (start->info == value)
    {
        
	tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    
    }
    
    q = start;
    
    while (q->next->next != NULL)
    {   
        
	/*Element deleted in between*/
        
	if (q->next->info == value)  
        {
            
	    tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        
	}
        
	q = q->next;
    
    }

     /*last element deleted*/
    
    if (q->next->info == value)    
    { 	
        
	tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    
    }
    
    cout<<"Element "<<value<<" not found"<<endl;

}
 
/*
 * Display elements of Doubly Link List
 */

void double_llist::display_dlist()
{
    
    struct node *q;
    
    if (start == NULL)
    {
        
	cout<<"List empty,nothing to display"<<endl;
        return;
    
    }
    
    q = start;
    
    cout<<"The Doubly Link List is :"<<endl;
    
    while (q != NULL)
    {
        
	cout<<q->info<<" <-> ";
        q = q->next;
    
    }
    
    cout<<"NULL"<<endl;

}
 
/*
 * Number of elements in Doubly Link List
 */

void double_llist::count()
{ 	
    
    struct node *q = start;
    
    int cnt = 0;
    
    while (q != NULL)
    {
        
	q = q->next;
        cnt++;
    
    }
    
    cout<<"Number of elements are: "<<cnt<<endl;

}
 
/*
 * Reverse Doubly Link List
 */

void double_llist::reverse()
{
    
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    
    while (p2 != NULL)
    {
        
	p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    
    }
    
    start = p1;
    
    cout<<"List Reversed"<<endl; 

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
	}
	while(choice!=4);
	return 0;
}
