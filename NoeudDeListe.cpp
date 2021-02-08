#include "NoeudDeListe.h"

#ifndef IOSTREAM
#include <iostream>

using namespace std;

int T;

class NoeudDeListe {
private:
    int donnee;
    NoeudDeListe* suivant;
public:

    explicit NoeudDeListe(int donnee) {
        this->donnee = donnee;
        this->suivant = nullptr; // cf différence avec NULL
    }

    int getDonnee() {
        return this->donnee;
    }

    void setDonnee(int d) {
        this->donnee = d;
    }

    NoeudDeListe* getSuivant() {
        return this->suivant;
    }

    void setSuivant(NoeudDeListe* s) {
        this->suivant = s;
    }

    void afficher() {
        cout << "Donnee -> " << this->donnee << "\n";
    }



};
#endif
