#include "ConsoleApplication.h"
int main() {
	ConsoleApplication& app{ ConsoleApplication::getInstance() };
	app.run();
}