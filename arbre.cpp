

#ifndef IOSTREAM
#define NDEBUG 
#include <iostream>

template <class T> class arbre;

template <class T>
class node
{
 friend class arbre<T>;

 private :
	T data;
	node * filsg;
	node * filsd;

	node(const T & d) { data = d; filsg = filsd = NULL;}
}


template <class T>
class arbre
{
 private :
	node<T> * racine;
	node<T> * courant;
	int nb_noeuds;

	arbre(const arbre &);
	arbre& operator = (const arbre &);

	void detruire_arbre(node<T> *);
	int profondeur_arbre(const node<T> *) const;
	int compter_feuilles_arbre(const node<T> *) const;

	void parcours_prefixe(const node<T> *, void (*f) (const T &)) const;
	void parcours_suffixe(const node<T> *, void (*f) (const T &)) const;


 public :
	// Contruction
	arbre() { racine = courant = NULL; nb_noeuds = 0;}


	// Destruction
	inline ~arbre();
	// Modification
	int add_left(const T &);
	int add_right(const T &);

	int move_current_left();
	int move_current_right();
	int move_current_root();
	void empty();

	// parcours
	inline void prefix(void (*f) (T &)) { parcours_prefixe(racine, f);}
	inline void suffix(void (*f) (T &)) { parcours_suffixe(racine, f);}


	// Affichage
	inline void prefix(void (*f) (const T &)) const { parcours_prefixe(racine, f);}
	inline void suffix(void (*f) (const T &)) const { parcours_suffixe(racine, f);}

	int consult_current(T &) const;					// contenu noeud

	inline int size() const { return nb_noeuds;}	// nb noeuds

	inline int count_leaves() const					// nb feuilles
	{ return compter_feuilles_arbre(racine);}

	inline int depth() const                        // profondeur
	{ return profondeur_arbre(racine);}
};

template <class T>
void arbre<T>::detruire_arbre(node<T> * arbre)
{
	if (arbre != NULL)
	{
		detruire_arbre(arbre->filsg);
		detruire_arbre(arbre->filsd);
		delete arbre;
	}
}

template <class T>
int arbre<T>::profondeur_arbre(const node<T> * arbre) const
{
	if (arbre == NULL)
		return 0;

	int prof_gauche = profondeur_arbre(arbre->filsg);
	int prof_droit = profondeur_arbre(arbre->filsd);
	return 1 + ((prof_gauche > prof_droit) ? prof_gauche : prof_droit);
}

template <class T>
int arbre<T>::compter_feuilles_arbre(const node<T> * arbre) const
{
	if (arbre == NULL)
		return 0;
	else if (arbre->filsg == NULL && arbre->filsd == NULL)
		return 1;
	else
		return compter_feuilles_arbre(arbre->filsg) +
			   compter_feuilles_arbre(arbre->filsd);
}

template <class T>
void arbre<T>::parcours_suffixe(const node<T> *, void (*f)(const T &)) const
{
  if (arbre != NULL)
  {
    parcours_suffixe(arbre->filsg, f);
    parcours_suffixe(arbre->filsd, f);
    f(arbre->data);
  }
}

template <class T>
void arbre<T>::parcours_prefixe(const node<T> *, void (*f)(const T &)) const
{
  if (arbre != NULL)
  {
    f(arbre->data);
    parcours_prefixe(arbre->filsg, f);
    parcours_prefixe(arbre->filsd, f);
  }
}



// destructeur
template <class T>
arbre<T>::~arbre()
{
	if (nb_noeuds > 0)
	{
		detruire_arbre(racine->filsg);
		detruire_arbre(racine->filsd);
		delete racine;
	}
}


// modifications
template <class T>
int arbre<T>::add_left(const T & element)
{
	// création du noeuf et vérif mémoire
	node<T> * nouveau = new node<T>(element);
	if (nouveau == NULL)
		return 0;
	if (nb_noeuds == 0)
		racine = courant = nouveau;
	else
		courant->filsg = nouveau;

	++nb_noeuds;
	return 1;
}


template <class T>
int arbre<T>::add_right(const T & element)
{	node<T> * nouveau = new node<T>(element);
	if (nouveau == NULL)
		return 0;

	if (nb_noeuds == 0)
		racine = courant = nouveau;
	else
		courant->filsd = nouveau;

	++nb_noeuds;
	return 1;
}


// positionne pointeur courant
template <class T>
int arbre<T>::move_current_left()
{
	if (courant == NULL || courant->filsg == NULL)
		return 0;

	courant = courant->filsg;
	return 1;
}


template <class T>
int arbre<T>::move_current_right()
{
	if (courant == NULL || courant->filsd == NULL)
		return 0;

	courant = courant->filsd;
	return 1;
}


template <class T>
int arbre<T>::move_current_root()
{
	if (nb_noeuds == 0)
		return 0;

	courant = racine;
	return 1;
}


template <class T>
void arbre<T>::empty()
{
	if (nb_noeuds > 0)
	{
		detruire_arbre(racine->filsg);
		detruire_arbre(racine->filsd);
		delete racine;
		nb_noeuds = 0;
	}
}


template <class T>
int arbre<T>::consult_current(T & contenu) const
{
	if (courant == NULL)
		return 0;

	contenu = courant->data;
	return 1;
}


