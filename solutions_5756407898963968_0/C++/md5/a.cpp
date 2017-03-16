#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int nbLins = 4, nbCols = 4;

int main() {
    int nbTests;
    
    scanf("%d", &nbTests);
    
    for (int iTest = 1; iTest <= nbTests; iTest++) {
        vector<int> possible, reponse;
        
        for (int iTour = 0; iTour < 2; iTour++) {
            int linChoisie;
            scanf("%d", &linChoisie);
            linChoisie--;
            
            for (int iLin = 0; iLin < nbLins; iLin++)
                for (int iCol = 0; iCol < nbCols; iCol++) {
                    int valeur;
                    scanf("%d", &valeur);
                    
                    if (iLin == linChoisie) {
                        if (iTour == 0)
                            possible.push_back(valeur);
                        else if (iTour == 1 && find(possible.begin(), possible.end(), valeur) != possible.end())
                            reponse.push_back(valeur);
                    }
                }
        }
        
        printf("Case #%d: ", iTest);
        
        if (reponse.empty())
            puts("Volunteer cheated!");
        else if (reponse.size() > 1)
            puts("Bad magician!");
        else
            printf("%d\n", reponse[0]);
    }
    
    return 0;
}
