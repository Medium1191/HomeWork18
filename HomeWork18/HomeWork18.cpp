#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

using namespace std;

class User {
public:
    string _name;
    string _login;
    string _pass;
};

class Message {
public:
    string _text;
    string _sender;
    string _receiver;
};

void save_user(User user) {
    fstream file;
    file.open("user.txt", ios::out);
    if (file.is_open()) {
        file << user._name << endl;
        file << user._login << endl;
        file << user._pass << endl;
        file.close();
        chmod("user.txt", 0600);
    }
}

User load_user() {
    User user;
    fstream file;
    file.open("user.txt", ios::in);
    if (file.is_open()) {
        getline(file, user._name);
        getline(file, user._login);
        getline(file, user._pass);
        file.close();
    }
    return user;
}

void save_message(Message message) {
    fstream file;
    file.open("message.txt", ios::out);
    if (file.is_open()) {
        file << message._text << endl;
        file << message._sender << endl;
        file << message._receiver << endl;
        file.close();
        chmod("message.txt", 0600);
    }
}

Message load_message() {
    Message message;
    fstream file;
    file.open("message.txt", ios::in);
    if (file.is_open()) {
        getline(file, message._text);
        getline(file, message._sender);
        getline(file, message._receiver);
        file.close();
    }
    return message;
}

int main() {
    User user = { "John Doe", "johndoe", "password" };
    save_user(user);

    User loaded_user = load_user();
    cout << loaded_user._name << endl;
    cout << loaded_user._login << endl;
    cout << loaded_user._pass << endl;

    Message message = { "Hello, World!", "johndoe", "janedoe" };
    save_message(message);

    Message loaded_message = load_message();
    cout << loaded_message._text << endl;
    cout << loaded_message._sender << endl;
    cout << loaded_message._receiver << endl;

    return 0;
}