//-----------QUEUE USING LINKED LIST------------//

#include<iostream>
#include<stdlib.h>

using namespace std;

//structure of Node
struct Node
{
    int data;
    Node *Next;
};

class queue
{
    Node *front = NULL; // for deQueue
    Node *rear = NULL; // for enQueue

    public :
    bool isempty();  //To check if queue is empty or not.
    void enQueue(int value); //To enter elements in queue
    void deQueue(); //Delete element from queue
    void peek(); //Show the element at front
    void display(); //Display elements

};

void queue :: enQueue(int value)

{
    Node *ptr = new Node();
    ptr -> data = value;
    ptr -> Next = NULL;

    if( front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear -> Next = ptr;
        rear = ptr;
    }

}

bool queue :: isempty()

{
    if (front == NULL && rear == NULL)
    return true;
    else
    return false;
}

void queue :: deQueue()

{
    if( isempty())
    cout<<"---QUEUE IS EMPTY---\n";
    else
    if (front == rear)
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
    Node *ptr = front;
    front = front -> Next;
    free(ptr);
    }
}

void queue :: peek()

{
    if ( isempty())
    cout<<"---QUEUE IS EMPTY--- \n";
    else
    cout<<"The TOP Element is : " << front ->data;
}

void queue ::display()
{

    if(isempty())
    cout<<"Queue is empty\n";
    else
    {
        Node *ptr = front;
        while(ptr != NULL)
        {
            cout<<ptr ->data << " -> ";
            ptr = ptr -> Next;
        }

    }

}

int main()
{
    int choice,flag=1,value;
    queue que;
    while(flag == 1)
    {
        cout<< "\n\n*****QUEUE USING LINKED LIST*****";


        cout<<"\n1 Insert Element to Queue."<<endl;

        cout<<"2 Delete Element from Queue. "<<endl;

        cout<<"3 Display TOP Element. "<<endl;

        cout<<"4 Display all Elements of Queue. "<<endl;

        cout<<"5 to exit"<<endl;
        
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1: cout<<"Enter Value : \n";
                cin>>value;
                que.enQueue(value);
                break;

            case 2 : que.deQueue();
                break;

            case 3 : que.peek();
                break;

            case 4 :cout<<"Elements are : " ;
                    que.display();    
                break;

            case 5 : exit(0);
                break;

            default:
			cout<<"\n Enter valid choice.";// if entered wrong choice
			break;    

            
        }
    }
    return 0;
}