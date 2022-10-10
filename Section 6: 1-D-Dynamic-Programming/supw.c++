#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Function Top Down: Recursive Approach:

int minimize_min(vector<int> vctr , int i , int n , int cnt)
{
	if(i >= n)
	{
		return 0;
	}
	int a = INT_MAX;
	if(cnt < 2)
	{
		a = min(a , minimize_min(vctr , i+1 , n , cnt + 1));
	}
	   
	 a =  min(a ,vctr[i] + minimize_min(vctr , i+1 , n , 0));
	 // a =  min(a ,vctr[i +1] + minimize_min(vctr , i+2 , n ,0));
	 // a =  min(a ,vctr[i +2] + minimize_min(vctr , i+3 , n , 0));
	 return a;

}
//Function Using Dynamic Programming Bottom UP:
int minimize_minute(vector<int> vctr , int n)
{
	vector<int> dp(n+1 ,100000);
	dp[0] =0;
	for(int i=0;i<3;i++)
	{
        dp[i+1] = vctr[i];
	}
	for(int i=3;i<n;i++)
	{
		dp[i+1] = min(dp[i+1] , vctr[i] + dp[i+1 - 1]);
		dp[i+1] = min(dp[i+1] , vctr[i] + dp[i+1 - 2]);
		dp[i+1] = min(dp[i+1] , vctr[i] + dp[i+1 - 3]);
	}
	// cout << min({dp[n ], dp[n - 1], dp[n - 2]});
	return min({dp[n ], dp[n - 1], dp[n - 2]});
}
/***********************Greedy Approach will not work*******************************/
//Function using queue -- Greedy approach fails here:
int minimize_minutes(vector<int> vctr , int num , int n)
{
	queue<int> que;
	int ans = 0;
	if(n > num)
	{
		for(int i=0;i<num;i++)
		{
			while((!que.empty()) and que.front() > vctr[i])
			{
				que.pop();
			}
			que.push(vctr[i]);
		}
		// cout<<que.front()<<endl;
		for(int j = num;j<n;j++)
		{
			if(que.front() == vctr[j-num])
			{
				int ele = que.front();
				que.pop();
				if(!(que.empty()))
				{
					if(ele == que.front())
					{

					}
				}
				else
				{
					ans += ele;
				}
				
			}
			while((!que.empty()) and que.front() > vctr[j])
			{
				que.pop();
			}
			que.push(vctr[j]);
		}
	}
	while(!que.empty())
	{
		ans += que.front();
		que.pop();
	}
	return ans;

}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
     int n;
     cin>>n;
     vector<int> vctr(n , 0);
     for(int i=0;i<n;i++)
     {
     	cin>>vctr[i];
     }
     cout<<"Top Down Approach Answer :"<<minimize_min(vctr , 0 , n , 0)<<endl;
     cout<<"Greedy Apprach give wrong Answer :"<<minimize_minutes(vctr , 3 , n)<<endl;
     cout<<"Bottom Apprach will give correct Answer :"<<minimize_minute(vctr , n)<<endl;
     return 0;
}