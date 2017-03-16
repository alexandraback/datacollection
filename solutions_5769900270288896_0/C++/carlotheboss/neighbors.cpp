#include <bits/stdc++.h>
using namespace std;

#define MAXR 18
#define INF 1000000
int T, R, C, N;
bool prese[ MAXR ][ MAXR ];
int sol[ 1 << MAXR ];
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

inline int Indice(int r, int c) { return C*r + c; }

int Prova(int r, int c, int mask, int messe, int ct) {
	//if(sol[ mask ] != -1) return sol[ mask ];
	if(messe == N) return sol[mask] = ct;
	if(r>=R || c>=C) return INF;
	
	//cout<<"Sono in "<<r<<" "<<c<<" con messe "<<messe<<" e ct "<<ct<<endl;
	int nr = ((c+1 == C) ? r+1 : r);
	int nc = (c+1)%C;
	
	//cout<<"Nr: "<<nr<<" Nc: "<<nc<<endl;
	int lascio = Prova(nr, nc, mask, messe, ct);
	
	prese[ r ][ c] = true;
	int add=0;
	for(int i=0;i <4; i++) {
		int gr = r+dr[i], gc=c+dc[i];
		if(gr<0 || gr>=R || gc<0 || gc>=C) continue;
		if(prese[gr][gc]) ++add;
	}
	//cout<<"Provo a prendere "<<r<<" "<<c<<" con indice "<<Indice(r,c)<<endl;
	int metto = Prova(nr, nc, (mask | Indice(r,c)), messe+1, ct+add);
	
	prese[r][c]=false;
	return sol[mask]=min(lascio,metto);
}
int main() {
    ios::sync_with_stdio(false);
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> T;
    for(int i=1;i <= T; i++) {
		in >> R >> C >> N;
		memset(sol, -1, sizeof sol);
		memset(prese, false, sizeof prese);
		out << "Case #"<<i<<": "<<Prova(0, 0, 0, 0, 0) << endl;
	}
	return 0;
}
