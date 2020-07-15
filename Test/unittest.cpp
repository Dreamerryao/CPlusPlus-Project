#include <QtTest/QtTest>
#include "testModels/arrayviewmodel.h"
#include "testModels/treeviewmodel.h"
#define TESTSIZE 100
class UnitTest: public QObject
{
    Q_OBJECT
private slots:
    void testArrayModel();
    void testArrayViewModel();

    void testTreeModel();
    void testTreeViewModel();
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

    //heap
    model->getArrayc()->type=1;
    model->getArrayc()->InitArrayc();//array[0]=20,array[1]=100
    //add
    model->add(11);//array[2] replace arrar[0],swap 11 and 20
    QCOMPARE(model->getArrayc()->getSize(),3);
    QCOMPARE(model->getArrayc()->getNumIndex(0),11);
    //deletemin
    for(int i=0;i<3;i++){
         QCOMPARE(model->deq(),true);
    }
    QCOMPARE(model->deq(),false);
}

void UnitTest::testArrayViewModel(){
     std::shared_ptr<ArrayModel> model = std::make_shared<ArrayModel>();
     std::shared_ptr<ArrayViewModel> viewmodel = std::make_shared<ArrayViewModel>();
     viewmodel->setArrayModel(model);
     //new
     viewmodel->_ArrayModel->Anew(TESTSIZE);
     QCOMPARE(viewmodel->_ArrayModel->getArrayc()->getSize(),TESTSIZE);

     //add
     viewmodel->_ArrayModel->add(11);
     QCOMPARE(viewmodel->_ArrayModel->getArrayc()->getSize(),TESTSIZE+1);
     QCOMPARE(viewmodel->_ArrayModel->getArrayc()->getNumIndex(model->getArrayc()->getSize()-1),11);

     //delete
     QCOMPARE(viewmodel->_ArrayModel->del(11),true);
     QCOMPARE(viewmodel->_ArrayModel->del(1),false);

     //pop
     for(int i=0;i<TESTSIZE;i++){
         QCOMPARE(viewmodel->_ArrayModel->pop(),true);
     }
     QCOMPARE(viewmodel->_ArrayModel->pop(),false);

     //replace
     viewmodel->_ArrayModel->Anew(TESTSIZE/2);
     QCOMPARE(viewmodel->_ArrayModel->replace(1,5),true);
//     QCOMPARE(viewmodel->_ArrayModel->replace(TESTSIZE/2+1,5),false);
     QCOMPARE(viewmodel->_ArrayModel->getArrayc()->getNumIndex(1),5);

     //deque
     for(int i=0;i<TESTSIZE/2;i++){
         QCOMPARE( viewmodel->_ArrayModel->deq(),true);
     }
     QCOMPARE( viewmodel->_ArrayModel->deq(),false);

     //heap
     viewmodel->_ArrayModel->getArrayc()->type=1;
     viewmodel->_ArrayModel->getArrayc()->InitArrayc();
     //add
     viewmodel->_ArrayModel->add(11);
     QCOMPARE(viewmodel->_ArrayModel->getArrayc()->getSize(),3);
     QCOMPARE(viewmodel->_ArrayModel->getArrayc()->getNumIndex(0),11);
     //deletemin
     for(int i=0;i<3;i++){
          QCOMPARE(viewmodel->_ArrayModel->deq(),true);
     }
     QCOMPARE(viewmodel->_ArrayModel->deq(),false);

}


