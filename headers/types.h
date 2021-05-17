
namespace golf {
	struct Data {
		std::string surname, name;
		double points;
		int birthYear;
		Data(const Data &d) :surname(d.surname), name(d.name), points(d.points), birthYear(d.birthYear) {};
		Data(std::string _surname = "Smith", std::string _name = "John", double _points = 42.0, int _birthYear = 1971) :surname(_surname), name(_name), points(_points), birthYear(_birthYear) {};
		bool operator ==(const Data &d) {
			if (d.surname == surname && d.name == d.name && d.points == d.points && d.birthYear == birthYear) return true;
			return false;
		}
		bool samePersonAs(const Data& d) {
			if (d.surname == surname && d.name == d.name && d.birthYear == birthYear) return true;
			return false;
		}
	};
}