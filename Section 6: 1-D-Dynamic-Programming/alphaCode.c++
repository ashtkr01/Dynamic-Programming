#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Helper:
void printAllString(int n , int i, int num ,string str)
{
	if(i >= num)
	{
		cout<<str<<endl;
		return ;
	}
   int z = 1;
     int a = pow(10,num-i-1);
     // cout<<a<<endl;
     int digit = n/a;
     if(digit == 0)
     {
      digit = n/(a/10);
      z=2;
     }
     // cout<<digit<<endl;
     int k= 96+digit;
     char d = static_cast<char>(k);
     // cout<<d<<endl;

     printAllString(n%a,i+z,num , str+d);
     if((num-i-1 >= 1) and (n/(a/10) <= 26))
     {
        digit = n/(a/10);
        k = 96+digit;
        d=static_cast<char>(k);
        printAllString(n%(a/10),i+z+1,num,str+d);

     }
}
//Tis function only calculate the number of string possible
int calc_all_string(int num , int digit)
{
   

}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    
    int n;
    int count=0;
    cin>>n;
    int help = n;
    while(help != 0)
    {
    	count++;
    	help=help/10;

    }
    // cout<<count<<endl;
    printAllString(n , 0 , count , "");
    return 0;

}