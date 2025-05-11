// You are using GCC
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ans;

bool solve(int n,int x,int y,vector<vector<int>>& maze)
{
    if(x==n-1 && y==n-1 )// Reached Destination
    {
        ans[x][y]=1;
        return true;
    }
    
    if(x>=0 && y>=0 && x<n && y<n && maze[x][y]==1)
    {
        ans[x][y]=1;
        maze[x][y]=0;
        
        if(solve(n,x+1,y,maze))return true;//Down movement
        if(solve(n,x,y+1,maze))return true;//Right movement
        if(solve(n,x-1,y,maze))return true;//Up movement
        if(solve(n,x,y-1,maze))return true;//Left movement
        
        //Backtrack line (remove from path)
        ans[x][y]=0;
    }
    return false;
}
void solution(vector<vector<int>>& maze,int n)
{
    ans.assign(n, vector<int>(n, 0));///Important to initialize with zero when it picked for usage i faced error here
    if(maze[0][0]==1 && solve(n,0,0,maze))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
        cout<<"No Solution Exists.";
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> input(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>input[i][j];
            
    solution(input,n);
    return 0;
}
