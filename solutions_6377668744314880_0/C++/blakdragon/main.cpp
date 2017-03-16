#include <bits/stdc++.h>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie
using namespace std;
typedef long long int lli;

struct punto{
    lli x,y,o;
};
bool operator<(punto a,punto b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

lli pCruz(punto a,punto b){
	return a.x*b.y-a.y*b.x;
}

punto Pp[17];

struct trio{
	lli a,b,c;
	lli pc;
	punto A,B,C;
	bool validoT(){
		A=Pp[a];
		B=Pp[b];
		C=Pp[c];
		A.x-=B.x;C.x-=B.x;
		A.y-=B.y;C.y-=B.y;
		pc=pCruz(A,C);
		return pc>=0;
	}
	bool validoB(){
		A=Pp[a];
		B=Pp[b];
		C=Pp[c];
		A.x-=B.x;C.x-=B.x;
		A.y-=B.y;C.y-=B.y;
		pc=pCruz(A,C);
		return pc<=0;
	}
};


vector<int>T;
vector<int>B;
trio trios[20002];
punto P[17];
lli menores[17];

int n;
int t,N;
int act;

void techo(){
    for(int i=1;i<=n;i++){
		trios[i].a=0;
		trios[i].b=0;
		trios[i].c=0;
	}
	lli fin=2,sig=2;
	trios[1].a=1;
	trios[1].b=1;
	trios[1].c=1;
	while(trios[fin-1].c!=n){
		trios[fin].a=trios[fin-1].b;
		trios[fin].b=trios[fin-1].c;
		trios[fin].c=sig;
		if(trios[fin].validoT()||fin<=2){
			fin++;
			sig++;
		} else {
			fin--;
		}
	}
	if(fin>3){
		T.push_back(trios[3].a);
		T.push_back(trios[3].b);
		for(int i=3;i<fin;i++){
			T.push_back(trios[i].c);
		}
	} else {
		T.push_back(trios[3].a);
		T.push_back(trios[3].c);
	}
}

void base(){
	for(int i=1;i<=n;i++){
		trios[i].a=0;
		trios[i].b=0;
		trios[i].c=0;
	}
	lli fin=2,sig=2;
	trios[1].a=1;
	trios[1].b=1;
	trios[1].c=1;
	while(trios[fin-1].c!=n){
		trios[fin].a=trios[fin-1].b;
		trios[fin].b=trios[fin-1].c;
		trios[fin].c=sig;
		if(trios[fin].validoB()||fin<=2){
			sig++;
			fin++;
		} else {
			fin--;
		}
	}
	if(fin>3){
		B.push_back(trios[3].a);
		B.push_back(trios[3].b);
		for(int i=3;i<fin;i++){
			B.push_back(trios[i].c);
		}
	} else {
		B.push_back(trios[3].a);
		B.push_back(trios[3].c);
	}
}

void une(){
	int quito=N-n;
	for(int i=0;i<B.size();i++){
        if(quito<menores[Pp[B[i]].o])
            menores[Pp[B[i]].o]=quito;
	}
	for(int i=T.size()-2;i>0;i--)
		if(quito<menores[Pp[T[i]].o])
            menores[Pp[T[i]].o]=quito;
}

void convexHull(){
    techo();
    base();
    une();
    B.clear();
    T.clear();
}

void combina(int pos,int pongo){
    if(pos>N&&pongo>=3){
        n=pongo;
        convexHull();
        return;
    }
    if(pos>N)
        return;
    Pp[pongo+1]=P[pos];
    combina(pos+1,pongo+1);
    combina(pos+1,pongo);
}

int main(){
    optimizar_io(0);
    cin>>t;
    for(int caso=1;caso<=t;caso++){
        cin>>N;
        B.clear();
        T.clear();
        for(int i=1;i<=N;i++){
            cin>>P[i].x>>P[i].y;
            P[i].o=i;
        }
        sort(P+1,P+N+1);
        cout<<"Case #"<<caso<<":\n";
        if(N==1||N==2||N==3){
            for(int i=1;i<=N;i++)
                cout<<0<<"\n";
        } else {
            for(int i=1;i<=N;i++)
                menores[i]=N-2;
            combina(1,0);
            for(int i=1;i<=N;i++)
                cout<<menores[i]<<"\n";
        }
    }
    return 0;
}
