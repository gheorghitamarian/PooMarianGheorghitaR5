#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

enum class ContactType {
    FRIEND,
    ACQUAINTANCE,
    COLLEAGUE
};

class Contact {
protected:
    std::string name;
public:
    Contact(const std::string& n) : name(n) {}
    virtual ~Contact() = default;

    virtual ContactType getType() const = 0;
    std::string getName() const { return name; }

    virtual void display() const = 0;
};

class Friend : public Contact {
private:
    std::string dob;
    std::string phone;
    std::string address;
public:
    Friend(const std::string& n, const std::string& d, const std::string& p, const std::string& a)
        : Contact(n), dob(d), phone(p), address(a) {
    }

    ContactType getType() const override {
        return ContactType::FRIEND;
    }

    void display() const override {
        std::cout << name << " | " << dob << " | " << phone << " | " << address << "\n";
    }
};

class Acquaintance : public Contact {
private:
    std::string phone;
public:
    Acquaintance(const std::string& n, const std::string& p)
        : Contact(n), phone(p) {
    }

    ContactType getType() const override {
        return ContactType::ACQUAINTANCE;
    }

    void display() const override {
        std::cout << name << " | " << phone << "\n";
    }
};

class Colleague : public Contact {
private:
    std::string phone;
    std::string company;
    std::string address;
public:
    Colleague(const std::string& n, const std::string& p, const std::string& c, const std::string& a)
        : Contact(n), phone(p), company(c), address(a) {
    }

    ContactType getType() const override {
        return ContactType::COLLEAGUE;
    }

    void display() const override {
        std::cout << name << " | " << phone << " | " << company << " | " << address << "\n";
    }
};

class AddressBook {
private:
    std::vector<std::shared_ptr<Contact>> contacts;
public:
    void addContact(std::shared_ptr<Contact> contact) {
        contacts.push_back(contact);
    }

    std::shared_ptr<Contact> searchByName(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact->getName() == name) {
                return contact;
            }
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<Friend>> getFriends() const {
        std::vector<std::shared_ptr<Friend>> friends;
        for (const auto& contact : contacts) {
            if (contact->getType() == ContactType::FRIEND) {
                friends.push_back(std::dynamic_pointer_cast<Friend>(contact));
            }
        }
        return friends;
    }

    void deleteByName(const std::string& name) {
        contacts.erase(
            std::remove_if(contacts.begin(), contacts.end(),
                [&name](const std::shared_ptr<Contact>& contact) {
                    return contact->getName() == name;
                }),
            contacts.end()
        );
    }

    void displayAll() const {
        for (const auto& contact : contacts) {
            contact->display();
        }
    }
};

int main() {
    AddressBook myAddressBook;

    myAddressBook.addContact(std::make_shared<Friend>("Alice Smith", "1995-05-12", "555-0101", "123 Maple St"));
    myAddressBook.addContact(std::make_shared<Acquaintance>("Bob Jones", "555-0202"));
    myAddressBook.addContact(std::make_shared<Colleague>("Charlie Brown", "555-0303", "Tech Innovations Inc.", "456 Silicon Blvd"));
    myAddressBook.addContact(std::make_shared<Friend>("Diana Prince", "1990-03-22", "555-0404", "789 Amazon Way"));

    auto searchResult = myAddressBook.searchByName("Bob Jones");
    if (searchResult) {
        searchResult->display();
    }

    std::vector<std::shared_ptr<Friend>> friendsList = myAddressBook.getFriends();
    for (const auto& f : friendsList) {
        f->display();
    }

    myAddressBook.deleteByName("Alice Smith");

    return 0;
}