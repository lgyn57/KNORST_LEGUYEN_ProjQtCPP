#ifndef LISTE_HPP
#define LISTE_HPP


class Liste
{
    public:
        Liste();
        virtual ~Liste();

    private:
    NoeudDeListe* pPremier;
    NoeudDeListe* pDernier;
    int nbElts;
    
    protected:
    
    
};

#endif // LISTE_H
