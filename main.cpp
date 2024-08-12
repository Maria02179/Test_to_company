#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class task {
public:
    int di; //�������
    int wi; //������

    task(int t_di, int t_wi) {//�����������
        di = t_di;
        wi = t_wi;
    }
};

bool comparison(const task& a, const task& b) {
    if (a.di == b.di)
        return a.wi > b.wi; // ������ ������� ������
    return a.di < b.di; // ������ ������� �������
};

int count(vector <task> tasks) {
    int total_s = 0; //���.������
    int size;
    bool FLAG=false;
    if (tasks.back().di-1 < tasks.size())
        size = tasks.back().di-1;
    else
        size = tasks.size();
    vector <bool> slots(size, false); //����� �� ������� (false-�����).  ������=����_��

    for (int i = 0; i < tasks.size(); i++) {
        int day = tasks[i].di - 1; 
        if (slots.size() <= day) //����� ��, ��� ������ ���-���� ����� (��� ��� ������ �������� ����)
            day = -20;

        while (day >= 0 && slots[day]) {
            day--;
        }
        if (day >= 0) {
            slots[day] = true; //������ ����
        }
        else {
            if (day != -20)
                total_s += tasks[i].wi; // ���� ��� ���������� ��� �� ��������, �� ��������� ������
        }
    }
    return total_s;
}

int main() {
    int n;
    cin >> n;
    vector <task> tasks; //�������� ������� ������� �����

    for (int i = 0; i < n; i++) {
        int di, wi;
        cin >> di >> wi;
        tasks.emplace_back(di, wi); //���������� ������ � ������
    }

    sort(tasks.begin(), tasks.end(), comparison); //���������� �����

    cout << count(tasks) << endl; //������� �������

    return 0;
}