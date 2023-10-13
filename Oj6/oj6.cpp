#include <conio.h>
#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

struct Pair
{
    public:
        int key;
        string val;
        Pair(int key, string val) : key(key), val(val){};
};

class ArrayHashMap
{
    private:
        vector<Pair *> buckets;
    public:
        ArrayHashMap()
        {
            buckets = vector<Pair *>(100);
        }
        ~ArrayHashMap()
        {
            for(auto &i:buckets)
            {
                delete i;
            }
            buckets.clear();
        }

        int hashFunc(int key)
        {
            return key % buckets.size();
        }

        string get(int key)
        {
            int index = hashFunc(key);
            Pair *pairtmp = buckets[index];
            if(pairtmp = nullptr)
            {
                throw out_of_range("在哈希表中找不到这个键值对");
            }
            else
            {
                return pairtmp->val;
            }
        }

        void put(int key, string val)
        {
            int index = hashFunc(key);
            Pair *pairtmp = new Pair(key, val);
            buckets[index] = pairtmp;
        }

        void remove(int key)
        {
            int index = hashFunc(key);
            delete buckets[index];
            buckets[index] = nullptr;
        }

        vector<Pair *> getHash()
        {
            vector<Pair *> HashtmpArray;
            for(auto &i:buckets)
            {
                if(i != nullptr)
                {
                    HashtmpArray.push_back(i);
                }
            }
            return HashtmpArray;
        }

        void print()
        {
            for(auto &i:getHash())
            {
                cout << i->key << " " << i->val << endl;
            }
        }
};

class HashMapChaining
{
    private:
        int size;
        int capacity;
        double loadThres;
        int extendRatio;
        vector<vector<Pair *>> buckets;
    public:
        HashMapChaining() : size(0), capacity(100), loadThres(2.0/3.0), extendRatio(2){};
        ~HashMapChaining()
        {
            for(auto &i:buckets)
            {
                for(auto &j:i)
                {
                    delete j;
                }
            }
            buckets.clear();
        }
        void expend1()
        {
            vector<vector<Pair *>> bucketsTmp = buckets;
            capacity *= extendRatio;
            buckets.clear();
            buckets.resize(capacity);
            size = 0;
            for(auto &i:bucketsTmp)
            {
                for(auto *j:i)
                {
                    put(j->key, j->val);
                    delete j;
                }
            }
        }

        int hashFunc(int key)
        {
            return key % capacity;
        }

        double loadFactor()
        {
            return (double)size / (double)capacity;
        }

        void put(int key, string val) {
            // 当负载因子超过阈值时，执行扩容
            if (loadFactor() > loadThres) {
                expand1();
            }
            int index = hashFunc(key);
            // 遍历桶，若遇到指定 key ，则更新对应 val 并返回
            for (Pair *pair : buckets[index]) {
                if (pair->key == key) {
                    pair->val = val;
                    return;
                }
            }
            // 若无该 key ，则将键值对添加至尾部
            buckets[index].push_back(new Pair(key, val));
            size++;
        }

        string get(int key)
        {
            int index = hashFunc(key);
            for(auto &i:buckets[index])
            {
                if(i->key == key)
                {
                    return i->val;
                }
            }
            throw out_of_range("在哈希表中找不到这个键值对");
        }

        void remove(int key)
        {
            int index = hashFunc(key);
            auto ptrtmp = buckets[index].begin();
            for(auto &i:buckets[index])
            {
                if(i->key == key)
                {
                    delete i;
                    buckets[index].erase(ptrtmp);
                    --size;
                    return;
                }
                ++ptrtmp;
            }
        }

        void expand1()
        {
            vector<vector<Pair *>> bucketsTmp = buckets;
            capacity *= extendRatio;
            buckets.clear();
            buckets.resize(capacity);
            size = 0;
            for(auto &i:bucketsTmp)
            {
                for(auto *j:i)
                {
                    put(j->key, j->val);
                    delete j;
                }
            }
        }

        void print()
        {
            for(auto &i:buckets)
            {
                cout << "[";
                for(auto &j:i)
                {
                    cout << j->key << " " << j->val << ", ";
                }
                cout << "]" << endl;
            }
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    /*
        1. 类的解析函数删除的不是新建的这个类, 而是删除这个类内函数用new创建的内存, 也就是说这个解析函数是写完类整体之后最后写的, 最后回顾看看哪个是用new创建的就删了他
    */
    // unordered_map<int, string> map1;
    // map1[1234] = "小李";
    // map1[3456] = "小王";
    // string name = map1[1234];
    // cout << name << endl;
    // map1.erase(1234);

    // for(auto &i:map1)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    /*
        1. delete有两个用法, new创建一个单元素时, delete 指针,就能释放这个new所占的内存, 并且让其指针悬挂(并不是空指针, 指针仍然指向那个地址, 但是那个地址的内存已经被释放了), 有可能产生未定义的后果, 所以尽量delete之后跟着一个指针定义为nullptr
        2. vec.clear()作用: 1. 删除所有元素, 2. 容器容量变为0
        3. 由于我们通过数组来模仿哈希表, 所以容量一般都定义很大, 外部想获得此时的键值对哈希表时, 一定要自定义一个vec将有数值的放出去, 没数值的就不要输出出去了
    */
    // ArrayHashMap map2;
    // map2.put(1234, "小李");
    // map2.put(3456, "小王");
    // map2.put(123, "不知道是谁");
    // map2.print();

    /*
        1. 一个void类型的函数 ,我们可以通过return;来提前结束函数, 比如说在遍历的时候如果找到了那个值, 就直接退出, 遍历结束没找到再执行其他事情就可以在if里用return;来结束遍历
    */

    // HashMapChaining map3; 有问题, 不知道为啥执行不了
    // map3.put(10, "小李");
    // map3.put(20, "小王");
    // map3.put(30, "不知道是谁");
    // map3.put(110, "小李2");
    // map3.put(120, "小王2");
    // map3.print();
    
    /*
        1. 开放寻址的线性寻址和平方寻址自己看看吧
    */
    
    _getch();
    return 0;
}