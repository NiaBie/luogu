#include <stdio.h>
#include <cstring>
using namespace std;
const int MAXN = 110;
int n;
char my_map[MAXN][MAXN];
char ans[MAXN][MAXN];
int step[8][2];
char sample[] = "yizhong";
int my_print();
int dfs(int x, int y, int direct, int num);
int main()
{
		memset(ans, 0, sizeof(ans));
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
		{
				scanf("%s", my_map[i]);
		}
		step[0][0] = -1, step[0][1] = -1;
		step[1][0] = -1, step[1][1] = +0;
		step[2][0] = -1, step[2][1] = +1;
		step[3][0] = +0, step[3][1] = -1;
		step[4][0] = +0, step[4][1] = +1;
		step[5][0] = +1, step[5][1] = -1;
		step[6][0] = +1, step[6][1] = +0;
		step[7][0] = +1, step[7][1] = +1;
		for (int i = 0; i < n; i ++)
		{
				for (int j = 0; j < n; j ++)
				{
						ans[i][j] = '*';
				}
		}
		for (int i = 0; i < n; i ++)
		{
				for (int j = 0; j < n; j ++)
				{
						for (int k = 0; k < 8; k ++)
						{
								dfs(i, j, k, 0);
						}
				}
		}
		my_print();
		return 0;
}
int dfs(int x, int y, int direct, int num)
{
		int next_x = x + step[direct][0];
		int next_y = y + step[direct][1];
		if (x < 0 || x >= n || y < 0 || y >= n)
		{
				return 0;
		}
		if (my_map[x][y] != sample[num])
		{
				return 0;
		}
		if (num == 6)
		{
				ans[x][y] = sample[num];
				return 1;
		}
		if (dfs(next_x, next_y, direct, num + 1) != 0)
		{
				ans[x][y] = sample[num];
				return 1;
		}
		return 0;
}
int my_print()
{
		for (int i = 0; i < n; i ++)
		{
				for (int j = 0; j < n; j ++)
				{
						printf("%c", ans[i][j]);
				}
				printf("\n");
		}
		return 0;
}
