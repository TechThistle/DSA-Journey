#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void subsets(vector<int> &arr, vector<int>ans, int i, vector<vector<int>> &allsubsets)
{
    if(i==arr.size())
    {
        allsubsets.push_back({ans});
        return;
    }
    ans.push_back(arr[i]);
    subsets(arr,ans, i+1, allsubsets);
    ans.pop_back();
    int idx=i+1;
    while(idx<arr.size() && arr[idx]==arr[idx-1])
    {
        idx++;
    }
    subsets(arr, ans, idx, allsubsets);
}
int main()
{
    vector<int> arr={1,2,2};
    sort(arr.begin(), arr.end());
    vector<int> ans;
    vector<vector<int>> allsubsets;
    subsets(arr, ans, 0, allsubsets);
    for(auto subset: allsubsets)
    {
        for(auto ele: subset)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;

}