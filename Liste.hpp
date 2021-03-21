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

    private:
};

#endif // LISTE_H
