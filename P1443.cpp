#include <stdio.h>
#include <assert.h>
#include <queue>
using namespace std;
const int MAXN = 410;

struct fuck
{
		int x, y;
		int my_time;
};
int m, n;
int visit[MAXN][MAXN];
int steps[8][2];
fuck src;
queue <fuck> que;

int bfs(int x, int y);
int main()
{
		steps[0][0] = -2; steps[0][1] = -1;
		steps[1][0] = -2; steps[1][1] = +1;
		steps[2][0] = -1; steps[2][1] = -2;
		steps[3][0] = +1; steps[3][1] = -2;
		steps[4][0] = -1; steps[4][1] = +2;
		steps[5][0] = +1; steps[5][1] = +2;
		steps[6][0] = +2; steps[6][1] = -1;
		steps[7][0] = +2; steps[7][1] = +1;

		scanf("%d%d%d%d", &n, &m, &src.x, &src.y);
		for (int i = 1; i <= n; i ++)
		{
				for (int j = 1; j <= m; j ++)
				{
						visit[i][j] = -1;
				}
		}
		bfs(src.x, src.y);
		for (int i = 1; i <= n; i ++)
		{
				for (int j = 1; j <= m; j ++)
				{
						printf("%-5d", visit[i][j]);
				}
				printf("\n");
		}
}
int bfs(int x, int y)
{
		int i;
		fuck u, v;
		u.x = x, u.y = y, u.my_time = 0;
		visit[u.x][u.y] = 0;
		que.push(u);
		while (que.empty() == 0)
		{
				u = que.front();
				que.pop();
				for (i = 0; i < 8; i ++)
				{
						v.x = u.x + steps[i][0];
						v.y = u.y + steps[i][1];
						v.my_time = u.my_time + 1;
						if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m)
						{
								if (visit[v.x][v.y] == -1 || v.my_time < visit[v.x][v.y])
								{
										visit[v.x][v.y] = v.my_time;
										que.push(v);
								}
						}
				}
		}
		return 0;
}
