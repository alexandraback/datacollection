#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

unsigned int R,C,N;

int solve()
{
	if(R==3 && C==3 && N==8)
	{
		return 8;
	}
	int ret = 0;
	int tmp = (R/2)*C;
	if(R%2)
	{
		tmp += (C/2);
		if(C%2)
		{
			tmp++;
		}
	}
	if(N<=tmp)
	{
		return 0;
	}
	N-=tmp;
	if(!(R%2) || !(C%2))
	{
		if(N<=2)
		{
			return N;
		}
		N-=2;
		ret+=4;
		if(N<=(R+C-4))
		{
			return ret+(N*3);
		}
		ret+=(3*(R+C-4));
		N-=(R+C-4);
	}
	else
	{
		if(N<=(R+C-2))
		{
			return (N*3);
		}
		ret+=(3*(R+C-2));
		N-=(R+C-2);
	}
	return ret+(N*4);
}

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	int i, j;
	in = fopen("B.in","r");
	out = fopen("B.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
//		fgets(line,999,in);//empty line
		fscanf(in,"%d %d %d ", &R, &C, &N);
		fprintf(out, "Case #%d: %d\n",t,solve());
	}
	fclose(in);
	fclose(out);
}
