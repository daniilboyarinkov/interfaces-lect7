#include <QtTest/QtTest>
#include "../src/levelsfacade.h"

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testGetLevelList() {
        LevelsFacade levelsFacade;
        QString directoryPath = "C:/lect6/levels/";
        QStringList levelList = levelsFacade.getLevelList(directoryPath);

        QVERIFY(!levelList.isEmpty());
    }

    void testLoadLevel() {
        LevelsFacade levelsFacade;
        QString levelFileName = "C:/lect6/levels/level1.csv";
        QStringList bricksData = levelsFacade.loadLevel(levelFileName);

        QVERIFY(!bricksData.isEmpty());
    }
};

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
