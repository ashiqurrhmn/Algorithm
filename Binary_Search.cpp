#include<bits/stdc++.h>
using namespace std;
int binary_search(int a[], int l, int r, int data)
{
    while(l<=r)
    {
       int mid = l+(r-l)/2;
       if(a[mid]==data)
        return mid;
       else if(a[mid]>data)
        r = mid-1;
       else
        l = mid+1;
    }
    return -1;
}
int main()
{
    int x;
    cout<<"Enter array size: ";
    cin>>x;
    cout<<"Enter array elements: ";
    int a[x];
    for(int i = 0; i<x; i++)
    {
        cin>>a[i];
    }
    int n;
    cout<<"Enter searching data: ";
    cin>>n;
    int result = binary_search(a, 0, x-1, n);
    (result==-1)?cout<<"Data not found":cout<<"Data found at index: "<<result;


    return 0;
}
