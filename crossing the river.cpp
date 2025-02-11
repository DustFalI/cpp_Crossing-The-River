#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long Map[25][25],n,m,cx,cy;
	cin>>n>>m>>cx>>cy;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			Map[i][j] = 1;
		}
	}
	Map[cx][cy] = 0;
	if(cx+2 <= n && cy+1 <= m) Map[cx+2][cy+1] = 0;
	if(cx+1 <= n && cy+2 <= m) Map[cx+1][cy+2] = 0;
	if(cx-1 >= 0 && cy+2 <= m) Map[cx-1][cy+2] = 0;
	if(cx-2 >= 0 && cy+1 <= m) Map[cx-2][cy+1] = 0;
	if(cx-2 >= 0 && cy-1 >= 0) Map[cx-2][cy-1] = 0;
	if(cx-1 >= 0 && cy-2 >= 0) Map[cx-1][cy-2] = 0;
	if(cx+1 <= n && cy-2 >= 0) Map[cx+1][cy-2] = 0;
	if(cx+2 <= n && cy-1 >= 0) Map[cx+2][cy-1] = 0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i == 0 && j == 0) continue;
			if(Map[i][j] == 0) continue;
			if(i == 0)
			{
				Map[i][j] = Map[i][j-1];
				continue;
			}
			if(j == 0)
			{
				Map[i][j] = Map[i-1][j];
				continue;
			}
			Map[i][j] = Map[i-1][j] + Map[i][j-1];
		}
	}
	cout<<Map[n][m];
	return 0;
}
