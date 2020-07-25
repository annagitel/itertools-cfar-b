#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace itertools{
	class range {
	public:
		range(int s, int e):s(s),e(e){}

		class iterator{
		private:
			int index;

		public:
			iterator(int i) : index(i) {}
			int operator*() const {return index;}

			const iterator &operator++() {
				++index;
				return *this;
			}

			bool operator==(const iterator &other) const {
				return other.index==index;
			}

			iterator& operator=(const iterator& other) {
				if (*this != other)
					this->index = other.index;
				return *this;
			}

			bool operator!=(const iterator &other) const {
				return other.index!=index;
			}
		};

		iterator begin() {return s;}
		iterator end() {return e;}
		typedef int value_type;
	private:
		iterator s;
		iterator e;
	};
}