#include <bits/stdc++.h>
using namespace std;
//geometry library almost verbatim from stanford icpc notebook
struct PT { 
  long long int x, y;
  int init_pos;
  PT() {}
  PT(long long int x, long long int y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y), init_pos(p.init_pos)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (long long int c)     const { return PT(x*c,   y*c  ); }
  PT operator / (long long int c)     const { return PT(x/c,   y/c  ); }
};

long long int dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
long long int dist2(PT p, PT q)   { return dot(p-q,p-q); }
long long int cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

PT lower_left;
//change sorter to use double in case using geometry libary
bool sorter(const PT &p, const PT &q)
{
	long long int cpq = cross(p-lower_left, q-lower_left);
	if(cpq == 0)
		return dist2(p, lower_left) < dist2(q, lower_left);
	return cpq>0;
}
//size of A should at least be three
void convex_hull(vector <PT> &A, vector <PT> &hull)
{
	for (int i = 1; i < A.size(); ++i)
	{
		if(A[i].y < A[0].y || (A[i].y <= A[0].y && A[i].x < A[0].x))
			swap(A[0],A[i]);
	}
	lower_left = A[0];
	sort(A.begin()+1, A.end(), sorter);
	hull.clear();
	hull.push_back(A[0]);
	hull.push_back(A[1]);
	int hull_sz=2;
	for (int i = 2; i < A.size(); ++i)
	{
		while(cross(hull[hull_sz-1]-hull[hull_sz-2], A[i]-hull[hull_sz-1]) < 0 && hull_sz > 1)
		{
			hull.pop_back();
			hull_sz--;
		}
		hull.push_back(A[i]);
		hull_sz++;
	}
}
int main()
{
	// freopen("input.txt", "r", stdin);
	freopen("c_small.in", "r", stdin);
	freopen("c_small.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int case_num = 1; case_num <= t; ++case_num)
	{
		int n;
		cin>>n;
		vector <PT> A(n);
		vector <int> ans(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i].x>>A[i].y;
			A[i].init_pos = i;
		}
		if(n == 1)
			ans[0] = 0;
		else if(n == 2)
		{
			ans[0] = 0;
			ans[1] = 0;
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				ans[i] = n-2;
			}
			for (int mask = 0; mask < (1<<n); ++mask)
			{
				if(__builtin_popcount(mask) < 3)
					continue;
				vector <PT> B;
				for (int i = 0; i < n; ++i)
				{
					if(mask & (1<<i))
					{
						B.push_back(A[i]);
					}
				}
				vector <PT> hull;
				convex_hull(B,hull);
				for (int i = 0; i < hull.size(); ++i)
				{
					PT curr = hull[i];
					PT nxt = hull[(i+1)%(hull.size())];
					for (int j = 0; j < n; ++j)
					{
						PT x = A[j]-curr;
						PT y = A[j]-nxt;
						if(cross(x,y) == 0 && dot(x,y) <= 0)
							ans[j] = min(ans[j], n-(__builtin_popcount(mask)));
					}
				}
			}
		}
		cout<<"Case #"<<case_num<<":\n";
		for (int i = 0; i < n; ++i)
		{
			cout<<ans[i]<<"\n";
		}
	}
	return 0;
}