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
int count(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return leftcount+rightcount+1;
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root=buildTree(pre);
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->right->left->data<<" "<<root->right->right->data<<endl;
    cout<<"Count of nodes in the tree: "<<count(root)<<endl;
    return 0;
}