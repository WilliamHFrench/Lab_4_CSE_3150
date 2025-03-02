#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
/*
  https://hackingcpp.com/cpp/tools/testing_frameworks.html
 */

#include <iostream>
#include "./include/doctest.h"
#include "LinkedList.h"

using namespace std;



TEST_CASE("Linked List Insertion Edge Cases") {

  SUBCASE("empty and almost-empty linked lists") {
  
    LinkedList ll_0, ll_start, ll_end;

    ll_start.insertAtBeginning(5);
    ll_end.insertAtEnd(-55);

    CHECK( 0 == ll_0.getSize() );
    CHECK( 1 == ll_start.getSize() );
    CHECK( 1 == ll_end.getSize() );
               
  };

  SUBCASE("insertion and deletion") {
    

    LinkedList ll_0, ll_1;

   
    ll_0.insertAtBeginning(2);
    ll_0.insertAtEnd(3);
    ll_0.insertAtBeginning(1);

    CHECK( 1 == ll_0.getValueAt( 1 ) );
    CHECK( 2 == ll_0.getValueAt( 2 ) );
    CHECK( 3 == ll_0.getValueAt( 3 ) );
    
  };

};

TEST_CASE("Testing Positive Prefix Sum"){
    LinkedList l1, l2, l3, l4;

    CHECK(!l1.positivePrefixSum());

    l2.insertAtBeginning(-1);
    l2.insertAtBeginning(1);
    l2.insertAtBeginning(-1);
    l2.insertAtBeginning(1);
    CHECK(l2.positivePrefixSum());
    l2.insertAtBeginning(-5);
    CHECK(!l2.positivePrefixSum());

    l3.insertAtBeginning(-6);
    l3.insertAtBeginning(1);
    l3.insertAtBeginning(1);
    CHECK(!l3.positivePrefixSum());
    l3.insertAtBeginning(6);
    CHECK(l3.positivePrefixSum());

    l4.insertAtBeginning(0);
    l4.insertAtBeginning(0);
    l4.insertAtBeginning(0);
    l4.insertAtBeginning(0);
    CHECK(!l4.positivePrefixSum());
}

TEST_CASE("Testing Negative Prefix Sum"){
  LinkedList l1, l2, l3, l4;

  CHECK(!l1.negativePrefixSum());

  l2.insertAtBeginning(-1);
  l2.insertAtBeginning(1);
  l2.insertAtBeginning(-1);
  l2.insertAtBeginning(1);
  CHECK(!l2.negativePrefixSum());
  l2.insertAtBeginning(-5);
  CHECK(l2.negativePrefixSum());

  l3.insertAtBeginning(1);
  l3.insertAtBeginning(1);
  l3.insertAtBeginning(-6);
  CHECK(l3.negativePrefixSum());
  l3.insertAtBeginning(6);
  CHECK(!l3.negativePrefixSum());

  l4.insertAtBeginning(0);
  l4.insertAtBeginning(0);
  l4.insertAtBeginning(0);
  l4.insertAtBeginning(0);
  CHECK(!l4.negativePrefixSum());
}

TEST_CASE("Testing InsertAtBeginning"){
  LinkedList l1;

  l1.insertAtBeginning(5);
  CHECK(l1.root->data == 5);
  l1.insertAtBeginning(6);
  CHECK(l1.root->data == 6);
  l1.insertAtBeginning(7);
  CHECK(l1.root->data == 7);
}

TEST_CASE("Testing Get Last Element"){
  LinkedList l1, l2;

  l1.insertAtBeginning(5);
  l2.insertAtBeginning(5);
  l2.insertAtBeginning(4);

  Node *p1 = l1.getLastElement();
  Node *p2 = l2.getLastElement();

  CHECK(p1->data == 5);
  CHECK(p2->data == 5);
}

TEST_CASE("Testing InsertAtEnd"){
  LinkedList l1, l2;
  l2.insertAtEnd(50);
  Node *p2 = l2.getLastElement();
  CHECK(p2->data == 50);
  
  l1.insertAtBeginning(5);
  l1.insertAtBeginning(6);
  l1.insertAtBeginning(7);
  Node *p1 = l1.getLastElement();
  CHECK(p1->data == 5);

  l1.insertAtEnd(22);
  Node *p3 = l1.getLastElement();
  CHECK(p3->data == 22);
}


TEST_CASE("Testing LL End Edgecases"){
LinkedList l1;

CHECK(l1.root == nullptr);

l1.insertAtBeginning(1);
Node *p1 = l1.root->next;
Node *p2 = l1.root;
CHECK(p1->data == p2->data);

l1.insertAtBeginning(2);
Node *p3 = l1.root->next;
CHECK(p2->data == p3->data);
}

TEST_CASE("Deleting Nth Node"){
  LinkedList l1, l2;

  l1.insertAtBeginning(5);
  l1.insertAtBeginning(4);
  l1.insertAtBeginning(3);

  l1.deleteNodeNumber(1);

  CHECK(l1.getValueAt(2) == 5);

  l2.insertAtBeginning(5);
  l2.deleteNodeNumber(0);

  CHECK(l2.root == nullptr);

}

TEST_CASE("Copy Constructor"){
  LinkedList l1, l3;

  LinkedList l2 = l1;
   CHECK(l2.root == nullptr);
   CHECK(&l1.root != &l2.root);

   l3.insertAtBeginning(4);
   l3.insertAtBeginning(3);
   l3.insertAtBeginning(2);
   l3.insertAtBeginning(1);
   LinkedList l4 = l3;

   CHECK(l4.getValueAt(1) == 1);
   CHECK(l4.getValueAt(2) == 2);
   CHECK(l4.getValueAt(3) == 3);
   CHECK(&l3.root != &l4.root);


}

TEST_CASE("PointerJumper"){
 LinkedList l;

  l.insertAtBeginning(5);
  l.insertAtBeginning(4);
  l.insertAtBeginning(3);
  l.insertAtBeginning(2);
  l.insertAtBeginning(1);

  Node * firstNode = l.root;
  Node * secondNode = l.root-> next;
  Node * thirdNode = secondNode-> next;

  CHECK(firstNode->next == secondNode);
  CHECK(secondNode->next == thirdNode);
  
  l.PointerJumper();

  Node * lastNode = l.getLastElement();

  CHECK(firstNode->next == lastNode);
  CHECK(secondNode->next == lastNode);
  CHECK(thirdNode->next == lastNode);
}