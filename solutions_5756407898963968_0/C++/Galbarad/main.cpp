#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

#define ARRAY_LENGTH 4

bool is_debug = false;

QString getAnswer(QString FirstLine, QString SecondLine) {
    if (is_debug) {
        qDebug() << "start getAnswer " << FirstLine << " , " << SecondLine;
    }
    QStringList Line1 = FirstLine.split(" ");
    QStringList Line2 = SecondLine.split(" ");
    QStringList merge;

    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        for (int j = 0; j < ARRAY_LENGTH; ++j) {
            if (is_debug) {
                qDebug() << "Compare " << Line1.at(i) << " and " << Line2.at(j);
            }
            if (Line1.at(i).compare(Line2.at(j)) == 0) {
                if (is_debug) {
                    qDebug() << "equal";
                }
                merge.append(Line1.at(i));
            }
        }
    }
    if (merge.count() == 0) {
        return "Volunteer cheated!";
    } else if (merge.count() == 1) {
        return merge.at(0);
    } else {
        return "Bad magician!";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList params = QCoreApplication::arguments();
    if (params.count() < 3) {
        return 1;
    }

    QFile file_in(params.at(1)); // this is a name of a file text1.txt sent from main method
    if (!file_in.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return 2;
    }

    QTextStream in(&file_in);

    QFile file_out(params.at(2));
    if (!file_out.open(QIODevice::WriteOnly)) {
        return 3;
    }

    is_debug = params.count() > 3 && params.at(3).compare("debug") == 0;

    QTextStream out(&file_out);
    QString line;
    int Idx = -1;
    int CaseNum = 0;
    int LineNumber = 0;
    int SearchLineNumber = 0;
    int FirstAnswer = 0;
    int SecondAnswer = 0;
    QString FirstLine;
    QString SecondLine;
    bool SearchFirstLine = true;

    while (!in.atEnd()) {
        line = in.readLine();
        if (++Idx == 0 && is_debug) {
            qDebug() << "Input case count " << line;
            continue;
        }
        if (is_debug) {
            qDebug() << "Current index " << Idx;
        }
        if (Idx % 5 == 1) {
            SearchLineNumber = line.toInt();
            SearchFirstLine = Idx % 10 == 1;
            if (SearchFirstLine) {
                FirstAnswer = SearchLineNumber;
                if (is_debug) {
                    qDebug() << "Line with answer 1";
                }
            } else {
                SecondAnswer = SearchLineNumber;
                if (is_debug) {
                    qDebug() << "Line with answer 1";
                }
            }
            continue;
        }
        LineNumber = (Idx - 1) % 5;

        if (is_debug) {
            qDebug() << "Line number " << LineNumber;
        }

        if (SearchLineNumber == LineNumber) {
            if (SearchFirstLine) {
                FirstLine = line;
                if (is_debug) {
                    qDebug() << "Find line 1";
                }
            } else {
                SecondLine = line;
                if (is_debug) {
                    qDebug() << "Find line 2";
                }
            }
        }
        if (!FirstLine.isEmpty() && !SecondLine.isEmpty()) {
            out << "Case #" << ++CaseNum << ": " << getAnswer(FirstLine, SecondLine);
            endl(out);
            FirstAnswer = 0;
            SecondAnswer = 0;
            FirstLine.clear();
            SecondLine.clear();
        }

    }
    return 0;
    //return a.exec();
}
