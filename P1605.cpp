#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXn = 10;
const int MAXm = 10;
int m, n, t;
int sx, sy, fx, fy;
int ans = 0;
int my_map[MAXn][MAXn] = {0};
int visit[MAXn][MAXm] = {0};
int step[4][2];
int dfs(int x, int y);
int main()
{
		int x, y;
		step[0][0] = -1, step[0][1] = +0;// up
		step[1][0] = +1, step[1][1] = +0;// down
		step[2][0] = +0, step[2][1] = -1;// left
		step[3][0] = +0, step[3][1] = +1;// right
		scanf("%d%d%d", &n, &m, &t);
		scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
		for (int i = 0; i < t; i ++)
		{
				scanf("%d%d", &x, &y);
				my_map[x][y] = 1;
		}
		dfs(sx, sy);
		printf("%d\n", ans);
		return 0;
}
int dfs(int x, int y)
{
		visit[x][y] = 1;
		if (x == fx && y == fy)
		{
				ans ++;
		    visit[x][y] = 0;
				return 0;
		}
		int next_x, next_y;
		for (int i = 0; i < 4; i ++)
		{
				next_x = x + step[i][0];
				next_y = y + step[i][1];
				if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m)
				{
						if (my_map[next_x][next_y] == 0 && visit[next_x][next_y] == 0)
						{
								dfs(next_x, next_y);
						}
				}
		}
		visit[x][y] = 0;
		return 0;
}
