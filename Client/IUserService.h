#pragma once

class IUserService {
public:
	virtual void showMenu(int submenu_level = 0, int submenu_id = -1) = 0;
	virtual void handleInput(int option, int submenu_level = 0, int submenu_id = -1) = 0;
};