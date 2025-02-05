#include <iostream>
#include "list.hpp"

using namespace std;

//让原本的单向链表中的第n1节点与第n2节点间的内容成环，第n2节点原本在第n1后面，所以让第n2节点的next指针指向第n1节点
void makeLoop(List& list, int n1, int n2){
    Node* temp = list.getDummy();
    Node* n1_node, * n2_node;
    int count = 0;
    while(temp->next!=nullptr){
        temp = temp->next;
        count++;
        if(count==n1){
            n1_node = temp;
        }
        if(count==n2){
            n2_node = temp;
            break;
        }
    }

    n2_node->next = n1_node;
}

void printLoop(List& list, int n1, int n2){
    Node* temp = list.getDummy();
    int count = 0;
    int cout_num = 0;
    while(temp->next!=nullptr && cout_num<30){
        temp = temp->next;
        count++;
        cout_num++;
        if(count==n1)   cout<<"|"<<flush;
        if(count==n2)   count = n1-1;
        cout<<temp->data<<" "<<flush;
    }

    cout<<endl;
}

Node* getNodeInLoop(List& list){
    if(list.getDummy()->next==nullptr 
     ||list.getDummy()->next->next==nullptr)
        return nullptr;

    Node* slow = list.getDummy()->next->next;
    Node* fast = slow->next;

    while(slow!=nullptr && fast!=nullptr){
        if(slow==fast)
            return slow;
        
        slow = slow->next;
        fast = fast->next;
        if(fast!=nullptr)
            fast = fast->next;
    }

    return nullptr;
}

Node* detectCycle1(List& list){
    Node* in_loop_node = getNodeInLoop(list);
    if(in_loop_node==nullptr)
        return nullptr;
    
    int loop_node_num = 1;
    for(Node* i = in_loop_node; i->next!=in_loop_node; i=i->next){
        loop_node_num++;
    }

    Node* fast = list.getDummy()->next;
    Node* slow = fast;

    for(int i=0; i<loop_node_num; i++){
        fast = fast->next;
    }

    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

Node* detectCycle2(List& list){
    Node* fast = getNodeInLoop(list);
    if(fast==nullptr){
        return nullptr;
    }

    Node* slow = list.getDummy()->next;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

//打破环，以保证链表不被双重释放
void breakLoop(List& list, int n){
    Node* i = list.getDummy();
    int count = 0;
    while(count<n){
        i = i->next;
        count++;
    }

    i->next = nullptr;
}

int main(){
    List list;
    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);
    list.appendNode(5);
    list.appendNode(6);

    list.print();
    
    //makeloop使链表成环，以得到题目中的链表
    makeLoop(list, 3, 6);
    printLoop(list, 3, 6);
    
    cout<<detectCycle1(list)->data<<endl;
    cout<<detectCycle2(list)->data<<endl;

    //打破环，以保证链表不被双重释放
    breakLoop(list, 6);

    return 0;
}