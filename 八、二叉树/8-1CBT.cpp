#include "8-0.hpp"
#include <iostream>

using namespace std;

class CBTInsert{
    private:
        queue<TreeNode*> que;
        TreeNode* root;
    
    public:
        CBTInsert(TreeNode* root){
            this->root = root;
            que.push(root);
            while(que.front()->left!=nullptr && que.front()->right!=nullptr){
                TreeNode* node = que.front();
                que.pop();
                que.push(node->left);
                que.push(node->right);
            }
        }

        int insert(int v){
            TreeNode* parent = que.front();
            TreeNode* new_node = new TreeNode(v);

            if(parent->left==nullptr){
                parent->left = new_node;
            }
            else{
                parent->right = new_node;
                que.pop();
                que.push(parent->left);
                que.push(parent->right);
            }

            return parent->val;
        }

        TreeNode* get_root(){
            return this->root;
        }

};

int main(){
    TreeNode* root = nullptr;
    init(root);
    CBTInsert cbt(root);
    cout<<cbt.get_root()->val<<endl;
    cout<<cbt.insert(111)<<endl;
    cout<<cbt.insert(111)<<endl;
    cout<<cbt.get_root()->val<<endl;

    return 0;
}