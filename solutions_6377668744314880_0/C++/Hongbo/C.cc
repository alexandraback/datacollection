#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <float.h>
#include <math.h>
using namespace std;

inline bool feq(double a, double b) {
	return fabs(a - b) < 1e-3;
}

struct vector2d {
	double x, y;
	vector2d() {}
	vector2d(double a, double b) { x = a, y = b; }
	bool operator == (const vector2d &other) const {
		return feq(x, other.x) && feq(y, other.y);
	}
	vector2d operator + (const vector2d &other) const {
		return vector2d(x + other.x, y + other.y);
	}
	vector2d operator - (const vector2d &other) const {
		return vector2d(x - other.x, y - other.y);
	}
	double operator * (const vector2d &other) const {
		return x * other.x + y * other.y;
	}
	double CrossProduct(const vector2d &other) const {
		return x * other.y - y * other.x;
	}
	double Length() const {
		return sqrt(x * x + y * y);
	}
	double Angle(const vector2d &other) const {
		double length_product = Length() * other.Length();
		double sin_a = CrossProduct(other) / length_product;
		double cos_a = (*this * other) / length_product;
		if (asin(sin_a) >= 0) return acos(cos_a);
		else return -acos(cos_a);
	}
};

bool CmpPolarAngle(const vector2d &vector1, const vector2d &vector2)
{
	vector2d base(1, 0);
	double angle1 = base.Angle(vector1);
	if (angle1 < 0) angle1 += asin(1) * 2;
	double angle2 = base.Angle(vector2);
	if (angle2 < 0) angle2 += asin(1) * 2;
	return angle1 < angle2;
}

vector <vector2d> ConvexHull(vector <vector2d> points)
{
	double x = DBL_MAX, y = DBL_MAX;
	for (int i = 0; i < static_cast<int>(points.size()); i ++)
	{
		if (points[i].x < x) x = points[i].x;
		if (points[i].y < y) y = points[i].y;
	}
	for (int i = 0; i < static_cast<int>(points.size()); i ++)
		points[i].x -= x, points[i].y -= y;
	sort(points.begin(), points.end(), CmpPolarAngle);
	vector <vector2d> convex;
	convex.push_back(points[0]);
	convex.push_back(points[1]);
	for (int i = 2; i < static_cast<int>(points.size()); i ++)
	{
		vector2d v1 = *(convex.rbegin()) - *(convex.rbegin() + 1);
		vector2d v2 = points[i] - *(convex.rbegin() + 1);
		while (v1.CrossProduct(v2) < 0)
		{
			convex.pop_back();
			if (convex.size() < 2) break;
			v1 = *(convex.rbegin()) - *(convex.rbegin() + 1);
			v2 = points[i] - *(convex.rbegin() + 1);
		}
		convex.push_back(points[i]);
	}
	convex.push_back(points[points.size() - 2]);
	int half_size = convex.size() - 2;
	for (int i = static_cast<int>(points.size() - 3); i >= 0; i --)
	{
		vector2d v1 = *(convex.rbegin()) - *(convex.rbegin() + 1);
		vector2d v2 = points[i] - *(convex.rbegin() + 1);
		while (v1.CrossProduct(v2) < 0)
		{
			convex.pop_back();
			if (convex.size() < half_size + 2) break;
			v1 = *(convex.rbegin()) - *(convex.rbegin() + 1);
			v2 = points[i] - *(convex.rbegin() + 1);
		}
		convex.push_back(points[i]);
	}
	convex.pop_back();
	for (int i = 0; i < static_cast<int>(convex.size()); i ++)
		convex[i].x += x, convex[i].y += y;
	return convex;
}

inline vector2d GetPoint() {
	double x, y;
	cin >> x >> y;
	return vector2d(x, y);
}

int CntMin(const vector2d &v, const vector <vector2d> &convex) {
	int ans = 0x3f3f3f3f;
	for (int j = 0; j < convex.size(); j ++) {
		vector2d base = convex[j] - v;
		if (base == vector2d(0, 0)) return 0;
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < convex.size(); i ++) {
			vector2d now = convex[i] - v;
			if (0 - now.CrossProduct(base) > 1e-3) cnt0 ++;
			if (now.CrossProduct(base) - 0 > 1e-3) cnt1 ++;
		}
		ans = min(cnt0, cnt1);
	}
	return ans;
}

void solve() {
	vector <vector2d> points;
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		points.push_back(GetPoint());
	vector <vector2d> Convex = ConvexHull(points);
	for (int i = 0; i < points.size(); i ++)
		cout << CntMin(points[i], Convex) << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i ++) {
		cout << "Case #" << i << ": " << endl;
		solve();
	}
	return 0;
}
