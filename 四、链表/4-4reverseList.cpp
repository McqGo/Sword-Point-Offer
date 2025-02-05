#include <iostream>
#include "list.hpp"

using namespace std;

Node* reverseList(Node* head){
    Node* cur = head;
    Node* prev = nullptr;
    //初始化，防止next成为野指针
    Node* next = nullptr;

    while(cur!=nullptr){
        //保存当前节点的后继节点
        next = cur->next;
        //修改next指针，当前节点指向反转
        cur->next = prev;
        //在原链表中，当前节点是下一个节点的前继节点
        prev = cur;
        //继续下一个节点
        cur = next;
    }

    //要求是返回反转后链表的头节点
    return prev;
}

int main(){
    List list_1;
    list_1.appendNode(1);
    list_1.appendNode(2);
    list_1.appendNode(3);
    list_1.appendNode(4);
    list_1.appendNode(5);
    list_1.appendNode(6);

    list_1.print();

    Node* new_head = reverseList(list_1.getDummy()->next);
    cout<<new_head->data<<endl;

    list_1.changeDummy(new_head);
    list_1.print();

    return 0;
}