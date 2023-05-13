#include "files.h"

using namespace std;


Chat::~Chat()
{
	users.clear();
	users.shrink_to_fit();
	messages.clear();
	messages.shrink_to_fit();
}

void Chat::addUser(const string& name, const string& login, const string& pass)
{
	User newUser;
	newUser._name = name; newUser._login = login; newUser._password = pass;
	users.push_back(newUser);
}

void Chat::addMessage(const string& text, const string& sender, const string& receiver)
{
	Message newMessage;
	newMessage._text = text; newMessage._sender = sender; newMessage._recipient = receiver;
	messages.push_back(newMessage);
}
void Chat::PrintAllInternalUserData(const User& curr)
{
	cout << "Name: " << curr._name << '\n' << "Login: " << curr._login << '\n' << "Password: " << curr._password << '\n' << endl;
}

void Chat::PrintOutAllMessagesInside(const Message& msg)
{
	cout << "Message: " << msg._text << '\n' << "From: " << msg._sender << '\n' << "To: " << msg._recipient << '\n' << endl;
}
void Chat::printAllUsers()
{
	for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
	{
		PrintAllInternalUserData(*it);
	}
}
void Chat::printAllMessages()
{
	for (vector<Message>::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		PrintOutAllMessagesInside(*it);
	}
}

void cinClear()
{
	cin.clear();
	cin.ignore(1, '\n');
}
void Chat::sendAllUsersToFile()
{
	ofstream user_file("users.txt", ios::out | ios::binary);

	fs::permissions("users.txt", fs::perms::all, fs::perm_options::remove);
	fs::permissions("users.txt", fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::add);

	if (user_file.is_open())
	{
		for (vector<User>::iterator it = users.begin(); it != users.end(); ++it)
		{
			user_file << *it;
		}
	}
	else
	{
	}
	user_file.close();
}

void Chat::readAllUsersFromFile()
{
	ifstream user_file("users.txt", ios::in | ios::binary);

	if (user_file.is_open())
	{
		int count = 1;
		string name, login, password;
		while (!user_file.eof())
		{
			if (count == 1)
			{
				getline(user_file, name);
				++count;
			}
			else if (count == 2)
			{
				getline(user_file, login);
				++count;
			}
			else
			{
				getline(user_file, password);
				this->addUser(name, login, password);
				name.clear();
				login.clear();
				password.clear();
				count = 1;
			}
		}
	}
	else
	{
	}
	user_file.close();
}

void Chat::sendAllMessagesToFile()
{
	ofstream message_file("messages.txt", ios::out | ios::binary);

	fs::permissions("messages.txt", fs::perms::all, fs::perm_options::remove);
	fs::permissions("messages.txt", fs::perms::owner_read | fs::perms::owner_write, fs::perm_options::add);

	if (message_file.is_open())
	{
		for (vector<Message>::iterator it = messages.begin(); it != messages.end(); ++it)
		{
			message_file << *it;
		}
	}
	message_file.close();
}

void Chat::readAllMessagesFromFile()
{
	ifstream message_file("messages.txt", ios::in | ios::binary);

	if (message_file.is_open())
	{
		int count = 1;
		string text, sender, recipient;
		while (!message_file.eof())
		{
			if (count == 1)
			{
				getline(message_file, text);
				++count;
			}
			else if (count == 2)
			{
				getline(message_file, sender);
				++count;
			}
			else
			{
				getline(message_file, recipient);
				this->addMessage(text, sender, recipient);
				text.clear();
				sender.clear();
				recipient.clear();
				count = 1;
			}
		}
	}
	message_file.close();
}
