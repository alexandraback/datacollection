//FRENCH
#include <cstdio>

#define PAS_TROUVE -1
#define PLUSIEURS_POSSIBILITES 20

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) //pour chaque test
    {
        ///Input
        int rep1, rep2; //premiere et 2eme reponse du volontaire
        scanf("%d", &rep1);

        int grille1[5][5], grille2[5][5];  //simplifie, evite des -1 de decalage
        for(int i = 1; i <= 4; i++) //i : ligne
        {
            for(int j = 1; j <= 4; j++) //j : colonne
            {
                scanf("%d", &grille1[i][j]);
            }
        }

        scanf("%d", &rep2);
        for(int i = 1; i <= 4; i++) //i : ligne
        {
            for(int j = 1; j <= 4; j++) //j : colonne
            {
                scanf("%d", &grille2[i][j]);
            }
        }
        ///Fin input

        ///Test
        int carte = PAS_TROUVE; //carte est le numero de la carte choisie
        for (int j1 = 1; j1 <= 4; j1++) //compteur de colonne dans la premiere grille
        {
            for(int j2 = 1; j2 <= 4; j2++)  //compteur de colonne dans la deuxieme grille
            {
                if(grille1[rep1][j1] == grille2[rep2][j2])  //la carte satisfait les 2 criteres
                {
                    if (carte == PAS_TROUVE)
                    {
                        carte = grille1[rep1][j1];  //cette carte peut etre celle cherchee
                    }
                    else    //il y avait deja une carte satisfaisant les criteres
                    {
                        carte = PLUSIEURS_POSSIBILITES;
                    }
                }
            }
        }
        ///Fin test

        ///Output
        printf("Case #%d: ", t);    //commun a tous les affichages

        if (carte == PAS_TROUVE)
        {
            printf("Volunteer cheated!\n");
        }
        else if (carte == PLUSIEURS_POSSIBILITES)
        {
            printf("Bad magician!\n");
        }
        else
        {
            printf("%d\n", carte);
        }
    }

    return 0;
}
