#define _SCL_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <map>
//#include <unordered_map>
#include <list>
#include <set>
#include <random>
#include <stack>
#include <sstream>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;



stack <time_t> time_stack;
void startTimer()
{
	time_stack.push(clock());
}
double stopTimer()
{
	double time = clock() - time_stack.top();
	time_stack.pop();
	return time / double(CLOCKS_PER_SEC);
}



#define MAXN 500000
#define MAXM 500
#define MAXK 100
#define INF int(2e9)
#define MOD 1000000009
#define EPS double(1e-15)
#define LAM double(1e-6)
#define PI double(3.14159265359)

double sqr(double x)
{
	return x*x;
}





int main()
{
	startTimer();
	ios::sync_with_stdio(false);
#ifdef _HOME_
	ifstream cin("input.txt");
	ofstream out("output.txt");
	//ofstream cout("output.txt");
	//freopen("output.txt", "w", stdout);
#else
	string TASK = "rvq";
	//ifstream cin(TASK + ".in");
	//ofstream cout(TASK + ".out");
	//freopen("dfsongrid.out", "w", stdout);
#endif
	cout.precision(9); cout << fixed;


	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		out << "Case #" << t + 1 << ": ";

		int n;
		cin >> n;
		vector <pair <int, char> > a(n);
		for (int i = 0; i < n; i++)
		{
			int r; cin >> r;
			a[i].first = r;
			a[i].second = char('A' + i);
		}

		sort(a.rbegin(), a.rend());
		do
		{
			int sum = 0, mx = 0;
			for (int i = 0; i < n; i++)
			{
				sum += a[i].first;
				mx = max(a[i].first, mx);
			}

			if (sum - mx < mx)
				mx = mx;

			if (a[0].first == a[1].first && !(a[0].first == 1 && sum == 3))
			{
				out << a[0].second << a[1].second << " ";
				a[0].first--;
				a[1].first--;
			}
			else
			{
				if (a[0].first > 1)
				{
					out << a[0].second << a[0].second << " ";
					a[0].first--;
					a[0].first--;
				}
				else
				{
					out << a[0].second << " ";
					a[0].first--;
				}
			}
			

			sort(a.rbegin(), a.rend());
		} while (a[0].first > 0);
		

		out << endl;
	}



	cout << endl;
#ifdef _HOME_
	cout.precision(3);
	cout << fixed << stopTimer() << "s\n";
	system("pause");
#endif

	return 0;
}