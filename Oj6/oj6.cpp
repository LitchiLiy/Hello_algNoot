#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. 类的解析函数删除的不是新建的这个类, 而是删除这个类内函数用new创建的内存, 也就是说这个解析函数是写完类整体之后最后写的, 最后回顾看看哪个是用new创建的就删了他
    */
    
    _getch();
    return 0;
}