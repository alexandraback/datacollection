#include <cstdio>
#include <set>

using namespace std;

int main (int argc, const char * argv[])
{
	freopen(argv[1], "r", stdin);
	if (argc == 3)
		freopen(argv[2], "w", stdout);

	int num_tc;
	scanf("%d\n", &num_tc);
	for (int i = 0; i < num_tc; i++)
	{
		int row_1, row_2, dup;
		int arr_1[4][4];
		int arr_2[4][4];
		set<int> cset;
		scanf("%d\n", &row_1);
		for (int j = 0; j < 4; j++)
			scanf("%d %d %d %d\n", &arr_1[j][0], &arr_1[j][1], &arr_1[j][2], &arr_1[j][3]);
		scanf("%d\n", &row_2);
		for (int j = 0; j < 4; j++)
			scanf("%d %d %d %d\n", &arr_2[j][0], &arr_2[j][1], &arr_2[j][2], &arr_2[j][3]);
		for (int j = 0; j < 4; j++)
			cset.insert(arr_1[row_1 - 1][j]);
		dup = 0;
		for (int j = 0; j < 4; j++)
			if (cset.find(arr_2[row_2 - 1][j]) != cset.end())
				if (dup == 0)
					dup = arr_2[row_2 - 1][j];
				else
					dup = -1;
		if (dup == 0)
			printf("Case #%d: %s\n", i + 1, "Volunteer cheated!");
		else if (dup == -1)
			printf("Case #%d: %s\n", i + 1, "Bad magician!");
		else
			printf("Case #%d: %d\n", i + 1, dup);

	}

	fclose(stdin);
	if (argc == 3)
		fclose(stdout);
	return 0;
}
