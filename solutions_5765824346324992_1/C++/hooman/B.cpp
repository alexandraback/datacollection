#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

unsigned int B,N,M[1000];

int f(unsigned long long t)
{
	unsigned int sum =B;
	for(int b=0;b<B;b++)
	{
		sum += (t / M[b]);
//if(t && t<100)
//cout<<"hey"<<t<<' '<<b<<' '<<M[b]<<' '<<sum<<' '<<(t / M[b])<<endl;
	}
	return sum;
}

int solve()
{
	unsigned long long time_=1, order = 1;
	
	while(f(time_)<N)
	{
		time_ <<= 1;
//if(time_)
//cout<<"Hooman1 "<<time_<<' '<<f(time_)<<' '<<N<<endl;
	}
	time_ >>= 1;
	for(order = time_>>1; order; order>>=1)
	{
		if(f(time_|order)<N)
		{
			time_ |= order;
		}
	}
	if(time_)
	{
		N -= f(time_);
		time_++;
	}
	for(int b=0;b<B;b++)
	{
		if(time_%M[b] == 0)
		{
			N--;
			if(!N)
				return b+1;
		}
	}
	return -1;
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
		fscanf(in,"%d %d ", &B, &N);
		for(i=0;i<B;i++)
		{
			fscanf(in,"%d ", &M[i]);
//cout<<"M "<<M[i]<<endl;
		}
		fprintf(out, "Case #%d: %d\n",t,solve());
	}
	fclose(in);
	fclose(out);
}
