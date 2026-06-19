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
bool isIdentical(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    bool left=isIdentical(root1->left,root2->left);
    bool right=isIdentical(root1->right,root2->right);
    return left && right;
}
int main()
{
    vector<int> pre={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index=-1;
    Node* root=buildTree(pre,index);
    index=-1;
    Node* root2=buildTree(pre,index);
    cout<<"Are the trees identical? "<<isIdentical(root,root2)<<endl;
    cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" "<<root->right->left->data<<" "<<root->right->right->data<<endl;
    return 0;
}