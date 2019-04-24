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

struct cnode
{
    int info;
    struct cnode *next;
}*last;
 
/*
 * Class Declaration
 */

class circular_llist
{
    public:
        void create_node(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_list();
        void update();
        void sort();
        circular_llist()
        {
            last = NULL;           
        }
};

/*
 * Insertion of element at beginning
 */

void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    struct cnode *temp;
    temp = new(struct cnode);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}

/*
 * Insertion of element at a particular place 
 */

void circular_llist::add_after(int value, int pos)
{
    
    if (last == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    
    struct cnode *temp, *s;
    s = last->next;
    
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list"<<endl;
            return;
        }
    }
    
    temp = new(struct cnode);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;
    
    /*Element inserted at the end*/
    
    if (s == last)
    { 
        last=temp;
    }

}

/*
 * Deletion of element from the list
 */

void circular_llist::delete_element(int value)
{
    
    struct cnode *temp, *s;
    s = last->next;
    
    /* If List has only one element*/
    
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        free(temp);
        return;
    }
    
    if (s->info == value)  /*First Element Deletion*/
    {
        temp = s;
        last->next = s->next;
        free(temp);
        return;
    }
    
    while (s->next != last)
    {
        /*Deletion of Element in between*/
        if (s->next->info == value)    
        {
            temp = s->next;
            s->next = temp->next;
            free(temp);
            cout<<"Element "<<value;
            cout<<" deleted from the list"<<endl;
            return;
        }
        
	s = s->next;
    }
    
    /*Deletion of last element*/
    
    if (s->next->info == value)    
    {
        temp = s->next;
        s->next = last->next;
        free(temp);		
        last = s;
        return;
    }
    
    cout<<"Element "<<value<<" not found in the list"<<endl;
}

/*
 * Search element in the list 
 */

void circular_llist::search_element(int value)
{
    
    struct cnode *s;
    int counter = 0;
    s = last->next;
    
    while (s != last)
    {
        counter++;
        
	if (s->info == value)    
        {
            cout<<"Element "<<value; 
            cout<<" found at position "<<counter<<endl;
            return;
        }
        
	s = s->next;
    }
    
    if (s->info == value)    
    {
        counter++;             
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<endl;
        return;
    }
    
    cout<<"Element "<<value<<" not found in the list"<<endl;

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
