#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Top Down Approach:
int minStep(int n)
{
	if(n==1)
	{
		return 0;
	}
	int a = INT_MAX;
	a=min(a,1+minStep(n-1));
	if(n % 2 == 0)
	{
		a = min(a , 1 + minStep(n/2));
	}
	if(n % 3 == 0)
	{
		a = min(a , 1 + minStep(n/3));
	}
	return a;
}
//Bottom Up Approach:
int minSteps(int n)
{
	vector<int> vctr(n+1 ,10000);
	vctr[1] =0;
	vctr[2]=1;
	for(int i=3;i<=n;i++)
	{
		vctr[i] = min(vctr[i] , 1+vctr[i-1]);
		if(i%2==0)
		{
			vctr[i] = min(vctr[i], 1+vctr[i/2]);
		}
		if(i%3==0)
		{
			vctr[i] = min(vctr[i], 1+vctr[i/3]);
		}
	}
	return vctr[n];
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	cout<<minStep(n)<<endl;
    	cout<<minSteps(n)<<endl;
    }

}