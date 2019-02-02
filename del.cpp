#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;
const int MAXN = 100100;

int n;
int height[MAXN];
int dp[MAXN];
int visit[MAXN];

int cmp(int a, int b)
{
    return a > b;
}
int my_search(int head, int tail, int x);
int main()
{
		int i = 0;
		scanf("%d", &n);
		for (i = 0; i < n; i ++)
		{
				scanf("%d", &height[i]);
		}
		sort(height, height + n, cmp);
		for (i = 0; i < n; i ++)
		{
				printf("%d ", height[i]);
		}
		printf("\n");
		int temp;
		while (~scanf("%d", &temp))
		{
				printf("%d\n", my_search(0, n, temp));
		}
		return 0;
}

int my_search(int head, int tail, int x)
{
		if (tail - head == 1)
		{
				return head;
		}
		int mid = (head + tail)/2;
		if (height[mid] < x)
		{
				return my_search(head, mid, x);
		}
		else
		{
				return my_search(mid, tail, x);
		}
		assert(0);
		return -1;
}
