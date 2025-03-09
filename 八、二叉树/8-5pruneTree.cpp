#include <iostream>
#include "8-0.hpp"

using namespace std;

void pruneTreeRecursion(TreeNode*& root){
    if(root!=nullptr){
        pruneTreeRecursion(root->left);
        pruneTreeRecursion(root->right);
        if(root->left==nullptr && root->right==nullptr && root->val==0){
            root = nullptr;
        }
    }
}

int main(){
    TreeNode* root = nullptr;
    init0(root);
    printBfs(root);
    pruneTreeRecursion(root);
    printBfs(root);
    return 0;
}