//-----------QUICK SORT-----------//

#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
int quick;
quick = *a;
*a = *b;
*b=quick;
}

int partition(int A[], int left,int right) // partition the array where partitioning elemment returned is sorted
{
    int loc=A[left];  //pivot is set at low 
    int i=left,j=right;
    do
    {
        do{i++;}while(A[i]<=loc);  //find element greater than loc , stop when A[i]>loc
        do{j--;}while(A[j]>loc); //find element smaller than loc ,stop when A[j]<=loc
        if(i<j)
        {
            swap(&A[i],&A[j]); //swap till i>=j
            
        }
    }
    while(i<j);
    swap(&A[left],&A[j]);
    return j;

}

void quicksort(int A[], int left,int right)
{
    if(left<right)
    {
        int j=partition(A,left,right); //PARTITION POSITION
        quicksort(A,left,j); //Recursive quicksort on left part of the partition
        quicksort(A,j+1,right); //Recursive quicksort on right part of the partition
    }
}
int main()
{
    int A[30],n;
    cout<<"ENTER ARRAY SIZE : ";
    cin>>n;
    cout<<"ENTER ARRAY ELEMENTS : ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];

    }
    quicksort(A,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
}