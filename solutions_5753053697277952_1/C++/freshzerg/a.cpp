#include <iostream>
#include <queue>
using namespace std;
struct ele
{
	char name;
	int number;
	ele(char name, int number): name(name), number(number) {}
	ele() {}
};
class cmp
{
public:
	bool operator() (const ele a, const ele b)
	{
		return a.number < b.number;
	}
};
int main()
{
	int T; cin >> T;
	for (int TT = 1; TT <= T; ++TT)
	{
		priority_queue<ele, vector<ele>, cmp> que;
		printf("Case #%d:", TT);
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int tmp; cin >> tmp;
			que.push(ele('A' + i, tmp));
		}
		while (!que.empty())
		{
			if (que.size() > 2)
			{
				ele a;
				a = que.top(); que.pop();
				a.number--;
				if (a.number) que.push(a);
				printf(" %c", a.name);
			}
			else
			{
				ele a, b;
				a = que.top(); que.pop();
				b = que.top(); que.pop();
				a.number--;
				b.number--;
				if (a.number) que.push(a);
				if (b.number) que.push(b);
				printf(" %c%c", a.name, b.name);
			}
		}
		printf("\n");
	}
	return 0;
}