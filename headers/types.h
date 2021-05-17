#pragma once
#include <string>
namespace golf {
	struct Data {
		std::string surname, name, club;
		double points;
		int birthYear;
		Data(const Data& d) :surname(d.surname), name(d.name), club(d.club), points(d.points), birthYear(d.birthYear) {};
		Data(std::string _surname = "Smith", std::string _name = "John", std::string _club = "International Golf Club", double _points = 42.0, int _birthYear = 1971) :surname(_surname), name(_name),club(_club), points(_points), birthYear(_birthYear) {};
		bool operator ==(const Data& d) {
			if (d.surname == surname && d.name == name && d.club == club && d.points == points && d.birthYear == birthYear) return true;
			return false;
		}
		bool samePersonAs(const Data& d) {
			if (d.surname == surname && d.name == d.name && d.birthYear == birthYear) return true;
			return false;
		}
		friend std::ostream& operator<<(std::ostream& out, const Data& d) {
			out << d.name +" "+ d.surname + " nato nel " + std::to_string(d.birthYear) + " appartiene al club :" + d.club + ". Al momento ha " + std::to_string(d.points) + " punti.";;
			return out;
		}

		bool operator>(Data d) {
			return (points > d.points);
		}
	};
}
