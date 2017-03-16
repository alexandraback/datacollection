#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class point
{
public:
	int x, y;
	int treeIndex;
	
	point() {x=y=treeIndex=0;}
	point(int _x, int _y) {x = _x; y = _y; treeIndex =0;}
	point operator+(const point z) const
	{
		return point(x + z.x, y+z.y);
	}
	point operator-(const point z) const
	{
		return point(x-z.x, y-z.y);
	}
	
	point operator-=(point z)
	{
		x -= z.x;
		y -= z.y;
		return *this;
	}
	point operator+=(point z)
	{
		x += z.x;
		y += z.y;
	}
	
	bool pureGT(const point z) const
	{
		return x*z.y-y*z.x > 0;
	}
	
	bool operator<(const point z) const
	{
		if (x*z.y-y*z.x == 0)
			return x*x+y*y < z.x*z.x+z.y*z.y;
		return x*z.y-y*z.x < 0;
	}
	bool operator>(const point z) const
	{
		if (x*z.y-y*z.x == 0)
			return x*x+y*y > z.x*z.x+z.y*z.y;
		return x*z.y-y*z.x > 0;
	}
	bool operator>=(const point z) const
	{
		return !(*this < z);
	}
	bool operator<=(const point z) const
	{
		return !(*this > z);
	}
};

void doCase()
{
	int N;
	cin >> N;
	
	vector<point> trees(N);
	
	for (int i=0; i<N; i++)
	{
		cin >> trees[i].x >> trees[i].y;
		trees[i].treeIndex = i;
	}
	
	int minI=-1;
	int minX=1000001;
	int minY=1000001;
	
	for (int i=0; i<N; i++)
	{
		if (trees[i].x < minX || 
			(trees[i].x == minX && trees[i].y < minY))
		{
			minI = i;
			minX = trees[i].x;
			minY = trees[i].y;
		}
	}
	
	point base = trees[minI];
	
	swap(trees[minI], trees[trees.size()-1]);
	trees.pop_back();
	
	for (int i=0; i<N-1; i++)
	{
		trees[i] -= base;
	}
	
	sort(trees.begin(), trees.end());
	
	vector<int> count(N,0);
	vector<point> hull;
	hull.push_back(base);
	hull.push_back(trees[0]);
	
	for (int i=1; i<N-1; i++)
	{
		while (hull.size() > 1 && 
			(hull[hull.size()-1]-hull[hull.size()-2]).pureGT(trees[i]-hull[hull.size()-1]))
				hull.pop_back();
		
		hull.push_back(trees[i]);
		
		int curCount = 0;
		for (int j=i+1; j<N-1; j++)
		{
			if ((hull[hull.size()-1]-hull[hull.size()-2]).pureGT(trees[j]-trees[i]))
				curCount++;
		}
		if (trees[i].x*trees[N-2].y-trees[i].y*trees[N-2].x == 0)
			curCount = 0;
		count[trees[i].treeIndex] = curCount;
	}
	
	cout << endl;
	for (int i=0; i<N; i++)
		cout << count[i] << endl;
}

int main()
{
	int T;
	
	cin >> T;
	
	for (int i=0; i<T; i++)
	{
		cout << "Case #" << i+1 << ": ";
		doCase();
	}
	
	return 0;
}
