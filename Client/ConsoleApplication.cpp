#include "ConsoleApplication.h"

ConsoleApplication& ConsoleApplication::getInstance() {
	static ConsoleApplication app;
	return app;
}

void ConsoleApplication::setConnectionProvider(const IConnectionProvider& provider) {
	connector = std::make_unique<IConnectionProvider>(provider);
}

void ConsoleApplication::run() {
	connector->connect();

	std::string name, password;
	std::cout << "Wprowadz nazwe uzytkownika i haslo, by sie zalogowac: ";
	std::cin >> name >> password;

	currentUser = connector->Log(name,password);
	std::cout << "Zalogowano pomyslnie!\n";

	connector->disconnect();
}