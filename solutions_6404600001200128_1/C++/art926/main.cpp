#include <QFile>
#include <QTextStream>
#include <QSet>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam/Round1/A/A-large.in");
QFile outFile("C:/CodeJam/Round1/A/output.txt");

int indexOfMaxValue(QList<qint64> *list)
{
    int index = 0;
    qint64 max = list->value(0);
    for(int i=1; i<list->count(); i++)
    {
        if(list->value(i) > max)
        {
            max = list->value(i);
            index = i;
        }
    }

    return index;
}

int main(int argc, char *argv[])
{
    inFile.open(QFile::ReadOnly);
    outFile.open(QFile::WriteOnly);
    QTextStream inData(&inFile);
    QTextStream outData(&outFile);

    int T;
    inData >> T;

    for(int t=0; t<T; t++)
    {
        QList<qint64> mushrooms;  //array of mushrooms in time
        QList<qint64> mushroomsDiff;  //array of differences
        int N;

        inData >> N;
        for(int i=0; i<N; i++)
        {
            qint64 d;  //number of mushrooms in this moment
            inData >> d;
            mushrooms.append(d);
        }

        for(int i=0; i<(N-1); i++)
        {
            mushroomsDiff.append( mushrooms[i] - mushrooms[i+1] );
        }

        qint64 answer1 = 0;
        for(int i=0; i<mushroomsDiff.count(); i++)
        {
            if(mushroomsDiff[i]>0)  answer1 += mushroomsDiff[i];
        }

        qint64 minRate = mushroomsDiff[ indexOfMaxValue(&mushroomsDiff) ];
        if(minRate<0) minRate = 0;
        qint64 answer2 = 0;
        for(int i=0; i<(mushrooms.count()-1); i++)
        {
            answer2 += qMin(minRate, mushrooms[i]);
        }

        outData << QString("Case #%1: %2 %3\r\n").arg(t+1).arg(answer1).arg(answer2);
    }
}

















