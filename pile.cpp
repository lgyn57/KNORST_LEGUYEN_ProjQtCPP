#include <iostream.h>
#include <stdlib.h>

#include "pile.hpp"


template <class T>
pile<T>::pile(int size)
{
	if (size > 0)
	{
		donnees = new T[size];
		taille = ((donnees != NULL) ? size : 0);
		nb_elem = 0;
	}
}

template <class T>
int pile<T>::~pile()
{
	if (taille > 0)
		delete [] donnees;
}



template <class T>
int pile<T>::push(const T & element)
// On ajoute le nouvel element a la fin du vecteur.
{
	if (nb_elem >= taille)
		return 0;

	donnees[nb_elem++] = element;
	return 1;
}


template <class T>
int pile<T>::pop(T & resultat)
// On retire l'element a la fin du vecteur.
{
	if (nb_elem == 0)
		return 0;

	resultat = donnees[--nb_elem];
	return 1;
}