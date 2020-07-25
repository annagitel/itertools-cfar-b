#pragma once
#include <iostream>
namespace itertools{
	template <typename T, typename BT>
	class compress{
		T container;
		BT b;
	public:
		compress(T c, BT _b) : container(c),b(_b){}
		class iterator{
			typename T::iterator t_b;
			typename T::iterator t_e;
			typename BT::iterator bt_b;
			typename BT::iterator bt_e;

		public:
			iterator(typename T::iterator _b, typename T::iterator _e, typename BT::iterator _bt_b, typename BT::iterator _bt_e):
					t_b(_b),t_e(_e),bt_b(_bt_b),bt_e(_bt_e){
				while (t_b != t_e && *bt_b == false){
					++t_b;
					++bt_b;
				}
			}

			auto operator*(){
				return *t_b;
			}

			iterator &operator++(){
				++t_b;
				++bt_b;
				while(t_b != t_e && *bt_b == false){
					++t_b;
					++bt_b;
				}
				return *this;
			}

			iterator& operator=(const iterator& other) {
				if (*this != other){
					this->t_e = other.t_e;
					this->t_b = other.t_b;
					this->bt_e = other.bt_e;
					this->bt_b = other.bt_b;
				}
				return *this;
			}

			bool operator==(const iterator& other) const {
				return t_b==other.t_b;
			}

			bool operator!=(const iterator& other) const {
				return t_b!=other.t_b;
			}
		};
		iterator begin(){return iterator(container.begin(),container.end(),b.begin(), b.end());}
		iterator end(){return iterator(container.end(),container.end(),b.end(), b.end());}
	};
}