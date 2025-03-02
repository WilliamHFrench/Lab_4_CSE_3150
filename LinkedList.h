#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>

#include "Node.h"


using namespace std;

class LinkedList {
  public:

    Node * root;

    LinkedList() : root(nullptr) {}

    /* */
    LinkedList(const LinkedList & fromLL) {
        if (nullptr == fromLL.root) {
            root = nullptr;
            return;
        }

        root = new Node(fromLL.root->data);

        Node * currentOld = fromLL.root;
        Node * newList = root;
        while (currentOld && currentOld->next != currentOld) {
        newList->next = new Node(currentOld->next->data);
        newList = newList->next;
        currentOld = currentOld->next;
        }
        newList->data = currentOld->data;
        newList->next = newList;
    }

    LinkedList(LinkedList && fromLL){
        root = fromLL.root;
        fromLL.root = nullptr;
    }
    
    LinkedList& operator=(LinkedList&& fromLL) noexcept {
        if (this != &fromLL) {              
            root = fromLL.root;  
            fromLL.root = nullptr; 
        }
        return *this;
    }
    /* */

    void insertAtBeginning(int val) {
        Node * newNode = new Node(val);
        newNode->next = root;
        if(!root){
            newNode->next = newNode;
        }
        root = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        newNode->next = newNode;
        if (!root) {
            root = newNode;
            return;
        }
        Node* current = root;
        while (current && current->next != current) {
            current = current->next;
        }
        current->next = newNode;
    }

    Node * getLastElement() {
        Node * current = root;
        while (current->next != current) {
            current = current->next;
        }
        return current;
    }

    int getSize() {
        if(!root)return 0;
        if(root->next = root){
            return 1;
        }
        int size = 0;
        Node * current = root;
        while (current && current->next != current) {
            size ++;
            current = current->next;
        }
        return size;
    }

    /*
     * -1 if the position is off the linked list
     */

    int getValueAt(int position) {
        int value = -1;

        if (!root) return value;
        int count = 1;
        Node * current = root;
        while (current->next != current && count < position) {
            count++;
            current = current->next;
        }
        if(count == position){
        value = current->data;
        }
        return value;

    }
    

    void deleteNodeNumber(int nodeNumber) {
        if (!root) return;

        if (0 == nodeNumber) {
            Node* temp = root;
            if(root->next != root){
            root = root->next;
        }
        else{
            root = nullptr;
        }
            delete temp;
            return;
        }
        int count = 1;
        Node * current = root;
        while (current->next != current && count != nodeNumber) {
            count++;
            current = current->next;
        }
        if (current->next != current) {
            Node * temp = current->next;
            if(temp->next == temp){
                current->next = current;
            }
            else{
                current->next = current->next->next;
            }
            delete temp;
        }
    }

    void PointerJumper(){
        if(root == nullptr) return;
        Node* last = getLastElement();
        Node* current = root;
        while(current->next != current){
            Node* temp = current;
            current = current->next;
            temp->next = last;
        }
    }

    bool positivePrefixSum(){
        if(root == nullptr) return false;
        bool aboveZero = false;
        int sum = 0;
        Node* current = root;
        while(current->next != current){
            if(sum > 0){
                aboveZero = true;
            }

            sum += current->data;

            if(sum < 0){
                return false;
            }
            current = current->next;
        }
        sum += current->data;
        if(sum < 0){
            return false;
        }
        return aboveZero;
    }

    bool negativePrefixSum(){
        if(root == nullptr) return false;
        bool belowZero = false;
        int sum = 0;
        Node* current = root;
        while(current->next != current){
            if(sum < 0){
              belowZero = true;
            }

            sum += current->data;

            if(sum > 0){
                return false;
            }
            current = current->next;
        }
        sum += current->data;
        if(sum > 0){
            return false;
        }
        return belowZero;
    }

    ~LinkedList(){
      Node * current = root;
        while(current && current != current->next){
            Node * next = current->next;
            delete current;
            current = next;
       }
       delete current;
       root = nullptr;
    }

};


ostream & operator<<(ostream & os, const LinkedList & linkedList) {
    Node * current = linkedList.root;
    while (current && current != current->next) {
        os << *current << " ";
        current = current->next;
    }
        
    return os;
}


#endif