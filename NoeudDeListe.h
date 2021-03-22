#ifndef NOEUDDELISTE_HPP
#define NOEUDDELISTE_HPP


class NoeudDeListe
{
    public:
        
    NoeudDeListe();
    virtual ~NoeudDeListe();
    
    explicit NoeudDeListe(int donnee);
    
    int getDonnee();
    void setDonnee(int d);
    
    NoeudDeListe* getSuivant();
    void setSuivant(NoeudDeListe* s);
    
    void afficher();

    protected:

    private:
    int donnee;
    NoeudDeListe* suivant;
    
};

#endif // NOEUDDELISTE_HPP
