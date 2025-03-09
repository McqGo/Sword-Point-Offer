#include <iostream>
#include <stack>
#include <algorithm>
#include "8-0.hpp"

using namespace std;





void dfsPreOrderRecursion(TreeNode* root, vector<int>& res){
    if(root!=nullptr){
        res.emplace_back(root->val);
        dfsPreOrderRecursion(root->left, res);
        dfsPreOrderRecursion(root->right, res);
    } 
}

void dfsPreOrderIteration(TreeNode* root, vector<int>& res){
    stack<TreeNode*> sta;
    if(root!=nullptr){
        sta.emplace(root);
        while(!sta.empty()){
            TreeNode* node = sta.top();
            sta.pop();
            res.emplace_back(node->val);
            if(node->right)  sta.emplace(node->right);
            if(node->left)  sta.emplace(node->left);
        }
    }
    
}

void dfsInOrderRecursion(TreeNode* root, vector<int>& res){
    if(root!=nullptr){
        dfsInOrderRecursion(root->left, res);
        res.emplace_back(root->val);
        dfsInOrderRecursion(root->right, res);
    } 
}

void dfsInOrderIteration(TreeNode* root, vector<int>& res){
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    while(cur!=nullptr || !sta.empty()){
        if(cur!=nullptr){
            sta.emplace(cur);
            cur = cur->left;
        }
        else{
            cur = sta.top();
            sta.pop();
            res.emplace_back(cur->val);
            cur = cur->right;
        }
    }
}

void dfsPostOrderRecursion(TreeNode* root, vector<int>& res){
    if(root!=nullptr){
        dfsPostOrderRecursion(root->left, res);
        dfsPostOrderRecursion(root->right, res);
        res.emplace_back(root->val);
    } 
}

void dfsPostOrderIteration(TreeNode* root, vector<int>& res){
    stack<TreeNode*> sta;
    if(root!=nullptr){
        sta.emplace(root);
        while(!sta.empty()){
            TreeNode* node = sta.top();
            sta.pop();
            res.emplace_back(node->val);
            if(node->left)  sta.emplace(node->left);
            if(node->right)  sta.emplace(node->right);
        }
    }

    reverse(res.begin(), res.end());
}

void dfsPostOrderIteration_(TreeNode* root, vector<int>& res) {
    if (root!=nullptr){
        stack<TreeNode*> sta;
        TreeNode *cur = root, *prev = nullptr;
        while (cur || !sta.empty()) {
            // 向左遍历到叶子节点，压入栈
            while (cur) {
                sta.push(cur);
                cur = cur->left;
            }    
            cur = sta.top(); // 查看栈顶节点     
            // 若右子树存在且未被访问，转向右子树
            if (cur->right && cur->right != prev) {
                cur = cur->right;
            } else { 
                // 右子树已处理，记录当前节点值
                res.push_back(cur->val);
                prev = cur;   // 标记当前节点为已处理
                sta.pop();      // 弹出栈顶
                cur = nullptr; // 防止重复访问左子树
            }
        }
    }
}



int main(){
    TreeNode* root = nullptr;
    init(root);
    printBfs(root);
    
    vector<int> res;
    cout<<"前序"<<endl;
    dfsPreOrderRecursion(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();

    dfsPreOrderIteration(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();

    cout<<"中序"<<endl;
    dfsInOrderRecursion(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();

    dfsInOrderIteration(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();

    cout<<"后序"<<endl;
    dfsPostOrderRecursion(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();

    dfsPostOrderIteration(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();

    dfsPostOrderIteration_(root, res);
    for(auto i:res){
        cout<<i<<" "<<flush;
    }
    cout<<endl;
    res.clear();


    return 0;
}