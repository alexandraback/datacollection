#include <QFile>
#include <QTextStream>
#include <QVector>

//Artem Klimov's solution
//soved using Qt Framework


QFile inFile("C:/CodeJam2016/Round1C/A/A-small-attempt1.in");
QFile outFile("C:/CodeJam2016/Round1C/A/output.txt");

int main(int argc, char *argv[])
{
    inFile.open(QFile::ReadOnly);
    outFile.open(QFile::WriteOnly);
    QTextStream inData(&inFile);
    QTextStream outData(&outFile);

    int T;
    inData >> T;
    int partie[1000];

    for(int t=0; t<T; t++)
    {
        int N;
        inData >> N;

        int totalSenators = 0;
        for(int i=0; i<N; i++)
        {
            inData >> partie[i];
            totalSenators += partie[i];
        }

        outData << QString("Case #%1:").arg(t+1);

        while(totalSenators>2)
        {
            int max = 0;
            int maxIndex = 0;

            for(int i=0; i<N; i++)
            {
                if(partie[i]>max)
                {
                    max = partie[i];
                    maxIndex = i;
                }
            }

            outData << QString(" %1").arg(QChar(maxIndex+'A'));
            partie[maxIndex]--;
            totalSenators--;

            if(totalSenators>2)
            {
                max = 0;
                maxIndex = 0;
                for(int i=0; i<N; i++)
                {
                    if(partie[i]>max)
                    {
                        max = partie[i];
                        maxIndex = i;
                    }
                }

                outData << QString("%1").arg(QChar(maxIndex+'A'));
                partie[maxIndex]--;
                totalSenators--;
            }
        }
        outData << QString(" ");

        //print last two
        for(int i=0; i<N; i++)
        {
            if(partie[i]>0) outData << QString("%1").arg(QChar(i+'A'));
        }
        outData << "\r\n";
    }
}
