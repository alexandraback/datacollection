#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B, I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main()
{
	int T;
	cin >> T;
	
	forn (i, T)
	{
		int a, b;
		vector <vector <int> > card1 (4, vector <int>(4));
		vector <vector <int> > card2 (4, vector <int>(4));
		
		cin >> a;
		forn (j, 4)
			forn (k, 4)
				cin >> card1[j][k];
		cin >> b;
		forn (j, 4)
			forn (k, 4)
				cin >> card2[j][k];
		
		vector <int> list;
		forn (j, 4)
			forn (k, 4)
				if (card1[a-1][j]==card2[b-1][k])
				{
					list.pb(card1[a-1][j]);
					break;
				}
		
		cout << "Case #" << i+1 << ": ";
		if (list.size()==1)
			cout << list[0];
		else if (list.size()>1)
			cout << "Bad magician!";
		else
			cout << "Volunteer cheated!";
		cout << endl;
	}
	
	return 0;
}