#include <stdio.h>
#include <assert.h>
#include <string.h>
const int MAXN = 30;
int n;
int my_map[MAXN][MAXN] = {0};
char words[MAXN][MAXN];
int visit[MAXN] = {0};
int ans = 0;
int length = 0;
int build_way();
int my_link(char a[], char b[]);
int dfs(int x);
int my_max(int a, int b)
{
		if (a > b)
				return a;
		return b;
}
int main()
{
		scanf("%d", &n);
		for (int i = 0; i < n + 1; i ++)
		{
				scanf("%s", words[i]);
		}
		words[n][1] = words[n][0];
		words[n][2] = '\0';
		build_way();
		length = 1;
		dfs(n);
		/*
		for (int i = 0; i < n + 1; i ++)
		{
				for (int j = 0; j < n + 1; j ++)
				{
						printf("%d ", my_map[i][j]);
				}
				printf("\n");
		}
		for (int i = 0; i < n + 1; i ++)
		{
				printf("%d ", visit[i]);
		}
		printf("\n");
		*/
		printf("%d\n", ans);
		return 0;
}
int dfs(int x)
{
		visit[x] ++;
		ans = my_max(ans, length);
		for (int i = 0; i < n; i ++)
		{
				if (visit[i] <= 1 && my_map[x][i] != 0)
				{
						length = length - strlen(words[x]) + my_map[x][i] + strlen(words[i]);
						dfs(i);
						length = length + strlen(words[x]) - my_map[x][i] - strlen(words[i]);
				}
		}
		visit[x] --;
		return 0;
}
int build_way()
{
		n ++;
		for (int i = 0; i < n; i ++)
		{
				for (int j = 0; j < n; j ++)
				{
						//if (i == j)
						//		continue;
						my_map[i][j] = my_link(words[i], words[j]);
				}
		}
		n --;
		return 0;
}
int my_link(char a[], char b[])
{
		int tail;
		int a_len = strlen(a), b_len = strlen(b);
		int flag;
		// <--        a        -->
		// <--     tail       --><-- b -->
		// tail = a_len - 1
		// <--        a        -->
		// <--  tail   --><-- b -->
		// tail = a_len + 1 - b_len
		// <--        a        -->
		// <-tail-><--        b       -->
		for (tail = a_len - 1; tail >= a_len + 1 - b_len && tail >= 1; tail --)
		{
				flag = 1;
				for (int i = tail, j = 0; i < a_len; i ++, j ++)
				{
						if (a[i] != b[j])
						{
								flag = 0;
								break;
						}
				}
				if (flag == 1)
				{
						return tail;
				}
		}
		return 0;
}
