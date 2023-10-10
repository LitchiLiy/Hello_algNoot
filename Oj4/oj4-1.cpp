#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
 
int *banjia(int *num, int size, int enlarge)
{
    int *new_num = new int[size + enlarge];
    for (int i = 0; i < size; ++i)
    {
        new_num[i] = num[i];
    }
    delete[] num;
    return new_num;
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
// 前插, 在index索引之前插入一个val数值
void listcharu(ListNode *listtemp, int val, int index)
{
    ListNode *tempnum = new ListNode(val);
    for (int i = 0; i < index - 1; ++i)
    {
        if (listtemp == nullptr)
        {
            break; // 索引到最后
        }
        listtemp = listtemp->next;
    }
    tempnum->next = listtemp->next;
    listtemp->next = tempnum;
}
// 找查指针第一步先看看是不是一个空指针
int listfind(ListNode *listtemp, int val)
{
    for (int i = 0;listtemp != nullptr; ++i)
    {
        if (listtemp->val == val)
        {
            return i;
        }
        listtemp = listtemp->next;
    }
    return -1;
}





int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. new一般在函数内部领域用, 用他创建的变量不会随着函数结束而释放内存, 需要delete手动释放, 他是存储在堆而不是帧栈上.
        2. 引入数组作为形参一般是用指针或者是引用来引入数组
        3. 链表存储着一个值, 在前面, 后面跟着下一个值位置的指针, 存储着地址, 尾部为空指针nullptr
        4. 为什么要在作用域里用new来创建分配内存, 因为作用域的栈帧是有限的, 这个容量在作用域刚被打开时就分配好了, 如果变量太大可能会溢出栈帧, 需要注意的是new需要用delete来删除
    */

    // 5个列表值
    ListNode *n0 = new ListNode(0);
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    /*
        1. 找查指针中, 如果指针被循环指向了地址最后一个元素的下一个元素, 我们定义的是一个空指针, 所以在条件判决语句中就是如果指针是一个空指针, 那么就结束查找
    */

    vector<int> num1{1, 2, 3, 4, 5, 6, 7, 8};
    cout << *num1.insert(num1.begin(), 444) << endl;
    cout << *num1.erase(num1.begin()) << endl;

    /*
        1. list列表插入, 在指定位置之前插入一个数值, 就是前插, 并且返回指向插入值的指针, 其实就是指向原地址, 本来的数据被往后推了.
        2. 删除list, 指定位置删除, 并且返回删除那个索引之后的指针.其实就是指向原地址, 后面的数据自己弹上来了
    */
    

    _getch();
    return 0;
}