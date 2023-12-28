#include <QtTest/QtTest>
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testHelloWithName() {
        stringstream input;
        stringstream output;
        input << "Ivan";

        hello(input, output);

        QCOMPARE(output.str(), string("hello, Ivan"));
    }

    void testHelloWithEmptyName() {
        stringstream input;
        stringstream output;
        input << "";

        hello(input, output);

        QCOMPARE(output.str(), string("name not entered"));
    }

};

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
