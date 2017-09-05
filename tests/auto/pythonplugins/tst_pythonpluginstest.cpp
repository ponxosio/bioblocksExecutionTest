/*
 * PLEASE ALWAYS IMPORT PYTHON PLUGINS THE FIRST IN A PROJECT, USING MSVC boost/python/operators.hpp COLIDES WITH <cisco646>
 * http://boost.2283326.n4.nabble.com/boost-python-incorrect-use-of-keywords-and-or-etc-td4630496.html
 */
#include <pythonPlugins/actuators/pythonpluginabstractfactory.h>
#include <pythonPlugins/environment/PythonEnvironment.h>

#include <QString>
#include <QtTest>

#include <bioblocksExecution/bioblocksexecution.h>

#include <communications/CommandSender.h>
#include <communications/FileSender.h>
#include <communications/SerialSender.h>

#include <utils/units.h>
#include <utils/utilsjson.h>

#include "debugusercommunications.h"

class PythonpluginsTest : public QObject
{
    Q_OBJECT

public:
    PythonpluginsTest();

private:
    void copyResourceFile(const QString & resourcePath, QTemporaryFile* file) throw(std::invalid_argument);

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    void testCase1();
    void testCase2();
    void EVOPROG_no_cleaning();

    void simulateTime();
};

PythonpluginsTest::PythonpluginsTest()
{
}

void PythonpluginsTest::testCase1()
{
    QTemporaryFile* tempFileProtocol = new QTemporaryFile();
    QTemporaryFile* tempFileMachine = new QTemporaryFile();

    QTemporaryFile* output = new QTemporaryFile();
    QTemporaryFile* data = new QTemporaryFile();

    if (tempFileProtocol->open() &&
            tempFileMachine->open() &&
            output->open() &&
            data->open())
    {
        std::string outFile = output->fileName().toStdString();
        std::string dataFile = data->fileName().toStdString();
        std::shared_ptr<CommandSender> command = std::make_shared<FileSender>(outFile, dataFile);

        try {
            command->connect();

            std::string pluginFolderPath = "X:/bioblocksExecution/bioblocksExecutionTest/tests/auto/pythonplugins";
            PluginFileLoader::setPluginDir(pluginFolderPath);

            PythonEnvironment::GetInstance()->initEnvironment("X:/pluginScripts/interfacePlugins");

            std::shared_ptr<PythonPluginAbstractFactory> pythonPlugins = std::make_shared<PythonPluginAbstractFactory>(command);
            std::shared_ptr<DebugUserCommunications> userCom = std::make_shared<DebugUserCommunications>();
            BioblocksExecution execution(pythonPlugins, userCom);

            copyResourceFile(":/protocols/protocols/turbidostat_not_time.json", tempFileProtocol);
            copyResourceFile(":/machines/machines/turbidostat_test.json", tempFileMachine);

            std::string protocolFilePath = tempFileProtocol->fileName().toStdString();
            std::string machineFilePath = tempFileMachine->fileName().toStdString();
            units::Time timeSlice = 1 * units::s;

            execution.executeNewProtocol(protocolFilePath, machineFilePath, timeSlice);

            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QVERIFY(true);
        } catch (std::exception & e) {
            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QFAIL(e.what());
        }
    } else {
        QFAIL("Imposible to create temporary file");
    }
}

void PythonpluginsTest::testCase2()
{
    QTemporaryFile* tempFileProtocol = new QTemporaryFile();
    QTemporaryFile* tempFileMachine = new QTemporaryFile();

    QTemporaryFile* output = new QTemporaryFile();
    QTemporaryFile* data = new QTemporaryFile();

    if (tempFileProtocol->open() &&
            tempFileMachine->open() &&
            output->open() &&
            data->open())
    {
        std::string outFile = output->fileName().toStdString();
        std::string dataFile = data->fileName().toStdString();
        std::shared_ptr<CommandSender> command = std::make_shared<FileSender>(outFile, dataFile);

        try {
            command->connect();

            std::string pluginFolderPath = "X:/bioblocksExecution/bioblocksExecutionTest/tests/auto/pythonplugins";
            PluginFileLoader::setPluginDir(pluginFolderPath);

            PythonEnvironment::GetInstance()->initEnvironment("X:/pluginScripts/interfacePlugins");

            std::shared_ptr<PythonPluginAbstractFactory> pythonPlugins = std::make_shared<PythonPluginAbstractFactory>(command);
            std::shared_ptr<DebugUserCommunications> userCom = std::make_shared<DebugUserCommunications>();
            BioblocksExecution execution(pythonPlugins, userCom);

            copyResourceFile(":/protocols/protocols/turbidostat2.json", tempFileProtocol);
            copyResourceFile(":/machines/machines/turbidostat_test.json", tempFileMachine);

            std::string protocolFilePath = tempFileProtocol->fileName().toStdString();
            std::string machineFilePath = tempFileMachine->fileName().toStdString();
            units::Time timeSlice = 1 * units::s;

            execution.executeNewProtocol(protocolFilePath, machineFilePath, timeSlice);

            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QVERIFY(true);
        } catch (std::exception & e) {
            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QFAIL(e.what());
        }
    } else {
        QFAIL("Imposible to create temporary file");
    }
}

