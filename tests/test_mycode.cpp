#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT

private slots:
void testEmptySubstring();
void testSingleMatch();
};

void TestMyCode::testEmptySubstring()
{
    string str = "string";
    string sub = "";
    QVector<int> result = boyerMooreSearch(str, sub);
    QCOMPARE(result[0], 0);
}

void TestMyCode::testSingleMatch()
{
    string str = "string";
    string sub = "ri";
    QVector<int> result = boyerMooreSearch(str, sub);
    QCOMPARE(result[0], 2);
}


};

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
