#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace fs = filesystem;
class Chat
{
private:
	struct User
	{
		string _name;
		string _login;
		string _password;

		User() = default;
		User(string name, string login, string pass) : _name(name), _login(login), _password(pass)
		{

		}
		~User()
		{
			_name.clear();
			_login.clear();
			_password.clear();
		}

		friend ostream& operator << (ostream& os, const User& us)
		{
			os << us._name << '\n' << us._login << '\n' << us._password << endl;

			return os;
		}
	};
	struct Message
	{
		string _text;
		string _sender;
		string _recipient;

		Message() = default;
		Message(string text, string sender, string recipient) : _text(text), _sender(sender), _recipient(recipient)
		{

		}
		~Message()
		{
			_text.clear();
			_sender.clear();
			_recipient.clear();
		}

		friend ostream& operator << (ostream& os, const Message& msg)
		{
			os << msg._text << '\n' << msg._sender << '\n' << msg._recipient << endl;

			return os;
		}
	};
	vector<User> users;
	vector<Message> messages;

	void PrintAllInternalUserData(const User& curr);
	void PrintOutAllMessagesInside(const Message& msg);

public:
	Chat() = default;
	~Chat();
	void addUser(const string& name, const string& login, const string& pass);
	void addMessage(const string& text, const string& sender, const string& recipient);
	void sendAllUsersToFile();
	void readAllUsersFromFile();
	void printAllUsers();
	void sendAllMessagesToFile();
	void readAllMessagesFromFile();
	void printAllMessages();
};
void cinClear();