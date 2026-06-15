#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
    bool issafe(vector<string> &board, int row, int col, int n)
    {
        for(int i=0; i<n; i++)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }
        for(int j=0; j<n; j++)
        {
            if(board[row][j]=='Q')
            {
                return false;
            }
        }
        for(int i=row,j=col; i>=0 && j>=0; i--, j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=row,j=col; i>=0 && j<n; i--, j++)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void nqueen(vector<string> &board, int row, int n,int &count)
    {
        if(row==n)
        {
            count++;
            return;
        }
        for(int j=0; j<n; j++)
        {
            if(issafe(board, row, j, n))
            {
                board[row][j]='Q';
                nqueen(board,row+1,n,count);
                board[row][j]='.';
            }
        }
    }
int main()
{   int n;
    cin>>n;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0; i<n; i++)
        board[i] = s;
    int count=0;
    nqueen(board, 0, n, count);
    cout<<count<<endl;
}