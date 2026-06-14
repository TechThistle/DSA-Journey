#include<iostream>
#include<vector>
using namespace std;
void getcomb(vector<int> &candidates, vector<int> &curr, int target, vector<vector<int>> &ans, int idx)
{
    if(target==0)
    {
        ans.push_back(curr);
        return;
    }
    if(target<0 || idx==candidates.size())
    {
        return;
    }
    curr.push_back(candidates[idx]);
    getcomb(candidates, curr, target-candidates[idx], ans, idx);    
    curr.pop_back();
    getcomb(candidates, curr, target, ans, idx+1);

}
int main()
{
    vector<int> candidates={2,3,6,7};
    int target=7;
    vector<vector<int>> ans;
    vector<int> curr;
    getcomb(candidates, curr, target, ans, 0);
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