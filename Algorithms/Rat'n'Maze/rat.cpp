// You are using GCC
#include<iostream>
#include<vector>
using namespace std;
vector<string> ans;
void paths(int n,int x,int y,vector<vector<int>>& maze,vector<vector<bool>>& visited,string path)
{
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y]=true;
    
    if(x+1<n && maze[x+1][y]==1 && !visited[x+1][y])
        paths(n,x+1,y,maze,visited,path+"D");
        
    if(y+1<n && maze[x][y+1]==1 && !visited[x][y+1])
        paths(n,x,y+1,maze,visited,path+"R");
        
    if(x-1>=0 && maze[x-1][y]==1 && !visited[x-1][y])
        paths(n,x-1,y,maze,visited,path+"U");
    
    if(y-1>=0 && maze[x][y-1]==1 && !visited[x][y-1])
        paths(n,x,y-1,maze,visited,path+"L");
    
    visited[x][y]=false;    
}
void solve(vector<vector<int>>& maze,int n)
{
    vector<vector<bool>> visit(n,vector<bool>(n,false));
    if(maze[0][0]==1)
        paths(n,0,0,maze,visit,"");
    for(auto i:ans)
        cout<<i<<"  ";
    
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> input(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>input[i][j];
    solve(input,n);        
}
