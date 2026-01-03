#include <QtTest/QtTest>

#include "domain.hpp"

class DomainTest : public QObject {
    Q_OBJECT
   private slots:
    void test_example_function() { QCOMPARE(example_function(), 42); }
};

QTEST_MAIN(DomainTest)
#include "test_domain.moc"
