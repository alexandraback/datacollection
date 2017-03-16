#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include "qmath.h"

/**

  CODE JAM: ROUND 1B

  Problem 1:


  */

int happiness_global;

void calculate(QList<bool> people, QList<int> not_occupied_index, int happines_level, int N, int R, int C){
    int index, aux_hap;

    if(N == 0){
//        qDebug() << "We already put all of them.";
        if(happiness_global > happines_level){
//            qDebug() << "WE HAVE NEW MAXIMUN" << happines_level;
        }
        happiness_global = qMin(happiness_global,happines_level);
        return;
    }

    N --;


    for(int i = not_occupied_index.size() - 1; i >= 0  ; i --){
        index = not_occupied_index.at(i);
        not_occupied_index.removeAt(i);
        people[index] = true;
        aux_hap = 0;

        //Calculate new happiness.
        if(int(index / C) > 0){
            //We have neighbour up
            if(people.at(index - C)){
                aux_hap ++;
            }
        }

        if(int(index / C) < R - 1 ){
            //We have neighbour down
            if(people.at(index + C)){
                aux_hap ++;
            }
        }

        if(index % C > 0){
            //We have neighbour left
            if(people.at(index -1)){
                aux_hap ++;
            }
        }

        if(index % C < (C -1)){
            //We have neighbour left
            if(people.at(index +1)){
                aux_hap ++;
            }
        }

        calculate(people, not_occupied_index, happines_level + aux_hap, N, R, C);
        people[index] = false;
    }
}

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QFile inputFile("/home/spheris/Downloads/B-small-attempt0(1).in");
    QFile solution_file("/home/spheris/Downloads/solution.txt");


    if(solution_file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&solution_file);

        qDebug()<< "Hola " << inputFile.exists();


        if(inputFile.open(QIODevice::ReadOnly)){

            qDebug()<< "No problem with the files! Start programing!";

            QTextStream in(&inputFile);
            int T = in.readLine().toInt();
            qDebug()<< "caseNumber T:" << T;

            for(int z = 0 ; z< T ; z++){

                QStringList lista_m = in.readLine().split(" ");


                int R = lista_m.at(0).toInt();
                int C = lista_m.at(1).toInt();
                int N = lista_m.at(2).toInt();

//                qDebug()<< "Lista_m " << lista_m;
//                qDebug()<< "R " << R;
//                qDebug()<< "C " << C;


                QList<bool> people;
                QList<int> not_occupied;

                for(int i = 0; i < R*C ; i++){
                    people.append(false);
                    not_occupied.append(i);
                }

                int happiness_level = 0;

                happiness_global = R*C*4;


                if((R>2 || C > 2) && N < (R*C/2)){
                    qDebug() << "Special case, for sure zero";
                    happiness_global = 0;
                }else{
                    calculate(people, not_occupied, happiness_level, N, R, C);
                }

                QString solution ("Case #" + QString::number(z+1) + ": " + QString::number(happiness_global));
                qDebug()<< "solution " << solution;
                stream << solution << endl;
            }

        }else{
            qDebug()<< "Problems opening the problem file";
        }
    }

    solution_file.close();
    inputFile.close();
}
