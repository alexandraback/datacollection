#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <set>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for (int no = 0; no < t; ++no)
	{
		int a, b, in;
		std::set<int> test, ans;
		scanf("%d", &a);
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d", &in);
				if (i + 1 == a)
					test.insert(in);
			}
		}
		scanf("%d", &b);
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				scanf("%d", &in);
				if (i + 1 == b)
				{
					if (test.count(in))
						ans.insert(in);
				}
			}
		}
		printf("Case #%d: ", no + 1);
		switch (ans.size())
		{
		case 0:
			printf("Volunteer cheated!\n");
			break;
		case 1:
			printf("%d\n", *ans.begin());
			break;
		default:
			printf("Bad magician!\n");
			break;
		}
	}
	return 0;
}