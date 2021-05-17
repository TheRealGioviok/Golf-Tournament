#pragma once
#include <iostream>
#include "types.h"
#include <exception>
#include "list.h"

struct PlayerNotFoundException : public std::exception {
	const char* what() const throw () {
		return "No player was found by the search.";
	}
};


namespace golf {
	class GolfList {
		List<Data>* golfList;
	public:
		GolfList() {
			golfList = new List<Data>();
		}
		void sort() { //a simple bubbleSort
			for (int i = 0; i < golfList->getSize() - 1; i++) {
				bool ord = true;
				for (int k = 0; k < golfList->getSize() - i - 1; k++) {
					if (golfList->operator[](k) > golfList->operator[](k + 1)) {
						golfList->swap(k, k + 1);
						ord = false;
					}
				}
				if (ord)break;
			}
		}

		static void print(GolfList *g,bool increasing=true) {
			g->sort();
			if (increasing) {
				for (int i = 0; i < g->golfList->getSize(); i++) {
					std::cout << g->golfList->operator[](i) << std::endl;
				}
			}
			else {
				for (int i = g->golfList->getSize()-1; i > 0 ; i--) {
					std::cout << g->golfList->operator[](i) << std::endl;
				}
			}
		}


		static void infoPlayerAndSame(GolfList *g,std::string surname) {
			double pt = -1.0;
			for (int i = 0; i < g->golfList->getSize(); i++) {
				if (g->golfList->operator[](i).surname == surname) {
					pt = g->golfList->operator[](i).points;
					break;
				}
			}
			if (pt == -1.0) {
				throw PlayerNotFoundException();
			}
			for (int i = 0; i < g->golfList->getSize(); i++) {
				if (g->golfList->operator[](i).points == pt) {
					std::cout << g->golfList->operator[](i) << std::endl;
				}
			}
		}

		void removePlayersByPoints(double points) {
			for (int i = 0; i < golfList->getSize(); i++) {
				if (golfList->operator[](i).points == points)std::cout << golfList->operator[](i) << std::endl;
			}
		}


		

		void add(Data* d) {
			golfList->push_back(d);
		}

		void add(Data d) {
			golfList->push_back(d);
		}
	};
}
