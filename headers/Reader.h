#pragma once
#include <fstream>
#include "types.h"
#include "list.h"
#include "GolfList.h"
#include <string>
#include <iostream>
namespace golf {
	class Reader {
	public:
		static void populateList(GolfList* l, std::string filename) {
			std::ifstream file;
			file.open(filename);
			if (!file.is_open()) {
				return;
			}
			std::string read;
			while (!file.eof()) {
				Data *d=new Data();
				
				std::getline(file, read);
				
				size_t _sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					delete d;
					continue;
				}
				d->surname = read.substr(0,_sur);
				read= read.substr(_sur+1,read.size()-_sur-1);


				_sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					delete d;
					continue;
				}
				d->name = read.substr(0, _sur);
				read = read.substr(_sur + 1, read.size() - _sur - 1);
				
				_sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					delete d;
					continue;
				}
				d->club= read.substr(0, _sur);
				read = read.substr(_sur + 1, read.size() - _sur - 1);
				
				_sur = read.find(';');
				if (_sur == std::string::npos) {
					std::cout << "Warning: Malformed line" << std::endl;
					delete d;
					continue;
				}
				d->points = std::stod(read.substr(0, _sur));
				read = read.substr(_sur + 1, read.size() - _sur - 1);

				d->birthYear = std::stoi(read);
				
				
				l->add(d);
			}
			file.close();
		}
	};
}
