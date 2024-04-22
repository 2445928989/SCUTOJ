/*题目描述
建立结点，包括一个任意类型的数据域和一个指针域的单向链表类模板。在 main 函数中使用该类模板建立数据域为整型的单向链表，并把链表中的数据显示出来。
设计好类以后，请使用以下main函数测试：
int main() {
    int idata, n, fdata;
    cout << "输入结点的个数：";
    cin >> n;
    cout << "输入第一个结点的数据域：";
    cin >> fdata;
    List<int> headnode(fdata);
    List<int>* last = &headnode;

    for (int i = 1; i < n; i++) {
        cout << "输入第" << i + 1 << "个结点的数据域：";
        cin >> idata;
        List<int>* p = new List<int>(idata);
        p->append(last);
        last = p;
    }

    cout << "链表已经建立！" << endl;
    cout << "链表中的数据为：" << endl;

    List<int>* p = &headnode;
    while (p != nullptr) {
        cout << p->getData() << endl;
        p = p->getNext();
    }

    return 0;
}

输入
节点个数和节点内存放的数据
输出
建立的链表中的数据

必须使用的关键字
class
样例输入 Copy
5
4
6
8
9
7
样例输出 Copy
输入结点的个数：输入第一个结点的数据域：输入第2个结点的数据域：输入第3个结点的数据域：输入第4个结点的数据域：输入第5个结点的数据域：链表已经建立！
链表中的数据为：
4
6
8
9
7*/
#include <iostream>
using namespace std;
template<typename T>
class List{
    private:
        T Data;
        List<T> *Next;

    public:
        void append(List<T>*last) {
            last->Next = this;
        }
        List() {}
        List(T fdata) {
            Data = fdata;
            Next = 0;
        }
        T getData(){
            return Data;
        }
        List<T>* getNext(){
            return Next;
        }
};
int main()
{
    int idata, n, fdata;
    cout << "输入结点的个数：";
    cin >> n;
    cout << "输入第一个结点的数据域：";
    cin >> fdata;
    List<int> headnode(fdata);
    List<int> *last = &headnode;

    for (int i = 1; i < n; i++)
    {
        cout << "输入第" << i + 1 << "个结点的数据域：";
        cin >> idata;
        List<int> *p = new List<int>(idata);
        p->append(last);
        last = p;
    }

    cout << "链表已经建立！" << endl;
    cout << "链表中的数据为：" << endl;

    List<int> *p = &headnode;
    while (p != nullptr)
    {
        cout << p->getData() << endl;
        p = p->getNext();
    }

    return 0;
}