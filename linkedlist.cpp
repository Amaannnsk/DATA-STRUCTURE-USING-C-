//-----------SINGLY LINKED LIST------------//

#include<iostream>
#include<stdlib.h>
using namespace std;

//structure of Node
struct Node
{
    int data;
    Node *next; 
};

class linkedlist

{
    Node *start = NULL; // point start node as NULL


    public:
    void create();
    void insert_beg();
    void insert_after();
	void insert_before();
    void insert_end();
    void delete_beg();
    void delete_position();
    void delete_end();
    void display();
    void search();
    int count_nodes();

};

void linkedlist::create() // to create linked list
{
        Node *n;
        int value; 
        n = new Node();
        n->next = NULL;
        cout << "Enter element: ";
        cin >> value;
        n->data = value;
        if(start == NULL)
            start = n;
        else
		{
            Node *ptr;
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = n;
        }
    }


void linkedlist::insert_beg()  // to Insert Element at Beginning
{
	    Node *n;
	    int value;
	    n = new Node();
	    cout << "Enter value: ";
	    cin >> value;
	    n->data=value;
	    if(start==NULL)
		{
		    n->next=NULL;
		    start=n;	
		    cout << "\nValue is inserted in beginning." << endl;
	    }
	    else
		{
		    n->next=start;
		    start=n;
		    cout << "\nValue is inserted in beginning." << endl;
	    }
        display();
    }

void linkedlist::insert_after()
{
        Node *newnode,*ptr2,*ptr;
	    int value,position;
	    newnode = new Node();
	    
	cout << "\nEnter position: "; // On which position changes to be made
		cin >> position;
    cout << "\nEnter value: ";
        cin >> value;
		newnode->data=value;


		ptr2=start;
		for(int i=0;i<position-1;i++)
		{
			ptr=ptr2;
			if(ptr==NULL) // If user entered wrong position
			{
				cout << "\nValue can't be inserted.....Please insert correct position";
				return;		
			}	
			ptr2=ptr2->next;
		}
		newnode->next=ptr2;
		ptr->next=newnode;
		cout << "\nValue inserted at: " << position << endl;
        display();
    }

void linkedlist::insert_before() // Insert element before given position
{
	Node *newnode,*ptr2;
	int value,Position;
	newnode = new Node();

	cout << "\n Enter Value : ";
	cin >> value;
	newnode ->data = value;
	cout << " \n Enter Position before which you want to insert : ";
	cin >> Position;

	if (start -> data == Position)
	{
		newnode -> next=start;
		start=newnode;
	}
	else
	{
		ptr2=start;
		while(ptr2 -> next -> data!=Position)
		ptr2=ptr2 ->next;
		newnode ->next=ptr2->next;
		ptr2 -> next=newnode;

	}
	cout << "\n Value is inserted before Position value ." <<endl;
	display();
}

void linkedlist::insert_end() // Insert at end
{
	    Node *newnode,*ptr2;
	    int value;
	    newnode = new Node();
	    
		cout << "\nEnter value: ";
		cin >> value;
		newnode->data=value;
		if(start==NULL)
		{
			newnode->next=NULL;
			start=newnode;
			cout<<"\nValue is inserted at last." << endl;
		}
		else
		{
			ptr2=start;
			while(ptr2->next!=NULL)
				ptr2=ptr2->next;
			newnode->next=NULL;
			ptr2->next=newnode;
			cout<<"\nValue is inserted at last." << endl;
		}
        display();
    }

    void linkedlist::delete_beg() // Delete beginning
    {
	    Node *ptr2;
	    if(start==NULL)
		{
		    cout << "\nList empty." << endl;
		    return;
	    }
	    else
		{
		    ptr2=start;
		    start=ptr2->next;
		    free(ptr2);
		    cout << "\nNode deleted from beginning" << endl;
        }
        display();
    }

    void linkedlist::delete_position() //Delete at given Position
    {
	    Node *ptr2,*ptr;
	    int position;
	    if(start==NULL)
		{
		    cout << "\nList empty." << endl;
		    return;
	    }
	    else
		{
		    ptr2=start;
		    cout << "\nEnter position: ";
		    cin >> position;
		
		    for(int i=0;i<position-1;i++)
			{
			    ptr=ptr2;
			    ptr2=ptr2->next;
			    if(ptr==NULL)
				{
				    cout<<"\nCAN'T DELETE." << endl; // if list is empty
				    return;
			    }
		    }
		    ptr->next=ptr2->next;
		    free(ptr2);
		    cout<<"\nNode deleted at position " << position << endl;
	    }
        display();
    }

    void linkedlist::delete_end()  //delete at end
    {
       Node *ptr2,*ptr;
	    if(start==NULL) // TO check whether list is empty or not to delete
		{
		    cout << "\nList Empty." << endl;
		    return;
	    }
	    else if(start->next==NULL)
		{
		    start==NULL;
		    free(start);
		    cout << "\nNode deleted." << endl;
		    return;
	    }
	    else
		{
		    ptr2=start;
		    while(ptr2->next!=NULL)
			{
			    ptr=ptr2;
			    ptr2=ptr2->next;
		    }
		    ptr->next=NULL;
		    free(ptr2);
		    cout << "\nNode deleted from last." << endl;
	    }
        display();
    }

