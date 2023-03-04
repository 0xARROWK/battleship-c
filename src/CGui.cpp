//
// Created by 0xark on 10/03/2021.
//

#include "CGui.h"

/**
 * Allows to create an empty GUI
 */
CGui::CGui() {

    this->m_pArmada = NULL;
    this->m_pCoups = NULL;

}

/**
 * ALlows to create a GUI with a predefined Armada and a shot list
 * @param pArmada - predefined armada
 * @param pCoups - shot list
 */
CGui::CGui(CArmada *pArmada, CCoups *pCoups) {

    if (pArmada == NULL or pCoups == NULL) {
        throw "The Armada and the shot can't be NULL";
    }

    this->m_pCoups = pCoups;
    this->m_pArmada = pArmada;

}

/**
 * Allows to set the armada and the shot list for this GUI
 * @param pArmada - armada to set
 * @param pCoups - shot list
 */
void CGui::setArmadaCoups(CArmada *pArmada, CCoups *pCoups) {

    this->m_pCoups = pCoups;
    this->m_pArmada = pArmada;

}

/**
 * Allows to
 * @return true if all ship could be placed, or false
 */
bool CGui::positionnerBateaux() {

    return m_pArmada->placerAleatoirement();

}

/**
 * Allows to choose coordinates for make a shot
 *
 * @return coordinates of the shot
 */
pair<int, int> CGui::choisirAttaque() {

    int x;
    int y;

    cout << "Enter x value : " << endl;

    while (!(cin >> x) or (x < 0 or x > TAILLE_GRILLE-2)) {
        cout << "You must enter a number between 0 and " << TAILLE_GRILLE - 2;
        cin.clear();
        cin.ignore(132, '\n');
    }

    cout << "Enter y value : " << endl;

    while (!(cin >> y) or (y < 0 or y > TAILLE_GRILLE-2)) {
        cout << "You must enter a number between 0 and " << TAILLE_GRILLE - 2;
        cin.clear();
        cin.ignore(132, '\n');
    }

    return make_pair(x,y);

}

/**
 * Allows to display win text
 */
void CGui::afficheGagne() {

    cout << "Well played, you win :)" << endl;

}

/**
 * Allows to display loose text
 */
void CGui::affichePerdu() {

    cout << "Sorry, you lost :(" << endl;

}

/**
 * Allows to display our grid and the grid of opponent with indications
 *
 * @param os - stream to write
 */
void CGui::remplirDeuxGrilles(ostream &os) {

    for (int i = 0; i <= TAILLE_GRILLE-2; i++) {
        for (int j = 0; j <= TAILLE_GRILLE-2; j++) {
            this->m_grilleJou[i][j] = '-';
            this->m_grilleAdv[i][j] = '-';
        }
    }

    for (int i = 0; i < m_pArmada->getEffectifTotal(); i++) {

        CBateau* bateau = m_pArmada->getBateau(i);
        pair<int, int> position = bateau->getPosition();

        for (int j = 0; j < bateau->getTaille(); j++) {
            if (bateau->getDegats(j)) {
                this->m_grilleJou[position.first + j][position.second] = 'X';
            } else {
                this->m_grilleJou[position.first + j][position.second] = 'B';
            }
        }
    }

    for (int i = 0; i < m_pCoups->getTaille("ploufAdverse"); i++) {
        pair<int,int> position;
        position = m_pCoups->getPair("ploufAdverse", i);
        this->m_grilleJou[position.first][position.second] = 'O';
    }

    // Grid of the opponent | La grille de l'adverse
    for (int i = 0; i < m_pCoups->getTaille("touche"); i++) {
        pair<int, int> position;
        position = m_pCoups->getPair("touche", i);
        this->m_grilleAdv[position.first][position.second] = 'X';
    }

    for (int i = 0; i <m_pCoups->getTaille("dansLEau"); i++) {
        pair<int,int> position;
        position = m_pCoups->getPair("dansLEau", i);
        this->m_grilleAdv[position.first][position.second] = 'O';
    }

    afficherLaGrille(os, "joueur");
    afficherLaGrille(os, "adversaire");

}

/**
 * Allows to display a grid on the screen
 *
 * @param os - stream to write
 * @param jouOuAdv - specify if we want to display our grid or the opponent grid
 */
void CGui::afficherLaGrille(ostream &os, string jouOuAdv) {

    if (jouOuAdv == "joueur") {

        os << "Your grid :" << endl;

        // Display the top number | Affiche les nombres en haut
        os << " ";
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            os << " " << j;
        }
        os << endl;

        // Display the content | Affiche le contenu
        for (int x = 0 ; x < TAILLE_GRILLE-1 ; x++) {
            os << x;
            for (int y = 0 ; y < TAILLE_GRILLE-1 ; y++) {
                os << " " << this->m_grilleJou[y][x];
            }
            os << endl;
        }
        os << endl;

    } else  if (jouOuAdv == "adversaire") {

        os << "Grid of your ennemy :" << endl;

        // Display the top number | Affiche les nombres en haut
        os << " ";
        for (int j = 0; j < TAILLE_GRILLE-1; j++) {
            os << " " << j;
        }
        os << endl;

        // Display the content | Affiche le contenu
        for (int x = 0 ; x < TAILLE_GRILLE-1 ; x++) {
            os << x;
            for (int y = 0 ; y < TAILLE_GRILLE-1 ; y++) {
                os << " " << this->m_grilleAdv[x][y];
            }
            os << endl;
        }
        os << endl;

    } else {
        throw "An invalid player's grid is attempted to be displayed";
    }

}

/**
 * Allows to display grids of the current game
 *
 * @param os - stream to write
 * @param theG - gui that we have to display
 * @return - what we have to display in the command line
 */
ostream& operator<<(ostream& os, CGui& theG) {

    theG.remplirDeuxGrilles(os);

    return os;

}

/**
 * Allows to destroy array of armada and shot list for this GUI
 */
CGui::~CGui() {

    this->m_pArmada = NULL;
    delete m_pArmada;
    this->m_pCoups = NULL;
    delete m_pCoups;

}
