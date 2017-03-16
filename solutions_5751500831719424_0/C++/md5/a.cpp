#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define fst first
#define snd second
#define pb push_back
#define sz(a) ((int)(a).size())

const int INF = 1000 * 1000 * 1000;
const int MAX_NB_MOTS = 100;
const int MAX_TAILLE_MOT = 100;

string mots[MAX_NB_MOTS];
vector<pair<int,char> > parties[MAX_NB_MOTS];
int nbMots;

void GenererParties() {
    for (int mot = 0; mot < nbMots; mot++) {
        int nbLettresConsec = 1;
    
        for (int lettre = 1; lettre < sz(mots[mot]); lettre++) {
            if (mots[mot][lettre] == mots[mot][lettre - 1])
                nbLettresConsec++;
            else {
                parties[mot].push_back(make_pair(nbLettresConsec, mots[mot][lettre - 1]));
                nbLettresConsec = 1;
            }
        }
        
        parties[mot].push_back(make_pair(nbLettresConsec, mots[mot][sz(mots[mot]) - 1]));
    }
}

bool FeglaGagne() {
    for (int mot = 1; mot < nbMots; mot++) {
        if (sz(parties[mot]) != sz(parties[mot - 1]))
            return true;
        
        for (int partie = 0; partie < sz(parties[mot]); partie++)
            if (parties[mot][partie].second != parties[mot - 1][partie].second)
                return true;
    }
    
    return false;
}

int CompterCoutTotal() {
    int coutTotal = 0;

    for (int partie = 0; partie < sz(parties[0]); partie++) {
        int coutCourant = 0;
        vector<int> valeurs;
    
        for (int mot = 0; mot < nbMots; mot++)
            valeurs.push_back(parties[mot][partie].first);
            
        sort(valeurs.begin(), valeurs.end());
        
        int egalise = valeurs[sz(valeurs) / 2];

        for (int mot = 0; mot < nbMots; mot++)
            coutTotal += abs(egalise - parties[mot][partie].first);

        coutTotal += coutCourant;
    }
    
    return coutTotal;
}

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    
    for (int iTest = 1; iTest <= nbTests; iTest++) {
        scanf("%d", &nbMots);
        
        for (int mot = 0; mot < nbMots; mot++) {
            char motCourant[MAX_TAILLE_MOT + 1];
            parties[mot].clear();
            scanf("%s", motCourant);
            mots[mot] = motCourant;
        }
        
        printf("Case #%d: ", iTest);
        GenererParties();
        
        if (FeglaGagne()) {
            puts("Fegla Won");
            continue;
        }
        
        printf("%d\n", CompterCoutTotal());
    }
    
    return 0;
}
