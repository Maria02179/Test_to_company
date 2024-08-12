#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class task {
public:
    int di; //дедлайн
    int wi; //стресс

    task(int t_di, int t_wi) {//конструктор
        di = t_di;
        wi = t_wi;
    }
};

bool comparison(const task& a, const task& b) {
    if (a.di == b.di)
        return a.wi > b.wi; // первее больший стресс
    return a.di < b.di; // первее меньший дедлайн
};

int count(vector <task> tasks) {
    int total_s = 0; //общ.стресс
    int size;
    bool FLAG=false;
    if (tasks.back().di-1 < tasks.size())
        size = tasks.back().di-1;
    else
        size = tasks.size();
    vector <bool> slots(size, false); //слоты дд заданий (false-пусты).  Размер=макс_дд

    for (int i = 0; i < tasks.size(); i++) {
        int day = tasks[i].di - 1; 
        if (slots.size() <= day) //ловим дд, кот больше кол-ства задач (для них всегда найдется день)
            day = -20;

        while (day >= 0 && slots[day]) {
            day--;
        }
        if (day >= 0) {
            slots[day] = true; //заняли слот
        }
        else {
            if (day != -20)
                total_s += tasks[i].wi; // если нет свободного дня до дедлайна, то добавляем стресс
        }
    }
    return total_s;
}

int main() {
    int n;
    cin >> n;
    vector <task> tasks; //создание пустого вектора задач

    for (int i = 0; i < n; i++) {
        int di, wi;
        cin >> di >> wi;
        tasks.emplace_back(di, wi); //добавление задачи в вектор
    }

    sort(tasks.begin(), tasks.end(), comparison); //сортировка задач

    cout << count(tasks) << endl; //подсчет стресса

    return 0;
}