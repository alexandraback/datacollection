#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <hash_map>
#include <sstream>
#include <time.h>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


int main()
{
	FILE *fp = freopen("A-large.in", "r", stdin);
	ofstream out("A-large.out");
	
	int testNum;
	//cin>>testNum;
	scanf("%d", &testNum);

	for (int testI = 1; testI <= testNum; ++testI)
	{
		int maxShy;
		char aud[1000];
		//cin>>maxShy>>aud;
		scanf("%d %s", &maxShy, aud);
		int NeedNum = 0;
		int people = 0;
		for (int i = 0; i<=maxShy; ++i)
		{
			int nc = aud[i] - '0';
			if (nc == 0)
			{
				continue;
			}
			if (people < i)
			{
				int addition = i-people;
				people+=addition + nc;
				NeedNum += addition;
			}
			else
			{
				people += nc;
			}
		}

		out<<"Case #"<<testI<<": "<<NeedNum<<endl;
		//fprintf(fpres, "Case #%d: %d", testI, NeedNum);

	}
	
	fclose(fp);
	out.close();
	return 0;
}

