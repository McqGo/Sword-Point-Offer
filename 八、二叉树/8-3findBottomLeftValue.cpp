#include <iostream>
#include "8-0.hpp"

using namespace std;

int findBottomLeftValue(TreeNode* root){
    queue<TreeNode*> que1;
    queue<TreeNode*> que2;

    que1.push(root);
    int bottom_left = root->val;
    while(!que1.empty()){
        TreeNode* new_node = que1.front();
        que1.pop();
        if(new_node->left!=nullptr){
            que2.push(new_node->left);
        }
        if(new_node->right!=nullptr){
            que2.push(new_node->right);
        }
        if(que1.empty()){
            que1 = que2;
            que2 = queue<TreeNode*>();
            if(!que1.empty()){
                bottom_left = que1.front()->val;
            }
        }
    }

    return bottom_left;
}

int main(){
    TreeNode* root = nullptr;
    init(root);
    cout<<findBottomLeftValue(root)<<endl;
    return 0;
}

