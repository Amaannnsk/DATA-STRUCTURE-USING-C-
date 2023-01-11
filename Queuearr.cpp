//--------QUEUE USING ARRAY----------//

#include<iostream>
using namespace std;
#define MAX 10

class Queue
{
    int arr[MAX];
    int front = -1;
    int rear =-1;
    
    public :
    void enQueue();
    void deQueue();
    void peek();
    void display();
};

void Queue ::enQueue()
{
    int data;
    if(rear==MAX -1) //Queue is full
    cout<<"QUEUE IS FULL !"<<endl;
    else if(front == -1 && rear == -1) //Queue is empty
    {
        front=0;
        rear=0;
        cout<<"Insert the element in queue : ";
        cin>>data;
        arr[rear]=data;
    }
    else
    {
        rear++;
        cout<<"Insert the element in queue : ";
        cin>>data;
        arr[rear]=data;
    }
} 

void Queue :: deQueue()

{
    if (front == -1 && rear == -1) // Queue is empty
    cout<<"QUEUE IS EMPTY !"<<endl;
    else if(front == rear) //only one element present
    {
        cout<<"Deletd data : "<<arr[front]<<endl;
        front = -1;
        rear = -1;
    } 
    else
    {
        cout<<"Deleted data : "<<arr[front]<<endl;
        front++;
    }
}

void Queue :: peek() // to show peek value

{
    if (front == -1 && rear == -1)
        cout<<"QUEUE IS EMPTY!"<<endl;
    else
        cout<<"Peeked value: "<<arr[front]<<endl;
}

void Queue :: display () // Display the elements .
{
    int i;
    if (front == -1 && rear == -1)
        cout<<"QUEUE IS EMPTY !"<<endl;
    else
    {
        cout<<"Queue is : "<<endl;
        for (i=front;i<=rear;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    int choice;
    Queue que;
    do
    {
        cout<< "\n\n------QUEUE USING ARRAY------"<<endl;

        cout<<"1.EnQueue"<<endl;
        cout<<"2.DeQueue"<<endl;
        cout<<"3.Peek"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                que.enQueue();
                break;

            case 2:
                que.deQueue();
                break;

            case 3:
                que.peek();
                break;

            case 4:
                que.display();
                break;
                
            default:
                cout<<"Wrong choice.\n";
        }
    }
    while (choice<5);
    return 0;
}