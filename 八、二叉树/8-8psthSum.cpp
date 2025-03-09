#include "8-0.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;

int dfs(TreeNode* root, int sum, unordered_map<int, int>& hash, int path){
    if(root==nullptr)
        return 0;

    path+=root->val;
    int count = 0;
    if(hash.find(path-sum)!=hash.end()){
        count+=hash[path-sum];
    }
    hash[path]++;
    count+=dfs(root->left, sum, hash, path);
    count+=dfs(root->right, sum, hash, path);
    hash[path]--;
    return count;

}

int pathSum(TreeNode* root, int sum){
    unordered_map<int, int> hash;
    hash[0] = 1;
    return dfs(root, sum, hash, 0);
}

int main(){
    TreeNode* root = nullptr;
    initPathSum(root);
    cout<<pathSum(root, 8)<<endl;

    return 0;
}