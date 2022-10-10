#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
/********************Top Down Approach********************/
int subsetSum(int n , int j , vector<int> vctr , vector<int> &temp)
{
	if(n == 0)
	{
		for(auto x : temp )
		{
			cout<<x<<" ";
		}
		cout<<endl;
		return 1;
	}
	if(j < 0)
	{
		return 0;
	}
	int ans = 0;
	if( n - vctr[j] >= 0)
	{
		temp.push_back(vctr[j]);
		ans = subsetSum(n - vctr[j] , j-1 , vctr , temp);
		temp.pop_back();
	}
	ans += subsetSum( n ,  j - 1 , vctr , temp);

	return ans;
}
/*******************Top Down Dp*******************************/
int subsetSum2(int n , int j , vector<int> vctr , vector<vector<int > > &dp)
{
	if(n == 0)
	{
		return 1;
	}
	if(j < 0)
	{
		return 0;
	}
	if(dp[j][n] != -1)
	{
		return dp[j][n];
	}
	int ans = 0;
	if( n - vctr[j] >= 0)
	{
		ans = subsetSum2(n - vctr[j] , j-1 , vctr , dp);
	}
	ans += subsetSum2( n ,  j - 1 , vctr , dp);

	return dp[j][n] = ans;
}

/**************************Bottom Up Approach**********************************/
int subsetSum3(int n , int j , vector<int> vctr )
{
	vector<vector<int> > dp( j + 1  , vector<int> ( n + 1 , 0));
	for(int i=0;i<=j;i++)
	{
		dp[i][0] =1;
	}

	for(int i=1;i<=j;i++)
	{
		for(int k = 1;k<=n;k++)
		{
			dp[i][k] = dp[i-1][k];
			if( k - vctr[i - 1] >= 0)
			{
				dp[i][k] += dp[i-1][k-vctr[i - 1]];
			}
		}
	}
	return dp[j][n];
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif

	int n;
	cin>>n;
	vector<int> vctr;
	vector<int> temp;
	
	int ele =0;
	while(cin>>ele)
	{
		vctr.push_back(ele);
	}
	int len = vctr.size();
	vector<vector<int> > dp( len , vector<int> (n + 1 , -1));
	// for(auto x : vctr)
	// {
	// 	cout<<x<<" "<<endl;
	// }
	cout<<"Answer :"<<subsetSum(n , len-1 , vctr , temp)<<endl;
	//Top Down Dp:
	cout<<"Answer : "<<subsetSum2(n , len - 1 , vctr , dp)<<endl;
	//Bottom Up Approach :
	cout<<"Answer :"<<subsetSum3(n , len , vctr)<<endl;


}