#include<bits/stdc++.h>
using namespace std;


int helperApple(vector<int> arr , int n , int k , vector<vector<int> > &dp)
{
	if(k==0)
	{
		return 0;
	}
	if(n<=0)
	{
		return INT_MAX;
	}
	
	if(dp[n][k] != -5)
	{
		return dp[n][k];
	}
	int a = INT_MAX;

	for(int i=1;i<=k;i++)
	{
		if(arr[i] != -1 and k-i >= 0)
		{
			a = min(a , arr[i] + helperApple(arr , n-1 , k - i , dp));
		}
	}
	return dp[n][k] = a;
}
/**********By Ignoring n*****************************/
int helper(vector<int> arr , int n , int k)
{
	vector<int> vctr(k + 1 , INT_MAX);
	vctr[0] = 0;
	for(int i =1;i<=k;i++)
	{
		for(int j = 1;j<=k;j++)
		{
			if(i-j >= 0 and arr[j] != -1)
			{
				vctr[i] = min(vctr[i] , arr[j] + vctr[i - j]);
			}
		}
	}
	return vctr[k];
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n , k;
	cin>>n>>k;
	vector<int> pricePerKg(k+1 , -1);
	int check = 0;
	int minEle = INT_MAX;
	for(int i=1;i<=k;i++)
	{
		cin>>pricePerKg[i];
		check += pricePerKg[i];
		if(minEle > pricePerKg[i])
		{
			minEle = pricePerKg[i];
		}
	}
	vector<vector<int> > dp(n + 1 , vector<int> (k+1 , -5));
	// int res = helperApple(pricePerKg , n , k , dp);
	int res = helper(pricePerKg , n , k );
	if(minEle <= res and res <= *check)
	{
		cout<<res<<endl;
	}
	else{
		cout<<-1<<endl;
	}

	}
	

	return 0;
}