void PythonpluginsTest::EVOPROG_no_cleaning() {
    QTemporaryFile* tempFileProtocol = new QTemporaryFile();
    QTemporaryFile* tempFileMachine = new QTemporaryFile();

    QTemporaryFile* output = new QTemporaryFile();
    QTemporaryFile* data = new QTemporaryFile();

    if (tempFileProtocol->open() &&
            tempFileMachine->open() &&
            output->open() &&
            data->open())
    {
        std::string outFile = output->fileName().toStdString();
        std::string dataFile = data->fileName().toStdString();
        std::shared_ptr<CommandSender> command = std::make_shared<FileSender>(outFile, dataFile);

        try {
            command->connect();

            std::string pluginFolderPath = "X:/bioblocksExecution/bioblocksExecutionTest/tests/auto/pythonplugins";
            PluginFileLoader::setPluginDir(pluginFolderPath);

            PythonEnvironment::GetInstance()->initEnvironment("X:/pluginScripts/interfacePlugins");

            std::shared_ptr<PythonPluginAbstractFactory> pythonPlugins = std::make_shared<PythonPluginAbstractFactory>(command);
            std::shared_ptr<DebugUserCommunications> userCom = std::make_shared<DebugUserCommunications>();
            BioblocksExecution execution(pythonPlugins, userCom);

            copyResourceFile(":/protocols/protocols/quemostat_30s.json", tempFileProtocol);
            copyResourceFile(":/machines/machines/EVOPROG_NO_CLEANING_V2.json", tempFileMachine);

            std::string protocolFilePath = tempFileProtocol->fileName().toStdString();
            std::string machineFilePath = tempFileMachine->fileName().toStdString();
            units::Time timeSlice = 1 * units::s;

            execution.executeNewProtocol(protocolFilePath, machineFilePath, timeSlice);

            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QVERIFY(true);
        } catch (std::exception & e) {
            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QFAIL(e.what());
        }
    } else {
        QFAIL("Imposible to create temporary file");
    }
}

void PythonpluginsTest::simulateTime() {
    QTemporaryFile* tempFileProtocol = new QTemporaryFile();
    QTemporaryFile* tempFileMachine = new QTemporaryFile();

    QTemporaryFile* output = new QTemporaryFile();
    QTemporaryFile* data = new QTemporaryFile();

    if (tempFileProtocol->open() &&
            tempFileMachine->open() &&
            output->open() &&
            data->open())
    {
        std::string outFile = output->fileName().toStdString();
        std::string dataFile = data->fileName().toStdString();
        std::shared_ptr<TimeStampSimulator> timestampSimulator = std::make_shared<TimeStampSimulator>();
        std::shared_ptr<CommandSender> command = std::make_shared<FileSender>(outFile, dataFile, timestampSimulator);

        try {
            command->connect();

            std::string pluginFolderPath = "X:/bioblocksExecution/bioblocksExecutionTest/tests/auto/pythonplugins";
            PluginFileLoader::setPluginDir(pluginFolderPath);

            PythonEnvironment::GetInstance()->initEnvironment("X:/pluginScripts/interfacePlugins");

            std::shared_ptr<PythonPluginAbstractFactory> pythonPlugins = std::make_shared<PythonPluginAbstractFactory>(command);
            std::shared_ptr<DebugUserCommunications> userCom = std::make_shared<DebugUserCommunications>();
            BioblocksExecution execution(pythonPlugins, userCom);

            copyResourceFile(":/protocols/protocols/quemostat_30s.json", tempFileProtocol);
            copyResourceFile(":/machines/machines/EVOPROG_NO_CLEANING_V2.json", tempFileMachine);

            std::string protocolFilePath = tempFileProtocol->fileName().toStdString();
            std::string machineFilePath = tempFileMachine->fileName().toStdString();
            units::Time timeSlice = 1 * units::s;

            execution.executeNewProtocolSimulateTime(protocolFilePath, machineFilePath, timeSlice, timestampSimulator);

            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QVERIFY(true);
        } catch (std::exception & e) {
            PythonEnvironment::GetInstance()->finishEnvironment();
            command->disconnect();

            QFAIL(e.what());
        }
    } else {
        QFAIL("Imposible to create temporary file");
    }
}

void PythonpluginsTest::copyResourceFile(const QString & resourcePath, QTemporaryFile* tempFile) throw(std::invalid_argument) {
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

void PythonpluginsTest::initTestCase() {
    PrologExecutor::createEngine(std::string(QTest::currentAppName()));
}

void PythonpluginsTest::cleanupTestCase() {
    PrologExecutor::destoryEngine();
}

QTEST_APPLESS_MAIN(PythonpluginsTest)

#include "tst_pythonpluginstest.moc"
