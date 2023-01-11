//-------TRANSPOSE MATRIX-------//

#include<iostream>
using namespace std;
class trans
{
    int a[2][3], b[3][2];
    public:
    void input();
    void output1();
    void Transpose();
    void output2();
};

 void trans::input()
{
    cout<<"enter the elements of matrix\n";
    for(int i = 0; i<2; i++)
    {
        for(int j = 0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
}

void trans::output1()
{
    cout<<"the elements of matrix\n";
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void trans::Transpose()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            b[i][j] = a[j][i];
        }
    }
}
void trans::output2()
{
    cout<<"Matrix after transpose\n";
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<" \n";
    }
}
int main() {
    trans t;
    t.input();
    t.output1();
    t.Transpose();
    t.output2();
    return 0;
}