#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int unordered_pairs(int n , int i)
{
	if(n==0)
	{
		return 1;
	}
	int ans = 0;

	for(int j = i;j<=n;j++)
	{
		if(n - j >= 0)
	{
		ans += unordered_pairs(n - j , j);
	}
	}
	return ans;
}
/***********************2nd Approach****************************/
int unordered_pairs2(int n)
{
	vector<int> dp(n + 1 , 0);
	dp[0] = 1;

	for(int i=n;i>=1;i--)
	{
		for(int j = i;j<=n;j++)
		{
			dp[j] += dp[j-i];
		}
	}
	return dp[n];
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    
    int n;
    cin>>n;
    cout<<unordered_pairs(n,1)<<endl;
    cout<<unordered_pairs2(n)<<endl;

    return 0;

}