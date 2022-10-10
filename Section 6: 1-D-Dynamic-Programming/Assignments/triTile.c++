#include<iostream>
#include<vector>

using namespace std;

//REcursion Method:
long long int tri_tile(int n)
{
	vector<long long int> f(n+1 , 0);
	vector<long long int> h(n+1 , 0);
	vector<long long int> i(n+1 , 0);

	f[0] = 1;
	f[1] = 0;

	h[0] = 1;
	h[1] = 0;

	i[0] = 0;
	i[1] = 1;

	for(int j=2;j<=n;j++)
	{
		f[j] = f[j-2] + 2*h[j-2];

		h[j] = f[j] + i[j-1];

		i[j] = h[j-1];
	}
	return f[n];

}

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt" , "r" , stdin );
	// freopen("output.txt" , "w" , stdout);
	// #endif

	int n;
	while(cin>>n)
	{
		if(n == -1)
		{
			break;
		}
		cout<<tri_tile(n)<<endl;
	}
	return 0;
}