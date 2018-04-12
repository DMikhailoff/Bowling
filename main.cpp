#include <string>
#include <iostream>
#include <vector>
#include <ostream>

#include "tableau_tuple.hpp"


using namespace std;

int main()
{
	int first_throw;
	int second_throw;
	tableau_tuple tab_result;
	int i = 1;

	while(i != 10){
		cout << "Score du premier lancer : ";
		cin >> first_throw;
		if(first_throw!=10){
			cout << "Score du second lancer : ";
			cin >> second_throw;
		}
		else
			cout << "Felicitation pour votre strike" << endl;

		tab_result.add(first_throw,second_throw);

		tab_result.affiche();

		i++;
	}
	

	return 0;
}