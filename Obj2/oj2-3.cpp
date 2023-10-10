#include <conio.h>
#include <stack>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int forLoopRecur(int i);
int factorial(int n);
int bubbleSort_bigright(vector<int> &vec);
int bubbleSort_smallright(vector<int> &vec);

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. 尾递归的意思是调用函数是返回函数之前的最后一条语句, 而我这个函数在返回之前还有个求和过程, 所以不算尾递归
    */
    // int i;
    // std::cout << "输入一个正整数:" << std::endl;
    // std::cin >> i;
    // std::cout << "这个数字的位置的斐波那契数列为:" << factorial(i) << std::endl;

    // cout << forLoopRecur(i) << endl;
    
    // while(i)
    // {
    //     cout << factorial(i--)<<" ";
    // }

    /*
        1. 冒泡算法是将大的数往右边送, 小的数往左边送, 默认右边是地址更大的地方, 也就是push_back的地方
        2. 技巧: 第一轮循环封上限, 内循环托底与旁边交互比较, 一个个提上来
    */
    
    vector<int> num{1, 5, 3, 6, 8, 345, 35, 434, 345, 6, 56, 73, 652, 78, 67, 352, 345, 7, 4, 3, 454, 34};
    cout << bubbleSort_smallright(num) << endl;
    for(auto i : num)
    {
        cout << i << " ";
    }

    _getch();
    return 0;
}

int factorial(int n)
{
    if(n == 1)
    {
        return 0;
    }
    else if(n == 2)
    {
        return 1;
    }
    else if(n <= 0)
    {
        return -1;
    }
    else
    {
        return factorial(n - 1) + factorial(n - 2);
    }
}

int forLoopRecur(int i)
{
    stack<int> stack;
    int sum = 0;
    for (; i > 0;i--)
    {
        stack.push(i);
    }
    while(!stack.empty())
    {
        sum += stack.top();
        stack.pop();
    }
    return sum;
}

int bubbleSort_bigright(vector<int> &vec)
{
    int count = 0;
    for (auto i = vec.size() -1; i > 0; i--)
    {
        for (auto j = 0; j < i; ++j)
        {
            if(vec[j] > vec[j+1])
            {
                int num_temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j+1] = num_temp;
                count++;
            }
        }
    }
    return count;
}

int bubbleSort_smallright(vector<int> &vec) // 沉底算法
{
    int count = 0;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (auto j = vec.size() - 1; j > i; --j)
        {
            if(vec[j]>vec[j-1])
            {
                int num_temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j-1] = num_temp;
                count++;
            }
        }
    }
    return count;
}


int alg2n(int n)
{
    int count = 0;
    int base = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < base;++j)
        {
            ++count;
        }
        base *= 2;
    }
}


int log(int n)
{
    int count = 0;
    while(n > 1)
    {
        n /= 2;
        ++count;
    }
    return count;
}