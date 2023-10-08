#include <iostream>
#include <map>

using namespace std;

map<string, map<string, string>> dataAkun;
int hashFunction(string password) {
    return tolower(password[0]) - 97;
}

void registerAkun() {
    string username, password;
    cout << "Masukkan Username: " << endl;
    cin >> username;
    cout << "Masukkan Password: " << endl;
    cin >> password;

    string hashKey = to_string(hashFunction(password));

    map<string, string> dataDetail;
    dataDetail["username"] = username;

    dataAkun[hashKey] = dataDetail; 
}

void printAkun() {
    cout << endl;
    for (auto i = dataAkun.begin(); i != dataAkun.end(); i++) { 
        cout << "Key: " << i->first << "\t" << "Username: " << i->second["username"] << "\tFullname: " << i->second["fullname"] << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Register Akun" << endl;
        cout << "2. Print Akun" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerAkun();
                break;
            case 2:
                printAkun();
                break;
            case 3:
                cout << "Terima kasih" << endl;
                break;
            default:
                cout << "Invalid." << endl;
        }
    } while (choice != 3);

    return 0;
}
