#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Memo
vector<int> dp(100 , -1);
//Top-Down:
int max_robbing(vector<int> vctr , int i , int j)
{
	if(i >= j)
	{
		return 0;
	}
	if(dp[i] != -1)
	{
		return dp[i];
	}
    //If robbing current house:
    int a = vctr[i] + max_robbing(vctr , i + 2 , j);
    //else excluding current house:
    int b = max_robbing(vctr , i + 1 , j);
    return dp[i] =  max(a , b);
}
//Bottom Approach
int maxRobbing(vector<int> vctr)
{
	
	int n = vctr.size();
	vector<int> dp(n,0);
	dp[0] = vctr[0];
	dp[1] = vctr[1];
	for(int i=2;i<n;i++)
	{
		dp[i] = max(vctr[i] + dp[i-2] , dp[i-1]);
	}
	return dp[n-1];
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    vector<int> vctr;
    while(!cin.eof())
    {
    	int ele;
    	cin>>ele;
    	vctr.push_back(ele);
    }
    int n = vctr.size();
    //Call to top down approach:
    cout<<"Answer :"<<max_robbing(vctr , 0 , n)<<endl;
    cout<<"Answer :"<<maxRobbing(vctr)<<endl;
    //Print the vector:
    for(auto x : vctr)
    {
    	cout<<x<<" ";
    }

}