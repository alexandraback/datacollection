// Project: Google Code Jam 2014: Magic Trick
// Author:  Kévin Moisy-Mabille
// Date:    2014/04/12

#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char ** argv){
    if (argc != 2)
        cout << "usage: ./MagicTrick input.txt" << endl;

    ifstream fichier(argv[1], ios::in);
    if(fichier) {
        int T;
        fichier >> T;
        for (int i=1; i<=T; i++){
            int l1[4], l2[4], garbage, ligne, sol, nbsol=0;
            fichier >> ligne;
            for (int j=0; j<(ligne-1)*4; j++)
                fichier >> garbage;
            fichier >> l1[0] >> l1[1] >> l1[2] >> l1[3];
            for (int j=0; j<(4-ligne)*4; j++)
                fichier >> garbage;
            fichier >> ligne;
            for (int j=0; j<(ligne-1)*4; j++)
                fichier >> garbage;
            fichier >> l2[0] >> l2[1] >> l2[2] >> l2[3];
            for (int j=0; j<(4-ligne)*4; j++)
                fichier >> garbage;
            for (int j=0; j<4; j++)
                for (int k=0; k<4; k++)
                    if (l1[j] == l2[k]){
                        nbsol++;
                        sol = l1[j];
                    }
            if (nbsol == 1)
                cout << "Case #" << i << ": " << sol << endl;
            else if (nbsol == 0)
                cout << "Case #" << i << ": Volunteer cheated!" << endl;
            else
                cout << "Case #" << i << ": Bad magician!" << endl;
        }
        fichier.close();
    } else 
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}

