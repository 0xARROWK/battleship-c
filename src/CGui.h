//
// Created by 0xark on 10/03/2021.
//

#include "BiblioStd.h"
#include "CBateau.h"
#include "CArmada.h"
#include "CCoups.h"
#include "CBaseJeu.h"

#ifndef BATAILLENAVALE_CGUI_H
#define BATAILLENAVALE_CGUI_H


class CGui: public CBaseJeu {

    private:
        char m_grilleJou[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1];
        char m_grilleAdv[TAILLE_GRILLE - 1][TAILLE_GRILLE - 1];
        CArmada* m_pArmada;
        CCoups* m_pCoups;

    public:
        CGui();
        CGui(CArmada* pArmada, CCoups* pCoups);
        void setArmadaCoups(CArmada* pArmada, CCoups* pCoups);
        bool positionnerBateaux();
        pair<int, int> choisirAttaque();
        void afficheGagne();
        void affichePerdu();
        void remplirDeuxGrilles(ostream& os);
        void afficherLaGrille(ostream& os, string jouOuAdv);
        friend ostream& operator<<(ostream& os, CGui& theG);
        virtual ~CGui();

};


#endif //BATAILLENAVALE_CGUI_H
