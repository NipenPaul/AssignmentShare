/**
Code Edit: BadLuckMan
Don't copy deep..
*/

#include <bits/stdc++.h>
using namespace std;

struct es
{
	int u, v, w;
}in[100], os[100], tem;
int n, e;
int parent[100], i;
void Union(int u, int v)
{
    i = 1;
	while(i <= n)
	{
		if(parent[i] == v)
		{
			parent[i] = u;
		}
		i++;
	}
}

int main()
{
	freopen("MST.txt", "r", stdin);
     cin >> n >> e;
     i = 1;
	while(i <= n){
		parent[i] = i;
		i++;
    }
    i = 0;
	while (i < e)
	{
		cin >> in[i].u >> in[i].v >> in[i].w;
		i++;
	}
	for(int i = 0; i < e; i++)
	{
	  int j = i + 1;
	   while(j < e)
	   {
	      if(in[i].w > in[j].w)
	      {
	         tem = in[j];
	         in[j] = in[i];
	         in[i] = tem;
	      }
	      j++;
	   }
	}

	int cost = 0, ind = 0;
	for (int i = 0; i < e; ++i)
	{
		int u = parent[in[i].u];
		int v = parent[in[i].v];
		if(parent[u] != parent[v])
		{
			Union(u, v);
			cost += in[i].w;
			os[ind++] = in[i];
		}
	}
	cout << "cost is: " << cost << '\n';
	cout << "Edge list:\n";
	for (int i = 0; i < n-1; ++i)
	{
		cout << os[i].u << " ";
		cout << os[i].v << " ";
		cout << os[i].w << "\n";
	}
	return 0;
}

/**
MST.txt
7
12
1 2 2
1 3 2
1 4 1
2 5 1
2 4 5
3 4 1
3 6 2
4 5 1
4 6 6
4 7 5
5 7 3
6 7 10
*/

