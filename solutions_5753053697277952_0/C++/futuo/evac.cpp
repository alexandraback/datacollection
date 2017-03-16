#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){

    multimap<int, char> senators;

    int NTC;
    cin >> NTC;

    for( int TC=1; TC<=NTC; TC++ ){
        int N, total=0;
        cin >> N;

        int size;
        for(int i=0; i<N; i++){
            cin >> size;
            senators.insert(pair<int,char>(-size, alphabet[i]));
            total += size;
        }

        cout << "Case #" << TC << ": ";
        multimap<int, char>::iterator it1, it2;
        while(!senators.empty()){
            
            //remove one senator
            it1 = senators.begin();
            int remaining1 = it1->first+1;
            char party1 = it1->second;
            senators.erase(it1);
            total -= 1;
            cout << party1;

            if( remaining1 < 0 ){
                senators.insert(pair<int, char>(remaining1, party1));
            }

            bool balanced = true;
            double perc;
            for( multimap<int, char>::iterator it = senators.begin(); it != senators.end(); it++ ){
                perc = (double)(-it->first) / (double)total;
                if( perc > 0.5 )
                    balanced = false;
            }

            if( balanced && !senators.empty() )
                cout << ' ';
        }
        cout << endl;
    }
}