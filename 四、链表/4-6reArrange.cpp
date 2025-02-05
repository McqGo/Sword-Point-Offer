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

void link(Node* node1, Node* node2, Node* dummy){
    Node* temp;
    Node* prev = dummy;
    while(node1!=nullptr && node2!=nullptr){
        //暂存node1的后继节点
        temp = node1->next;
        //node1后接node2
        node1->next = node2;
        //node1前接上一个node2节点后面
        prev->next = node1;
        //保存当前node2作为下一个node1的前继节点
        prev = node2;
        //继续下去
        node1 = temp;
        node2 = node2->next;
    }

    if(node1!=nullptr){
        prev->next = node1;
    }
}

void reArrange(List& list_1){
    //链表中节点数0、1、2不需要重排
    if(list_1.getDummy()->next==nullptr                 
    || list_1.getDummy()->next->next==nullptr
    || list_1.getDummy()->next->next->next==nullptr)
        return ;

    Node* slow = list_1.getDummy()->next->next;
    Node* fast = slow->next;
    while(fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next;
        if(fast->next!=nullptr)
            fast = fast->next;
    }

    Node* temp = slow->next;
    slow->next = nullptr;

    link(list_1.getDummy()->next, reverseList(temp), list_1.getDummy());

}

int main(){
    List list_1;
    list_1.appendNode(1);
    list_1.appendNode(2);
    list_1.appendNode(3);
    list_1.appendNode(4);
    list_1.appendNode(5);
    list_1.appendNode(6);
    list_1.appendNode(7);
    list_1.appendNode(8);
 
    list_1.print();

    reArrange(list_1);
    
    list_1.print();
    return 0;
}