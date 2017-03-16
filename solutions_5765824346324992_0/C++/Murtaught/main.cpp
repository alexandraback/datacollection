#include "case.hpp"
#include "casemanager.hpp"
#include "reader.hpp"
#include "writer.hpp"
#include "dispatcher.hpp"

#include <QCoreApplication>
#include <QMetaObject>
#include <QDebug>
#include <QDateTime>
#include <QThreadPool>

QDateTime start_time;
QDateTime finish_time;

void print_time_info()
{
    finish_time = QDateTime::currentDateTime();

    qDebug() << "Start time:"        << start_time.toString()
             << "\nFinish time:"     << finish_time.toString()
             << "\nExecution time: " << start_time.msecsTo(finish_time) << "ms";
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QThreadPool::globalInstance()->setMaxThreadCount(8);

    Reader     reader("input.txt");
    Writer     writer("output.txt");
    Dispatcher dispatcher;

    CaseManager *manager = CaseManager::instance();

    QObject::connect(&reader, &Reader::readCase, &dispatcher, &Dispatcher::dispatchCase);
    QObject::connect(manager, &CaseManager::allCasesAreSolved, &writer, &Writer::writeAllCases);

    QObject::connect(&writer, &Writer::wroteAllCases, &app, &QCoreApplication::quit);
    //QObject::connect(&app, &QCoreApplication::aboutToQuit, manager, &CaseManager::releasePool);

    start_time = QDateTime::currentDateTime();
    QObject::connect(&app, &QCoreApplication::aboutToQuit, &print_time_info);

    QMetaObject::invokeMethod(&reader, "readInput", Qt::QueuedConnection);
    return app.exec();
}
