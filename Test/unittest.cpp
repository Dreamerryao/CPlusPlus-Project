#include <QtTest/QtTest>
#include "arraymodel.h"
#define TESTSIZE 100
class UnitTest: public QObject
{
    Q_OBJECT
private slots:
    void testArrayModel();
};

void UnitTest::testArrayModel(){
     std::shared_ptr<ArrayModel> model = std::make_shared<ArrayModel>();
     //new
     model->Anew(TESTSIZE);
     QCOMPARE(model->getArrayc()->getSize(),TESTSIZE);

     //add
     model->add(11);
     QCOMPARE(model->getArrayc()->getSize(),TESTSIZE+1);
     QCOMPARE(model->getArrayc()->getNumIndex(model->getArrayc()->getSize()-1),11);

     //delete
     QCOMPARE(model->del(11),true);
     QCOMPARE(model->del(1),false);

     //pop
     for(int i=0;i<TESTSIZE;i++){
         QCOMPARE(model->pop(),true);
     }
     QCOMPARE(model->pop(),false);

     //replace
     model->Anew(TESTSIZE/2);
     QCOMPARE(model->replace(1,5),true);
     QCOMPARE(model->getArrayc()->getNumIndex(1),5);

     //deque
     for(int i=0;i<TESTSIZE/2;i++){
         QCOMPARE( model->deq(),true);
     }
     QCOMPARE( model->deq(),false);


}

QTEST_MAIN(UnitTest)
#include "unittest.moc"
