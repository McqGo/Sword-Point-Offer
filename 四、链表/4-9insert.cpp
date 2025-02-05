#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* initial(){
    Node* node1 = new Node;
    Node* node2 = new Node;
    Node* node3 = new Node;
    Node* node4 = new Node;
    Node* node5 = new Node;
    Node* node6 = new Node;

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 5;
    node5->data = 6;
    node6->data = 7;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node1;

    return node1;
}

Node* insert(Node* head, int data){
    if(head==nullptr){
        head = new Node;
        head->data = data;
        head->next = head;
        return head;
    }

    Node* new_node = new Node;
    new_node->data = data;

    if(head->next==head){
        head->next = new_node;
        new_node->next = head;
        return head;
    }

    Node* cur = head;
    Node* next = head->next;
    Node* biggest_node = head;
    while(!(new_node->data>=cur->data && new_node->data<=next->data)
          && next!=head){
        cur = next;
        next =next->next;
        //这里注意要加上等于这个判断
        if(cur->data>=biggest_node->data)
            biggest_node = cur;
    }

    if(new_node->data>=cur->data && new_node->data<=next->data){
        cur->next = new_node;
        new_node->next = next;
    }
    else{
        new_node->next = biggest_node->next;
        biggest_node->next = new_node;
    }
    return head;
}

void print(Node* node){
    Node* flag = node;
    while(node!=nullptr){
        cout<<node->data<<" "<<flush;
        node = node->next;
        if(node==flag){
            cout<<endl;
            return ;
        }    
    }
}

int main(){
    Node* head = initial();
    
    head = insert(head, 100);

    print(head);
    return 0;
}