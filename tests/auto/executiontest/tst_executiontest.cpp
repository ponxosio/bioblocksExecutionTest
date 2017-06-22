#include <QtTest>

// add necessary includes here
#include <bioblocksExecution/bioblocksexecution.h>

#include <utils/units.h>
#include <utils/utilsjson.h>

#include "consolepluginabstractfactory.h"
#include "debugusercommunications.h"

class executionTest : public QObject
{
    Q_OBJECT

public:
    executionTest();
    ~executionTest();

private:
    void copyResourceFile(const QString & resourcePath, QTemporaryFile* file) throw(std::invalid_argument);

private slots:
    void initTestCase();
    void cleanupTestCase();

    void executeProtocolOverMachine();
    void executeProtocol2OverMachine();

};

executionTest::executionTest()
{

}

executionTest::~executionTest()
{

}

void executionTest::executeProtocolOverMachine()
{
    QTemporaryFile* tempFileProtocol = new QTemporaryFile();
    QTemporaryFile* tempFileMachine = new QTemporaryFile();
    if (tempFileProtocol->open() && tempFileMachine->open()) {
        try {
            copyResourceFile(":/protocols/protocols/quemostat_30s.json", tempFileProtocol);
            copyResourceFile(":/machines/machines/turbidostat_test.json", tempFileMachine);

            std::shared_ptr<PluginAbstractFactory> consolePlugins = std::make_shared<ConsolePluginAbstractFactory>();
            std::shared_ptr<DebugUserCommunications> userCom = std::make_shared<DebugUserCommunications>();
            BioblocksExecution execution(consolePlugins, userCom);

            std::string protocolFilePath = tempFileProtocol->fileName().toStdString();
            std::string machineFilePath = tempFileMachine->fileName().toStdString();

            units::Time timeSlice = 10 * units::s;
            execution.executeNewProtocol(protocolFilePath, machineFilePath, timeSlice);

            std::string generated = userCom->getString().c_str();
            qDebug() << "generated:";
            qDebug() << generated.c_str();

            QVERIFY(true);
        } catch (std::exception & e) {
            QFAIL(e.what());
        }
    } else {
        QFAIL("Imposible to create temporary file");
    }
}

void executionTest::executeProtocol2OverMachine() {
    QTemporaryFile* tempFileProtocol = new QTemporaryFile();
    QTemporaryFile* tempFileMachine = new QTemporaryFile();
    if (tempFileProtocol->open() && tempFileMachine->open()) {
        try {
            copyResourceFile(":/protocols/protocols/turbidostat_not_time.json", tempFileProtocol);
            copyResourceFile(":/machines/machines/turbidostat_test.json", tempFileMachine);

            std::shared_ptr<PluginAbstractFactory> consolePlugins = std::make_shared<ConsolePluginAbstractFactory>();
            std::shared_ptr<DebugUserCommunications> userCom = std::make_shared<DebugUserCommunications>();
            BioblocksExecution execution(consolePlugins, userCom);

            std::string protocolFilePath = tempFileProtocol->fileName().toStdString();
            std::string machineFilePath = tempFileMachine->fileName().toStdString();

            units::Time timeSlice = 1 * units::s;
            execution.executeNewProtocol(protocolFilePath, machineFilePath, timeSlice);

            std::string generated = userCom->getString().c_str();
            qDebug() << "generated:";
            qDebug() << generated.c_str();

            QVERIFY(true);
        } catch (std::exception & e) {
            QFAIL(e.what());
        }
    } else {
        QFAIL("Imposible to create temporary file");
    }
}

void executionTest::copyResourceFile(const QString & resourcePath, QTemporaryFile* tempFile) throw(std::invalid_argument) {
    QFile resourceFile(resourcePath);
    if(!resourceFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw(std::invalid_argument("imposible to open" + resourcePath.toStdString()));
    }

    QTextStream out(tempFile);

    QTextStream in(&resourceFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        out << line;
    }
    out.flush();
}

void executionTest::initTestCase() {
    PrologExecutor::createEngine(std::string(QTest::currentAppName()));
}

void executionTest::cleanupTestCase() {
    PrologExecutor::destoryEngine();
}

QTEST_APPLESS_MAIN(executionTest)

#include "tst_executiontest.moc"
