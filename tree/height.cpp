#include<iostream>
#include<vector>
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
static int index=-1;
Node* buildTree(vector<int> pre)
{
    index++;
    if(pre[index]==-1)
    {
        return NULL;
    }
    Node* root=new Node(pre[index]);
    root->left=buildTree(pre);
    root->right=buildTree(pre);
    return root;
}
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return max(leftheight,rightheight)+1;
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(pre);
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->right->left->data<<" "<<root->right->right->data<<endl;
    cout<<"Height of the tree: "<<height(root)<<endl;
    return 0;
}