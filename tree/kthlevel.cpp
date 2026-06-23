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
void kthnode(Node* root, int k)
{
    if(root==NULL)
    {
        return ;
    }
    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }
    kthnode(root->left, k-1);
    kthnode(root->right, k-1);
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index=-1;
    Node* root=buildTree(pre, index);
    kthnode(root, 2);
    return 0;
}