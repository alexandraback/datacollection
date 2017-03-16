#include<iostream>
#include<fstream>
//#include<set>
#include<algorithm>

using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

void risolvi(pair<int,char> v[], int n, int somma){
    sort(v,v+n,greater<pair<int,char> >());

    if(somma==0)
        return;
    if(somma!=3){
        if(v[0].first>1 && v[1].first <= (somma-2)/2 ){
            v[0].first-=2;
            output << v[0].second << v[0].second;
        }
        else{
            v[0].first--;
            v[1].first--;
            output << v[0].second << v[1].second;
        }
        if(somma>2)
            output << " ";
        somma-=2;
    }
    else if(somma==3){
        v[0].first--;
        somma--;
        output << v[0].second << " ";
    }
    risolvi(v,n,somma);
}

int main(){


    int cases;
    input >> cases;

    int n,somma;

    for(int ncase=0;ncase<cases;ncase++){
        somma = 0;
        input >> n;
        pair<int,char> v[n];
        char insert='A';
        for(int i=0;i<n;i++){
            input >> v[i].first;
            somma+=v[i].first;
            v[i].second=insert;
            insert++;
        }
        output << "Case #" << ncase+1 << ": ";
        risolvi(v,n,somma);
        output << endl;
    }

    return 0;
}
