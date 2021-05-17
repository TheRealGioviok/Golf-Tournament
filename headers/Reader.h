#pragma once
#include <fstream>
#include "types.h"
#include "list.h"
#include <string>
#include <iostream>
namespace golf {
	class Reader {
		static void populateList(List<Data>* l, std::string filename) {
			std::ifstream file;
			file.open(filename);
			std::string read;
			while (!file.eof()) {
				Data d;
				
				std::getline(file, read);
				
				size_t _sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					continue;
				}
				d.surname = read.substr(0,_sur);
				read= read.substr(_sur+1,read.size()-_sur-1);


				_sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					continue;
				}
				d.name = read.substr(0, _sur);
				read = read.substr(_sur + 1, read.size() - _sur - 1);
				
				_sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					continue;
				}
				d.club= read.substr(0, _sur);
				read = read.substr(_sur + 1, read.size() - _sur - 1);
				
				_sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					continue;
				}
				d.points = std::stod(read.substr(0, _sur));
				read = read.substr(_sur + 1, read.size() - _sur - 1);

				d.birthYear = std::stoi(read);
				
				
				l->push_back(d);
			}
			file.close();
		}
	};
}
