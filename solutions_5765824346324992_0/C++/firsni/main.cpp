#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include <fstream>
#include<vector>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>
#include <algorithm>

std::vector<string> split(string chaine)
{
    int i=0;
    int j=0;
    vector<string> chainesplit;

    while(j != chaine.size())
    {
        if (chaine[j] == ' ')
            {
                if(chaine[i] == ' ')
                    chainesplit.push_back(chaine.substr(i+1,j-i));
                else
                    chainesplit.push_back(chaine.substr(i,j-i));
                i = j;
            }
        j++;

    }
     if(chaine.size() == 1)
        chainesplit.push_back(chaine.substr(0,1));
    if(i+1 != chaine.size()) chainesplit.push_back(chaine.substr(i+1,j-i));
    return chainesplit;
}


int min_time1(vector<string> ligne)
{
    int sortie = 0;

    for(int j=1;j<ligne.size();j++)
    {
        //cerr<< ligne[j]<<endl;
        sortie += max(atoi(ligne[j-1].c_str()) - atoi(ligne[j].c_str()),0);

    }

    return sortie;
}

int min_time2(vector<string> ligne)
{
    int freq = 0;
    for(int j=1;j<ligne.size();j++)
    {
        freq = max(atoi(ligne[j-1].c_str()) - atoi(ligne[j].c_str()),freq);
    }
    freq = freq;
    int mange = 0;
cerr<< "freq 0 "<<freq<<endl;
    for(int j=0;j<ligne.size()-1;j++)
    {
        mange += min(atoi(ligne[j].c_str()),freq);
        cerr<< mange<<endl;
    }

    return mange;
}


int barber(int N,vector<int> ligne)
{
    vector<int> ligne1(ligne.size(),0);
    int b = -1;

    for(int j=0; j<N;j++)
    {
        vector<int>::iterator a = min_element(ligne1.begin(),ligne1.end());
        int dis = distance(ligne1.begin(),a);

        ligne1[dis] += ligne[dis];

        b = dis + 1;
        if(count(ligne1.begin(),ligne1.end(),*a) == ligne1.size())
        {

            N = N % (j+1);

            j = -1;
        }


    }
    return b;
}


int main()
{
    vector<string> resultat;
    vector<string> vec;
    freopen("C:/Users/Firas/Documents/codejam2/result.out","w",stdout);
    ifstream fichier("C:/Users/Firas/Documents/codejam2/B-small-attempt1.in", ios::in);  // on ouvre le fichier en lecture
    int Ncases = 0;


        if(fichier)  // si l'ouverture a réussi
        {
            string ligne;
            int cpt = 0;
            while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
            {
                    if(cpt == 0)
                        Ncases = atoi(ligne.c_str());
                    else
                        {
                                cerr <<"case "<<cpt <<endl;
                                vector<string> NB = split(ligne);
                                int B = atoi(NB[0].c_str());

                                int N =  atoi(NB[1].c_str());
                                cerr<<"b = " <<B<<" , "<<" n = "<<N<<endl;
                                getline(fichier, ligne);
                                vector<string> minutes = split(ligne);
                                vector<int> ligne5;

                                for(int p=0;p<minutes.size();p++)
                                    ligne5.push_back( atoi(minutes[p].c_str()));
                                int rang = barber(N,ligne5);

                                cout << "case #"<< cpt<<": "<<rang<<endl;
                                //string ss = "Case #:"+cpt + s1 +" " + s2 ;
                                //resultat.push_back(ss);

                        }
                    cpt++;
            }
                fichier.close();  // on ferme le fichier
        }
        else  // sinon
                cerr << "Impossible d'ouvrir le fichier !" << endl;


        //for(int h=0;h<vec.size();h++)
          //      cerr<<"vec size "<<vec[h]<<endl;



        /*ofstream fichier1("C:/Users/Firas/Documents/code jam/dijkstra.out", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

        if(fichier1)
        {
                for(int j=0;j<resultat.size();j++)
                //fichier1 << "Case #" << j+1 <<": "<< resultat[j] <<endl;

                fichier1 <<ss<<endl;
                fichier1.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;*/

    return 0;
}
