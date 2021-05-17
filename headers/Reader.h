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
				d.surname = read;
				if (file.eof()) {
					std::cout << "WARNING: Input file is malformed" << std::endl;
					break;
				}

				std::getline(file, read);
				d.name = read;
				if (file.eof()) {
					std::cout << "WARNING: Input file is malformed" << std::endl;
					break;
				}

				std::getline(file, read);
				d.club = read;
				if (file.eof()) {
					std::cout << "WARNING: Input file is malformed" << std::endl;
					break;
				}

				std::getline(file, read);
				d.points = std::stod(read);
				if (file.eof()) {
					std::cout << "WARNING: Input file is malformed" << std::endl;
					break;
				}

				std::getline(file, read);
				d.birthYear = std::stoi(read);
				if (file.eof()) {
					std::cout << "WARNING: Input file is malformed" << std::endl;
					break;
				}

				l->push_back(d);
			}
			file.close();
		}
	};
}
