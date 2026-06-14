#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getcomb(vector<int> &arr,vector<vector<int>> &ans, vector<int> &curr, int target, int idx)
{
     if(target==0)
        {
            ans.push_back(curr);
            return;
        }

        for(int i=idx; i<arr.size(); i++)
        {
            if(i>idx && arr[i]==arr[i-1])
            {
                continue;
            }
            if(arr[i]>target)
            {
                break;
            }
            curr.push_back(arr[i]);
            getcomb(arr, ans, curr, target-arr[i], i+1);
            curr.pop_back();
}
}
int main()
{
    vector<int> arr={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> ans;
    vector<int> curr;
    sort(arr.begin(), arr.end());
    getcomb(arr, ans, curr, target, 0);
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