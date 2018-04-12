#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>

#include "tableau_tuple.hpp"


TEST_CASE("Test de ma classe 'tableau_tuple'")
{
	SECTION("Test de la fonction 'Somme'"){
		tableau_tuple tab1;
		tab1.add(1,2);
		tab1.add(4,3);
		REQUIRE(tab1.somme() == 10);
	}
	SECTION("Si chacune des valeurs du tuple est >=0"){
		tableau_tuple tab2;
		
		REQUIRE_THROWS(tab2.add(-1,2));
	}
	SECTION("Taille du tableau doit etre <= 10"){
		tableau_tuple tab3;
		tab3.add(1,2);
		tab3.add(4,3);
		tab3.add(1,2);
		tab3.add(4,3);
		tab3.add(1,2);
		tab3.add(1,2);
		tab3.add(4,3);
		tab3.add(1,2);
		tab3.add(4,3);
		tab3.add(1,2);
		REQUIRE_THROWS(tab3.add(1,2));
	}
	SECTION("Somme de 2 elements d'un tuple <= 10"){
		tableau_tuple tab4;
		REQUIRE_THROWS(tab4.add(6,6));
	}
	SECTION("Si somme de 2 elements d'un tuple = 10 ==> ajout de l'element suivant"){
		tableau_tuple tab5;
		tab5.add(8,2);
		tab5.add(4,3);
		REQUIRE(tab5.somme() == 21);
	}
	SECTION("Si premiere valeur d'un tuple = 10 ==> ajout du tupl suivant"){
		tableau_tuple tab6;
		tab6.add(10,0);
		tab6.add(4,3);
		REQUIRE(tab6.somme() == 24);
	}
	SECTION("Si le dernier tuple = 10 ==> 1 element bonus"){
		tableau_tuple tab7;
		tab7.add(2,3);
		tab7.add(4,3);
		tab7.add(2,3);
		tab7.add(4,3);
		tab7.add(2,3);
		tab7.add(4,3);
		tab7.add(2,3);
		tab7.add(4,3);
		tab7.add(2,3);
		tab7.add(8,2);//spare
		tab7.add(6,0);
		REQUIRE(tab7.get_vec_length() == 11);
		// REQUIRE(tab7.somme() == 75);
	}
	SECTION("Si le premier element du dernier tuple = 10 ==> 2 elements bonus"){
		tableau_tuple tab8;
		tab8.add(2,3);
		tab8.add(4,3);
		tab8.add(2,3);
		tab8.add(4,3);
		tab8.add(2,3);
		tab8.add(4,3);
		tab8.add(2,3);
		tab8.add(4,3);
		tab8.add(2,3);
		tab8.add(10,0);//strike
		tab8.add(6,3);
		REQUIRE(tab8.get_vec_length() == 11);
		//REQUIRE(tab8.somme() == 81);
	}
}