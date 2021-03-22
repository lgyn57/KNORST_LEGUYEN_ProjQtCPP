#ifndef LISTE_HPP
#define LISTE_HPP


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
    
    void ajouterFin(int x);
    virtual bool afficher();
    
    private:
    
    bool listeVide();
    
    
};

#endif // LISTE_H
