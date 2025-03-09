#include "8-0.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string serialize(TreeNode* root){
    if(root==nullptr)
        return "#";
    
    string str_left = serialize(root->left);
    string str_right = serialize(root->right);
    return to_string(root->val)+","+str_left+","+str_right;
}

TreeNode* dfs(vector<string>& strs, int& index){
    string str = strs[index++];
    if(str=="#")
        return nullptr;
    TreeNode* node = new TreeNode(stoi(str));
    node->left = dfs(strs, index);
    node->right = dfs(strs, index);
    return node;
}

TreeNode* deSerialize(const string& str){
    stringstream ss(str);
    string s;
    vector<string> strs;
    while(getline(ss, s, ','))
        strs.emplace_back(s);

    int index = 0;
    return dfs(strs, index);
}


int main(){
    TreeNode* root = nullptr;
    init6_left(root);
    printBfs(root);
    string str_left = serialize(root);
    cout<<str_left<<endl;
    int i = 0;
    TreeNode* root_new = deSerialize(str_left);
    printBfs(root_new);

    TreeNode* root_ = nullptr;
    init6_right(root_);
    printBfs(root_);
    string str_right = serialize(root_);
    cout<<str_right<<endl;
    TreeNode* root_new_ = deSerialize(str_right);
    printBfs(root_new_);

    return 0;
}