//---------DOUBLY LINKED LIST------------//

#include<iostream>
using namespace std;

//structure of Node
struct node
{
    struct node *prev; //Previous pointer
    int data; //Data
    struct node *next; // next pointer
}*start;

class doubly

{
    public :
    void create(int value);
    void insert_beg(int DATA);
    void insert_end(int DATA);
    void insert_after(int DATA , int pos);
    void delete_beg();
    void delete_end();
    void delete_position(int pos);
    void display(struct node *ptr1);
    int count(struct node *ptr1);
    int search(int value);
};

void doubly :: create(int value) // To create circular linked list

{
    int i, DATA;
    struct node *ptr , *ptr1;
    start  = new node;
    cout<<"Enter the data of node 1 : ";
    cin>>DATA;
    start -> data = DATA;
    start -> next = start -> prev = NULL;
    ptr1 = start;
    for(i = 1;i<value;i++)
    {
        ptr  =  new node;
        cout<<"Enter the data of node "<<i+1<<" : ";
        cin>>DATA;
        ptr -> data =  DATA;
        ptr -> prev =  ptr1;
        ptr -> next =  NULL;
        ptr1 -> next = ptr;
        ptr1 = ptr;
    }
}

void doubly::insert_beg(int DATA)  // to Insert at Beginning

{
    struct node *ptr;
    ptr  =  new node;
    ptr -> data =  DATA;
    ptr -> next =  start;
    ptr -> prev =  NULL;
    start -> prev = ptr;
    start = ptr;
}

void doubly::insert_after(int DATA , int pos) // Insert after

{
    struct node* ptr  = new node , *ptr1  = start;
    ptr -> data = DATA;
    for(int i = 0;i<pos-1;i++)
    {
        ptr1 = ptr1 -> next;
    }
    ptr -> next = ptr1 -> next;
    ptr -> prev = ptr1;
    if(ptr1 -> next != NULL)
    {
        ptr1 -> next -> prev = ptr;
    }
    ptr1 -> next = ptr;
}

void doubly::insert_end(int DATA) // Insert at end

{
    struct node *ptr, *ptr1;
    ptr1 = start;
    ptr  =  new node;
    ptr -> data =  DATA;
    ptr -> next =  NULL;
    while(ptr1 != NULL)
    {
        if(ptr1 -> next == NULL)
        {
           ptr1 -> next = ptr;
           ptr -> prev = ptr1;
           break;
        }
        ptr1 = ptr1 -> next;
    }
}

void doubly::delete_beg() // Delete beginning

{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    if(start != NULL)
    {
    start -> prev = NULL;
    }
    cout<<ptr -> data<< " HAS BEEN DELETED";
    delete(ptr);
}

void doubly::delete_position(int pos) //Delete at given Position

{
    struct node *ptr1 = start;
    for(int i = 0;i<pos-1 && ptr1 != NULL;i++)
    {
        ptr1 = ptr1 -> next;
    }
    ptr1 -> prev -> next = ptr1 -> next;
    if(ptr1 -> next != NULL)
    {
        ptr1 -> next -> prev = ptr1 -> prev;
    }
    cout<<ptr1 -> data<< " HAS BEEN DELETED";
    delete(ptr1);
}

void doubly::delete_end()  //delete at end

{
    struct node *ptr1 = start;
    while(ptr1 != NULL)
    {
        if(ptr1 -> next == NULL)
        {
           cout<<ptr1 -> data<< " HAS BEEN DELETED";
           ptr1 -> prev -> next = NULL;
           delete(ptr1);
           break;
        }
        ptr1 = ptr1 -> next;
    }
}

int doubly::count(struct node *ptr1) // Count number of nodes

{
    int count = 0;
    while (ptr1 != NULL)
    {
        count++;
        ptr1 = ptr1->next;
    }
    return count;
}

int doubly::search(int value) // Search the elements

{
    struct node *ptr = start;
    int pos = 1;
    while (ptr != NULL)
    {
        if (ptr->data == value)
        {
            return pos;
        }
        ptr = ptr->next;
        pos++;
    }
    return -1;
}

void doubly::display(struct node *ptr1) // Display the Elements

{
    while(ptr1 != NULL)
    {
        cout<<ptr1 -> data<<" ";
        ptr1 = ptr1 -> next;
    }
}

int main()
{
    int choice,n,m,position;
    doubly dl;
    cout<<"Enter the total number of nodes : ";
    cin>>n;
    dl.create(n);
    while(1)
    {
        cout<<"\n\n----------------------------\n";
        cout<<"    DOUBLY LINKED LIST\n";
        cout<<"----------------------------\n";
        cout<<"1.Insert Node at beginning\n";
        cout<<"2.Insert node at last\n";
        cout<<"3.Insert node at position\n";
        cout<<"4.Delete node from beginning\n";
        cout<<"5.Delete node from last\n";
        cout<<"6.Delete node from position\n";
        cout<<"7.Count the total number of nodes\n";
        cout<<"8.Search for a value in the list\n";
        cout<<"9.Show the elements of the list\n";
        cout<<"10.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 :
            {
                cout<<"Enter the data : ";
                cin>>m;
                dl.insert_beg(m);
                break;
            }

            case 2:
            {
                cout<<"Enter the data : ";
                cin>>m;
                dl.insert_end(m);
                break;
            }

            case 3:
            {
                cout<<"Enter the data : ";
                cin>>m;
                cout<<"Enter the position : ";
                cin>>position;
                dl.insert_after(m,position);
                break;
            }

            case 4:
            {
                dl.delete_beg();
                break;
            }

            case 5:
            {
                dl.delete_end();
                break;
            }

            case 6:
            {
                cout<<"Enter the position of the node to be deleted : ";
                cin>>position;
                dl.delete_position(position);
                break;
            }

            case 7:
            {
                cout << "Number of nodes in the list: " << dl.count(start) << endl;
                break;
            }

            case 8:
            {
                cout << "Enter the value to search for: ";
                cin >> m;
                position = dl.search(m);
                if (position != -1)
                {
                    cout << "Value found at position " << position << endl;
                }
                else
                {
                    cout << "Value not found" << endl;
                }
                break;
            }

            case 9:
            {
                dl.display(start);
                break;
            }

            case 10:
            {
                exit(1);
                break;
            }

            default:
            {
                cout<<"Wrong choice\n";
            }
        }
    }
    return 0;
}
