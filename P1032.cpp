#include <iostream>
#include <assert.h>
#include <string>
#include <queue>
#include <map>
using namespace std;
const int GROUP = 10;

queue <string> que;
map <string, int> mp;
string src, dest;
string rule_a[GROUP];
string rule_b[GROUP];
int cnt, num, n, ans;

int bfs();
int main()
{
		cin >> src >> dest;
		int i = 0;
		while (cin >> rule_a[i] >> rule_b[i])
		{
				i ++;
		}
		n = i;
		if (bfs() == 1)
				cout << ans << endl;
		else
				cout << "NO ANSWER!" << endl;
		return 0;
}

int bfs()
{
		int i, j, k;
		string u, v;
		que.push(src);
		cnt = 0;
		ans = -1;
		num = 0;
		while (que.empty() == 0)
		{
				if (cnt == num)
				{
						num = que.size();
						cnt = 0;
						ans ++;
				}
				u = que.front();
				que.pop();
				//cout << "pop(" << u << ")" << endl;
				cnt ++;
				if (u == dest)
						return 1;
				if (ans > 10)
						return 0;
				if (mp[u] == 1)
						continue;
				mp[u] = 1;
				for (i = 0; i < n; i ++)
				{
						int len_o = u.length();
						int len_a = rule_a[i].length();
						int len_b = rule_b[i].length();
						for (j = 0; j <= len_o - len_a; j ++)
						{
								int flag = 1;
								for (k = 0; k < len_a; k ++)
								{
										assert(j + k < len_o);
										if (u[j + k] != rule_a[i][k])
										{
												flag = 0;
												break;
										}
								}
								if (flag == 1)
								{
										v = "";
										v.append(u, 0, j);
										v.append(rule_b[i]);
										v.append(u, j + len_a, len_o - (j + len_a));
										//printf("push(%s)\n", v.c_str());
										//cout << "push(" << v << ")" << endl;
										//if (mp[v] == 0)
										    que.push(v);
								}
						}
				}
		}
		return 0;
}
