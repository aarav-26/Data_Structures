// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int n=a.length();
    if(n<2){
        cout<<a;
        return 0;
    }
    vector<vector<bool>> arr(n,vector<bool>(n,false));
    //vector<string> res;
    string res="";
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]==a[j] && ((j-i<3)|| arr[i+1][j-1]))
            {
                arr[i][j]=true;
                if(j-i+1>res.length())
                {
                    res=a.substr(i,j-i+1);
                    //res.push_back(a.substr(i,j-i+1));
                }
            }
        }
    }
    cout<<res;
    // for(string i:res)
    //     cout<<i<<endl;
    
}