void linkedlist::display() // Display the elements 
	{
        Node *ptr2;
        ptr2 = start;
        while(ptr2 != NULL)
		{
            cout << ptr2->data << " ";
            ptr2 = ptr2->next;
        }
    }

void linkedlist::search() // search the elements in list
{
        Node *ptr2;
	    int value,flag=0;
	    if(start==NULL)
		    cout << "\nList is empty." << endl;
	    else
		{
		    ptr2=start;
		    cout << "\nEnter value: ";
		    cin >> value;
		    for(int i=0;ptr2!=NULL;i++)
			{
			    if(ptr2->data==value)
				{
				    cout << "\nValue is found at position " << i+1 << endl;
				    flag=0;
				    return;
			    }
			    else
				    flag=1;
			    ptr2=ptr2->next;
		    }
		    if(flag==1)
			    cout << "\nValue not found." << endl;
	    }
        display();   
    }
int linkedlist::count_nodes() // count No.of nodes or element in list
  
    {
      Node* ptr2 = start;
     int cnt = 0;
      while(ptr2 != NULL)
	  {
        cnt++;
        ptr2 = ptr2->next;
      }
      return cnt;  
    } 

int main()
{
    int n;
    linkedlist list;
    cout<< "Enter the Number of Elements : ";
    cin >> n;
    for(int i=0; i<n; i++)
    list.create();
    list.display();
    int all=0,insr,del;
	while(all!=6)

	{
		cout<< "\n\n*****MENU*****";

		cout<< "\n 1)Insert \n 2)Delete \n 3)Search \n 4)Display \n 5)Count the nodes \n 6)Exit \n";
		cout<<"ENTER THE CHOICE : ";
		cin>>all;

		switch(all) // Here we will be using nested switch statement
		{

			case 1:
			cout<<"\n 1) Insert at the beginning.";
			cout<<"\n 2) Insert at the after given position.";
			cout<<"\n 3) Insert at the before given position.";
			cout<<"\n 4) Insert at the end.";
			
            cout<<"\n Enter the option to Insert : ";
			cin>>insr;

			switch(insr)

			{
				case 1:
				list.insert_beg();
				break;
                
				case 2:
				list.insert_after();
				break;

				case 3:
				list.insert_before();

				case 4:
				list.insert_end();

				

			}
            break;

			case 2:
			cout<<"\n 1) Delete at the beginning.";
			cout<<"\n 2) Delete at given position.";
			cout<<"\n 3) Delete in last.";

			cout<<"\n Enter the option to Delete : ";
            
			cin>>del;

			switch(del)

			{
				case 1:
				list.delete_beg();
				break;
                
				case 2:
				list.delete_position();
				break;

				case 3:
				list.delete_end();

			}
            break;

			case 3:
			list.search();
			break;    


			case 4:
			list.display();
			break;
            

			case 5:
			cout<<"Total no. of Nodes : "<<list.count_nodes();
			break;
			

			case 6:
			exit(0);
			break;

			

			default:  // if user entered wrong case 
			cout<<"\n Enter valid choice.";
			break;
		}
	}
}