#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
bool issafe(vector<string> &board, int row, int col, int n)
{
    for(int i=0; i<row; i++)
    {
        if(board[i][col] == 'Q')
            return false;
    }
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
    {
        if(board[i][j] == 'Q')
            return false;
    }
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++)
    {
        if(board[i][j] == 'Q')
            return false;
    }
    for(int j=0; j<n; j++)
    {
        if(board[row][j] == 'Q')
            return false;
    }
    return true;
}
void nqueen(vector<string> &board, vector<vector<string>> &ans, int n, int row)
{
    if(row==n)
    {
        ans.push_back(board);
        return;
    }
    for(int j=0; j<n; j++)
    {
        if(issafe(board,row,j,n))
        {
            board[row][j] = 'Q';
            nqueen(board, ans, n, row + 1);
            board[row][j] = '.';
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0; i<n; i++)
        board[i] = s;
    nqueen(board, ans, n, 0);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<endl;
        cout<<endl;
    }
}