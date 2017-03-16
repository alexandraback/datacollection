#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int I=1;I<=T;I++)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];
		cout << "Case #" << I << ":";
		int suma = 0;
		for(int i=0;i<n;i++)
			suma+=v[i];
		
		while(suma>0)
		{
			int mx = 0;
			int pos1 = -1;
			int pos2 = -1;
			for(int i=0;i<n;i++)
			{
				if(v[i]>mx)
				{
					mx = v[i];
					pos1 = i;
					pos2 = -1;
				}
				else if(v[i]==mx)
					pos2 = i;
			}
			if(mx>1)
			{
				cout << " " << char('A'+pos1);
				v[pos1]--;
				suma--;
				if(pos2>=0)
					cout << char('A'+pos2),v[pos2]--,suma--;
			}
			else if(suma!=2)
			{
				cout << " " << char('A'+pos1);
				v[pos1]--,suma--;;
			}
			else
			{
				cout << " " << char('A'+pos1);
				v[pos1]--;
				cout << char('A'+pos2),v[pos2]--;
				suma-=2;
			}
		}
		cout << endl;
	}
}
