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


int return_guests(string chaine)
{

    vector<string> ch_split = split(chaine);
    vector<int> shyness;
    string a = ch_split[0];
    int guests_to_invite = 0;
    int guest_count = 0;
    int Smax = atoi(ch_split[0].c_str());
    for(int h=0;h<ch_split[1].size();h++)
        {
            string aa = ch_split[1].substr(h,1);
            shyness.push_back(atoi(aa.c_str()));
            int plus = 0;
            if(h > guest_count)
                {
                    guests_to_invite += h - guest_count ;
                    plus =  h - guest_count;
                }
            guest_count += (shyness[h] + plus);

        }
    // logic


        return guests_to_invite;
}

int return_minutes(string chaine)
{

    vector<string> ch_split = split(chaine);
    vector<int> plates;
    int min = 0;
    int max = 0;
    cout<< "chaine plates " <<chaine<<endl;
    int coord_max = 0;
    int Max_initial = 0;
    for(int h=0;h<ch_split.size();h++)
        {
            plates.push_back(atoi(ch_split[h].c_str()));

            if(max< plates[h]) {max = plates[h]; coord_max = h;}
        }
    //logic
    int cpt = 0;

    Max_initial = max;
    while(max / 2 > 1)
    {
        cpt++;
        if(max % 2 == 1)
        {
            plates.push_back(max/2);
            max = max/2 + 1;

        }
        else
        {
            plates.push_back(max/2);
            max = max/2;
        }
        plates[coord_max] = max;


        max = 0;

        for(int h=0;h<plates.size();h++)
        {
            if(max< plates[h]) {max = plates[h]; coord_max = h;}
        }
        //cerr<<" max partiel= "<<max<<endl;
        if( max + cpt< Max_initial)
            Max_initial = max + cpt;

    }
        cerr<<" max = "<<Max_initial<<endl;
        return Max_initial;
}

string multiply(string ch)
{
    string chaine;
    if(ch == "ij")
                chaine = "k" ;
    else if(ch == "ji")
                chaine = "-k" ;
    else if(ch == "ik")
                chaine = "-j" ;
    else if(ch == "ki")
              chaine = "j" ;
    else if(ch == "jk")
                chaine = "i" ;
    else if(ch == "kj")
               chaine = "-i" ;
    else if(ch == "-1")
            chaine = "-1";
    else if(ch == "ii")
            chaine = "-1";
    else if(ch == "kk")
            chaine = "-1";
    else if(ch == "jj")
            chaine = "-1";

            return chaine;
}

bool calcul_multiply(string chaine)
{
    int nb_moins = 0;
    int cpt  = 0;
    cerr<<"chaine  = "<<chaine<<endl;
    bool continu = chaine.size() > 2 ;
    while(continu)
          {

              string res = multiply(chaine.substr(0,2));

              cerr<<"res  = "<<res<<endl;
              if(res == "-1" && chaine.size()>2)
                {
                        nb_moins++;
                        chaine = chaine.substr(2,chaine.size()-2);

                }
                else if(res == "-1")
                {
                    chaine = res ;
                }
              else if(res[0] == '-')
              {
                  nb_moins++;
                  chaine = chaine.substr(1,chaine.size()-1);

              }
              else
                {
                    chaine = chaine.substr(2,chaine.size()-2);
                    chaine = res + chaine;
                }
                cerr<<"ch = "<<chaine<<endl;
            cpt++;
            if(chaine == "-1" || chaine.size()<2 ) continu = false;
          }
          bool ok = false;
          if(((chaine == "-1" ) && nb_moins % 2 == 0) || (chaine == "1" && nb_moins % 2 == 1))
             ok = true;

             return ok;
}


