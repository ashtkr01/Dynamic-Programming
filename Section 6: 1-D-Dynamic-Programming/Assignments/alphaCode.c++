#include<bits/stdc++.h>
// #define int long long int
#define F first
#define S second
#define pb push_back


using namespace std;

long long int alpha_code(string str)
{
	int length = str.size();
	int size = length +1;
	vector<long long int> vctr(size , 0);
	string str1 = str.substr(0,1);
	vctr[1] = 1;
	if(length == 1)
	{
		return vctr[1];
	}
	str1 = str.substr(1,1);
	int ele = stoi(str1);
	if(ele >=1 and ele <= 9)
	{
		vctr[2] = 1;
	}
	string str2 = str.substr(0,2);
	ele = stoi(str2);
	if(ele <= 26 and ele >= 10)
	{
		vctr[2]++;
	}
	
     
     if(length >= 3)
     {
     	for(int i=3;i<=length;i++)
	{
		// vctr[i] = vctr[i-1];
		string str3 = str.substr(i-2 , 2);
		int element = stoi(str3);
		if(element <=26 and element >=10)
		{
			vctr[i] += vctr[i-2];
		}
		string str4 = str.substr(i-1 , 1);
		element = stoi(str4);
		if(element <= 9 and element >=1)
		{
			vctr[i] += vctr[i-1];
		}
	}
     }
	
	// cout<<vctr[1]<<" "<<vctr[5]<<endl;
	return vctr[length];
}



int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    
    string str;
    while(cin>>str)
    { 
    	if(str == "0")
    	{
    		break;
    	}
    	cout<<alpha_code(str)<<endl;
    }
    return 0;
}