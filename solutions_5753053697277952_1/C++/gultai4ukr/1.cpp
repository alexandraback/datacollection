#include <bits/stdc++.h>

#define wait system("pause") 
#define LLI long long int
#define LD long double
#define PB push_back
#define MP make_pair
#define FORi(i, a, b) for(int i = a; i < b ; ++i)
#define FORd(i, a, b) for(int i = a; i > b ; --i)
 
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");
	 
const LLI mod = 1e9+7;
int n;
priority_queue<pair<int,int> > pq;

int main(){
	int t,s,tmp,ind,tmp2,ind2;
	fin >> t;
	FORi(q,0,t){
		fout << "Case #" << q+1 << ":";
		//...solution starts...
		
		fin >> n;
		s=0;
		FORi(i,0,n){
			fin >> tmp;
			s += tmp;
			pq.push(MP(tmp,i));
		}
		
		while (s){
			if (pq.top().first>1){
				s -= 2;
				tmp = pq.top().first - 2;
				ind = pq.top().second;
				pq.pop();
				if (pq.top().first + pq.top().first <= s){
					fout << ' ' << char('A'+ind) << char('A'+ind);
					pq.push(MP(tmp,ind));	
					continue;
				}
				else {
					s += 2;
					tmp += 2;
				}
				pq.push(MP(tmp,ind));
			}
			
			s -= 1;
			tmp = pq.top().first - 1;
			ind = pq.top().second;
			pq.pop();
			if (pq.top().first + pq.top().first <= s){
				fout << ' ' << char('A'+ind);
				pq.push(MP(tmp,ind));
				continue;
			}
			else {
				s += 1;
				tmp += 1;
			}
			pq.push(MP(tmp,ind));
				
			s -= 2;
			tmp = pq.top().first - 1;
			ind = pq.top().second;
			pq.pop();
			tmp2 = pq.top().first - 1;
			ind2 = pq.top().second;
			pq.pop();
			fout << ' ' << char('A'+ind) << char('A'+ind2);
			pq.push(MP(tmp,ind));
			pq.push(MP(tmp2,ind2));
		}
		
		while(pq.size())
			pq.pop();
		
		//...solution ends...
		fout << endl;
	}
	fin.close();
	fout.close();
}
