#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int,int>> arr;
int n, sum;

bool check(int idx1, vector<pair<int,int>> v)
{
	v[idx1].first--;
	sort(v.begin(), v.end());
	if(v.back().first*2 <= sum-1)
		return true;
	return false;
}

bool check(int idx1, int idx2, vector<pair<int,int>> v)
{
	v[idx1].first--;
	v[idx2].first--;
	sort(v.begin(), v.end());
	if(v.back().first*2 <= sum-2)
		return true;
	return false;
}

int main()
{
	int tcc;
	scanf("%d", &tcc);
	for(int tc = 1; tc <= tcc; tc++)
	{
		printf("Case #%d:", tc);
		sum = 0;

		scanf("%d", &n);
		arr.clear();
		arr.resize(n);

		for(int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			arr.push_back(make_pair(temp, i));
			sum += temp;
		}

		while(sum != 0)
		{
			bool process = false;
			sort(arr.begin(), arr.end());
			if(sum >= 2)
				for(int i = 0; i < arr.size(); i++)
				{
					for(int j = 0; j < arr.size(); j++)
					{
						if(arr[i].first != 0 && arr[j].first != 0 && check(i, j, arr))
						{
							arr[i].first--;
							arr[j].first--;
							sum -= 2;
							process= true;
							printf(" %c%c", 'A'+arr[i].second, 'A'+arr[j].second);
							break;
						}
					}
					if(process)	break;
				}
			if(process)	continue;

			for(int i = 0; i < arr.size(); i++)
			{
				if(arr[i].first != 0 && check(i, arr))
				{
					arr[i].first--;
					sum -= 1;
					printf(" %c", 'A'+arr[i].second);
					break;
				}
			}
		}
		printf("\n");
	}
}
