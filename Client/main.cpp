#include "ConsoleApplication.h"
#include "TCPConnectionProvider.h"

int main() {
	std::shared_ptr<IConnectionProvider> tcp(std::make_shared<TCPConnectionProvider>());

	ConsoleApplication& app{ ConsoleApplication::getInstance() };
	app.setConnectionProvider(tcp);
	app.run();
}