#include <iostream>
#include "8-0.hpp"
#include <limits>

using namespace std;

vector<int> largestValues1(TreeNode* root){
    int current = 0;
    int next = 0;
    queue<TreeNode*> que;
    if(root!=nullptr){
        que.push(root);
        current = 1;
    }

    vector<int> res;
    int max_int = numeric_limits<int>::min();
    while(!que.empty()){
        TreeNode* node = que.front();
        que.pop();
        current--;
        max_int = max(max_int, node->val);
        
        if(node->left!=nullptr){
            que.push(node->left);
            next++;
        }
        if(node->right!=nullptr){
            que.push(node->right);
            next++;
        }

        if(current==0){
            res.emplace_back(max_int);
            max_int = numeric_limits<int>::min();
            current = next;
            next = 0;
        }
    }

    return res;
}

vector<int> largestValues2(TreeNode* root){
    queue<TreeNode*> que1;
    queue<TreeNode*> que2;
    if(root!=nullptr){
        que1.push(root);
    }

    vector<int> res;
    int max_int = numeric_limits<int>::min();
    while(!que1.empty()){
        TreeNode* node = que1.front();
        que1.pop();
        max_int = max(max_int, node->val);
        if(node->left!=nullptr){
            que2.push(node->left);
        }
        if(node->right!=nullptr){
            que2.push(node->right);
        }
        if(que1.empty()){
            res.emplace_back(max_int);
            max_int = numeric_limits<int>::min();
            que1 = que2;
            que2 = queue<TreeNode*>();
        }
    }

    return res;
}

int main(){
    TreeNode* root = nullptr;
    init(root);
    vector<int> res1 = largestValues1(root);
    for(auto i: res1)
        cout<<i<<" "<<flush;
    cout<<endl;
    vector<int> res2 = largestValues2(root);
    for(auto i: res2)
        cout<<i<<" "<<flush;
    cout<<endl;
    return 0;
}