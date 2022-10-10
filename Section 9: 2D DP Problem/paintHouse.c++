#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int min_Cost(int n , int m , int i , int flag , vector<vector<int> > vctr)
{
	if(i == n)
	{
		return 0;
	}
   int ans = INT_MAX;
   for(int k = 0;k<m;k++)
   {
   	if(k != flag)
   	{
   	  ans = min(ans , vctr[i][k] + min_Cost(n , m , i + 1 , k , vctr));
   	}
   }
   return ans;

}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif

	int house , color;
	cin>>house>>color;

	vector< vector <int> > vctr(color , vector<int> (house , 0));

	for(int i=0;i<color;i++)
	{
		for(int j= 0;j<house;j++)
		{
			cin>>vctr[i][j];
		}
	}

	cout<<"Answer :"<<min_Cost(house , color , 0 , -1 , vctr)<<endl;

	return 0;




}