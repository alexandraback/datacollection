#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include <climits>
#include <cstring>
#include <list>
#include <iomanip>
#include <unordered_map>


using namespace  std;

#define int64 long long
#define F(vec, index) for (int index=0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index=0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int indexfrom + 1; index  < vec.size(); ++index)
#define _GLIBCXX_DEBUG
/*
void Do(fstream &cin, fstream &cout) {
    
}

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    
    fstream cout("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/out.txt", fstream::out);
    fstream cin("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/in.txt", fstream::in);
    
   	int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << i << endl;
        cout << "Case #" << i + 1 << ": ";
        Do(cin, cout);
    }
    return 0;
}*/



#include "vector"
#include "string"
#include "set"
#include "map"
#include "sstream"
#include "algorithm"
#include "cmath"
#include "cassert"
#include "iostream"
#include "numeric"
#include "fstream"
#include "queue"
#include <functional>
#include <climits>
#include <cstring>
#include <list>
#include <iomanip>
#include <unordered_map>


using namespace  std;

#define int64  long long
#define F(vec, index) for (int index=0; index  < vec.size(); ++index)
#define F2(index, vec) for (int index=0; index  < vec.size(); ++index)
#define F3(index, from, vec) for (int indexfrom + 1; index  < vec.size(); ++index)
#define _GLIBCXX_DEBUG

void Do(fstream &cin, fstream &cout) {
    int n;
    cin >> n;
    vector<pair<int, int>> data;
    for (int  i = 0; i < n; ++i) {
        int v;
        cin >> v;
        data.push_back({v, i + 1});
    }
    sort(data.rbegin(), data.rend());
    if (data.size() == 1) {
        for (int i = 0; i < data[0].first; ++i) {
            cout << ' ' << char('A' - 1 + data[0].second);
        }
        cout << endl;
        return;
    }
    
    while (data[0].first != data[1].first) {
        cout << ' ' << char('A' - 1 + data[0].second);
        --data[0].first;
    }
    for (int i = 2; i < data.size(); ++i) {
        for (int j = 0; j < data[i].first; ++j) {
        	cout << ' ' << char('A' - 1 + data[i].second);
        }
    }
    assert(data[0].first == data[1].first);
    while (data[0].first != 0) {
        cout << ' '
        	<< char('A' - 1 + data[0].second)
       	 << char('A' - 1 + data[1].second);
        --data[0].first;
        --data[1].first;
    }
    cout << endl;
    
}
 
int main(int argc, char* argv[])
{
	std::ios::sync_with_stdio(false);
 	fstream cout("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/out.txt", fstream::out);
 	fstream cin("/Users/a-voronin/xcode/CompetitionGeneral/CompetitionGeneral/in.txt", fstream::in);
 
	int t;
 	cin >> t;
 	for (int i = 0; i < t; ++i) {
 		std::cout << i << endl;
 		cout << "Case #" << i + 1 << ":";
 		Do(cin, cout);
	}
	return 0;
}

