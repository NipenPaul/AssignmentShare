/**
Coder: BadLuckMan
Don't copy deep..
*/

#include<bits/stdc++.h>
#define INF 1000000007

using namespace std;
float G[100][100], c[100][100], cost[100], d[100], cc;
int p[100], N, n, e, u, v, tem, i, j;

int main()
{
   // freopen("input.txt","r", stdin);
	cin >> N;
	cin >> n;
	cin >> e;
	i = 1;
	while(i <= n)
	{
	   j = 1;
		while(j <= n)
		{
			G[i][j] = INF;
			j++;
		}
		i++;
	}
	while(e--)
	{
		cin >> u;
		cin >> v;
		cin >> cc;
		G[u][v] = cc;
	}
	cost[n] = 0.0;
	j = n-1;
	while(j >= 1)
	{
		cost[j] = INF;
		i = j;
		while(i <= n)
		{
			if(G[j][i] != INF)
			{
				if(cost[j] > G[j][i] + cost[i])
				{
					cost[j] = G[j][i] + cost[i];
					d[j] = i;
				}
			}
			i++;
		}
		j--;
	}
	p[1] = 1, p[N] = n;
	j = 2;
	while(j <= N-1)
	{
	    tem = p[j-1];
		p[j] = d[tem];
		j++;
	}
	cout << "Cost is: ";
	cout << cost[1];
	cout << endl;
	cout << "Path is: ";
	i = 1;
	while(i <= N)
	{
      cout << p[i];
      cout << "->";
      i++;
	}
	cout << endl;
	return 0;
}


/**
4 8 12
1 2 1
1 3 2
1 4 5
2 5 4
2 6 11
3 5 9
3 6 5
3 7 16
4 7 2
5 8 18
6 8 13
7 8 2
**/
