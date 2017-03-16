#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <memory>

using namespace std;
using ll = long long;

struct Entry
{
	int id;
	int count;	
	bool operator < (const Entry &other) const
	{
		return count == other.count
			? id < other.id
			: count > other.count;
	}
};

void SolveCase(int caseId);

int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i)
		SolveCase(i);
	return 0;
}

inline char IdToChar(int id)
{
	return 'A' + id;
}

void GetOne(set<Entry> &P)
{
	auto it = P.begin();
	auto entry = *it;
	P.erase(it);
	printf("%c", IdToChar(entry.id));
	if(--entry.count > 0)
		P.insert(entry);
}

void SolveCase(int caseId)
{
	printf("Case #%d: ", caseId);
	int N;
	int sum = 0;
	set<Entry> P;
	scanf("%d", &N);
	for(int i = 0, count; i < N; ++i)
	{
		scanf("%d", &count);
		P.insert(Entry{i, count});
		sum += count;
	}
	if(sum % 2 == 1)
	{
		GetOne(P);
		printf(" ");
	}
	
	while(!P.empty())
	{
		GetOne(P);
		GetOne(P);
		printf(" ");
	}
	
	puts("");
}

