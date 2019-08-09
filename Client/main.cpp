#include "ConsoleApplication.h"
#include "TCPConnectionProvider.h"

int main() {
	TCPConnectionProvider tcp;

	ConsoleApplication& app{ ConsoleApplication::getInstance() };
	app.setConnectionProvider(tcp);
	app.run();
}