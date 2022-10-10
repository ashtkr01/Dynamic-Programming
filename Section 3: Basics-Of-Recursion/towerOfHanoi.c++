#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
  
  void towerOfHan(int n , char a , char b, char c)
  {
     if(n==0)
     {
     	return ;
     }
     towerOfHan(n-1 , a  , c , b);
     cout<<"Put "<<n<<" on "<<c<<" by using "<<a<<endl;
     towerOfHan(n-1 , b , a , c);
  }
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    
    char a = 's';
    char b = 'h';
    char c = 'd';
    int n;
    cin>>n;
    towerOfHan(n , a , b , c);

}