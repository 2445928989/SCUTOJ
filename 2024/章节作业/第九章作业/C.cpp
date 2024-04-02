/*题目描述
使用第2题中定义的教职工类体系,编写程序,输入某月各种职称教师的工资信息,建立异质链表输出每位教师的工资条，统计当月的总工资、平均工资、最高工资和最低工资。
使用以下main函数测试这个类体系：
int main() {
    vector<teacher*> teachers; // 创建一个存储教职工指针的向量

    // 输入教职工信息
    int numTeachers;
    cout << "请输入教职工人数：";
    cin >> numTeachers;

    for (int i = 0; i < numTeachers; ++i) {
        char name[30];
        int coursetime;
        cout << "请输入教职工姓名和课时：";
        cin >> name >> coursetime;

        int type;
        cout << "请选择职称（1. 教授 2. 副教授 3. 讲师）：";
        cin >> type;

        teacher* t;
        if (type == 1)
            t = new professor(name, coursetime);
        else if (type == 2)
            t = new associateprofessor(name, coursetime);
        else if (type == 3)
            t = new lecturer(name, coursetime);
        else {
            cout << "无效的职称类型！" << endl;
            continue;
        }

        teachers.push_back(t);
    }

    // 输出每位教职工的工资条
    cout << "教职工工资条：" << endl;
    for (auto t : teachers) {
        t->print();
        cout << " 工资：" << t->pay() << endl;
    }

    // 统计当月总工资、平均工资、最高工资和最低工资
    int totalSalary = 0;
    int maxSalary = 0;
    int minSalary = INT_MAX; // 初始化为最大值
    for (auto t : teachers) {
        int salary = t->pay();
        totalSalary += salary;
        maxSalary = max(maxSalary, salary);
        minSalary = min(minSalary, salary);
    }
    double averageSalary = static_cast<double>(totalSalary) / numTeachers;

    // 输出统计结果
    cout << "当月总工资：" << totalSalary << endl;
    cout << "平均工资：" << averageSalary << endl;
    cout << "最高工资：" << maxSalary << endl;
    cout << "最低工资：" << minSalary << endl;

    // 释放内存
    for (auto t : teachers) {
        delete t;
    }

    return 0;
}


输入
一个班的学生总人数
每个学生的分数
必须使用的关键字
class
样例输入 Copy
3
yan 52
3
lu 29
1
ba 62
2
样例输出 Copy
请输入教职工人数：请输入教职工姓名和课时：请选择职称（1. 教授 2. 副教授 3. 讲师）：请输入教职工姓名和课时：请选择职称（1. 教授 2. 副教授 3. 讲师）：请输入教职工姓名和课时：请选择职称（1. 教授 2. 副教授 3. 讲师）：教职工工资条：
讲师：yan 工资：6040
教授：lu 工资：6450
副教授：ba 工资：6860
当月总工资：19350
平均工资：6450
最高工资：6860
最低工资：6040*/
