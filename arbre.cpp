#include <stdlib.h>
#include <assert.h>


template <class T> class bintree;

template <class T>
class node
{
 friend class bintree<T>;

 private :
	T data;
	node * filsg;
	node * filsd;

	node(const T & d) { data = d; filsg = filsd = NULL;}
}


template <class T>
class bintree
{
 private :
	node<T> * racine;
	node<T> * courant;
	int nb_noeuds;

	bintree(const bintree &);
	bintree& operator = (const bintree &);

	void detruire_arbre(node<T> *);
	int profondeur_arbre(const node<T> *) const;
	int compter_feuilles_arbre(const node<T> *) const;

	void parcours_prefixe(const node<T> *, void (*f) (const T &)) const;
	void parcours_infixe(const node<T> *, void (*f) (const T &)) const;
	void parcours_suffixe(const node<T> *, void (*f) (const T &)) const;

	void parcours_prefixe(node<T> *, void (*f) (T &));
	void parcours_infixe(node<T> *, void (*f) (T &));
	void parcours_suffixe(node<T> *, void (*f) (T &));


 public :
	// Contruction
	bintree() { racine = courant = NULL; nb_noeuds = 0;}


	// Destruction
	inline ~bintree();
	// Modification
	int add_left(const T &);
	int add_right(const T &);

	int move_current_left();
	int move_current_right();
	int move_current_root();
	void empty();

	// parcours
	inline void prefix(void (*f) (T &)) { parcours_prefixe(racine, f);}
	inline void infix(void (*f) (T &))  { parcours_infixe(racine, f);}
	inline void suffix(void (*f) (T &)) { parcours_suffixe(racine, f);}


	// Affichage
	inline void prefix(void (*f) (const T &)) const { parcours_prefixe(racine, f);}
	inline void infix(void (*f) (const T &)) const  { parcours_infixe(racine, f);}
	inline void suffix(void (*f) (const T &)) const { parcours_suffixe(racine, f);}

	int consult_current(T &) const;					// contenu noeud

	inline int size() const { return nb_noeuds;}	// nb noeuds

	inline int count_leaves() const					// nb feuilles
	{ return compter_feuilles_arbre(racine);}

	inline int depth() const                        // profondeur
	{ return profondeur_arbre(racine);}
};

template <class T>
void bintree<T>::detruire_arbre(node<T> * arbre)
{
	if (arbre != NULL)
	{
		detruire_arbre(arbre->filsg);
		detruire_arbre(arbre->filsd);
		delete arbre;
	}
}

template <class T>
int bintree<T>::profondeur_arbre(const node<T> * arbre) const
{
	if (arbre == NULL)
		return 0;

	int prof_gauche = profondeur_arbre(arbre->filsg);
	int prof_droit = profondeur_arbre(arbre->filsd);
	return 1 + ((prof_gauche > prof_droit) ? prof_gauche : prof_droit);
}

template <class T>
int bintree<T>::compter_feuilles_arbre(const node<T> * arbre) const
{
	if (arbre == NULL)
		return 0;
	else if (arbre->filsg == NULL && arbre->filsd == NULL)
		return 1;
	else
		return compter_feuilles_arbre(arbre->filsg) +
			   compter_feuilles_arbre(arbre->filsd);
}

