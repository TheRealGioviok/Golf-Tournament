#include <iostream>

#include "list.h"
#include "types.h"
#include <iostream>
int main() {
	List<int> list;
	for (int i = 0; i < 10; i++) {
		list.push_back(i);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << list[i] << std::endl;
	}
	
}
