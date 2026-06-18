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
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(pre);
    inorder(root);
    return 0;
}