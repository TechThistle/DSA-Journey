#include<iostream>
#include<vector>
using namespace std;
void getper(vector<int> &arr,vector<vector<int>> &ans, int idx)
{
    int n=arr.size();
    if(idx==n)
    {
        ans.push_back(arr);
        return;
    }
    for(int i=idx; i<n; i++)
    {
        swap(arr[idx], arr[i]);
        getper(arr, ans, idx+1);
        swap(arr[idx], arr[i]);
    }
}
int main()
{
    vector<int> arr={1,2,3};
    vector<vector<int>> ans;
    getper(arr, ans, 0);
    for(auto ele: ans)
    {
        for(auto e: ele)
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}