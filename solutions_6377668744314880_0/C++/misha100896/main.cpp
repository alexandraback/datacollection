#include <bits/stdc++.h>

using namespace std;


struct point{
	int x, y;
	int id;
};

bool cmp(point a, point b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool proverka3(point a, point b, point c)
{
	return ((b.y - c.y) * a.x + (c.y - a.y) * b.x + (a.y-b.y) * c.x <= 0);
}

bool proverka4(point a, point b, point c) {
	return ((b.y - c.y) * a.x + (c.y - a.y) * b.x + (a.y - b.y) * c.x >= 0);
}

bool proverka(point a, point b, point c)
{
	return ((b.y - c.y) * a.x + (c.y - a.y) * b.x + (a.y-b.y) * c.x < 0);
}

bool proverka2(point a, point b, point c) {
	return ((b.y - c.y) * a.x + (c.y - a.y) * b.x + (a.y - b.y) * c.x > 0);
}

void obolochka(vector<point> &a)
{
	sort(a.begin(), a.end(), cmp);
	point a1, a2;
	a1 = a[0];
	a2 = a.back();

    vector <point> zz1, zz2;
	zz1.push_back(a1);
	zz2.push_back(a1);
	for (int i = 1; i < a.size(); ++i){
		if (i + 1 == a.size() || proverka3(a1, a[i], a2)) {
			while (zz1.size() > 1 && !proverka3(zz1[zz1.size() - 2], zz1[zz1.size() - 1], a[i]))
				zz1.pop_back();
			zz1.push_back (a[i]);
		}
		if (i + 1 == a.size() || proverka4(a1, a[i], a2)) {
			while (zz2.size()> 1 && !proverka4(zz2[zz2.size() - 2], zz2[zz2.size() - 1], a[i]))
				zz2.pop_back();
			zz2.push_back (a[i]);
		}
	}
	a.clear();
	for (int i = 0; i < zz1.size(); ++i)
		a.push_back(zz1[i]);
	for (int i = zz2.size() - 2; i > 0; --i)
		a.push_back(zz2[i]);
}

int t;
vector <point> m;
int k;
int rez[100], a[100];

void perebor(int zz)
{
    if (zz == m.size())
    {
        int sum = 0;
        for (int i = 0; i < m.size(); ++i)
            sum += a[i];
        if (sum < 4)
        {
            rez[k] = min(rez[k], (int)m.size() - sum);
            return ;
        }
        vector <point> Z;
        Z.clear();
        for (int i = 0; i < m.size(); ++i)
            if (a[i])
                Z.push_back(m[i]);
        obolochka(Z);
        bool f = false;
        for (int i = 0; i < Z.size(); ++i)
            if (Z[i].id == k)
            {
                f = true;
                break;
            }
        if (f)
            rez[k] = min(rez[k], (int)m.size() - sum);
        return ;
    }
    if (zz == k)
    {
        a[zz] = 1;
        perebor(zz + 1);
        a[zz] = 0;
        return ;
    }
    a[zz] = 1;
    perebor(zz + 1);
    a[zz] = 0;
    perebor(zz + 1);
}

int main()
{
    freopen("aaa.in","r",stdin);
    freopen("aaa.out","w",stdout);
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        int n;
        cin >> n;
        m.clear();
        for (int i = 0; i < n; ++i)
            rez[i] = n;
        for (int i = 0; i < n; ++i)
        {
            point aaa;
            cin >> aaa.x >> aaa.y;
            aaa.id = i;
            m.push_back(aaa);
        }
        for (k = 0; k < n; ++k)
            perebor(0);
        cout << "Case #" << j + 1 << ":\n";
        for (int i = 0; i < n; ++i)
            cout << rez[i] << '\n';
    }
    return 0;
}
