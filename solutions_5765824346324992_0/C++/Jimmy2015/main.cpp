#include <fstream>
#include <algorithm>
using namespace std;
int m[1005];

int gcd(int a, int b) {
	int t;
	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	while (t = a % b) {
		a = b;
		b = t;
	}
	return b;
}

int main()
{
	int t;
	ifstream infile("G:\\B-small-attempt2.in");
	ofstream outfile("G:\\B-small-attempt2.out");
	infile >> t;
	for (int i = 1; i <= t; i++)
	{
		int b,n;
		infile>>b>>n;
		for(int j=0;j<b;++j)
		{
			infile>>m[j];
		}

		int gongyueshu=m[0];
		for(int qq=1;qq<b;qq++)
			gongyueshu=gcd(gongyueshu,m[qq]);

		int lunxun=0;
		long long gongbeishu=gongyueshu;

		for(int bar=0;bar<b;bar++)
		{
			gongbeishu *= m[bar]/gongyueshu;
		}
		for(int bar=0;bar<b;bar++)
		{
			lunxun+=gongbeishu/m[bar];
		}
		
		int result;
		int number=(n-1)%lunxun+1;
		bool flag=false;
		int serve=0;
		for(int time=0;;time++)
		{
			for(int bar=0;bar<b;bar++)
			{
				if(time%m[bar]==0)
					serve++;
				if(serve==number)
				{
					flag=true;
					result=bar+1;
					break;
				}
			}
			if(flag)
				break;
		}

		outfile << "Case #" << i << ": " <<result << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}