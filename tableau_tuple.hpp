#ifndef TABLEAU_TUPLE_H
#define TABLEAU_TUPLE_H

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class tableau_tuple
{
private:
	vector<tuple<int,int>> vec_;

public:
	vector<tuple<int,int>> add(int a, int b)
	{
		if(vec_.size() == 10){
			if(get<0>(vec_[vec_.size()-1]) + get<1>(vec_[vec_.size()-1]) != 10)
				throw("Le tableau contient déjà 10 tuples et le dernier n'est pas un spare");
			else if(get<0>(vec_[vec_.size()-1]) == 10){
				vec_.push_back(make_tuple(a,b));
				return vec_;
			}
			else{
				vec_.push_back(make_tuple(a,0));
				return vec_;
			}
		}else{
			if(a >= 0 && b >= 0){
				if(a + b <= 10){
					vec_.push_back(make_tuple(a,b));
					return vec_;
				}else{
					throw("La somme des 2 elements > 10");
				}
			}else{
				throw("L'une des deux valeurs est < 0");
			}
		}
	}

	int somme()
	{
		int result = 0;
		for (int i = 0; i < vec_.size(); i++){
			if(get<0>(vec_[i]) + get<1>(vec_[i]) == 10 && get<0>(vec_[i]) != 10 )
				result = result + get<0>(vec_[i]) + get<1>(vec_[i]) + get<0>(vec_[i+1]);
			else if (get<0>(vec_[i]) == 10)
				result = result + get<0>(vec_[i]) + get<1>(vec_[i]) + get<0>(vec_[i+1]) + get<1>(vec_[i+1]);
			else
				result = result + get<0>(vec_[i]) + get<1>(vec_[i]);
		}
		return result;
	}

	int get_vec_length()
	{
		return vec_.size();
	}
};
#endif