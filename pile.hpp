#ifndef DEF_TEST_PILE_HPP
#define DEF_TEST_PILE_HPP


#include <iostream.h>
#include <stdlib.h>

template <class T>
class pile
{
 private :
	T * donnees;		// Le tableau de donnees.
	int taille;			// Taille de la pile.
	int nb_elem;		// Nombre d'elements de la pile.


	pile(const pile &);
	pile& operator = (const pile &);

 public :

	// C O N S T R U C T E U R

	pile(int size);


	// D E S T R U C T E U R

	inline ~pile();


	// M E T H O D E S

	//Modification.

	int push(const T &);// Permet d'ajouter un element dans la pile.

	int pop(T &);// Permet de retirer un element de la pile.
	

	inline void empty() { nb_elem = 0;} //vide la pile


	//Consultation.
	inline int size() const { return nb_elem;}
};