#include <iostream>
#include <fstream>
using namespace std;
int oo(int a, int b, int n)
{
	if (n <= a*b/2)return 0;
	int re = n - a*b / 2;
	if (re <= 2)return re * 2;
	re -= 2;
	int ans = 4;
	if (re <= a + b - 4)
	{
		ans += re * 3;
		return ans;
	}
	ans += (a + b - 4) * 3;
	re -= (a + b - 4);
	ans += re * 4;
	return ans;
}
int jj(int a, int b, int n)
{
	if (n <= (a*b+1) / 2)return 0;
	int re = n - (a*b+1) / 2;
	if (re <= (a / 2 + b / 2) * 2)return re * 3;
	int ans = (a / 2 + b / 2) * 6;
	re -= (a / 2 + b / 2) * 2;
	ans += re * 4;
	return ans;
}
int jj2(int a, int b, int n)
{
	if (n <= a*b / 2)return 0;
	int re = n - a*b / 2;
	if (re <= 4)return re * 2;
	int ans = 8;
	re -= 4;
	if (re <= ((a + 1) / 2 - 2 + (b + 1) / 2 - 2) * 2)
	{
		ans += re * 3;
		return re;
	}
	ans += ((a + 1) / 2 - 2 + (b + 1) / 2 - 2) * 6;
	re -= ((a + 1) / 2 - 2 + (b + 1) / 2 - 2) * 2;
	ans += re * 4;
	return ans;
}
int zuixiao1(int a, int b, int n)
{
	if (b % 2 == 0)
	{
		if (n <= b / 2)return 0;
		if (n == b / 2 + 1)return 1;
		return 1 + (n - b / 2 - 1) * 2;
	}
	if (n <= (b+1) / 2)return 0;
	return (n - (b+1) / 2) * 2;
}
int re(int a, int b, int n)
{
	if (a == 1)return zuixiao1(a, b, n);
	if (b == 1)return zuixiao1(1,a, n);
	if (a % 2 == 0 || b % 2 == 0)
		return oo(a, b, n);
	int a1 = jj(a, b, n);
	int a2 = jj2(a, b, n);
	if (a1 < a2)return a1;
	return a2;
}
int main()
{
	ifstream fin;
	fin.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.in");
	ofstream fout;
	fout.open("C:\\Users\\ty\\Desktop\\codejam2015\\B.txt");
	int T;
	fin >> T;
	for (int i = 0; i < T; ++i)
	{
		int a, b, n;
		fin >> a >> b >> n;
		//fout << a << " " << b << " " << " " << n << " ";
		fout << "Case #" << i + 1 << ": " <<
			re(a, b, n) << endl;
	}
	fout.close();
	return 0;
}