bool find_i(string chaine)
{
    int nb_moins = 0;
    int cpt  = 0;
     //cerr<<"chaine = "<<chaine<<endl;
    bool continu = chaine.size() > 2 ;
    //cout<<"recherche i"<<endl;
    while(chaine.size()>1 && (chaine[0] != 'i' && chaine.substr(0,2) != "-i"))
          {
              string res = multiply(chaine.substr(0,2));
              //cerr<<"res  = "<<res<<endl;
              if(res == "-1" && chaine.size()>2)
                {
                        nb_moins++;
                        chaine = chaine.substr(2,chaine.size()-2);

                }
              else if(res == "-1")
                {
                    chaine = "" ;
                    nb_moins++;
                }
                else if(res[0] == '-')
              {
                  nb_moins++;
                  chaine = chaine.substr(2,chaine.size()-2);
                  chaine = res.substr(1,1) + chaine;
              }
              else
              {
                 chaine = chaine.substr(2,chaine.size()-2);
                 chaine = res + chaine;
              }
                //cerr<<"ch = "<<chaine<<endl;
            cpt++;


          }
          bool ok = false;
          if(chaine.size()>0 && chaine[0] == 'i' )
           {
               ok = true;
               chaine = chaine.substr(1,chaine.size()-1);
               //cerr<<"j'ai trouvé i "<<chaine<< endl;
            }
           else if(chaine.size()>1 && chaine[0] == '-i' )
            {
                    ok = true;
                    nb_moins++;
                 chaine = chaine.substr(2,chaine.size()-2);
                 //cerr<<"j'ai trouvé -i "<<chaine<< endl;
            }
            else
            ok = false;


        if(ok)
        {
            //cerr<<"recherche de j"<<endl;
            //cerr<<"ch1 "<<chaine<<endl;
            ok = false;
            //recherche de j
        while(chaine.size()>1 && (chaine[0] != 'j' && chaine.substr(0,2) != "-j"))
          {
              string res = multiply(chaine.substr(0,2));
              //cerr<<"res  = "<<res<<endl;
              if(res == "-1" && chaine.size()>2)
                {
                        nb_moins++;
                        chaine = chaine.substr(2,chaine.size()-2);

                }
              else if(res == "-1")
                {
                    chaine = "" ;
                    nb_moins++;
                }
              else if(res[0] == '-')
              {
                  nb_moins++;
                  chaine = chaine.substr(2,chaine.size()-2);
                  chaine = res.substr(1,1) + chaine;
              }
              else
              {
                 chaine = chaine.substr(2,chaine.size()-2);
                 chaine = res + chaine;
              }
                //cerr<<"ch = "<<chaine<<endl;
            cpt++;


          }
          if(chaine.size()>0 && chaine[0] == 'j' )
            {
               ok = true;
               //cout<<"je trouve j "<< chaine<<endl;
               chaine = chaine.substr(1,chaine.size()-1);
            }
           else if(chaine.size()>1 && chaine[0] == '-j' )
            {
                ok = true;
                //cout<<"je trouve -j "<< chaine<<endl;
                nb_moins++;
                chaine = chaine.substr(2,chaine.size()-2);
            }
            else
            ok = false;
        }

        if(ok)
        {
          //cerr<<"recherche de k"<<endl;
          //cerr<<"ch "<<chaine<<endl;
          ok = false;
          while(chaine.size()>1 && (chaine[0] != 'k' && chaine.substr(0,2) != "-k"))
          {
              string res = multiply(chaine.substr(0,2));
              //cerr<<"res  = "<<res<<endl;
              if(res == "-1" && chaine.size()>2)
                {
                  nb_moins++;
                  chaine = chaine.substr(2,chaine.size()-2);

                }
              else if(res == "-1")
                {
                    chaine = "" ;
                    nb_moins++;
                }
              else if(res[0] == '-')
              {
                  nb_moins++;
                  chaine = chaine.substr(2,chaine.size()-2);
                  chaine = res.substr(1,1) + chaine;
              }
              else
              {
                 chaine = chaine.substr(2,chaine.size()-2);
                 chaine = res + chaine;
              }
                //cerr<<"ch = "<<chaine<<endl;
            cpt++;
          }

          if(chaine.size()>0 && chaine[0] == 'k' )
            {
               ok = true;
               chaine = chaine.substr(1,chaine.size()-1);
            }
           else if(chaine.size()>1 && chaine[0] == '-k' )
            {
                ok = true;
                nb_moins++;
                chaine = chaine.substr(2,chaine.size()-2);
            }
            else
            ok = false;


            //cout<<"recherche finale "<<endl;
            //cerr<<"ch = "<<chaine<<endl;
            if(ok && chaine.size()>0)
            {
                ok = false;
                while(chaine.size()>1)
                    {
                      string res = multiply(chaine.substr(0,2));
                      //cerr<<"res  = "<<res<<endl;
                      if(res == "-1" && chaine.size()>2)
                        {
                          nb_moins++;
                          chaine = chaine.substr(2,chaine.size()-2);

                        }
                      else if(res == "-1")
                        {
                            chaine = "" ;
                            nb_moins++;
                        }
                      else if(res[0] == '-')
                      {
                          nb_moins++;
                          chaine = chaine.substr(2,chaine.size()-2);
                          chaine = res.substr(1,1) + chaine;
                      }
                      else
                      {
                         chaine = chaine.substr(2,chaine.size()-2);
                         chaine = res + chaine;
                      }
                    }
            }
            if(chaine == "1" || chaine == "")
                ok = true;

        }

            ok = ok && (nb_moins % 2 == 0);
             return ok;


}

string dijkstra(string chaine,int L,int X)
{
    string element = chaine;
    bool same = true;
    int cpt = 0;
    while(cpt <chaine.size()-1 && same)
    {
        if(chaine[cpt] != chaine[cpt+1]) same = false;
        cpt++;
    }
    if (chaine.size()>1 && !same)
    {


    for(int h=1;h<X;h++)
        {
            chaine += element;
        }
    }

        return chaine;
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

int main()
{
    vector<string> resultat;
    vector<string> vec;
    freopen("C:/Users/Firas/Documents/codejam2/result.out","w",stdout);
    ifstream fichier("C:/Users/Firas/Documents/codejam2/A-small-attempt1.in", ios::in);  // on ouvre le fichier en lecture
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


                                int N = atoi(ligne.c_str());
                                getline(fichier, ligne);
                                vector<string> Mushrooms = split(ligne);
                                int s1 = min_time1(Mushrooms);
                                int s2 = min_time2(Mushrooms);
                                cout << "case #"<< cpt<<": "<<s1 <<" "<<s2<<endl;
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
