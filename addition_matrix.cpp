//-------ADDITION MATRIX-------//

#include<iostream>
using namespace std;

class addition
{
    int a[2][2] , b[2][2] , c[2][2];
    public:
    void input();
    void add();
    void output();
};

void addition :: input() //Input the elements in matrix
{
    cout<<"Enter the elements in matrix A: \n";
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
    cin>>a[i][j];
    }

    cout<<"Enter the elements in matrix B: \n";
    for(int i =0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            cin>>b[i][j];
        }
    }
}

void addition :: add() // Function to add matrix
{
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void addition :: output() // display the matrix
{
    cout<<"The result of matrix addition is: \n";
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    addition obj;
    obj.input();
    obj.add();
    obj.output();
    return 0;
}
