#include <string>
#include <iostream>
using namespace std;

class Person {
public:
    string first_name;
    string last_name;
    string street_address;
    string city;
    int zip_code;

    void print_info() {
        cout << "first name: " << first_name << "\n";
        cout << "last name: " << last_name << "\n";
        cout << "address: " << street_address << "\n";
        cout << "city: " << city << "\n";
        cout << "zip code: " << zip_code << endl;
    }
};

int main() {
    Person person;

    person.first_name = "joe";
    person.last_name = "smith";
    person.street_address = "123 street, Austin, Texas";
    person.city = "Austin";
    person.zip_code = 123123;

    person.print_info();

    return 0;
}