#include <fstream>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

int main(){
	ifstream fin ("B-small-attempt4.in");
	ofstream fout ("B-output.txt");
	int T, B, mmin, temp;
	long long N, k;
	int m[1001];
	double x, y;
	fin >> T;
	for(int c = 1; c <= T; c++){
        multiset<pair<int, int> >::iterator it;
        pair<int, int> cur;
        fin >> B >> N;
        x = 0;
        mmin = 100001;
        for(int i = 1; i<=B; i++){
            fin >> m[i];
            x += 1.0/((double) m[i]);
            if(m[i]<mmin) mmin = m[i];
            //cout << m[i] << ' ';
        }
        //cout << '\n';
        y = N/x - mmin;
        while(1){
            multiset<pair<int, int> > work;     //timestamp, #
            k = 0;
            for(int i = 1; i<=B; i++){
                temp = y / m[i] + 1;
                //cout << temp << ' ';
                k += temp;
                work.insert(make_pair(m[i]*temp, i));
            }
            //cout << '\n' << '\n';
            if(k<N){
                for(int i = k+1; i<N; i++){
                    it = work.begin();
                    cur = *it;
                    cur.first += m[cur.second];
                    work.erase(it);
                    work.insert(cur);
                }
                it = work.begin();
                fout << "Case #" << c << ": " << (*it).second << '\n';
                break;
            }
            //cout << c << ' ' << y << ' ' << k << ' ' << N << '\n';
            y -= B*mmin;
            //cout << y - (y-B) << '\n';
        }
	}
}
