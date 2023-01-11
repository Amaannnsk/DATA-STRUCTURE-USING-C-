//-----------CIRCULAR LINKED LIST------------//

#include <iostream>
using namespace std;

//structure of Node
struct node
{
    int data;
    struct node *next;
};
struct node *last; // THERE IS NO NULL POINTER IN CIRCULAR LINKED LIST.

class CIRCULAR

{

public:
    void create_list();
    void insert_begin();
    void insert_end();
    void insert_pos();
    void delete_begin();
    void delete_pos();
    void delete_end();
    void search();
    void sort();
    void display();
    void reverse();

};

void CIRCULAR::create_list() // To create circular linked list
{
    int VALUE;
    cout << "Enter the number of elements in the list: ";
    cin >> VALUE;

    struct node *ptr;
    ptr = new node;
    int value;
    cout << "Input the value of node: ";
    cin >> value;
    ptr->data = value;
    last = ptr;
    last->next = last;

    for (int i = 1; i < VALUE; i++)
    {
        ptr = new node;
        cout << "Input the value of node: ";
        cin >> value;
        ptr->data = value;
        ptr->next = last->next;
        last->next = ptr;
        last = ptr;
    }
}

void CIRCULAR::insert_begin() // To Insert Element at Beginning
{
    struct node *ptr;
    ptr = new node;
    int value;
    cout << "Input the value of node: ";
    cin >> value;
    ptr->data = value;
    ptr->next = last->next;
    last->next = ptr;
}

void CIRCULAR::insert_end() // To insert element at end
{
    struct node *ptr;
    ptr = new node;
    int value;
    cout << "Input the value of node: ";
    cin >> value;
    ptr->data = value;
    ptr->next = last->next;
    last->next = ptr;
    last = ptr;
}

void CIRCULAR::insert_pos() // To insert element at given position
{
    struct node *ptr, *ptr1;
    ptr1 = last->next;
    int value;
    int pos;
    cout << "Input the position where the node is to be inserted: ";
    cin >> pos;
    cout << "Input the value of node: ";
    cin >> value;
    ptr = new node;
    ptr->data = value;
    for (int i = 1; i < pos; i++)
    {
        if (ptr1 == last)
        {
            break;
        }
        ptr1 = ptr1->next;
    }
    ptr->next = ptr1->next;
    ptr1->next = ptr;
}

void CIRCULAR::delete_begin() // Delete node or Element at beginning
{
    struct node *ptr;
    ptr = last->next;
    last->next = ptr->next;
    delete ptr;
}


void CIRCULAR::delete_pos() // Delete node or Element at given position
{
    struct node *ptr, *ptr1;
    ptr1 = last->next;
    int pos;
    cout << "Input the position where the node is to be deleted: ";
    cin >> pos;
    for (int i = 1; i < pos; i++)
    {
        if (ptr1 == last)
        {
            break;
        }
        ptr = ptr1;
        ptr1 = ptr1->next;
    }
    ptr->next = ptr1->next;
    delete (ptr1);
}

void CIRCULAR::delete_end() // Delete node or Element at end
{
    struct node *ptr, *ptr1;
    ptr1 = last->next;
    while (ptr1->next != last)
    {
        ptr = ptr1;
        ptr1 = ptr1->next;
    }
    ptr->next = ptr1->next;
    last = ptr;
    delete ptr1;
}


void CIRCULAR::search() // Search element
{
    struct node *ptr1;
    int item;
    int flag;
    cout << "Input the value to be searched: ";
    cin >> item;
    ptr1 = last->next;
    while (ptr1 != last)
    {
    if (ptr1->data == item)
    {
        flag = 1;
        break;
    }
    ptr1 = ptr1->next;
}
if (flag == 1)
{
    cout << "Element found" << endl;
}
else
{
    cout << "Element not found" << endl;
}
}

void CIRCULAR::sort() // Sort the elements 
{
    struct node *ptr1;
    struct node *ptr2;
    int ptr;
    ptr1 = last->next;
    while (ptr1->next != last)
    {
        ptr2 = ptr1->next;
        while (ptr2 != last->next)
        {
            if (ptr1->data > ptr2->data)
            {
                ptr = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = ptr;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void CIRCULAR::display() // Display the elements
{
    struct node *ptr1;
    ptr1 = last->next;
    cout << "The list is: " << endl;
    while (ptr1 != last)
    {
        cout << ptr1->data << " ";
        ptr1 = ptr1->next;
    }
    cout << ptr1->data << endl;
}

void CIRCULAR::reverse() //Reverse all Elements

{
    struct node *Ptr1, *Ptr2;
    Ptr1 = last;
    Ptr2 = Ptr1->next;
    Ptr1->next = NULL;
    Ptr1 = Ptr2;
    while (Ptr2 != last)
    {
        Ptr2 = Ptr2->next;
        Ptr1->next = last;
        last = Ptr1;
        Ptr1 = Ptr2;
    }
}

int main()

{
    CIRCULAR obj;
    int choice;
    while (1)

    {
        cout<<"\n\n-------------------------------\n";
        cout<<"     CIRCULAR LINKED LIST\n";
        cout<<"-------------------------------\n";
        cout << "\n1. Create List" << endl;
        cout << "2. Insert at beginning" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Insert at position" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from end" << endl;
        cout << "7. Delete from position" << endl;
        cout << "8. Search for an element" << endl;
        cout << "9. Sort the list" << endl;
        cout << "10. Reverse the list" << endl;
        cout << "11. Display the list" << endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.create_list();
            break;

        case 2:
            obj.insert_begin();
            break;

        case 3:
            obj.insert_end();
            break;

        case 4:
            obj.insert_pos();
            break;

        case 5:
            obj.delete_begin();
            break;

        case 6:
            obj.delete_end();
            break;

        case 7:
            obj.delete_pos();
            break;

        case 8:
            obj.search();
            break;

        case 9:
            obj.sort();
            break;

        case 10:
            obj.reverse();
            break;

        case 11:
            obj.display();
            break;

        default:
            cout << "Invalid choice" << endl; // If user entered wrong case
        }
    }
    return 0;
}
