#include <iostream>
#include <vector>

using namespace std;

int infmax;

void recrandom(vector<vector<bool> >& m,int nahora,int n,int inf)
{
	if(nahora-n)
	{
		for(int i=1;i<m.size();i++)
		{
			for(int j=1;j<m[i].size();j++)
			{
				if(!m[i][j])
					continue;
				int infant = inf;
				m[i][j] = false;
				if(m[i-1][j]) inf--;
				if(m[i+1][j]) inf--;
				if(m[i][j+1]) inf--;
				if(m[i][j-1]) inf--;
				recrandom(m,nahora-1,n,inf);
				inf = infant;
				m[i][j] = true;
			}
		}
	}
	else if(inf<infmax)
		infmax = inf;
}

int main()
{
	int T;
	cin >> T;
	for(int I=0;I<T;I++)
	{
		int r,c,n;
		cin >> r >> c >> n;
		cout << "Case #" << I+1 << ": ";
		if((r*c+1)>=2*n)
			cout << 0 << endl;
		else
		{
			vector<vector<bool> > m(r+2,vector<bool>(c+2,false));
			for(int i=1;i<=r;i++)
			{
				for(int j=1;j<=c;j++)
					m[i][j] = true;
			}
			infmax = r*(c+1)+c*(r+1)-2*r-2*c;
			recrandom(m,r*c,n,r*(c+1)+c*(r+1)-2*r-2*c);
			cout << infmax << endl;
		}
	}
}
