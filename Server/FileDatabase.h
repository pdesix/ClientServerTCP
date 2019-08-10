#pragma once
#include "../Shared/dirent.h"
#include "IDataReader.h"
#include "IDataUpdater.h"
#include <fstream>

class FileDatabase : public IDataReader, public IDataUpdater {
public:
	virtual std::vector<Data> readData() override;
	virtual int checkUserData(const std::string& username, const std::string& password) override;
	virtual void updateData(int id, std::string new_text) override;
	virtual void updateData(int id, int new_number) override;

private:
	std::vector<std::string> listFiles(const std::string& directory);
};