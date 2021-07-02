#include "FileSystem.h"

void FileSystem::CreateFile() {
	std::fstream my_file;
	my_file.open("my_test_file.txt", std::ios::out);

	if (!my_file) {
		std::cout << "FILE: my_test_file.txt CANNOT BE CREATED" << std::endl;
		return;
	}

	my_file << "YAS";

	my_file.close();
}