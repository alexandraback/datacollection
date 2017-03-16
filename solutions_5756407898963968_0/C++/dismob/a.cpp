
#include <iostream>

#include <vector>
#include <string>
#include <sstream>

using namespace std;

int tests;

template< typename T >
std::string ToString( const T& v )
{
  std::ostringstream oss;
  oss << v;
  return oss.str();
}


int main()
{
	cin >> tests;

	for( int curTest=0; curTest<tests; ++curTest )
	{
		int a1, a2;
		int g1[4][4];
		int g2[4][4];

		cin >> a1;
		for( int i=0; i<4; ++i ) for( int j=0; j<4; ++j )
		{
			cin >> g1[i][j];
		}
		cin >> a2;
		for( int i=0; i<4; ++i ) for( int j=0; j<4; ++j )
		{
			cin >> g2[i][j];
		}
		--a1;
		--a2;

		int r =0;
		int sel =-1;
		for( int i=0; i<4; ++i ) for( int j=0; j<4; ++j )
		{
			if ( g1[a1][i] == g2[a2][j] )
			{
				++r;
				sel = g1[a1][i];
			}
		}
		string res =( r==0 ? "Volunteer cheated!" : ( r==1 ? ToString(sel) : "Bad magician!" ) );

		cout << "Case #" << (curTest+1) << ": ";
		cout << res;
		cout << endl;
	}

	return 0;
}

