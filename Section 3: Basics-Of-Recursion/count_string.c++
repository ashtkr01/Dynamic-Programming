#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int count(int n , int check)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1 and check == 0)
	{
		return 2;
	}
	if(n==1 and check == 1)
	{
		return 1;
	}
	int ans = 0;
	if(check!=1)
	{
		ans = count(n-1 , 1);
	}
	ans += count(n-1 , 0);
	return ans;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
     
     int n , check;
     cin>>n>>check;
     cout<<"Answer :"<<count(n , check)<<endl;

}