#include <map>
#include <cstdio>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);

	for ( int i = 0; i < t; ++i ) {

		int n;
		scanf("%d", &n);
		multimap <int, char> p;

		for ( int j = 0; j < n; ++j ) {
			int pi;
			scanf("%d", &pi);
			p.insert(make_pair(pi, 'A'+j));
		}

		printf("Case #%d:", i+1);

		while ( p.size() > 2 ) {
			pair <int, char> o = *p.rbegin();
			printf(" %c", o.second);
			o.first--;
			p.erase(--p.end());
			if ( o.first )
				p.insert(o);
		}

		pair <int, char> o1 = *p.rbegin();
		pair <int, char> o2 = *++p.rbegin();

		for ( int j = 0; j < o1.first-o2.first; ++j )
			printf(" %c", o1.second);

		for ( int j = 0; j < o1.first; ++j )
			printf(" %c%c", o1.second, o2.second);

		printf("\n");

	}

	return 0;

}
