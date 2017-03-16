#include <iostream>
#include <fstream>

using namespace std;

int N;
long long m[10001];
int main()
{
	ifstream OpenFile("A-small-attempt0.txt");
	ofstream SaveFile("output.txt");

	int T;
	OpenFile>>T;
	for (int t = 0; t < T; t++)
	{
		OpenFile>>N;
		long long res1=0;
		long long res2=0;
		long long rate=0;
		OpenFile>>m[0];
		for (int i = 1; i < N; i++){
			OpenFile>>m[i];
			if(m[i-1]>m[i]){
				res1+=m[i-1]-m[i];
				rate=max(rate,m[i-1]-m[i]);
			}
		}
		
		for (int i = 0; i < N-1; i++)
		{
			if(m[i]<rate)
			{
				res2=res2+m[i];
			}
			else
			{
				res2+=rate;
			}
		}
		
		SaveFile<<"Case #"<<t+1<<": "<<res1<<" "<<res2<<endl;
	}
	OpenFile.close();
	SaveFile.close();
	return 0;
}
