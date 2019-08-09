#include "ConsoleApplication.h"

ConsoleApplication& ConsoleApplication::getInstance() {
	static ConsoleApplication app;
	return app;
}

void ConsoleApplication::run() {

}