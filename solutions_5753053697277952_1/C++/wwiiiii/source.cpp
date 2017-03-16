#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void input();
void output();
void solve(int);

int n, left;
int arr[30];
vector<int> answer;
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
}

void solve(int casen)
{
	printf("Case #%d: ", casen);
	input();
	while (left > 0)
	{
		int max1 = 0, max2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >= arr[max1]) max1 = i;
		}
		if (max1 == 0) max2 = 1;
		for (int i = 0; i < n; i++)
		{
			if (i == max1) continue;
			if (arr[i] >= arr[max2]) max2 = i;
		}
		if (left == 3)
		{
			left -= 1;
			arr[max1] -= 1; answer.push_back(max1); answer.push_back(-1);
			continue;
		}
		left -= 2;
		arr[max1] -= 1; arr[max2] -= 1;
		answer.push_back(max1);
		answer.push_back(max2);
		answer.push_back(-1);
	}
	output();
}

void input()
{
	left = 0; answer.clear();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		left += arr[i];
	}
	return;
}

void output()
{
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == -1) printf(" ");
		else printf("%c", answer[i] + 'A');
	} 
	puts("");
	return;
}