#include<iostream>
#include<vector>
using namespace std;
void selectionsort(vector<int> &arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int minidx=i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[minidx])
            {
                minidx=j;
            }
        }
        swap(arr[i], arr[minidx]);
    }
}
void printArray(vector<int> arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();
    selectionsort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}