
#ifndef LAINLIB_H
#define LAINLIB_H

#define OK 1
#ifndef ERROR
	#define ERROR -1
#endif
#define STOP 0


/**
* Stream control tools
* @author: C++ STL
* @namespace: std
*
*/
#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::cerr;
using std::clog;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::stringstream;

/**
* Containers
* @author: C++ STL
* @namespace: std
* @include: vector, list, deque, string, stack, queue
*			map, set
*/
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <regex>

using std::string;
using std::vector;
using std::list;
using std::deque;
using std::stack;
using std::queue;
using std::map;
using std::set;
using std::pair;
using std::regex;

/**
* General algorithms
* @author: C++ STL
* @namespace: std
*
*/
#include <algorithm>

/**
* Memory mangement
* @author: C++ STL
* @namespace: std
*
*/
#include <memory>

#include <functional>

/**
* Useful
*
*/

#include <cctype>
#include <cmath>
#include <ctime>
#include <windows.h>





namespace lain {



	class Comparable {

	private:
		int value_;

	public:
		Comparable() {}
		Comparable(int value) { this->value_ = value; }
		Comparable(const Comparable &that) : value_(that.value()) {}

		int value() const { return this->value_; }
		virtual bool operator==(const Comparable &that) const {
			return this->value_ == that.value();
		}
		virtual bool operator!=(const Comparable &that) const { return !(*this == that); }
		virtual bool operator<(const Comparable &that) const {
			return this->value_ < that.value();
		}
		virtual bool operator>(const Comparable &that) const {
			return *this != that && !(*this < that);
		}
		virtual bool operator<=(const Comparable &that) const {
			return *this < that || *this == that;
		}
		virtual bool operator>=(const Comparable &that) const {
			return *this > that || *this == that;
		}

	};
	
	
	






}// namespace lain

















#endif














