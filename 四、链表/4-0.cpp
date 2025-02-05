#include <iostream>
#include "list.hpp"
using namespace std;

int main(){
    //无哨兵节点
//    List_ list_;
//    list_.appendNode(10);
//    list_.appendNode(11);
//    list_.appendNode(21);
//    list_.appendNode(56);
//    list_.appendNode(100);
//
//    list_.deleteNode(21);
//    list_.deleteNode(101);
//    list_.deleteNode(10);
//
//    list_.print();
//
//    //有哨兵节点
//  List list;
//
//  list.appendNode(10);
//  list.appendNode(11);
//  list.appendNode(21);
//  list.appendNode(56);
//  list.appendNode(100);
//
//  list.deleteNode(21);
//  list.deleteNode(101);
//  list.deleteNode(10);
//
//  list.print();

   List list;
   list.insertAtHead(10);
   list.insertAtHead(11);
   list.insertAtHead(12);
   list.insertAtHead(13);

   list.insertBefore(13, 100);
   list.insertBefore(10, 11);
   list.print();

    return 0;
}