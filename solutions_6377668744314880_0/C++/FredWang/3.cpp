#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
vector<int> vx;
vector<int> vy;
vector<int> sign;
vector<int> answer;
long long min(long long x, long long y)
{
	return x < y ? x : y;
}
int si(long long A, long long B, long long C, int x, int y)
{
	long long ans = A*x + B*y + C;
	if (ans == 0)return 0;
	if (ans > 0)return 1;
	return -1;
}
int cal(int i)
{
	int ans = 3000;
	for (int k = 0; k < vx.size(); ++k)
	{
		if (k == i)continue;
		long long A = long long(vy[i]) - vy[k];
		long long B = long long(vx[k]) - vx[i];
		long long C = long long(vy[i])*(vx[i] - vx[k]) + long long(vx[i])*(vy[k] - vy[i]);
		for (int j = 0; j < vx.size(); ++j)
		{
			if (j == i || j == k)continue;
			sign[j] = si(A, B, C, vx[j], vy[j]);
		}
		long long zhenghao = 0, fuhao = 0;
		for (int j = 0; j < vx.size(); ++j)
		{
			if (sign[j]>0)++zhenghao;
			else if (sign[j] < 0)++fuhao;
		}
		ans = min(ans, min(zhenghao, fuhao));
	}
	return ans;
}
int main()
{
	ifstream fin;
	fin.open("C:\\Users\\ty\\Desktop\\codejam2015\\A.txt");
	ofstream fout;
	fout.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");
	long long n, t, min, now1, now2;
	long long x[10000], y[10000], temp, a, b, c;
	fin >> t;
	for (int kk = 0; kk<t; kk++) {
		fin >> n;
		for (int i = 0; i<n; i++)
			fin >> x[i] >> y[i];
		fout << "Case #" << kk + 1 << ":" << endl;
		for (int i = 0; i<n; i++) {
			min = 10000;
			for (int j = 0; j<n; j++) {
				if (i == j) continue;
				a = y[i] - y[j];
				b = x[j] - x[i];
				c = y[i] * (x[i] - x[j]) + (y[j] - y[i])*x[i];
				now1 = 0; now2 = 0;
				for (int k = 0; k<n; k++) {
					if (k == i || k == j) continue;
					temp = a*x[k] + b*y[k] + c;
					if (temp>0) now1++;
					if (temp<0) now2++;
				}
				if (now1 < min) min = now1;
				if (now2 < min) min = now2;
			}
			if (n <= 3) fout << 0 << endl; else fout << min << endl;
		}
	}
	fin.close();
	fout.close();
	/*for (int i = 0; i < n; ++i)
	{
		int number;
		f1 >> number;
		for (int k = 0; k < number; ++k)
		{
			int x, y;
			f1 >> x >> y;
			vx.push_back(x);
			vy.push_back(y);
			sign.push_back(0);
			answer.push_back(0);
		}
		if (number <= 3)
		{
			f << "case #" << i + 1 << ": ";
			for (int i = 0; i < number; ++i)
			{
				f << 0 << " ";
			}
			f << endl;
		}
		else
		{
			f << "case #" << i + 1 << ": ";
			for (int i = 0; i < number; ++i)
			{
				f << cal(i) << " ";
			}
			f << endl;
		}
		vx.clear();
		vy.clear();
		sign.clear();
		answer.clear();
	}*/
	return 0;
}