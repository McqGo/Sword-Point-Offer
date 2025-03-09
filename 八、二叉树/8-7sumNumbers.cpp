#include "8-0.hpp"
#include <iostream>

using namespace std;


int dfs(TreeNode* root, int sum){
    if(root==nullptr)
        return 0;

    sum = sum*10+root->val;
    if(root->left==nullptr && root->right==nullptr)
        return sum;

    return dfs(root->left, sum)+dfs(root->right, sum);
}

int sumNumbers(TreeNode*  root){
    return dfs(root, 0);
}

int main(){
    TreeNode* root = nullptr;
    initSum(root);
    cout<<sumNumbers(root)<<endl;


    return 0;
}
