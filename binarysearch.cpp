#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &arr, int tar, int st, int end)
{
    if(st<=end)
    {
        int mid=(st+end)/2;
        if(mid==tar)
        {
            return mid;
        }
        else if(arr[mid]<=tar)
        {
            return binarysearch(arr, tar, mid+1, end);
        }
        else
        {
            return binarysearch(arr, tar, st, mid-1);
        }
    }
    return -1;
}
int main()
{
    vector<int> arr={1, 2, 3, 4, 5};
    cout<<binarysearch(arr, 6, 0, arr.size()-1)<<endl;
    return 0;
}