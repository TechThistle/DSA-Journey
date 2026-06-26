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
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int sumtree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftsum=sumtree(root->left);
    int rightsum=sumtree(root->right);
    root->data+=leftsum+rightsum;
    return root->data;
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index=-1;
    Node* root=buildTree(pre, index);
    cout<<"Before conversion: ";
    preorder(root);
    cout<<endl;
    sumtree(root);
    cout<<"After conversion: ";
    preorder(root);
    return 0;
}