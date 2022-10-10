#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Helper:
void generator(char *output , int i , int j , int idx , int n)
{
	if(idx == 2*n)
	{
		output[idx] = '\0';
		cout<<output<<endl;
		return;
	}
    if(i <= n)
    {
    	output[idx] = '(';
    	generator(output , i+1 , j , idx + 1 , n);
    }
    if(j < i)
    {
    	output[idx] = ')';
    	generator(output , i , j + 1 , idx + 1 , n);
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
    char output[100];
    generator(output , 1 , 1 , 0 , n);


}