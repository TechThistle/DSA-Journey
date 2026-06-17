#include<iostream>
#include<vector>
using namespace std;
void helper(vector<vector<int>> &maze, int r, int c, string path, vector<string> &ans)
{
    if(r==maze.size()-1 && c==maze.size()-1)
    {
        ans.push_back(path);
        return;
    }
    if(r<0 || c<0 || r>=maze.size() || c>=maze.size() || maze[r][c]==0)
    {
        return;
    }
    maze[r][c]=0;
    helper(maze,r+1,c,path+'D',ans);
    helper(maze,r-1,c,path+'U',ans);
    helper(maze,r,c+1,path+'R',ans);
    helper(maze,r,c-1,path+'L',ans);
    maze[r][c]=1;
}
vector<string> findPath(vector<vector<int>> &maze)
{
    int n=maze.size();
    vector<string> ans;
    helper(maze,0,0,"",ans);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>maze[i][j];
        }
    }
    vector<string> ans=findPath(maze);
    for(auto x: ans)
    {
        cout<<x<<" ";
    }
}