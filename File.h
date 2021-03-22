#ifndef FILE_H
#define FILE_H

#include <stdlib.h>

class File
{
	public:
		File();
	protected:
};

template <class T>
class queue
{
 private :
	T * donnees;
	int taille;
	queue(const queue &);
	queue& operator = (const queue &);

 public :

	queue() { donnees = NULL, taille = 0;}

	inline ~queue() { empty();}

	int ajout(const T &);
	// ajoute element dans la file

	int retrait(T &);
	// retire

	inline void empty()
	{
		if (taille > 0)
			delete [] donnees, taille = 0;
	}
	inline int size() const { return taille;}
};


template <class T>
int queue<T>::ajout(const T & element)
// ajout élément
{
	T * temp = new T[taille + 1];
	if (temp == NULL)
		return 0;

	for (int i = 0; i < taille; i++)
		temp[i] = donnees[i];
	temp[taille] = element;
	if (taille > 0)
		delete [] donnees;
	donnees = temp;
	taille++;
	return 1;
}


template <class T>
int queue<T>::retrait(T & resultat)
// enlève élément
{
	if (taille == 0)
		return 0;

	T * temp = new T[taille - 1];
	if (temp == NULL)
		return 0;

	resultat = donnees[0];
	for (int i = 1; i < taille; i++)
		temp[i-1] = donnees[i];
	delete [] donnees;
	donnees = temp;
	--taille;
	return 1;
}
#endif