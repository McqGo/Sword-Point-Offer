#ifndef BT_HPP
#define BT_HPP
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void init(TreeNode*& root){
    root = new TreeNode(9999);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(10);
    root->right->left->left = new TreeNode(11);
    root->right->right->right = new TreeNode(12);
}

void init0(TreeNode*& root){
    root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

}

void init6_left(TreeNode*& root){
    root = new TreeNode(6);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(6);
}

void init6_right(TreeNode*& root){
    root = new TreeNode(6);
    root->left = new TreeNode(6);
    root->right = new TreeNode(6);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(6);
}

void initSum(TreeNode*& root){
    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);

    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    
    root->right->right = new TreeNode(2);
    
}

void initPathSum(TreeNode*& root){
    root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(7);
    
}

void initPathSumMax(TreeNode*& root){
    root = new TreeNode(-9);
    root->left = new TreeNode(4);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    root->right->left->left = new TreeNode(-3);
}

vector<vector<int>> bfs(TreeNode* root){
    queue<TreeNode*> que;
    if(root!=nullptr)   que.push(root);
    vector<vector<int>> res;
    while(!que.empty()){
        int size = que.size();
        vector<int> vec;
        for(int i=0; i<size; i++){
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left)  que.push(node->left);
            if(node->right) que.push(node->right);
        }

        res.push_back(vec);
    }

    return res;
}

void printBfs(TreeNode* root){
    if(root==nullptr){
        cout<<"Empty Tree!!!"<<endl;
        return ;
    }
    vector<vector<int>> res_bfs = bfs(root);
    cout<<"BFS打印："<<endl;
    for(auto i: res_bfs){
        for(auto j: i){
            cout<<j<<" "<<flush;
        }
        cout<<endl;
    }
}
#endif