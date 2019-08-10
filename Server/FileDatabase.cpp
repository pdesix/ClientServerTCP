#include "FileDatabase.h"

std::vector<Data> FileDatabase::readData() {
	std::vector<Data> dataList;
	std::vector<std::string> fileList{ listFiles("data/data") };
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

int FileDatabase::checkUserData(const std::string& username, const std::string& password) {
	return 1;
}

void FileDatabase::updateData(int id, std::string new_text) {

}

void FileDatabase::updateData(int id, int new_integer) {

}

std::vector<std::string> FileDatabase::listFiles(const std::string& directory)
{
	std::vector<std::string> list;

	DIR* d;
	struct dirent* dir;
	d = opendir(directory.c_str());

	int j = 0;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
			if (std::string{ dir->d_name }.find("dat") != std::string::npos)
				list.push_back(directory + dir->d_name);
		closedir(d);
	}

	return list;
}