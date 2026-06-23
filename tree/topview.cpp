#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=right=NULL;
    }
};
Node* buildTree(vector<int> pre, int index)
{
    index++;
    if(pre[index]==-1)
    {
        return NULL;
    }
    Node* root=new Node(pre[index]);
    root->left=buildTree(pre, index);
    root->right=buildTree(pre, index);
    return root;
}
void topview(Node* root)
{
    queue<pair<Node*,int>> q;
    map<int,int> m;
    q.push({root, 0});
    while(q.size()>0)
    {
        Node* curr=q.front().first;
        int currhd=q.front().second;
        q.pop();
        if(m.find(currhd)==m.end())
        {
            m[currhd]=curr->data;
        }
        if(curr->left!=NULL)
        {
            q.push({curr->left, currhd-1});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right, currhd+1});
        }
    }
    for(auto i:m)
    {
        cout<<i.second<<" ";
    }
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index=-1;
    Node* root=buildTree(pre, index);
    topview(root);
    return 0;
}