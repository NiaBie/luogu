#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 1010;
const int MAXM = 1000010;
struct fuck
{
		int x, y;
};
queue <fuck> que;
char my_map[MAXN][MAXN];
int visit[MAXN][MAXN];
int ans[MAXM];
int step[4][2];
int breadth;
int mode;// ans[mode] = breadth
int m, n;
int bfs(int x, int y);
void test();
int main()
{
		step[0][0] = -1, step[0][1] = +0;
		step[1][0] = +0, step[1][1] = -1;
		step[2][0] = +0, step[2][1] = +1;
		step[3][0] = +1, step[3][1] = +0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i ++)
		{
				scanf("%s", my_map[i]);
		}
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i ++)
		{
				for (int j = 0; j < n; j ++)
				{
						bfs(i, j);
				}
		}
		for (int j = 0; j < m; j ++)
		{
				int x, y;
				scanf("%d%d", &x, &y);
				printf("%d\n", ans[visit[x - 1][y - 1]]);
		}
		return 0;
}
int bfs(int x, int y)
{
		assert(que.empty() == 1);
		mode ++;
		if (visit[x][y] != 0)
				return 0;
		breadth = 0;
		fuck u;
		u.x = x, u.y = y;
		que.push(u);
		visit[x][y] = mode;
		while (que.empty() == 0)
		{
				u = que.front();
				que.pop();
				breadth ++;
				for (int i = 0; i < 4; i ++)
				{
						int next_x = u.x + step[i][0];
						int next_y = u.y + step[i][1];
						if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
								continue;
						if (visit[next_x][next_y] == 0 && my_map[u.x][u.y] != my_map[next_x][next_y])
						{
								fuck v;
								v.x = next_x, v.y = next_y;
								que.push(v);
				        visit[v.x][v.y] = mode;
						}
				}
		}
		ans[mode] = breadth;
		return 0;
}
void test()
{
		return;
}
