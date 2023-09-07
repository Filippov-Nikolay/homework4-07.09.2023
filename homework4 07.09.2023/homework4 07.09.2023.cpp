#include <iostream>

using namespace std;

class PhoneBook {
    char* firstName;
    char* lastName;
    char* surName;

    char* homePhone;
    char* workPhone;

public:
    // Конструктор
    PhoneBook() {
        cout << "Constructor by def." << endl;

        firstName = nullptr;
        lastName = nullptr;
        surName = nullptr;

        homePhone = nullptr;
        workPhone = nullptr;
    }
    PhoneBook(const char* fn, const char* ln, const char* sn, const char* hp, const char* wp) {
        // fn - firstName, ln - lastName, sn - surName, hp - homePhone, wp - workPhone
   
        cout << "Constructor 5 params" << endl;

        firstName = new char[strlen(fn) + 1];
        strcpy_s(firstName, strlen(fn) + 1, fn);

        lastName = new char[strlen(ln) + 1];
        strcpy_s(lastName, strlen(ln) + 1, ln);

        surName = new char[strlen(sn) + 1];
        strcpy_s(surName, strlen(sn) + 1, sn);

        homePhone = new char[strlen(hp) + 1];
        strcpy_s(homePhone, strlen(hp) + 1, hp);

        workPhone = new char[strlen(wp) + 1];
        strcpy_s(workPhone, strlen(wp) + 1, wp);
    }

    void Input() {
        char buff[100];

        // Имя
        cout << "Введите имя: ";
        cin >> buff;

        if (firstName != nullptr) {
            cout << "Delate firstName -> " << firstName << endl << endl;
            delete[] firstName;
        }

        firstName = new char[strlen(buff) + 1];
        strcpy_s(firstName, strlen(buff) + 1, buff);


        // Фамилия
        cout << "Введите фамилию: ";
        cin >> buff;

        if (lastName != nullptr) {
            cout << "Delate lastName -> " << lastName << endl << endl;
            delete[] lastName;
        }

        lastName = new char[strlen(buff) + 1];
        strcpy_s(lastName, strlen(buff) + 1, buff);


        // Отчество
        cout << "Введите отчество: ";
        cin >> buff;

        if (surName != nullptr) {
            cout << "Delate surName -> " << surName << endl << endl;
            delete[] surName;
        }

        surName = new char[strlen(buff) + 1];
        strcpy_s(surName, strlen(buff) + 1, buff);


        // Домашний номер телефона
        cout << "Введите домашний номер телефона: ";
        cin >> buff;

        if (homePhone != nullptr) {
            cout << "Delate homePhone -> " << homePhone << endl << endl;
            delete[] homePhone;
        }

        homePhone = new char[strlen(buff) + 1];
        strcpy_s(homePhone, strlen(buff) + 1, buff);


        // Рабочий номер телефона
        cout << "Введите рабочий номер телефона: ";
        cin >> buff;

        if (workPhone != nullptr) {
            cout << "Delate workPhone -> " << workPhone << endl << endl;
            delete[] workPhone;
        }

        workPhone = new char[strlen(buff) + 1];
        strcpy_s(workPhone, strlen(buff) + 1, buff);
    }
    void Print() {
        cout << "Фамилия: " << lastName << endl;
        cout << "Имя: " << firstName<< endl;
        cout << "Отчество: " << surName << endl;

        cout << "Домашний номер тф.: " << homePhone << endl;
        cout << "Раб. номер тф.: " << workPhone << endl;
    }

    // Деструктор
    ~PhoneBook() {
        cout << "Destructor\n";

        delete[] lastName;
        delete[] firstName;
        delete[] surName;

        delete[] homePhone;
        delete[] workPhone;
    }
};

int main() {
    setlocale(0, "");
    system("chcp 1251");
    
    PhoneBook subscriber1("Nikolay", "Filippov", "Olegovich", "+38 098 056 65 970", "+38 09 05 970");
    subscriber1.Print();

    subscriber1.Input();
    cout << endl;
    subscriber1.Print();

    return 0;
}
