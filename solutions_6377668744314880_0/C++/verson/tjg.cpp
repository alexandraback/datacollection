#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <string>
#pragma warning(disable:4996)
const float pi = 3.14159265;

#define ll long long
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

struct Point
{
	double x, y;
}first[1010], p[1010], ch[1010];

int w[1010], pd[1010];

double xmult(Point p1, Point p2, Point p0){
	return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
double dis(Point p, Point q){
	return (p.x - q.x)*(p.x - q.x) + (p.y - q.y)*(p.y - q.y);
}
int cmp(Point a, Point b){
	float mu = xmult(a, b, p[0]);
	if (mu>0) return 1;
	if ((mu == 0) && (dis(p[0], a)<dis(p[0], b))) return 1;
	return 0;
}
bool on_line(Point p1, Point p2, Point q)
{
	if (min(p1.x, p2.x) <= q.x && q.x <= max(p1.x, p2.x) &&
		min(p1.y, p2.y) <= q.y && q.y <= max(p1.y, p2.y)) return xmult(p1, p2, q)==0;
	return false;
}

int Graham(int n){
	int i, top, k;
	Point tmp;
	k = 0; top = 2;
	if (n <= 3){
		for (i = 0; i < n; i++) ch[i] = p[i]; ch[n] = ch[0];
		return n;
	}
	for (i = 1; i<n; i++)
		if ((p[i].y<p[k].y) || ((p[i].y == p[k].y) && (p[i].x>p[k].x))) k = i;
	tmp = p[0]; p[0] = p[k]; p[k] = tmp;
	sort(p + 1, p + n, cmp);
	ch[0] = p[0]; ch[1] = p[1]; ch[2] = p[2];
	for (i = 3; i<n; i++)
	{
		while (top>0 && xmult(p[i], ch[top], ch[top - 1])>=0) top--;
		ch[++top] = p[i];
	}
	ch[++top] = ch[0];
	return top;
}

int main()
{
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("tjg.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n, l, top;
		double num;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> first[i].x >> first[i].y, w[i] = 1;
		for (int i = 0; i < (1 << n); i++)
		{
			l = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) pd[l] = 1, p[l++] = first[j];
			top = Graham(l);
			for (int j = 0; j < n; j++) if (i & (1 << j)) 
				for (int k = 1; k <= top; k++)
					if (on_line(ch[k - 1], ch[k], first[j]))
					{
						w[j] = max(w[j], l);
						break;
					}
		}

		cout << "Case #" << t << ":" << endl;
		for (int i = 0; i < n; i++) cout << n - w[i] << endl;
	}
}