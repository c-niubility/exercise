#include <cstring>
#include <iostream>

using namespace std;
class Employee 
{
public:
    Employee(const char* name, const char* id) 
    {
        strcpy_s(Name, name);
        strcpy_s(Id, id);
    }
    char* getName() { return Name; }
    char* getId() { return Id; }
    void display() { cout << Name << "\t" << Id << endl; }
     
private:
    char Name[20];
    char Id[20];
};

class Manager : public Employee 
{
public:
    Manager(const char* name, const char* id, int week) : Employee(name, id) 
    {
        WeeklySalary = week * 1000;
    }
    void display() 
    {
        cout << "����" << getName() << "\t" << getId() << "\t" << WeeklySalary
            << endl;
    }

private:
    int WeeklySalary;
};

class SaleWorker : public Employee {
public:
    SaleWorker(const char* name, const char* id, int profit, int x)
        : Employee(name, id) {
        workerMoney = baseMoney + x * 0.05 * profit;
    }
    void display() {
        cout << "����Ա��" << getName() << "\t" << getId() << "\t" << workerMoney
            << endl;
    }

private:
    float baseMoney = 800.0;
    float workerMoney;
};
class HourWorker : public Employee {
public:
    HourWorker(const char* name, const char* id, int h) : Employee(name, id) {
        TotalMoney = h * hourMoney;
    }
    void display() {
        cout << "Сʱ����" << getName() << "\t" << getId() << "\t" << TotalMoney
            << endl;
    }

private:
    float hourMoney = 100.0;
    float TotalMoney;
};

int main(int argc, char const* argv[]) {
    cout << "�����빤���ܣ�";
    int week;
    cin >> week;
    Manager m("С��", "1", week);
    m.display();
    cout << "��������������";
    int profit;
    cin >> profit;
    cout << "���������ۼ�����";
    int x;
    cin >> x;
    SaleWorker s("С��", "2", profit, x);
    s.display();
    cout << "�����빤��Сʱ��";
    int hour;
    cin >> hour;
    HourWorker h("С��", "3", hour);
    h.display();

    return 0;
}