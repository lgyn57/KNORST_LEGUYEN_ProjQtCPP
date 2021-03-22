#include "NoeudDeListe.hpp"

#ifndef IOSTREAM
#include <iostream>

using namespace std;

int T;

template <class<T>
class NoeudDeListe {

/*
private:
    int donnee;
    NoeudDeListe* suivant;
*/    

public:

    explicit NoeudDeListe<T>::NoeudDeListe(int donnee) {
        this->donnee = donnee;
        this->suivant = nullptr; // cf différence avec NULL
    }

    int NoeudDeListe<T>::getDonnee() {
        return this->donnee;
    }

    void NoeudDeListe<T>::setDonnee(int d) {
        this->donnee = d;
    }

    NoeudDeListe* getSuivant() {
        return this->suivant;
    }

    void setSuivant(NoeudDeListe* s) {
        this->suivant = s;
    }

    void NoeudDeListe<T>::afficher() {
        cout << "Donnee -> " << this->donnee << "\n";
    }



};
#endif
