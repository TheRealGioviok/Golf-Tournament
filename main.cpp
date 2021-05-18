#include <iostream>

#include "list.h"
#include "types.h"
#include "Reader.h"
#include "GolfList.h"
#include <iostream>

int main() {
	List<int> list;
	for (int i = 0; i < 10; i++) {
		list.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << list[i] << std::endl;
	}

	List<golf::Data> list2;
	golf::Data f = golf::Data("Stroustrup", "Bjarne","Danish Golf Club ", 100.0, 1950);
	golf::Data f2 = golf::Data("Ritchie", "Dennis","US Golf Club", 100.0, 1941);

	golf::GolfList list3;
	golf::Reader::populateList(&list3,"testCase.txt");
	std::cout << std::endl;
	golf::GolfList::print(&list3, true);  //Crescente
	std::cout << std::endl;
	golf::GolfList::print(&list3, false); //Decrescente
	std::cout << std::endl;

	golf::GolfList::infoPlayerAndSame(&list3, "SARI");
	std::cout << std::endl;

	list3.removePlayersByPoints(150.0);
	std::cout << std::endl;

	golf::GolfList::print(&list3, true);  //Crescente
	std::cout << std::endl;

}
