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
Node* getInorderSuccessor(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
Node* delnode(Node* root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key<root->data)
    {
        root->left=delnode(root->left, key);
    }
    else if(key>root->data)
    {
        root->right=delnode(root->right, key);
    }
    else
    {
        if(root->left==NULL)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node* IS=getInorderSuccessor(root->right);
            root->data=IS->data;
            root->right=delnode(root->right, IS->data);
        }
    }
    return root;
}
int main()
{
    vector<int> arr={5,1,3,4,2,7};
    Node* root=buildBST(arr);
    inorder(root);
    cout<<endl;
    root=delnode(root, 3);
    inorder(root);
    cout<<endl;
    return 0;
}