#include <iostream>
#include "8-0.hpp"

using namespace std;


vector<int> rightSideView(TreeNode* root){
    vector<int> res;
    if(root==nullptr){
        return res;
    }

    queue<TreeNode*> que1;
    queue<TreeNode*> que2;
    que1.push(root);
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
            res.emplace_back(new_node->val);
            que1 = que2;
            que2 = queue<TreeNode*>();
        }
    }

    return res;
}

int main(){
    TreeNode* root = nullptr;
    init(root);
    vector<int> res = rightSideView(root);
    for(auto i: res){
        cout<<i<<" "<<flush;
    }

    cout<<endl;
    return 0;
}