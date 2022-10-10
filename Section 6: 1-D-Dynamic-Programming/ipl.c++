#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Top Down Approach:
int maximize_score(vector<int> vctr ,int i , int n , int count)
{
	if(i == n)
	{
		return 0;
	}
	int a = INT_MIN;
    if(count < 2)
    {
    	a=max(a , vctr[i] + maximize_score(vctr , i+1 , n , count + 1));
    }
    a = max(a , maximize_score(vctr , i+1 , n , 0));
    return a;

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

     cout<<maximize_score(vctr ,0, n,0)<<endl;

}