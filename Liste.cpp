#include "Liste.hpp"


int T;

template <class T>
class Liste {
protected:
    NoeudDeListe* pPremier;
    NoeudDeListe* pDernier;
    int nbElts;
public:
    NoeudDeListe* getpPremier() {
        return pPremier;
    }

    NoeudDeListe* getpDernier() {
        return pDernier;
    }

    Liste<T>::Liste() {
        this->pPremier = nullptr;
        this->pDernier = nullptr;
        this->nbElts = 0;
    }

    void Liste<T>::ajouterFin(int elt) {
        auto *tmp = new NoeudDeListe(int);
        if (listeVide()) {
            this->pPremier = tmp;
            this->pDernier = tmp;
        } else {
            this->pDernier->setSuivant(tmp);
            this->pDernier = tmp;
        }
        this->nbElts++;
    }

    virtual bool Liste<T>::afficher() {
        cout << "Affichage de la liste :\n";
        NoeudDeListe* pListe = this->pPremier;
        if (listeVide()) {
            cout << "La Liste est vide.";
            return true;
        }
        for (int i = 1; i <= nbElts; i++) {
            cout << "NoeudDeListe [" << i << "] {";
            pListe->afficher();
            pListe = pListe->getSuivant();
        }
         nbElts->afficher();

        return true;
    }

private:
    bool Liste<T>::listeVide() {
        if (this->nbElts == 0) return true;
        else return false;
    }
};
#endif
