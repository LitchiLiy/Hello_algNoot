#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};
class LinkedListStack
{
    private:
        ListNode *stacktop;
        int linksize;
    public:
        LinkedListStack()
        {
            stacktop = nullptr;
            linksize = 0;
        }

        ~LinkedListStack()
        {
            delete(stacktop);
        }

        int size()
        {
            return linksize;
        }

        bool isEmpty()
        {
            return linksize == 0;
        }

        void push(int value)
        {
            ListNode *newnode = new ListNode(value);
            newnode->next = stacktop;
            stacktop = newnode;
            ++linksize;
        }

        void pop()
        {
            ListNode *temp = stacktop;
            stacktop = stacktop->next;
            delete temp;
            --linksize;
        }

        int top()
        {
            if(isEmpty())
            {
                throw out_of_range("Stack is empty");
            }
            return stacktop->val;
        }

        vector<int> Tovector()
        {
            ListNode *temp = stacktop;
            vector<int> res(linksize);
            for (int i = res.size() - 1; i >= 0;--i)
            {
                res[i] = temp->val;
                temp = temp->next;
            }
            return res;
        }
};

// 队列双向链表实现
class LinkedListQueue
{
    private:
        ListNode *front, *rear;
        int queSize;
    public:
        LinkedListQueue()
        {
            front = rear = nullptr;
            queSize = 0;
        }

        ~LinkedListQueue()
        {
            delete(front);
        }

        int size()
        {
            return queSize;
        }

        bool isEmpty()
        {
            return queSize == 0;
        }

        void push(int value)
        {
            ListNode *newnode = new ListNode(value);
            if (isEmpty())
            {
                front = rear = newnode;
            }
            else
            {
                rear->next = newnode;
                rear = newnode;
            }
            ++queSize;
        }

        void pop()
        {
            ListNode *temp = front;
            front = front->next;
            delete temp;
            --queSize;
        }

        int peek()
        {
            if (isEmpty())
            {
                throw out_of_range("Queue is empty");
            }
            return front->val;
        }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. 栈的话是stack, 有三大操作, 时间复杂度都是O1
        2. throw out_of_range("information") 这是一个抛出错误的语句, 抛出的错误可以中断程序
        3. 这里有一点需要注意, 栈顶说是顶, 但是操作仍然是push, 也就是说这个口是向下的, 或者说是向右的, 再或者说这个顶的地址是比底要大的, 所以在转换成vector的时候需要将top的内容存放到vec的底中
        4. 这里谈到了用数组(动态数组vector)实现和用链表实现的优缺点:
        5. 时间复杂度: 入栈出栈来说, 数组是很快的, 但是要考虑到超出数组容量时要搬家为On, 而链表由于需要初始化新入栈的元素, 故比较慢, 但效率比较平均
        6. 空间复杂度来说: 数组浪费比较大, 而链表需要存指针, 占用的空间比较大
        7. 如果你想要得到一个bool类型的字符值, 那就用==这种类型的运算符来得到, 或者在return的地方用逻辑运算符
    */
    
    /*
        1. 所有访问操作, 必须保证访问的地址不是空的
        2. delete的操作对象是一个指针, 故删除操作需要定义一个临时变量来保存要删除的数组.
        3. 栈的头部和push尾部是向下的, 但是队列queue和双向队列deque则不一样, 头部是向上向左的, 地址比较小.
    */
    
    _getch();
    return 0;
}