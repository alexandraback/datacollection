#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <iomanip>
#define MAXLEN 3

using namespace std;
string s;

int main()
{

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("small.out", "w", stdout);
	//ios_base::sync_with_stdio(0);
	int tests;
	cin >> tests;
	cin >> ws;
	vector<int> part;
	int n;
	for (int t = 1; t <= tests; ++t)
	{
		scanf("%d", &n);
		part.assign(n, 0);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &part[i]);
		}
		cout << "Case #" << t << ":";
		int maxid=-1;
		int maxc = 0;
		int grzero = 0;
		char temp;
		do
		{
			maxc = 0;
			maxid = -1;
			grzero = 0;
			for (int i = 0; i < n; ++i)
			{
				if (part[i] > 0)
				{
					grzero++;
				}
				if (part[i] > maxc)
				{
					maxc = part[i];
					maxid = i;
				}
			}
			if (maxid > -1)
			{
				if (grzero > 2)
				{
					part[maxid]--;
					temp = 'A' +(char) maxid;
					printf(" %c",temp);
				}
			}
			if (grzero == 2)
				break;
		} while (maxid>-1);
		int fnonzero, snonzero;
		fnonzero = -1;
		snonzero = -1;
		for (int i = 0; i < n; ++i)
		{
			if (part[i] > 0 && fnonzero == -1)
				fnonzero = i;
			else
			{
				if (part[i] > 0 && fnonzero > -1)
					snonzero = i;
			}
		}
		char temp1, temp2;
		temp1 = 'A' + (char)fnonzero;
		temp2 ='A' + (char)snonzero;
		while (part[fnonzero] > 0)
		{
			
			printf(" %c%c", temp1, temp2);
			part[fnonzero]--;
		}
		cout << endl;
	}
	//system("pause");
	//in.close();
	//out.close();
	return 0;
}