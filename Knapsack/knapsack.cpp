// You are using GCC
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int n,capacity;
    cin>>n>>capacity;
    int weight[n],values[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>values[i];
    }
    
    vector<int> dp(capacity+1,0);
    
    for(int i=0;i<n;i++)
    {
        for(int k=capacity;k>=weight[i];k--)
        {
            dp[k]=max(dp[k],values[i]+dp[k-weight[i]]);
        }
    }
    
    cout<<"The Highest Profit in given Capacity is : "<<dp[capacity]<<endl;
}
