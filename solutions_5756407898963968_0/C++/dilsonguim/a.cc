#include <bits/extc++.h>
#include <iostream>

using namespace std;

//#define NDEBUG
#ifdef NDEBUG
#define DEBUG if (false)
#else
#define DEBUG if (true)
#endif
#define WRITE(x) DEBUG { cout << (x) << endl; }
#define WATCH(x) DEBUG { cout << #x << " = " << (x) << endl; }
//#define ALL(x) (x).begin(), (x).end()
//#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); ++i)
//#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ntc;
	cin >> ntc;
	for(int tc = 0; tc < ntc; tc++){
		set<int> possibilities;

		int first_answer;
		cin >> first_answer;
		for(int i = 1; i < 5; i++){
			for(int j = 1; j < 5; j++){
				int card;
				cin >> card;
				if(i == first_answer){
					possibilities.insert(card);
				}
			}
		}
		
		int second_answer;
		cin >> second_answer;
		for(int i = 1; i < 5; i++){
			for(int j = 1; j < 5; j++){
				int card;
				cin >> card;
				if(i != second_answer){
					possibilities.erase(card);
				}
			}
		}

		cout << "Case #" << (tc + 1) << ": ";
		if(possibilities.empty()){
			cout << "Volunteer cheated!";
		}else if(possibilities.size() > 1){
			cout << "Bad magician!";
		}else{
			cout << (*possibilities.begin());
		}
		cout << '\n';
	}
}
