#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

bool modulo_sum(vector<int> vctr , int sum)
{
	int size = vctr.size();
	vector< vector<bool> > dp(size + 1 , vector<bool> (sum + 1 , false));

	for(int i = 0;i<=sum;i++)
	{
		dp[0][i] = false;
	}

	for(int i = 0;i<=size;i++)
	{
		dp[i][0] = true;
	}

	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			dp[i][j] = dp[i-1][(j-vctr[i - 1] % j)%j] | dp[i-1][j];
		}
	}
	return dp[size][sum];
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif

	int n , sum;
	cin>>n>>sum;

	vector<int> vctr(n , 0);
	for(int i=0;i<n;i++)
	{
		cin>>vctr[i];
	}

	cout<<modulo_sum(vctr , sum)<<endl;




}