void UnitTest::testTreeModel(){
   std::shared_ptr<TreeModel> Tmodel = std::make_shared<TreeModel>();
   //BST
   Tmodel->getTree()->type = 7;
   Tmodel->getTree()->InitialTree();

   //insert
   Tmodel->ins(7);
   QCOMPARE(Tmodel->getTree()->isTreeNull(),false);
   node * root  = Tmodel->getTree()->getTree();
   QCOMPARE(root->value,6);
   QCOMPARE(root->right->value,9);
   QCOMPARE(root->right->left->value,7);

   //delete
   QCOMPARE(Tmodel->del(9),true);
   root  = Tmodel->getTree()->getTree();
    QCOMPARE(root->right->value,7);
   QCOMPARE(Tmodel->del(9),false);

   //AVL
   Tmodel->getTree()->type = 8;
   Tmodel->getTree()->InitialTree();

   //insert
   root  = Tmodel->getTree()->getTree();
   QCOMPARE(root->right->value,9);
   Tmodel->ins(7);
   Tmodel->ins(8);
   QCOMPARE(Tmodel->getTree()->isTreeNull(),false);
   QCOMPARE(root->right->value,8);//do rotation

   //delete
   QCOMPARE(Tmodel->del(6),true);
   root  = Tmodel->getTree()->getTree();
   QCOMPARE(root->value,7);

   //red black tree
   Tmodel->getTree()->type = 9;
   Tmodel->getTree()->InitialTree();

   //insert
   Tmodel->ins(12);
   root  = Tmodel->getTree()->getTree();
   QCOMPARE(root->color,0);//color:0-black 1-red
   QCOMPARE(root->left->color,0);//after insert 12,right and left child of root change from red to black
   QCOMPARE(root->right->color,0);

   //delete
   QCOMPARE(Tmodel->del(6),true);
   root  = Tmodel->getTree()->getTree();
   QCOMPARE(root->value,9);
   QCOMPARE(Tmodel->del(12),true);
   root  = Tmodel->getTree()->getTree();
   QCOMPARE(root->left->color,1);//after delete two children, root has only one child,so it must be red

}


void UnitTest::testTreeViewModel(){
    std::shared_ptr<TreeModel> Tmodel = std::make_shared<TreeModel>();
    std::shared_ptr<TreeViewModel> Tviewmodel = std::make_shared<TreeViewModel>();
    Tviewmodel->setTreeModel(Tmodel);

    //BST
    Tviewmodel->getTree()->type = 7;
    Tviewmodel->getTree()->InitialTree();

    //insert
    Tviewmodel->_TreeModel->ins(7);
    QCOMPARE(Tviewmodel->getTree()->isTreeNull(),false);
    node * root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->value,6);
    QCOMPARE(root->right->value,9);
    QCOMPARE(root->right->left->value,7);

    //delete
    QCOMPARE(Tviewmodel->_TreeModel->del(9),true);
    root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->right->value,7);
    QCOMPARE(Tviewmodel->_TreeModel->del(9),false);

    //AVL
    Tviewmodel->getTree()->type = 8;
    Tviewmodel->getTree()->InitialTree();

    //insert
    root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->right->value,9);
    Tviewmodel->_TreeModel->ins(7);
    Tviewmodel->_TreeModel->ins(8);
    QCOMPARE(Tviewmodel->getTree()->isTreeNull(),false);
    QCOMPARE(root->right->value,8);//do rotation

    //delete
    QCOMPARE(Tviewmodel->_TreeModel->del(6),true);
    root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->value,7);

    //red black tree
    Tviewmodel->getTree()->type = 9;
    Tviewmodel->getTree()->InitialTree();

    //insert
    Tviewmodel->_TreeModel->ins(12);
    root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->color,0);//color:0-black 1-red
    QCOMPARE(root->left->color,0);//after insert 12,right and left child of root change from red to black
    QCOMPARE(root->right->color,0);

    //delete
    QCOMPARE(Tviewmodel->_TreeModel->del(6),true);
    root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->value,9);
    QCOMPARE(Tviewmodel->_TreeModel->del(12),true);
    root  = Tviewmodel->getTree()->getTree();
    QCOMPARE(root->left->color,1);//after delete two children, root has only one child,so it must be red

}
QTEST_MAIN(UnitTest)
#include "unittest.moc"
