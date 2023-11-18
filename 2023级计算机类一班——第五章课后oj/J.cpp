/*题目描述
设有说明语句:
struct List { int data; List * next; };
List *head;
head是有序单向链表的头指针。请编写函数:
void Count( List * head );
计算并输出链表中有相同值的结点及其个数。例如，若数据序列为:
2 3 3 3 4 5 5 6 6 6 6 7 8 9 9
则输出结果为:
data number
3     3
5     2    
6     4
9     2
可以用例 5-18 的程序生成有序链表，测试 Count 函数。
输入
一个链表的长度（也就是链表中有多少个数据），需要存进链表的数据（注意输入的数据要是升序）
输出
相同值的节点及其个数（中间以一个空格间隔）
样例输入 Copy
5
1 1 1 2 2
8
1 1 2 2 2 3 3 3
样例输出 Copy
1 3
2 2
1 2
2 3
3 3*/

#include<iostream>
#include<map>
using namespace std;
struct Node {
    int data;
    Node* pre;
    Node* next;
};
void createList(Node*&head,Node*&end,int len) {
    Node* s, * p;
    int i = 1;
    s = new Node;
    head = s;
    s->pre = NULL;
    cin >> s->data;
    while (i<len) {
        p = s;
        s = new Node;
        p->next = s;
        s->pre = p;
        cin >> s->data;
        i++;
    }
    end = s;
    s->next = NULL;
}
void show(Node* begin) {
    while (true) {
        cout << begin->data;
        if (begin->next != NULL)begin = begin->next;
        else break;
    }
}
void rshow(Node* end) {
    while (true) {
        cout << end->data;
        if (end->pre != NULL)end = end->pre;
        else break;
    }
}
void del(Node* begin) {
    Node* s;
    while (true) {
        s = begin;
        begin = begin->next;
        delete s;
        if (begin == NULL)break;
    }
}
void count(Node* begin) {
    map<int, int>m1;
    while (true) {
        m1[begin->data]++;
        if (begin->next != NULL)begin = begin->next;
        else break;
    }
    for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
        if(it->second>1)cout << it->first << " " << it->second << endl;
    }
}
int main() {
    Node* head, * end;
    int len;
    while (cin >> len) {
        createList(head, end, len);
        count(head);
        del(head);
    }
    system("pause");
}
