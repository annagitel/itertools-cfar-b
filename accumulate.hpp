#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace itertools{

	typedef struct {
		template <typename T>
		T operator()(T x, T y) const{
			return x+y;
		}
	}plus;

	template <typename T, typename Function = plus> class accumulate{
		T container;
		Function f;

	public:
		typedef typename T::value_type value_type;
		accumulate(T c, Function f=plus()):container(c),f(f){}

		class iterator{
			typename T::iterator s;
			typename T::iterator e;
			typename T::value_type sum;
			Function f;

			public:
			iterator(typename T::iterator start, typename T::iterator end, Function _F):s(start),e(end),f(_F){
				if(s != e)
					sum = *s;
			}

			auto operator*(){return sum;}
			const iterator& operator++(){
				++s;
				if(s!=e)
					sum=f(sum,*s);
				return *this;
			}
			const iterator& operator=(const iterator& other){
                            if (*this != other){
                                this->e = other.e;
                                this->sum = other.sum;
                                this->s = other.s;
                                this->f = other.f;
                            }
                            return *this;
                        }
			bool operator!=(const iterator& other) const {
				return s!=other.s;
			}
		};
		iterator begin(){return iterator(container.begin(),container.end(),f);}
		iterator end(){return iterator(container.end(),container.end(),f);}
	};

}