#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

const int MAXN = 105, MAXL = 105;
int t,n;
std::vector< std::pair<char,int> > in[MAXN];
char tmp[MAXL];

void create(int index)
{
	int len = strlen(tmp),count = 0;
	char currLet = tmp[0];

	for(int pos = 0; pos < len; ++pos)
	{
		if(tmp[pos] != currLet)
		{
			in[index].push_back(std::make_pair(currLet,count));
			currLet = tmp[pos]; count = 1;
		}
		else count++;
	}

	in[index].push_back(std::make_pair(currLet,count));
}

void calculate()
{
	int res = 0,index = 0;

	int size = in[0].size();
	for(int i = 1; i < n; ++i)
		if(in[i].size() != size)
		{
			printf("Fegla Won\n");
			return;
		}

	for(int index = 0; index < in[0].size(); ++index)
	{
		std::vector<int> vec;
		char let = in[0][index].first;
		for(int i = 0; i < n; ++i)
		{
			if(index >= in[i].size() || in[i][index].first != let)
			{
				//if(index >= in[i].size()) printf("index %d >= %d(%d)\n", index, in[i].size(),i);
				//else printf("let: %c %c\n", in[i][index].first, let);
				printf("Fegla Won\n");
				return;
			}
			vec.push_back(in[i][index].second);
		}

		std::sort(vec.begin(), vec.end());
		int mediana = vec[(vec.size()/2)];
		
		//printf("%d!!!\n", vec.size()/2);

		/*for(int i = 0; i < vec.size(); ++i)
			printf("%d ", vec[i]);
		printf(" (%d)\n", mediana);
*/
		for(int i = 0; i < vec.size(); ++i)
			res += abs(mediana-vec[i]);
	}

	printf("%d\n", res);
}

void init()
{
	for(int i = 0; i < MAXN; ++i)
		in[i].clear();
}

int main()
{
	scanf("%d", &t);
	for(int iter = 1; iter <= t; ++iter)
	{
		init();
		scanf("%d", &n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", tmp);
			create(i);
		}
		/*
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < in[i].size(); ++j)
				printf("(%c,%d) ", in[i][j].first, in[i][j].second);
			printf("\n");
		}
		*/
		printf("Case #%d: ", iter);
		calculate();
	}
}
