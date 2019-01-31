#include <stdio.h>
#include <assert.h>
const int MAXN = 40;
int n;
int tree[MAXN];
int mult[MAXN][MAXN];
int ans[MAXN][MAXN];
int my_max(int a, int b)
{
		if (a > b)
				return a;
		return b;
}
int dfs(int head, int tail);
int my_print(int head, int tail);
int main()
{
		for (int i = 0; i < n; i ++)
		{
				for (int j = 0; j < n; j ++)
				{
						ans[i][j] = -1;
				}
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i ++)
		{
				scanf("%d", &tree[i]);
		}
		printf("%d\n", dfs(0, n));
		my_print(0, n);
		printf("\n");
		return 0;
}
int dfs(int head, int tail)
{
		if (mult[head][tail] != 0)
		    return mult[head][tail];
		if (head == tail - 1)
		{
				ans[head][tail] = head;
				mult[head][tail] = tree[head];
				return mult[head][tail];
		}
		if (head == tail)
		{
				mult[head][tail] = 1;
				return 1;
		}
		for (int i = head; i < tail; i ++)
		{
				int left = dfs(head, i);
				int right = dfs(i + 1, tail);
				if (left*right + tree[i] > mult[head][tail])
				{
						ans[head][tail] = i;
						mult[head][tail] = left*right + tree[i];
				}
		}
		return mult[head][tail];
}
int my_print(int head, int tail)
{
		if (head == tail)
				return 0;
		printf("%d ", ans[head][tail] + 1);
		my_print(head, ans[head][tail]);
		my_print(ans[head][tail] + 1, tail);
		return 0;
}
