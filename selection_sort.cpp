#include<bits/stdc++.h>
using namespace std;
void selection_sort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
                min=j;
        }
        if(min!=i)
            swap(a[i], a[min]);
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
        cin>>a[i];
    cout<<"Before sorting: ";
    print(a,n);
    selection_sort(a, n);
    cout<<"After sorting: ";
    print(a,n);

    return 0;
}
