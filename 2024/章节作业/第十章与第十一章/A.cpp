/*��Ŀ����
������㣬����һ���������͵��������һ��ָ����ĵ���������ģ�塣�� main ������ʹ�ø���ģ�彨��������Ϊ���͵ĵ����������������е�������ʾ������
��ƺ����Ժ���ʹ������main�������ԣ�
int main() {
    int idata, n, fdata;
    cout << "������ĸ�����";
    cin >> n;
    cout << "�����һ������������";
    cin >> fdata;
    List<int> headnode(fdata);
    List<int>* last = &headnode;

    for (int i = 1; i < n; i++) {
        cout << "�����" << i + 1 << "������������";
        cin >> idata;
        List<int>* p = new List<int>(idata);
        p->append(last);
        last = p;
    }

    cout << "�����Ѿ�������" << endl;
    cout << "�����е�����Ϊ��" << endl;

    List<int>* p = &headnode;
    while (p != nullptr) {
        cout << p->getData() << endl;
        p = p->getNext();
    }

    return 0;
}

����
�ڵ�����ͽڵ��ڴ�ŵ�����
���
�����������е�����

����ʹ�õĹؼ���
class
�������� Copy
5
4
6
8
9
7
������� Copy
������ĸ����������һ�����������������2�����������������3�����������������4�����������������5�����������������Ѿ�������
�����е�����Ϊ��
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
    cout << "������ĸ�����";
    cin >> n;
    cout << "�����һ������������";
    cin >> fdata;
    List<int> headnode(fdata);
    List<int> *last = &headnode;

    for (int i = 1; i < n; i++)
    {
        cout << "�����" << i + 1 << "������������";
        cin >> idata;
        List<int> *p = new List<int>(idata);
        p->append(last);
        last = p;
    }

    cout << "�����Ѿ�������" << endl;
    cout << "�����е�����Ϊ��" << endl;

    List<int> *p = &headnode;
    while (p != nullptr)
    {
        cout << p->getData() << endl;
        p = p->getNext();
    }

    return 0;
}