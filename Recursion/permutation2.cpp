#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void getper(vector<int> &arr, vector<vector<int>> &ans, int idx)
{
    int n=arr.size();
    if(idx==n)
    {
        ans.push_back(arr);
        return;
    }
    unordered_set<int> duplicate;
    for(int i=idx; i<n; i++)
    {
        if(duplicate.find(arr[i])!=duplicate.end())
        {
            continue;
        }
        duplicate.insert(arr[i]);
        swap(arr[idx], arr[i]);
        getper(arr, ans, idx+1);
        swap(arr[idx], arr[i]);
    }
}
int main()
{
    vector<int> arr={1,2,2};
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