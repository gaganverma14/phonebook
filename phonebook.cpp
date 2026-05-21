#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

class PhoneBook {
private:
    vector<Contact> contacts;

public:

    void loadFromFile() {
        ifstream file("contacts.txt");

        if (!file.is_open()) {
            return;
        }

        Contact c;

        while (getline(file, c.name)) {
            getline(file, c.phone);
            getline(file, c.email);

            contacts.push_back(c);
        }

        file.close();
    }

    void saveToFile() {
        ofstream file("contacts.txt");

        for (auto &c : contacts) {
            file << c.name << endl;
            file << c.phone << endl;
            file << c.email << endl;
        }

        file.close();
    }

    void addContact() {
        Contact c;

        cin.ignore();

        cout << "\nEnter Name: ";
        getline(cin, c.name);

        cout << "Enter Phone: ";
        getline(cin, c.phone);

        cout << "Enter Email: ";
        getline(cin, c.email);

        contacts.push_back(c);

        cout << "\nContact Added Successfully.\n";
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "\nNo Contacts Found.\n";
            return;
        }

        cout << "\n===== CONTACT LIST =====\n";

        for (int i = 0; i < contacts.size(); i++) {
            cout << "\nContact " << i + 1 << endl;
            cout << "Name  : " << contacts[i].name << endl;
            cout << "Phone : " << contacts[i].phone << endl;
            cout << "Email : " << contacts[i].email << endl;
        }
    }

    void searchContact() {
        if (contacts.empty()) {
            cout << "\nNo Contacts Available.\n";
            return;
        }

        cin.ignore();

        string keyword;

        cout << "\nEnter Name or Phone to Search: ";
        getline(cin, keyword);

        bool found = false;

        for (auto &c : contacts) {

            if (c.name == keyword || c.phone == keyword) {

                cout << "\nContact Found\n";
                cout << "Name  : " << c.name << endl;
                cout << "Phone : " << c.phone << endl;
                cout << "Email : " << c.email << endl;

                found = true;
            }
        }

        if (!found) {
            cout << "\nContact Not Found.\n";
        }
    }

    void deleteContact() {
        if (contacts.empty()) {
            cout << "\nNo Contacts Available.\n";
            return;
        }

        cin.ignore();

        string name;

        cout << "\nEnter Name to Delete: ";
        getline(cin, name);

        for (int i = 0; i < contacts.size(); i++) {

            if (contacts[i].name == name) {

                contacts.erase(contacts.begin() + i);

                cout << "\nContact Deleted Successfully.\n";
                return;
            }
        }

        cout << "\nContact Not Found.\n";
    }

    void editContact() {
        if (contacts.empty()) {
            cout << "\nNo Contacts Available.\n";
            return;
        }

        cin.ignore();

        string name;

        cout << "\nEnter Name to Edit: ";
        getline(cin, name);

        for (auto &c : contacts) {

            if (c.name == name) {

                cout << "\nEnter New Name: ";
                getline(cin, c.name);

                cout << "Enter New Phone: ";
                getline(cin, c.phone);

                cout << "Enter New Email: ";
                getline(cin, c.email);

                cout << "\nContact Updated Successfully.\n";

                return;
            }
        }

        cout << "\nContact Not Found.\n";
    }

    void bubbleSort() {

        int n = contacts.size();

        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (contacts[j].name > contacts[j + 1].name) {

                    swap(contacts[j], contacts[j + 1]);
                }
            }
        }

        cout << "\nContacts Sorted Successfully.\n";
    }
};

int main() {

    PhoneBook pb;

    pb.loadFromFile();

    int choice;

    do {

        cout << "\n========== PHONEBOOK MENU ==========\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Sort Contacts\n";
        cout << "7. Save Contacts\n";
        cout << "8. Exit\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            pb.addContact();
            break;

        case 2:
            pb.displayContacts();
            break;

        case 3:
            pb.searchContact();
            break;

        case 4:
            pb.editContact();
            break;

        case 5:
            pb.deleteContact();
            break;

        case 6:
            pb.bubbleSort();
            break;

        case 7:
            pb.saveToFile();
            cout << "\nContacts Saved Successfully.\n";
            break;

        case 8:
            pb.saveToFile();
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 8);

    return 0;
}
