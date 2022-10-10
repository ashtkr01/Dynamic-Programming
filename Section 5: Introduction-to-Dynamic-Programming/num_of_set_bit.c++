#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Define a vector:
vector<int> vctr;

//First method: recursive
int calc_set_bits(int x)
{
	if(x == 0)
	{
		return 0;
	}
	if(x == 1 or x == 2)
	{
		return 1;
	}
	if(x % 2 == 0)
	{
		return calc_set_bits(x/2);
	}
	else
	{
		return 1 + calc_set_bits(x/2);
	}
}
//Dynamic_Approach:
void calc_set_bits_dp(int n)
{
	vctr[0] = 0;
	vctr[1] = 1;
	for(int i=2;i<=n;i++)
	{
		if(i%2==0)
		{
			vctr[i] = vctr[i/2];
		}
		else
		{
			vctr[i] = 1+ vctr[i/2];
		}

	}
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
   int n;
   cin>>n;
   for(int i =0;i<=n;i++)
   {
   	cout<<calc_set_bits(i)<<endl;
   }
   cout<<"**************"<<endl;
   //Initialization of vector:
   vctr.resize(n);
   //Call to the second approach:
   calc_set_bits_dp(n);
   for(int i=0;i<=n;i++)
   {
   	cout<<vctr[i]<<endl;
   }

    return 0;
}