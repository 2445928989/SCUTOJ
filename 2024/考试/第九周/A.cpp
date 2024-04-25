/*题目描述
对于之前题目：影片管理的类进行修改：

1.提供一个多态的成员函数input，用于读取输入Film、DirectoCut和ForeignFilm的具体信息，输入的具体信息详见样例输入。

2.根据输入的信息动态的创建Film类层次对象。(在read_input 函数中实现)

3.将Film类层次中的input函数设计为虚函数，使其具有多态性，动态创建的对象通过input函数可以从我们的输入中得到正确数据。

4.将Film类层次中的output函数设计为虚函数，使其具有多态性，动态创建的对象通过output函数可以将信息正确的输出。

根据以下测试函数进行测试：

int main()
{
    int n = 5;
    Film* films[n];
    for(int i=0; i<n; i++){
        cout << "Input class name:" << endl;
        string class_name;
        cin >> class_name;
        cin.ignore(); //可以去除输入流中的换行符
        films[i] = read_input(class_name);
        cout << class_name << "--" << endl;
        films[i]->output();
        cout << endl;
    }
}
输入
具体影片的信息，对于不同类型所输入信息是不同的。
Film 依次顺序
Input class name:
Input title:
Input director:
Input time:
Input quality:

DirectoCut类input依次顺序
Input class name:
Input title:
Input director:
Input time:
Input quality:
Input rev_time:
Input changes:

ForeignFilm类input依次顺序
Input class name:
Input title:
Input director:
Input time:
Input quality:
Input language:

输出
输出类中的信息
必须使用的关键字
virtual class
样例输入 Copy
DirectorCut
A Passage To India
David Lean
197
3
180
Cave scene twice as long; more local color
Film
Mean Streets
Martin Scorsese
168
4
Film
The Best Years of Our Lives
William Wyler
172
4
ForeignFilm
Diva
Jean-Jacques Beineix
123
3
French
Film
Orlando
Sally Potter
97
3
样例输出 Copy
Input class name:
Input title:
Input director:
Input time:
Input quality:
Input rev_time:
Input changes:
DirectorCut--
Title: A Passage To India
Director: David Lean
Time: 197 mins
Quality: ***
Revised time: 180 mins
Changes: Cave scene twice as long; more local color

Input class name:
Input title:
Input director:
Input time:
Input quality:
Film--
Title: Mean Streets
Director: Martin Scorsese
Time: 168 mins
Quality: ****

Input class name:
Input title:
Input director:
Input time:
Input quality:
Film--
Title: The Best Years of Our Lives
Director: William Wyler
Time: 172 mins
Quality: ****

Input class name:
Input title:
Input director:
Input time:
Input quality:
Input language:
ForeignFilm--
Title: Diva
Director: Jean-Jacques Beineix
Time: 123 mins
Quality: ***
Language: French

Input class name:
Input title:
Input director:
Input time:
Input quality:
Film--
Title: Orlando
Director: Sally Potter
Time: 97 mins
Quality: ***
提示
input(){
cout << "Input title:" <<endl;
...
}*/

#include <iostream>
#include <string>
using namespace std;
class Film
{
protected:
    string title;
    string director;
    string time;
    string quality;

public:
    void store_title(string t)
    {
        title = t;
    }
    void store_director(string t)
    {
        director = t;
    }
    void store_time(int t)
    {
        time = t;
    }
    void store_quality(int t)
    {
        quality = t;
    }
    virtual void output()
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Time: " << time << " mins\n";
        cout << "Quality: ";
        for (int i = 0; i < quality[0] - '0'; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    virtual void input()
    {
        cout << "Input title:\n";
        getline(cin, title);
        cout << "Input director:\n";
        getline(cin, director);
        cout << "Input time:\n";
        getline(cin, time);
        cout << "Input quality:\n";
        getline(cin, quality);
    }
};
class DirectorCut : public Film
{
    string rev_time;
    string chang;

public:
    void store_rev_time(int t)
    {
        rev_time = t;
    }
    void store_changes(string t)
    {
        chang = t;
    }
    void virtual output()
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Time: " << time << " mins\n";
        cout << "Quality: ";
        for (int i = 0; i < quality[0] - '0'; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Revised time: " << rev_time << " mins\n";
        cout << "Changes: " << chang << endl;
    }
    virtual void input()
    {
        cout << "Input title:\n";
        getline(cin, title);
        cout << "Input director:\n";
        getline(cin, director);
        cout << "Input time:\n";
        getline(cin, time);
        cout << "Input quality:\n";
        getline(cin, quality);
        cout << "Input rev_time:\n";
        getline(cin, rev_time);
        cout << "Input changes:\n";
        getline(cin, chang);
    }
};
class ForeignFilm : public Film
{
    string Language;

public:
    void store_language(string t)
    {
        Language = t;
    }
    void virtual output()
    {
        cout << "Title: " << title << endl;
        cout << "Director: " << director << endl;
        cout << "Time: " << time << " mins\n";
        cout << "Quality: ";
        for (int i = 0; i < quality[0] - '0'; i++)
        {
            cout << "*";
        }
        cout << endl;
        cout << "Language: " << Language << endl;
    }
    virtual void input()
    {
        cout << "Input title:\n";
        getline(cin, title);
        cout << "Input director:\n";
        getline(cin, director);
        cout << "Input time:\n";
        getline(cin, time);
        cout << "Input quality:\n";
        getline(cin, quality);
        cout << "Input language:\n";
        getline(cin, Language);
    }
};
Film *read_input(string name)
{
    if (name == "Film")
    {
        Film *t = new Film;
        t->input();
        return t;
    }
    else if (name == "ForeignFilm")
    {
        ForeignFilm *t = new ForeignFilm;
        t->input();
        return t;
    }
    else
    {
        DirectorCut *t = new DirectorCut;
        t->input();
        return t;
    }
}
int main()
{
    Film *films[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Input class name:" << endl;
        string class_name;
        cin >> class_name;
        cin.ignore(); // 可以去除输入流中的换行符
        films[i] = read_input(class_name);
        cout << class_name << "--" << endl;
        films[i]->output();
        cout << endl;
    }
    system("pause");
}