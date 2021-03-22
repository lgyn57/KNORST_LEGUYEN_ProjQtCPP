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

	// constructeur
	pile(int size);


	// destructeur

	inline ~pile();



	//Modification.

	int push(const T &);// Permet d'ajouter un element dans la pile.

	int pop(T &);// Permet de retirer un element de la pile.
	

	inline void empty() { nb_elem = 0;} //vide la pile


	//Consultation.
	inline int size() const { return nb_elem;}
};