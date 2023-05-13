#include "files.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Chat chat;
	chat.readAllUsersFromFile();
	chat.readAllMessagesFromFile();

	char choice;
	cout << "Выберите,что вы хотите сделать:\n1 - добавить пользователя\n2 -отправить сообщение\n3 -посмотреть всех пользователей\n4 -посмотреть все сообщения\nq -выйти из программы" << endl;
	cin >> choice;

	while (choice != 'q')
	{
		switch (choice)
		{
		case '1':
		{
			cinClear();
			string name, login, password;

			cout << "Введите имя: ";
			getline(cin, name);

			cout << "Введите логин: ";
			getline(cin, login);

			cout << "Введите пароль: ";
			getline(cin, password);

			chat.addUser(name, login, password);

			break;
		}
		case '2':
		{
			cinClear();
			string text, sender, recepient;

			cout << "Enter text: ";
			getline(cin, text);

			cout << "Enter your name: ";
			getline(cin, sender);

			cout << "Enter receiver: ";
			getline(cin, recepient);

			chat.addMessage(text, sender, recepient);

			break;
		}
		case '3':
		{
			cinClear();
			chat.printAllUsers();

			break;
		}
		case '4':
		{
			cinClear();
			chat.printAllMessages();

			break;
		}
		}
		cout << "Выберите,что вы хотите сделать:\n1 - добавить пользователя\n2 -отправить сообщение\n3 -посмотреть всех пользователей\n4 -посмотреть все сообщения\nq -выйти из программы" << endl;
		cin >> choice;
	}

	chat.sendAllUsersToFile();
	chat.sendAllMessagesToFile();

	return 0;
}