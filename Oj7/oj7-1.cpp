#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
};

vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode *> que1;
    vector<int> res;
    if (root == nullptr)
    {
        return res;
    }
    que1.push(root);
    while (!que1.empty())
    {
        res.push_back(que1.front()->val);
        if(que1.front()->left != nullptr)
        {
            que1.push(que1.front()->left);
        }
        if(que1.front()->right != nullptr)
        {
            que1.push(que1.front()->right);
        }
        que1.pop();
    }
    return res;
};

void frontOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    // vec.push_back(root->val);
    frontOrder(root->left);
    frontOrder(root->right);
};

void inOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    // vec.push_back(root->val);
    inOrder(root->right);
};

void backOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return;
    }
    backOrder(root->left);
    backOrder(root->right);
    // vec.push_back(root->val);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. 高度为h的树的叶节点数为2^h, 因为高度和深度是看经过的边来判断的, 层节点数才是2^h-1, 当层为1时, 高度为0
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    vector<int> res = levelOrder(root);
    for (int i = 0; i < res.size(); ++i)
    {
        cout << res[i] << " ";
    }
    /*
        1. 为什么pop要在push之前要建立一个tmpNote来记录front的指针?是因为pop会导致时间复杂度变大吗, 但是pop是O1的操作啊
        2. 时间复杂度, 要遍历n个节点, 故On, 空间复杂度, 同时存在的内存为叶节点数, 如果是完美二叉树, 那么叶节点的个数为(n+1)/2, 此时节点个数为n(这个可以通过高度和层节点数算出来,你记住也行), 故空间复杂度为On
    */
    
    /*
        1. 关于前序中序后序遍历, 时间复杂度可以看到就一个push_back操作每个函数, 故为On, 
        2. 空间复杂度包括(函数temp变量, 函数个数帧栈, 方法), 故当二叉树为链表时, 空间复杂度为On.
    */
    

    _getch();
    return 0;
}