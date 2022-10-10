#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;
//Function to check palindrome or not:
bool isPalindrome(string str)
{
	string str2 = str;
	reverse(str2.begin() , str2.end());
	if(str == str2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//Function 
void generateAllPalin(string str ,int i , int j, vector<string> &vctr, vector<vector<string>> &res)
{
	if(i >= j)
	{
		// cout<<"Hello"<<endl;
		res.push_back(vctr);
		return;
	}
	for(int x = i+1;x<=j;x++)
	{
		// cout<<i<<" "<<x<<endl;
		string substring = str.substr(i,x-i);
		// cout<<substring<<endl;
		if(isPalindrome(substring) == 1)
		{
			vctr.push_back(substring);
			// cout<<substring<<endl;
			generateAllPalin(str , x , j , vctr , res);
			vctr.pop_back();
		}
	}

}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
    string str;
    cin>>str;
    vector<vector<string>> res;
    vector<string> vctr;
    int j = str.size();
    //Call:
    generateAllPalin(str , 0 , j , vctr , res);
    //Print the Resultant Vector:
    // cout<<res.size()<<endl;
    for(auto x : res)
    {
    	for(auto y :x)
    	{
    		cout<<y<<" ";
    	}
    	cout<<endl;
    }
    // cout<<"Hi"<<endl;
    return 0;
}