#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Helper Function:
int max_Cost(int n , vector<int> vctr)
{
	if(n == 0)
	{
		return 0;
	}
	int a = INT_MIN;
	for(int i=1;i<=n;i++)
	{
		if(n-1>=0){
		a=max(a,vctr[i] + max_Cost(n-i , vctr));
	}

	}
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
    vector<int> vctr(n+1,0);
    vctr[0] = 0;
    for(int i=1;i<=n;i++)
    {
    	cin>>vctr[i];
    }
    cout<<"Total Cost :"<<max_Cost(n,vctr)<<endl;

}