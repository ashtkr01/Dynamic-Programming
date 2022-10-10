#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back

using namespace std;

class graph{
    int v;
    list<int> *l;
public:
	   graph(int v)
	   {
	   	this->v = v;
	   	l = new list<int>[v];
	   }
	   void addEdge(int u , int v , bool undirected = true)
	   {
	   	// cout<<"Hi"<<endl;
	   	l[u].push_back(v);
	   	if(undirected)
	   	{
	   		l[v].push_back(u);
	   	}
      }
      void display()
      {
      	for(int i=0;i<v;i++)
      	{
      		cout<<i<<" --> ";
      		for(auto x : l[i])
      		{
      			cout<<x<<"--";
      		}
      		cout<<endl;
      	}
      }
      //Helper:
      bool helperFun(int node , vector<int> &visited , int &count , vector<int> vctr)
      {
      	count++;
      	vctr.push_back(node);
      	visited[node] = 1;
      	if(count == v)
      	{
      		for(auto x: vctr)
      		{
      			cout<<x<<" ";
      		}
      		cout<<endl;
      		return true;
      	}
      	for(auto x : l[node])
      	{
      		if(visited[x] == 0)
      		{
      			bool res = helperFun(x , visited , count , vctr);
      			if(res == true)
      			{
      				return true;
      			}
      		}
      	}
      	vctr.pop_back();
      	visited[node] = 0;
      	count--;
      	return false;
      }
      bool hamiltonianPath()
      {
      	vector<int> visited(v,0);
      	vector<int>vctr;
      	for(int i=0;i<v;i++)
      	{
      		bool result = false;
      		int count = 0;
      	 	result = helperFun( i , visited , count , vctr);
      	 	if(result == true)
      	 	{
      	 		return true;
      	 	}
      	}
      	return false;
      }
};
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin );
	freopen("output.txt" , "w" , stdout);
	#endif
     
     int n;
     cin>>n;
     graph *g = new graph(n);
     while (!cin.eof())
     {
     	int u , v;
     	cin>>u>>v;
     	// cout<<"Hi"<<endl;
     	g->addEdge(u , v);
     }
     //Display:
     // cout<<"Hi"<<endl;
     g->display();
     // cout<<"Hi"<<endl;
     cout<<g->hamiltonianPath()<<endl;

}