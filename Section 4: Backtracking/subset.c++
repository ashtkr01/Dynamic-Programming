#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

//Function:
void subSet(char *input , char *output , int i , int j)
{
	if(input[i] =='\0')
	{
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}

	subSet(input , output , i + 1 , j);

	output[j] = input[i];
	subSet(input , output , i + 1 , j + 1);
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
     
     char input[100];
     char output[100];

     cin>>input;

     subSet(input , output , 0 , 0);
     cout<<output<<endl;
     return 0;


}