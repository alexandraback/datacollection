#include <iostream>
#include <set>
using namespace std;

int numOfCases;
int cards[5][5];

int main()
{
	cin>>numOfCases;
	for(int i=1; i<=numOfCases; ++i)
	{
		int r;
		cin>>r;
		set<int> choosed;
		for(int j=1; j<=4; ++j)
			for(int k=1; k<=4; ++k)
				cin>>cards[j][k];
		for(int j=1; j<=4; ++j)
			choosed.insert(cards[r][j]);
		cin>>r;
		for(int j=1; j<=4; ++j)
			for(int k=1; k<=4; ++k)
				cin>>cards[j][k];
		int cnt = 0, ans=0;
		for(int j=1; j<=4; ++j)
			if(choosed.count(cards[r][j]) != 0)
			{
				ans = cards[r][j];
				++cnt;
			}
		cout<<"Case #"<<i<<": ";
		if(cnt > 1) cout<<"Bad magician!"<<endl;
		else if(cnt == 0) cout<<"Volunteer cheated!"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
