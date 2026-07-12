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
Node* insert(Node* root, int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(root->data<val)
    {
        root->right=insert(root->right, val);
    }
    else
    {
        root->left=insert(root->left, val);
    }
    return root;
}
Node* buildBST(vector<int> arr)
{
    Node* root=NULL;
    for(int val: arr)
    {
        root=insert(root, val);
    }
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
    vector<int> arr={5,1,3,4,2,7};
    Node* root=buildBST(arr);
    inorder(root);
    cout<<endl;
    return 0;
}