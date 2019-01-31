#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

string src;
int n;

int build_tree(int head, int tail);
int main()
{
		cin >> n >> src;
		build_tree(0, (1 << n));
		cout << endl;
		return 0;
}
int build_tree(int head, int tail)
{
		int i;
		int flag = 0;
		int mid = (head + tail)/2;
		char h_type = src[head];
		char my_type = 'F';
		for (i = head; i < tail; i ++)
		{
				if (src[i] != h_type)
				{
						flag = 1;
						break;
				}
		}
		if (tail - head > 1)
		{
		    build_tree(head, mid);
		    build_tree(mid, tail);
		}
		if (flag != 1)
		{
				if (h_type == '1')
						my_type = 'I';
				else if (h_type == '0')
						my_type = 'B';
				else
						assert(0);
		}
		cout << my_type;
		return 0;
}
