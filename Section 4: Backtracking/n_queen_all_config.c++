#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

int left_diag[100] ={0};
int right_diag[100] = {0};
int col[100] = {0};
//Helper:
bool isValid(int n , int i , int j)
{
	if(col[j] == 1)
	{
		return false;
	}
	if(right_diag[i+j] == 1)
	{
		return false;
	}
	if(left_diag[n-(i-j)] == 1)
	{
		return false;
	}
	return true;
}
//Print:
void printConfig(vector<vector<int>> &vctr)
{
	for(auto x: vctr)
	{
		for(auto y : x)
		{
			cout<<y<<"  ";
		}
		cout<<endl;
	}
}
// n_Queen:
void isValidConfig(vector<vector<int>> &vctr , int i , int n)
{
	if(i == n)
	{
		printConfig(vctr);
		cout<<"****************"<<endl;
		return ;

	}
	for(int k=0;k<n;k++)
	{
		if(isValid( n , i , k))
		{
             vctr[i][k] = 1;
             col[k] = 1;
             right_diag[i+k] = 1;
             left_diag[n-(i-k)] = 1;
            
             isValidConfig(vctr , i+1 , n);
             
             vctr[i][k] = 0;
             col[k] = 0;
             right_diag[i+k] = 0;
             left_diag[n-(i-k)] = 0;
 
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
    vector<vector<int>> vctr(n , vector<int> (n,0));
    isValidConfig(vctr , 0 , n );

    return 0;


}