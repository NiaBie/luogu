#include <stdio.h>
#include <assert.h>
#include <queue>
using namespace std;
const int MAXN = 60;
const int INF = 0xfffffff;

struct fuck
{
		int x, y;
		int dir;
		int my_time;
};
queue <fuck> que;
fuck src, dest;
int my_map[MAXN][MAXN] = {0};
int visit[MAXN][MAXN][4] = {0};
int m, n;
int neigh[4][2];
int steps[12][2];
int ans = INF;

int my_min(int a, int b)
{
		if (a < b)
				return a;
		return b;
}
int bfs(int x, int y, char dir);
int main()
{
    char dir[2];
		int i, j, k;
		int x, y;
		int temp;
		neigh[0][0] = +0, neigh[0][1] = +0;
		neigh[1][0] = +0, neigh[1][1] = +1;
		neigh[2][0] = +1, neigh[2][1] = +0;
		neigh[3][0] = +1, neigh[3][1] = +1;
		steps[0][0] = -1; steps[0][1] = +0;// N
		steps[1][0] = +0; steps[1][1] = +1;// E
		steps[2][0] = +1; steps[2][1] = +0;// S
		steps[3][0] = +0; steps[3][1] = -1;// W
		steps[4][0] = -2; steps[4][1] = +0;// N
		steps[5][0] = +0; steps[5][1] = +2;// E
		steps[6][0] = +2; steps[6][1] = +0;// S
		steps[7][0] = +0; steps[7][1] = -2;// W
		steps[8][0] = -3; steps[8][1] = +0;// N
		steps[9][0] = +0; steps[9][1] = +3;// E
		steps[10][0] = +3; steps[10][1] = +0;// S
		steps[11][0] = +0; steps[11][1] = -3;// W

		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i ++)
		{
				for (j = 0; j < m; j ++)
				{
						scanf("%d", &temp);
						if (temp == 1)
						{
								for (k = 0; k < 4; k ++)
								{
										x = i + neigh[k][0];
										y = j + neigh[k][1];
										if (x >= 0 && x <= n && y >= 0 && y <= m)// n + 1, m + 1
										{
												my_map[x][y] = 2;
										}
								}
						}
				}
		}
		n ++, m ++;
		for (i = 0; i < n; i ++)
				my_map[i][0] = my_map[i][m - 1] = 2;
		for (i = 0; i < m; i ++)
				my_map[0][i] = my_map[n - 1][i] = 2;
		/*
		printf("\n");
		for (i = 0; i < n; i ++)
		{
				for (j = 0; j < m; j ++)
				{
						printf("%d ", my_map[i][j]);
				}
				printf("\n");
		}
		*/
		scanf("%d%d%d%d%s", &src.x, &src.y, &dest.x, &dest.y, dir);
		if (bfs(src.x, src.y, dir[0]) == 1)
				printf("%d\n", ans);
		else
				printf("-1\n");
		return 0;
}

int bfs(int x, int y, char dir)
{
		int i, j;
		fuck u, v;
		u.x = x, u.y = y, u.my_time = 0;
		switch (dir)
		{
				case 'N':
						u.dir = 0; break;
				case 'E':
						u.dir = 1; break;
				case 'S':
						u.dir = 2; break;
				case 'W':
						u.dir = 3; break;
				default: assert(0);
		}
		que.push(u);
		while (que.empty() == 0)
		{
				u = que.front();
				que.pop();
				assert(u.dir <= 3 && u.dir >= 0);
				//printf("pop x:%d y:%d dir:%d time:%d\n", u.x, u.y, u.dir, u.my_time);
				if (u.x == dest.x && u.y == dest.y)
				{
						ans = my_min(ans, u.my_time);
				}
				for (i = 0; i < 4; i ++)
				{
						for (j = 0; j < 12; j += 4)
						{
						    v.x = u.x + steps[i + j][0];// init x
						    v.y = u.y + steps[i + j][1];// init y
						    if (v.x >= 0 && v.x < n && v.y >= 0 && v.y < m)
						    {
						    		if (my_map[v.x][v.y] < 2)
										{
						    		    v.dir = i%4;// init dir
						    		    v.my_time = u.my_time + 1;
						    		    switch ((u.dir + 4 - v.dir)%4)
						    		    {
						    		    		case 0:
						    		    				break;
						    		    		case 1:
						    		    		case 3:
						    		    				v.my_time ++; break;
						    		    		case 2:
						    		    				v.my_time += 2; break;
						    		    		default: assert(0);
						    		    }// init time
											  if	(visit[v.x][v.y][v.dir] == 0 || visit[v.x][v.y][v.dir] > v.my_time)
						    		    {
						    		    		visit[v.x][v.y][v.dir] = v.my_time;
						    		    		//printf("push x:%d y:%d dir:%d time:%d\n", v.x, v.y, v.dir, v.my_time);
						    		    		que.push(v);
						    		    }
										}
										else
										{
												break;
										}
						    }
								else
								{
										break;
								}
						}
				}
		}
		if (ans == INF)
		    return 0;
		return 1;
}
