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

bool isPalindrome(List& list){
    Node* p = list.getDummy()->next;
    if(p==nullptr || p->next==nullptr)
        return true;
    
    Node* slow = p->next;
    Node* fast = slow->next;
    while(fast!=nullptr){
        fast = fast->next;
        //if语句的第一个判断是对fast执行非空的安全性检查
        if(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }            
    }

    Node* node1 = p;
    Node* node2 = slow->next;
    slow->next = nullptr;

    node2 = reverseList(node2);

    while(node1!=nullptr && node2!=nullptr){
        if(node1->data!=node2->data)
            return false;
        
        node1 = node1->next;
        node2 = node2->next;
    }

    return true;
}

 int main(){
    List list_1;
    list_1.appendNode(1);
    list_1.appendNode(2);
    list_1.appendNode(3);
    list_1.appendNode(2);
     list_1.appendNode(2);
    list_1.appendNode(1);
    list_1.appendNode(3);
    list_1.appendNode(2);
    list_1.appendNode(1);
 
    list_1.print();
    cout<<boolalpha<<isPalindrome(list_1)<<endl;
    return 0;
 }