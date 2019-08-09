#include "FileDatabase.h"

std::vector<Data> FileDatabase::readData() {
	std::vector<Data> dataList;
	std::vector<std::string> fileList{ FileUtilities::listFiles("data/data") };
	std::fstream currentFile;
	for (const std::string& fileName : fileList) {
		int id, integer;
		std::string text;
		currentFile.open(fileName, std::ios::in);
		currentFile >> id >> integer;
		std::getline(currentFile, text);
		dataList.push_back(Data(id, integer, text));
	}
	return dataList;
}

int FileDatabase::checkData(const std::string& username, const std::string& password) {
	return 1;
}

void FileDatabase::updateData(int id, std::string new_text) {

}

void FileDatabase::updateData(int id, int new_integer) {

}