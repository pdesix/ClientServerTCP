#include "ConsoleApplication.h"

ConsoleApplication& ConsoleApplication::getInstance() {
	static ConsoleApplication app;
	return app;
}

void ConsoleApplication::setConnectionProvider(std::shared_ptr<IConnectionProvider>& provider) {
	connector = provider;
}

void ConsoleApplication::run() {
	connector->establishConnection();

	std::string name, password;
	std::cout << "Wprowadz nazwe uzytkownika i haslo, by sie zalogowac: ";
	std::cin >> name >> password;

	currentUser = connector->log(name,password);
	std::cout << "Zalogowano pomyslnie!\n";

	currentUser->getServicer()->showMenu();
	//currentUser->getServicer()->handleInput(1);
}