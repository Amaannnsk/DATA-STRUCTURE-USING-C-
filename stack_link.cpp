//------------STACK USING LINKED LIST----------------//

#include<iostream>
using namespace std;

//structure of Node
struct Node 
{
    int data;
    Node *Next;

};
class stack

{
    Node *top = NULL; //intialize the top of stack to 0 or NULL using default like constructor

    public:
    bool isempty(); 
    void push(int value);
    void pop();
    void display();
    void peek();
};


void stack::push(int value)
{
    Node *ptr = new Node();
    ptr->data = value;
    ptr->Next = top;
    top = ptr;
}

bool stack::isempty()  // if the top of stack is 0, its empty and nothing to pop from stack
{
    if(top==NULL)
    return true;
    else 
    return false;
}

void stack::pop()
{
    if(isempty())
    cout<<"Stack is Empty";
    else    // if stack is not empty (When top is not equal to zero) element can be poped out of stack (Element can be removed from the top index stack)
    {
        Node *ptr = top; 
        top = top -> Next;
        free(ptr);  
    }
}

void stack::peek() // displays the top most element in the list
{
    if(isempty())
     cout<<"Stack is Empty";
    else
     cout<<"Element at top is : "<< top->data;
}

void stack::display() // display the elements of the stack
{
    if (isempty())
    cout<<"Stack is Empty";
    else
    {
        Node *temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->Next;
        }
        cout<<"\n";
    }
}

int main ()
{
    int choice,value;
    stack st;
    do{
        cout<<"\n\n***********LINKED STACK***********"<<endl;
        cout<<"1 for push"<<endl;
        cout<<"2 for pop"<<endl;
        cout<<"3 for peek"<<endl;
        cout<<"4 for display"<<endl;
        cout<<"5 to exit"<<endl;

        cout<<"Enter your choice: ";

        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the data: ";
                
                cin>>value;
                st.push(value);
                break;
            case 2:
                st.pop();
                cout<<endl;
                break;
            case 3:
                st.peek();
                cout<<endl;
                break;
            case 4:
                st.display();
                cout<<endl;
                break;

            case 5:
			exit(0);
			break;
        
            default:
			cout<<"\n Enter valid choice.";
			break;
        }
    }
	while (choice<6);
    return 0;
}
