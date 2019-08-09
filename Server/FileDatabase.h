#pragma once
#include "IDataReader.h"
#include "IDataUpdater.h"
#include "../Shared/FileUtilities.h"

class FileDatabase : public IDataReader, public IDataUpdater {
public:
	virtual std::vector<Data> readData() override;
	virtual bool checkData(const std::string& username, const std::string& password) override;
	virtual void updateData(int id, std::string new_text) override;
	virtual void updateData(int id, int new_number) override;

private:
};