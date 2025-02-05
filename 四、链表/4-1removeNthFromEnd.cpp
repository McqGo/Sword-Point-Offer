#include <iostream>
#include "list.hpp"
using namespace std;

void removeNthFromEnd(List& list, int n){
    Node* front = list.getDummy();
    Node* back = list.getDummy();

    for(int i=0; i<n; i++){
        front = front->next;
    }

    while(front->next!=nullptr){
        front = front->next;
        back = back->next;
    }

    Node* to_delete = back->next;
    back->next = back->next->next;
    delete to_delete;
}


int main(){
    List list;
    list.appendNode(1);
    list.appendNode(2);
    list.appendNode(3);
    list.appendNode(4);
    list.appendNode(5);

    list.print();

    removeNthFromEnd(list, 1);
    list.print();

    return 0;
}