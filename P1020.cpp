#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100100;
const int INF = 0xfffff;

int n;
int height[MAXN];
int dp[MAXN];
int visit[MAXN];
int missile = 0;
int defend = INF;

int cmp(int a, int b)
{
    return a > b;
}
int noup_search(int head, int tail, int x);
int up_search(int head, int tail, int x);
int main()
{
		int i = 0;
		while (~scanf("%d", &height[i]))
		{
				i ++;
		}
		n = i;
		missile = 0;
		for (i = 0; i < n; i ++)
		{
				dp[i] = -1;
				visit[i] = -1;
		}
		for (i = 0; i < n; i ++)
		{
				int place = noup_search(0, missile, height[i]);
				if (visit[place] != -1)
				{
						visit[place] = -1;
				}
				visit[i] = 1;
				dp[place] = height[i];
				missile = noup_search(0, missile + 1, 0);
				/*
				printf("place:%d missile:%d\n", place, missile);
				for (int j = 0; j < n; j ++)
				{
						printf("%d ", visit[j]);
				}
				printf("\n");
				for (int j = 0; j < n; j ++)
				{
						printf("%d ", dp[j]);
				}
				printf("\n");
				*/
		}
		printf("%d\n", missile);
		missile = 0;
		for (i = 0; i < n; i ++)
		{
				dp[i] = INF;
				visit[i] = -1;
		}
		for (i = 0; i < n; i ++)
		{
				int place = up_search(0, missile, height[i]);
				if (visit[place] != -1)
				{
						visit[place] = -1;
				}
				visit[i] = 1;
				dp[place] = height[i];
				missile = up_search(0, missile + 1, INF);
		}
		printf("%d\n", missile);
		return 0;
}

int noup_search(int head, int tail, int x)
{
		if (tail - head <= 1)// ???
		{
				if (x > dp[head])
				    return head;
				else
						return tail;
		}
		int mid = (head + tail)/2;
		if (dp[mid] < x)
		{
				return noup_search(head, mid, x);
		}
		else
		{
				return noup_search(mid, tail, x);
		}
		assert(0);
		return -1;
}

int up_search(int head, int tail, int x)
{
		if (tail - head <= 1)// ???
		{
				if (x <= dp[head])
				    return head;
				else
						return tail;
		}
		int mid = (head + tail)/2;
		if (dp[mid] > x)
		{
				return up_search(head, mid, x);
		}
		else
		{
				return up_search(mid, tail, x);
		}
		assert(0);
		return -1;
}
