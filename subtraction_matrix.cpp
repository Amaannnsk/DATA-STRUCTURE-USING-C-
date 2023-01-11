//------SUBTRACTION MATRIX------//

#include<iostream>
using namespace std;

class subtraction
{
    int a[2][2] , b[2][2] , c[2][2];
    public:
    void input();
    void subtract();
    void output();
};

void subtraction :: input()
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

void subtraction :: subtract()
{
    for(int i=0 ; i<2 ; i++)
    {
        for(int j=0 ; j<2 ; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void subtraction :: output()
{
    cout<<"The result of matrix subtraction is: \n";
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
    subtraction obj;
    obj.input();
    obj.subtract();
    obj.output();
    return 0;
}
