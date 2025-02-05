#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node* child;

    Node(int data, Node* prev, Node* next, Node* child)
    :data(data), prev(prev), next(next), child(child){}    
};

Node* initial(){
    //8 9
    Node* node3_1 = new Node(8, nullptr, nullptr, nullptr);
    Node* node3_2 = new Node(9, node3_1, nullptr, nullptr);
    node3_1->next = node3_2;

    //5 6 7
    Node* node2_1 = new Node(5, nullptr, nullptr, nullptr);
    Node* node2_2 = new Node(6, node2_1, nullptr, node3_1);
    Node* node2_3 = new Node(7, node2_2, nullptr, nullptr);
    node2_1->next = node2_2;
    node2_2->next = node2_3;

    //1 2 3 4
    Node* node1_1 = new Node(1, nullptr, nullptr, nullptr);
    Node* node1_2 = new Node(2, node1_1, nullptr, node2_1);
    Node* node1_3 = new Node(3, node1_2, nullptr, nullptr);
    Node* node1_4 = new Node(4, node1_3, nullptr, nullptr);
    node1_1->next = node1_2;
    node1_2->next = node1_3;
    node1_3->next = node1_4;

    return node1_1;
}

void print(Node* node, string indent = "") {
    while (node!=nullptr) {
        cout << indent << "|-- " << node->data << endl;

        if (node->child) {
            print(node->child, indent + "|   ");
        }
        
        node = node->next;  
    }
}



Node* flatten(Node* head){
    Node* node = head;
    Node* tail = nullptr;
    while(node!=nullptr){
        Node* temp = node->next;

        if(node->child!=nullptr){
            Node* child_head = node->child;
            Node* child_tail = flatten(child_head);
            
            node->child = nullptr;
            node->next = child_head;
            child_head->prev = node;
            child_tail->next = temp;
            if(temp!=nullptr)
                temp->prev = child_tail;

            tail = child_tail;
        }
        else{
            tail = node;
        }

        node = temp;
    }

    return tail;
}

int main(){
    Node* head = initial();
    print(head);
    flatten(head);
    cout<<endl;
    print(head);

    while(head!=nullptr){
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    return 0;
}