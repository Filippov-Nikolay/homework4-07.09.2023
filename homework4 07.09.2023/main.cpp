﻿#include <iostream>
#include "PhoneBook.h"

using namespace std;

int main() {
    setlocale(0, "");
    system("chcp 1251");

    int numberSub = 0;
    int numberDelate = 0;
    int userChoice = 0;
    int key = 0;
    int minMenuItem = 1, maxMenuItem = 7;

    bool flag = false;

    char buff[100];

    char* firstName;
    char* lastName;
    char* surName;

    PhoneBook* subscribers = nullptr;

    // Меню
    // ШАБЛОН МЕНЮ
    cout << "Меню: " << endl;
    cout << "1. Добавить абонентов" << endl;
    cout << "2. Добавить абонента" << endl;
    cout << "3. Поиск абонента по ФИО" << endl;
    cout << "4. Показать всех абонентов" << endl;
    cout << "5. Сохранить абонентов в файл" << endl;
    cout << "6. Загрузить абонентов из файла" << endl;
    cout << "7. Удалить абонента" << endl;
    cout << "0. Выход" << endl;
   
    do {
        cout << "Ввод: ";
        cin >> userChoice;

        if (userChoice == 0) {
            cout << "До свидания!" << endl;
            break;
        }
        else if (userChoice < minMenuItem || userChoice > maxMenuItem) {
            cout << "Вы ввели неверный пункт меню!" << endl << endl;
        }
        else {
            if (userChoice == 1) {
                cout << "Введите кол-во абонентов: ";
                cin >> numberSub;

                subscribers = new PhoneBook[numberSub];

                for (int i = 0; i < numberSub; i++) {
                    subscribers[i].Input();
                    cout << endl;
                }

                flag = true;
            }
            else if (userChoice == 2) {
                numberSub = subscribers->ResizeArray(subscribers, numberSub);
                for (int i = numberSub - 1; i < numberSub; i++) {
                    subscribers[i].Input();
                    cout << endl;
                }

                flag = true;
            }

            if (!flag)
                cout << "Выберите сначало 1 или 2 пункт!" << endl << endl;
            else {
                if (userChoice == 3) {
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
                }
                else if (userChoice == 4) {
                    if (numberSub == 0) {
                        cout << "Нет абонентов для вывода!" << endl << endl;
                    }
                    else {
                        for (int i = 0; i < numberSub; i++) {
                            subscribers[i].Print();
                            cout << endl;
                        }
                    }
                }
                else if (userChoice == 5) {
                    subscribers->SaveToFile(subscribers, numberSub);
                    cout << "Данные записаны в файл" << endl << endl;
                }
                else if (userChoice == 6) {
                    subscribers->LoadFromFile();
                }
                else if (userChoice == 7) {
                    cout << "Кол-во абонентов: " << numberSub << endl;

                    do {
                        cout << "Введите абонента которого нужно удалить: ";
                        cin >> numberDelate;

                        if (numberDelate > numberSub || numberDelate <= 0)
                            cout << "Вы ввели не допустимый диапозон!" << endl << endl;                   
                    } while (numberDelate > numberSub || numberDelate <= 0);
                    numberDelate--;

                    numberSub = subscribers->DelateSubscriber(subscribers, numberSub, numberDelate);
                    cout << "Абонент удалён!" << endl << endl;
                }
            }
        }
    } while (userChoice != 0 || userChoice < minMenuItem || userChoice > maxMenuItem);

    return 0;
}
