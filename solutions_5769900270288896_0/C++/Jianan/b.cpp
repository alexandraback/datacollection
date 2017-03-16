#include <iostream>
#include <fstream>
using namespace std;
int small(int a,int b,int c ,int d)
{
	int ret=0;
	if (d<=a) return d*2;
	else
	{
		d-=a;
		ret+=a*2;
	}
	if (d<=b) return ret+d*3;
	else
	{
		d-=b;
		ret+=b*3;
	}
	return ret+d*4;
}
int main()
{
	ifstream fin("3.txt");
	ofstream fout("4.txt");
	int T,o,i,tmp1,n,tmp2,r,c,jiao,bian,nei,ok;
	fin >> T;
	for (o=1;o<=T;o++)
	{
		fin >> r >> c >> n;
		if (r==1 || c==1)
		{
			if (r*c %2==0)
			{
				ok=r*c/2;
				jiao=1;
				bian=r*c/2-1;
				tmp1=0;
				if (ok>=n) tmp1=0;
				else
				{
					n-=ok;
					n-=jiao;
					tmp1+=jiao;
					if (n>0) tmp1+=n*2;

				}
			}
			else
			{
				ok=(r*c+1)/2;
				jiao=0;
				bian=(r*c-1)/2;
				tmp1=0;
				tmp2=n;
				if (ok>=n) tmp1=0;
				else
				{
					n-=ok;
					n-=jiao;
					tmp1+=jiao;
					if (n>0) tmp1+=n*2;
				}
				n=tmp2;
				ok=(r*c-1)/2;
				jiao=2;
				bian=r*c-ok-jiao;
				tmp2=0;
				if (ok>=n) tmp2=0;
				else
				{
					n-=ok;
					n-=jiao;
					tmp2+=jiao;
					if (n>0) tmp2+=n*2;
				}
				if (tmp1>tmp2) tmp1=tmp2;
			}
			cout << "Case #" << o << ": " << tmp1 << endl;
			fout << "Case #" << o << ": " << tmp1 << endl;
			continue;
		}
		if (r*c % 2==0)
		{
			jiao=2;
			bian=r+c-4;
			nei=(r-2)*(c-2)/2;
			ok=r*c/2;
			if (ok>=n) tmp1=0;
			else tmp1=small(jiao,bian,nei,n-ok);
		}
		else
		{
			jiao=4;
			bian=r+c-6;
			nei=((r-2)*(c-2)+1)/2;
			ok=(r*c-1)/2;

			if (ok>=n) tmp1=0;
			else tmp1=small(jiao,bian,nei,n-ok);
			jiao=0;
			bian=r+c-2;
			nei=((r-2)*(c-2)-1)/2;
			ok=(r*c+1)/2;
			if (ok>=n) tmp2=0;
			else tmp2=small(jiao,bian,nei,n-ok);
			if (tmp1>tmp2) tmp1=tmp2;
		}
		cout << "Case #" << o << ": " << tmp1 << endl;
		fout << "Case #" << o << ": " << tmp1 << endl;
	}
	return 0;
}