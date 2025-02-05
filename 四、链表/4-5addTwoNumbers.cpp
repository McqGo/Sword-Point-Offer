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

List addTwoNumbers(List& list_1, List& list_2){
    List res;
    Node* head_1 = reverseList(list_1.getDummy()->next);
    Node* head_2 = reverseList(list_2.getDummy()->next);

    int sum = 0;
    int carry = 0;
    while(head_1!=nullptr || head_2!=nullptr){
        sum = (head_1==nullptr? 0: head_1->data)
            + (head_2==nullptr? 0: head_2->data)
            + carry;

        carry = sum>=10? 1: 0;
        sum = sum>=10? sum-10: sum;

        res.appendNode(sum);

        head_1 = head_1==nullptr? nullptr: head_1->next;
        head_2 = head_2==nullptr? nullptr: head_2->next;   
    }

    if(carry>0){
        res.appendNode(1);
    }

    Node* head = reverseList(res.getDummy()->next);
    res.changeDummy(head);

    return res;
}

int main(){
    List list_1;

    list_1.appendNode(4);
    list_1.appendNode(5);
    list_1.appendNode(6);

    list_1.print();

    List list_2;
    list_2.appendNode(1);
    list_2.appendNode(2);
    list_2.appendNode(3);
    list_2.appendNode(4);
    list_2.appendNode(5);
    list_2.appendNode(6);
  
    list_2.print();

    List res = addTwoNumbers(list_1, list_2);
    
    res.print();
    return 0;
}