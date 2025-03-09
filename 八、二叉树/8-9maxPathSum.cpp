#include "8-0.hpp"
#include <iostream>
#include <limits>
using namespace std;

int dfs(TreeNode* root, int& max_sum){
    if(root==nullptr)
        return 0;

    int max_sum_left = numeric_limits<int>::min();
    int left = max(0, dfs(root->left, max_sum_left));

    int max_sum_right = numeric_limits<int>::min();
    int right = max(0, dfs(root->right, max_sum_right));

    max_sum = max(max_sum_left, max_sum_right);
    max_sum = max(max_sum, root->val+left+right);

    return root->val+max(left, right);
     
}

int maxPathSum(TreeNode* root){
    int max_sum;
    dfs(root, max_sum);
    return max_sum;
}

int main(){
    TreeNode* root = nullptr;
    initPathSumMax(root);
    printBfs(root);
    cout<<maxPathSum(root)<<endl;

    return 0;
}