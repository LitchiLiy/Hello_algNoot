#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int xibaofenlie(int n)
{
    int i = 0, count = 0, base = 1;
    for (i = 0; i < n;++i)
    {
        for (int j = 0; j < base;++j)
        {
            ++count;
        }
        base *= 2;
    }
    return count;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. 函数的循环调用空间复杂度也是O1, 因为函数的帧栈会被释放, 包括For循环的常量int也是, 每次循环都会释放内存, 因此每次都是O1, 但是循环内部有其他东西就不一定了
        2. 算法实质就是一个函数: 分析空间复杂度时间复杂度实质就是分析这个函数占了多少空间, 需要多少时间, 
        3. 1+2+3+4++++++n的复杂度是On^2的, 因为有n/2 * n次, 所以是On^2(递归, 冒泡)
        4. 尾递归也要占着空间, 空间不会被释放
    */

    // 细胞分裂

    
    _getch();
    return 0;
}