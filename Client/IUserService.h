#pragma once

class IUserService {
public:
	virtual void ShowMenu(int submenu_level = 0, int submenu_id = -1) = 0;
	virtual void HandleInput(int option, int submenu_level = 0, int submenu_id = -1) = 0;
};