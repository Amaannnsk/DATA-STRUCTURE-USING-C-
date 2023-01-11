#include <iostream>
using namespace std;
class multi
{
    int a[2][3], b[3][2], c[2][2];
    public:
    void input1();
    void input2();
    void output1();
    void output2();
    void multiplication();
    void output3();
};
 void multi::input1()
{
    cout<<"enter the elements of matrix A\n";
    for(int i = 0; i<2; i++)
    {
        for(int j = 0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
}

void multi::input2()
{
    cout<<"enter the elements of matrix B\n";
    for(int i=0; i<3;i++)
    {
        for(int j=0; j<2;j++)
        {
            cin>>b[i][j];
        }
    }
}

void multi::output1()
{
    cout<<"Matrix A\n";
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void multi::output2()
{
    cout<<"Matrix B\n";
    for(int i=0; i<3;i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<" \n";
    }
}
void multi::multiplication()
{
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            c[i][j]= 0;
            for(int k=0; k<3; k++)
            {
            c[i][j] = (c[i][j]+(a[i][k]*b[k][j]));
            }
        }
    }
}
void multi::output3()
{
    cout<<"Matrix after multiplication\n";
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<" \n";
    }
}
int main()  
{
    multi m;
    m.input1();
    m.input2();
    m.output1();
    m.output2();
    m.multiplication();
    m.output3();
    return 0;
}
