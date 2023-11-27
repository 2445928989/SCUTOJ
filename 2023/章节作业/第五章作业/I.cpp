/*题目描述
输入一行字符，按输入字符的反序建立一个字符结点的单向链表，并输出该链表中的字符。
输入
先输入一个整数，表示即将输入的字符串的个数，然后空格，输入一串字符（字符之间不要空格）
输出
反序字符串（不要空格间隔）
样例输入 Copy
5 abcde
10 abcdefghij
2 om
3 xyz
6 1wq02+
样例输出 Copy
edcba
jihgfedcba
mo
zyx
+20qw1*/

#include<iostream>
using namespace std;
struct Node {
    char data;
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
int main() {
    Node* head, * end;
    int len;
    while (cin >> len) {
        createList(head, end, len);
        rshow(end);
        del(head);
        cout << endl;
    }
    system("pause");
}
