#include <iostream>
#include "PhoneBook.h"

using namespace std;

int main() {
    setlocale(0, "");
    system("chcp 1251");

    int numberSub = 1;

    PhoneBook* subscribers = new PhoneBook[numberSub];

    subscribers[0].Input();

    numberSub = subscribers->ResizeArray(subscribers, numberSub);

    subscribers[1].Input();
    
    cout << endl << endl;

    subscribers[0].Print();
    subscribers[1].Print();


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
