#include<iostream>
using namespace std;
void bubble_sort(int a[], int n)
{
    bool flag;
    for(int i=0; i<n-1; i++)
    {
        flag=false;
        for(int j=0; j<n-1-i; j++)
        {
            if(a[j]>a[j+1])
                swap(a[j], a[j+1]);
                flag=true;
        }
        if(flag==false)
        break;
    }
}
void print(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<"Before sorting: ";
    print(a, n);
    cout<<"After sorting: ";
    bubble_sort(a, n);
    print(a, n);

    return 0;
}
