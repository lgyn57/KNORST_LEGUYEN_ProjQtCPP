#include <iostream>
#include <string>
#include "Liste.hpp"
#include "File.h"
#include "pile.hpp"
#include "Liste.cpp"
#include "File.cpp"
#include "Pile.cpp"
#include "Arbre.cpp"
using namespace std;


void creeArbre(string class_name, string list_name);
arbre* inserArbre(int i);
int main() {
    int choixDonnee;
    do {
        cout << "Choix type données" << endl;
        cout
                << "1 liste"
                << endl
                << "2 pile"
                << endl
                << "3 file"
                << endl
                << "4 arbre"
                << endl;

        cin >> choixDonnee;
        if(choixDonnee > 4 || choixDonnee < 1) {
            cout << "mauvais choix !" << endl;
        }

    } while(choixDonnee > 4 || choixDonnee < 1);
        switch(choixDonnee) {
            case 1:
                Liste<int> liste = new Liste<int>();
                bool ok;
                int nbValue;
                do {
                    cout << "Choix nombre de valeurs dans une liste d'entiers :" << endl;
                    if(cin >> nbValue) {
                        printf("VALEURS ?\n");
                        for (int i = 0; i < nbValue; i++) {
                            int value;
                            do {
                                if (cin >> value) {
                                    liste.ajouterFin(value);
                                    ok = false;
                                } else {
                                    cout << "ce n'est pas un entier" << endl;
                                    ok = true;
                                }
                            } while (ok);
                        }
                    }
                } while(nbValue != (int)nbValue);
                printf("Affichage de la liste :\n");
                liste.afficher();
            break;
            case 2:
                    Pile<int> pile = new Pile<int>();
                    bool ok;
                    int nbValue;
                    do {
                        cout << "Pile nb valeurs ?" << endl;
                        if(cin >> nbValue) {
                            printf("VALEURS ?:\n");
                            for (int i = 0; i < nbValue; i++) {
                                int value;
                                do {
                                    if (cin >> value) {
                                        pile.push(value);
                                        ok = false;
                                    } else {
                                        cout << "ce n'est pas un entier" << endl;
                                        ok = true;
                                    }
                                } while (ok);
                            }
                        }
                    } while(nbValue != (int)nbValue);
                    printf("Voici votre Pile :\n");
                    pile.afficher();
                break;
            case 3:

void creeArbre(string class_name, string list_name){
     var;
    bool stop = false;
    arbre* arbre = inserArbre(0);
    arbre->afficher();
}

arbre* inserArbre(int i) {
    arbre *ta = new arbre();
    string choix, str;
    do {
        cout << "situé : " << i << endl << "fils gauche ? y/n" << endl;
        cin >> choix;
    } while (choix != "y" && choix != "n");
    if (choix == "y") {
        ta->add_left(inserArbre(i+1));
    } else
        ta->parcours_prefixe(nullptr);

    cout << "situé : " << i << endl << "noeud ?" << endl;
    cin >> str;
    ta->node(str);
    do {
        cout << "situé" << i << endl << "fils droit ? y/n" << endl;
        cin >> choix;
    } while (choix != "y" && choix != "n");
    if (choix == "y") {
        ta->add_right(inserArbre(i+1));
    } else
        ta->parcours_suffixe(nullptr);
    return ta;
}
    break;
    }
    return 0;
}
