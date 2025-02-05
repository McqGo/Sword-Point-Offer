#include <iostream>
#include <stack>
#include "list.hpp"

using namespace std;

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

//制作交点，list_2后接list_1的第n个节点, 1<=n<=list_1的长度
void makeIntersection(List& list_1, List& list_2, int n){
    Node* p1 = list_1.getDummy();
    Node* p2 = list_2.getDummy();
    int count = 0, i;

    for(i=1; i<=n && p1->next!=nullptr; i++){
        p1 = p1->next;
    }

    if(i<=n){
        cout<<"n错误"<<endl;
    }
    
    while(p2->next!=nullptr){
        p2 = p2->next;
    }

    p2->next = p1;
}

//破除交点，以避免节点被双重释放
void breakIntersection(List& list_1, List& list_2, int n){
    Node* p1 = list_1.getDummy();
    Node* p2 = list_2.getDummy();
    int count = 0, i;

    for(i=1; i<=n && p1->next!=nullptr; i++){
        p1 = p1->next;
    }

    if(i<=n){
        cout<<"n错误"<<endl;
    }
    
    while(p2->next!=nullptr){
        p2 = p2->next;
        if(p2->next==p1){
            p2->next = nullptr;
            return ;
        }

    }
}

void getIntersectionNodeBF(List& list_1, List& list_2){
    Node* i = list_1.getDummy();
    Node* j;

    while(i->next!=nullptr){
        i = i->next;
        j = list_2.getDummy();
        while(j->next!=nullptr){
            j = j->next;
            if(i==j){
                cout<<i->data<<endl;
                return ;
            }
        }
    }

    cout<<"无重合节点"<<endl;
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

void getIntersectionNodeMakeLoop(List& list_1, List& list_2){
    Node* temp = list_1.getDummy();
    while(temp->next!=nullptr){
        temp = temp->next;
    }

    temp->next = list_2.getDummy()->next;

    Node* fast = getNodeInLoop(list_1);
    if(fast==nullptr){
        cout<<"无重合节点"<<endl;
    }

    Node* slow = list_1.getDummy()->next;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }

    cout<<slow->data<<endl;   
    
    temp->next = nullptr;
}

void getIntersectionNodeStack(List& list_1, List& list_2){
    stack<Node*> list_1_stack;
    stack<Node*> list_2_stack;

    Node* p = list_1.getDummy();
    while(p->next!=nullptr){
        p = p->next;
        list_1_stack.emplace(p);
    }

    p = list_2.getDummy();
    while(p->next!=nullptr){
        p = p->next;
        list_2_stack.emplace(p);
    }

    Node* p1 = list_1_stack.top();
    Node* p2 = list_2_stack.top();
    while(p1==p2){
        list_1_stack.pop();
        list_2_stack.pop();
        p1 = list_1_stack.top();
        p2 = list_2_stack.top();
    }

    cout<<p1->next->data<<endl;
}

void getIntersectionNodeTP(List& list_1, List& list_2){
    int extra_len = 0;
    Node* p = list_1.getDummy();
    while(p->next!=nullptr){
        p = p->next;
        extra_len++;
    }

    p = list_2.getDummy();
    while(p->next!=nullptr){
        p = p->next;
        extra_len--;
    }

    Node* longer = extra_len>=0? list_1.getDummy(): list_2.getDummy();
    Node* shorter = extra_len>=0? list_2.getDummy(): list_1.getDummy();
    extra_len = extra_len>=0? extra_len: -extra_len;

    while(extra_len>0){
        longer = longer->next;
        extra_len--;
    }

    while(longer!=shorter){
        longer = longer->next;
        shorter = shorter->next;
    }

    cout<<longer->data<<endl;
}

int main(){
    List list_1;
    list_1.appendNode(1);
    list_1.appendNode(2);
    list_1.appendNode(3);
    list_1.appendNode(4);
    list_1.appendNode(5);
    list_1.appendNode(6);

    List list_2;
    list_2.appendNode(7);
    list_2.appendNode(8);

    makeIntersection(list_1, list_2, 4);

    list_1.print();
    list_2.print();

    getIntersectionNodeBF(list_1, list_2);
    getIntersectionNodeMakeLoop(list_1, list_2);
    getIntersectionNodeStack(list_1, list_2);
    getIntersectionNodeTP(list_1, list_2);

    breakIntersection(list_1, list_2, 4);
    return 0;
}