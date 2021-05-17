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

	List<golf::Data> list3;
	golf::Reader::populateList(&list3,"test.txt");
	for (int i = 0; i < list3.getSize(); i++) {
		std::cout << list3[i] << std::endl;
	}
}
