#ifndef SORT_INCLUDE_FRUITS_H
#define SORT_INCLUDE_FRUITS_H

#include <iostream>
#include <string>
#include <vector>

class Fruits {
private:
	std::string _name;
	size_t _weight;
public:
	Fruits(): _name(""), _weight(0){}
	Fruits(std::string name,size_t weight):_name(name),_weight(weight){}

	Fruits(const Fruits& other) {
		_name = other._name;
		_weight = other._weight;
	}


	std::string get_name() const{
		return _name; 
	}

	size_t get_weight() const{ 
		return _weight; 
	}

	bool operator==(const Fruits& other) const {
		return ((_name == other._name) && (_weight == other._weight));
	}

	bool operator<(const Fruits& other) const {
		return ((_name < other._name) || ((_name == other._name) && (_weight < other._weight)));
	}

	bool operator>=(const Fruits& other) const {
		return ((_name >= other._name) || ((_name == other._name) && (_weight >= other._weight)));
	}

	bool operator<=(const Fruits& other) const {
		return ((_name <= other._name) || ((_name == other._name) && (_weight <= other._weight)));
	}

	bool operator>(const Fruits& other) const {
		return ((_name > other._name) || ((_name == other._name) && (_weight > other._weight)));
	}
};

std::ostream& operator<<(std::ostream& stream, const Fruits& fruits){
	stream << "[" << fruits.get_name() << ", " << fruits.get_weight() << "]";
	return stream;
}

std::ostream& operator<<(std::ostream& os, std::vector<Fruits>& list) {
	for (const Fruits& fruits : list) {
		os << fruits << std::endl;
	}
	os << std::endl;
	return os;
}


#endif