#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int t,n,pom[105][105],kolejka[105];
string wzor,tab[105];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	
	for (int czo=0; czo<t; czo++)
	{
		cin>>n;
		bool wynik=true;
		for (int i=0; i<n; i++) cin>>tab[i];
		wzor="";
		wzor+=tab[0][0];
		for (int i=1; i<tab[0].size(); i++)
		{
			if (tab[0][i]!=tab[0][i-1]) wzor+=tab[0][i];
		}
		
		for (int i=0; i<n; i++)
		{
			int z=0;
			for (int j=0; j<wzor.size(); j++)
			{
				char ciupa=wzor[j];
				int x=0;
				while (1)
				{
					if (z<tab[i].size() && tab[i][z]==ciupa) x++,z++;
					else
					{
						if (x==0)
						{
							wynik=false;
							break;
						}
						else break;
					}
				}
				pom[i][j]=x;
				
				if (wzor[wzor.size()-1]!=tab[i][tab[i].size()-1]) wynik=false;
				
				if (!wynik) break;
			}
			if (!wynik) break;
		}
		
		if (!wynik) cout<<"Case #"<<czo+1<<": Fegla Won\n";
		else
		{
			int w=0,srednia=0;
			for (int j=0; j<wzor.size(); j++)
			{
				for (int i=0; i<n; i++) kolejka[i]=pom[i][j];
				sort (kolejka, kolejka+n);
				
				srednia=kolejka[n/2];
				for (int i=0; i<n; i++) w+=abs(pom[i][j]-srednia);
			}
			cout<<"Case #"<<czo+1<<": "<<w<<"\n";
		}
	}
	
	return 0;
}
