#ifndef LISTE_HPP
#define LISTE_HPP


template <class T>
class Liste
{
    public:
        Liste();
        virtual ~Liste();

    protected:
    NoeudDeListe* pPremier;
    NoeudDeListe* pDernier;
    int nbElts;
    
    public:
    
    NoeudDeListe* getpPremier();
    NoeudDeListe* getpDernier();
    
    Liste();
    
    void ajouterFin(int elt);
    virtual bool afficher();
    
    private:
    
    bool listeVide();
    
    
};

#endif // LISTE_H
