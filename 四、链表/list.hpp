#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
using namespace std;

//不使用哨兵节点的链表
class List_{
    private:
        struct Node{
            int data;
            Node* next;
        };

        //头指针
        Node* head;

    public:
        //初始化
        List_(){
            head = nullptr;
        }

        ~List_(){
            Node* to_delete = head;
            while(to_delete!=nullptr){
                Node* temp = to_delete->next;
                delete to_delete;
                to_delete = temp;
            }
            head = nullptr;
            cout<<"析构释放完毕"<<endl;
        }
        
        //向链表尾部追加节点，不使用哨兵节点
        void appendNode(int val){
            Node* new_node = new Node;
            new_node->data = val;
            new_node->next = nullptr;

            if(head == nullptr){
                head = new_node;
                return ;
            }

            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = new_node; 
        }

        //删除指定节点，不使用哨兵节点
        void deleteNode(int val){
            if(head==nullptr){
                return ;
            }

            if(head->data==val){
                Node* to_delete = head;
                head = head->next;
                delete to_delete;
                return ;
            }

            Node* temp = head;
            while(temp->next!=nullptr){
                if(temp->next->data==val){
                    Node* to_delete = temp->next;
                    temp->next = temp->next->next;
                    delete to_delete;
                    return ;
                }
                temp = temp->next;
            }
        }

        //从头顺序打印每个节点的值
        void print(){
            Node* temp = head;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

struct Node{
    int data;
    Node* next;
};

//使用哨兵节点的链表
class List{
    private:
        Node* dummy;

    public:
        List(){
            dummy = new Node;
            dummy->data = 0;    
            dummy->next = nullptr;
        }

        ~List(){
            Node* to_delete = dummy->next;
            while(to_delete!=nullptr){
                Node* temp = to_delete->next;
                delete to_delete;
                to_delete = temp;
            }
            dummy->next = nullptr;
            cout << "析构释放完毕" << endl;
        }

        Node* getDummy(){
            return dummy;
        }

        //头插法
        void insertAtHead(int val){
            Node* new_node = new Node;
            new_node->data = val;
            new_node->next = dummy->next;
            dummy->next = new_node;
        }

        //尾插法，向链表尾部追加节点，使用哨兵节点
        void appendNode(int val){
            Node* new_node = new Node;
            new_node->data = val;
            new_node->next = nullptr;

            Node* temp = dummy;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = new_node;
        }

        // 删除指定节点，使用哨兵节点
        void deleteNode(int val){
            Node* temp = dummy;
            while(temp->next!=nullptr){
                if(temp->next->data==val){
                    Node* to_delete = temp->next;
                    temp->next = temp->next->next;
                    delete to_delete;
                    return ;
                }
                
                temp = temp->next;
            }
        }

        //指定元素前插入节点
        void insertBefore(int target, int val){
            Node* temp = dummy;
            while(temp->next!=nullptr){
                if(temp->next->data==target){
                    Node* new_node = new Node;
                    new_node->data = val;
                    new_node->next = temp->next;
                    temp->next = new_node;
                    return ;
                }
                temp = temp->next;
            }

            cout<<"插入失败：target不存在"<<endl;
        }

        //从头顺序打印每个节点的值
        void print(){
            cout<<"-----------------------"<<endl;
            Node* temp = dummy;
            while(temp->next!=nullptr){
                cout<<temp->next->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }

        void changeDummy(Node* node){
            dummy->next = node;
        }
        
};


#endif