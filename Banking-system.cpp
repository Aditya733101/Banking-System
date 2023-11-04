#include <iostream>
#include <string>
using namespace std;

class Bank {
private:
    int total;
    string id;

    struct Person {
        string name, ID, address;
        int contact, cash;
    } person[100];

public:
    Bank() {
        total = 0;
    }

    void choice();
    void perData();
    void show();
    void update();
    void search();
    void transactions();
    void del();
};

int main() {
    Bank b;
    b.choice();
    return 0;
}

void Bank::choice() {
    char ch;
    while (true) {
        cout << "\n\nPRESS..!!" << endl;
        cout << "1. Create new account" << endl;
        cout << "2. View customers list" << endl;
        cout << "3. Update information of an existing account" << endl;
        cout << "4. Check the details of an existing account" << endl;
        cout << "5. For transactions" << endl;
        cout << "6. Remove an existing account" << endl;
        cout << "7. Exit" << endl;
        cin >> ch;

        switch (ch) {
            case '1':
                perData();
                break;
            case '2':
                if (total == 0) {
                    cout << "No data is entered" << endl;
                } else {
                    show();
                }
                break;
            case '3':
                if (total == 0)
                    cout << "No data is entered" << endl;
                else
                    update();
                break;
            case '4':
                if (total == 0)
                    cout << "No data is entered" << endl;
                else
                    search();
                break;
            case '5':
                if (total == 0)
                    cout << "No data is entered" << endl;
                else
                    transactions();
                break;
            case '6':
                if (total == 0)
                    cout << "No data is entered" << endl;
                else
                    del();
                break;
            case '7':
                exit(0);
                break;
            default:
                cout << "Invalid input" << endl;
                break;
        }
    }
}

void Bank::perData() {
    cout << "Enter data of person " << total + 1 << endl;
    cout << "Enter name: ";
    cin >> person[total].name;
    cout << "ID: ";
    cin >> person[total].ID;
    cout << "Address: ";
    cin >> person[total].address;
    cout << "Contact: ";
    cin >> person[total].contact;
    cout << "Total Cash: ";
    cin >> person[total].cash;
    total++;
}

void Bank::show() {
    for (int i = 0; i < total; i++) {
        cout << "Data of person " << i + 1 << endl;
        cout << "Name: " << person[i].name << endl;
        cout << "ID: " << person[i].ID << endl;
        cout << "Address: " << person[i].address << endl;
        cout << "Contact: " << person[i].contact << endl;
        cout << "Cash: " << person[i].cash << endl;
    }
}

void Bank::update() {
    cout << "Enter ID of the person whose data you want to update" << endl;
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Previous data" << endl;
            cout << "Data of person " << i + 1 << endl;
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            cout << "\nEnter new data" << endl;
            cout << "Enter name: ";
            cin >> person[i].name;
            cout << "ID: ";
            cin >> person[i].ID;
            cout << "Address: ";
            cin >> person[i].address;
            cout << "Contact: ";
            cin >> person[i].contact;
            cout << "Total Cash: ";
            cin >> person[i].cash;
            break;
        }
        if (i == total - 1) {
            cout << "No such record found" << endl;
        }
    }
}

void Bank::search() {
    cout << "Enter ID of the person whose data you want to search" << endl;
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Name: " << person[i].name << endl;
            cout << "ID: " << person[i].ID << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "Cash: " << person[i].cash << endl;
            break;
        }
        if (i == total - 1) {
            cout << "No such record found" << endl;
        }
    }
}

void Bank::transactions() {
    int cash;
    char ch;

    cout << "Enter ID of the person for the transaction" << endl;
    cin >> id;

    for (int i = 0; i < total; i++) {
        if (id == person[i].ID) {
            cout << "Name: " << person[i].name << endl;
            cout << "Address: " << person[i].address << endl;
            cout << "Contact: " << person[i].contact << endl;
            cout << "\nExisting Cash: " << person[i].cash << endl;
            cout << "Press 1 to deposit" << endl;
            cout << "Press 2 to withdraw" << endl;
            cin >> ch;

            switch (ch) {
                case '1':
                    cout << "How much cash do you want to deposit?" << endl;
                    cin >> cash;
                    person[i].cash += cash;
                    cout << "Your new cash is: " << person[i].cash << endl;
                    break;
                case '2':
                    while (true) {
                        cout << "How much cash do you want to withdraw?" << endl;
                        cin >> cash;
                        if (cash > person[i].cash) {
                            cout << "Your existing cash is just: " << person[i].cash << endl;
                        } else {
                            person[i].cash -= cash;
                            cout << "Your new cash is: " << person[i].cash << endl;
                            break;
                        }
                    }
                    break;
                default:
                    cout << "Invalid input" << endl;
                    break;
            }
            break;
        }
        if (i == total - 1) {
            cout << "No such record found" << endl;
        }
    }
}

void Bank::del() {
    char ch;
    cout << "Press 1 to remove a specific record" << endl;
    cout << "Press 2 to remove all records" << endl;
    cin >> ch;

    switch (ch) {
        case '1':
            cout << "Enter ID of the person whose data you want to remove" << endl;
            cin >> id;

            for (int i = 0; i < total; i++) {
                if (id == person[i].ID) {
                    for (int j = i; j < total - 1; j++) {
                        person[j] = person[j + 1];
                    }
                    total--;
                    cout << "The required data is deleted" << endl;
                    break;
                }
            }
            if (total == 0) {
                cout << "No such record found" << endl;
            }
            break;

        case '2':
            total = 0;
            cout << "All records are deleted" << endl;
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
    }
}
