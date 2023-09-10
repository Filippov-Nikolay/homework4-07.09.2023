#include <iostream>
#include "PhoneBook.h"

using namespace std;

int main() {
    setlocale(0, "");
    system("chcp 1251");

    int numberSub = 2;
    int numberDelate = 0;
    int key = 0;

    char buff[100];

    char* firstName;
    char* lastName;
    char* surName;

    PhoneBook* subscribers = new PhoneBook[numberSub];

    for (int i = 0; i < numberSub; i++)
        subscribers[i].Input();

    cout << "Поиск по ФИО: " << endl;
    cout << "Введите фамилию: ";
    cin >> buff;
    lastName = new char[strlen(buff) + 1];
    strcpy_s(lastName, strlen(buff) + 1, buff);

    cout << "Введите имя: ";
    cin >> buff;
    firstName = new char[strlen(buff) + 1];
    strcpy_s(firstName, strlen(buff) + 1, buff);

    cout << "Введите отчество: ";
    cin >> buff;
    surName = new char[strlen(buff) + 1];
    strcpy_s(surName, strlen(buff) + 1, buff);

    key = subscribers->SearchByFullname(subscribers, numberSub, firstName, lastName, surName);

    cout << "KEY: " << key << endl;

    if (key == -1)
        cout << "Ключ не найден!" << endl;
    else 
        subscribers[key].Print();

    // Меню
    // ШАБЛОН МЕНЮ
    cout << "Меню: " << endl;
    cout << "Добавить абонента" << endl;
    cout << "Удалить абонента" << endl;
    cout << "Поиск абонента по ФИО" << endl;
    cout << "Показать всех абонентов" << endl;
    cout << "Сохранить абонентов в файл" << endl;
    cout << "Загрузить абонентов из файла" << endl;
    cout << "Ввод: ";
}
