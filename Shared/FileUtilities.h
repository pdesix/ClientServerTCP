#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "dirent.h"

namespace FileUtilities {
	std::vector<std::string> listFiles(const std::string& directory) {
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
}