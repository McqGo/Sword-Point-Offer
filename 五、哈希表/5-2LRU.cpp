#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int key, int value): key(key), value(value){}
};

class LRUCache{
    Node* dummy_head;
    Node* dummy_tail;
    unordered_map<int, Node*> hash;
    int capacity;

    public:
        LRUCache(int cap){
            capacity = cap;
            dummy_head = new Node(-1, -1);
            dummy_tail = new Node(-1, -1);
            dummy_head->next = dummy_tail;
            dummy_tail->prev = dummy_head;
        }

        //剥离出该节点
        void stripNode(Node* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void insertToTail(Node* node){
            dummy_tail->prev->next = node;
            node->prev = dummy_tail->prev;

            node->next = dummy_tail;
            dummy_tail->prev = node;
        }

        void moveToTail(Node* node){
            stripNode(node);
            insertToTail(node);
        }

        int get(int key){
            if(hash.count(key)==0){
                return -1;
            }

            Node* node = hash[key];
            moveToTail(node);

            return node->value;
        }

        void put(int key, int value){
            if(hash.count(key)!=0){
                Node* node = hash[key];
                node->value = value;
                moveToTail(node);
            }
            else{
                if(hash.size()==capacity){
                    Node* to_delete = dummy_head->next;
                    stripNode(to_delete);
                    hash.erase(to_delete->key);
                    delete to_delete;
                }

                Node* new_node = new Node(key, value);
                insertToTail(new_node);
                hash[key] = new_node;
            }
        }

        void print(){
            for(Node* iter=dummy_head; iter->next!=dummy_tail; iter=iter->next){
                cout<<"("<<iter->next->key<<","<<iter->next->value<<")"<<" "<<flush;
            }
            cout<<"===================="<<endl;
        }

};



int main(){
    LRUCache s(4);
    cout<<s.get(1)<<endl;
    s.put(1,3);
    s.put(1,100);
    s.put(3,5);
    s.put(29,40);
    s.print();
    s.put(6,7);
    s.print();
    s.put(9,3);
    s.put(7,3);
    s.print();
    cout<<s.get(29)<<endl;
    s.put(100,100);
    s.print();

    return 0;
}