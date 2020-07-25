#pragma once
#include <iostream>
#include <vector>
namespace itertools{
	template <typename T, typename Function>
	class filterfalse{
		T container;
		Function f;
	public:
		filterfalse(Function _f, T c):container(c),f(_f){}
		class iterator{
			typename T::iterator b;
			typename T::iterator e;
			Function f;

		public:
			iterator(typename T::iterator _b, typename T::iterator _e, Function _F):
					b(_b),e(_e),f(_F){
				while(b!=e && f(*b) == true){
					++b;
				}
			}

			auto operator*(){return *b;}

			iterator &operator++(){
				++b;
				while(b!=e && f(*b) == true ){
					++b;
				}
				return *this;
			}

			iterator& operator=(const iterator& other) {
				return iterator(other.b,other.e,other.f);
			}

			bool operator==(const iterator& other) const {
				return b==other.b;
			}

			bool operator!=(const iterator& other) const {
				return b!=other.b;
			}
		};
		iterator begin(){return iterator(container.begin(),container.end(),f);}
		iterator end(){return iterator(container.end(),container.end(),f);}
	};
}