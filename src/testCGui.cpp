//
// Created by 0xark on 12/03/2021.
//

#include "CGui.cpp"

void testConstructeurVide();
void testConstructeurNormal();
void testConstructeurNormalErreur();
void testPositionnerBateau();
void testChoisirAttaque();
void testAffichage();

int main() {

    cout << "\n\n******************************************" << endl;
    cout << "*               Test de CGui             *" << endl;
    cout << "******************************************" << endl;

    testConstructeurVide();
    testConstructeurNormal();
    testConstructeurNormalErreur();
    testPositionnerBateau();
    testChoisirAttaque();
    testAffichage();

}

void testConstructeurVide() {

    cout << "\n\n********** Test du constructeur vide **********\n\n" << endl;

    CGui cGui;

    cout << "OK : Le constructeur vide fonctionne." << endl;

}

void testConstructeurNormal() {

    cout << "\n\n********** Test du constructeur normal **********\n\n" << endl;

    CArmada armada;

    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    CCoups cCoups;

    try {
        CGui gui(&armada, &cCoups);
        cout << "OK : Le constructeur normal fonctionne." << endl;
    } catch (const char* msg) {
        cout << "ERREUR : Le constructeur normal a rencontré un problème." << endl;
        cerr << msg << endl;
    }

}

void testConstructeurNormalErreur() {

    cout << "\n\n********** Test du constructeur normal avec une erreur **********\n\n" << endl;

    try {
        CGui cGui(NULL, NULL);
        cout << "ERREUR : Le constructeur normal n'a pas rencontré d'erreurs." << endl;
    } catch (const char* msg) {
        cout << "OK : Le constructeur normal a bien rencontré une erreur." << endl;
    }

}

void testPositionnerBateau() {

    cout << "\n\n********** Test de la méthode positionnerBateaux() **********\n\n" << endl;

    CArmada armada;

    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    CCoups cCoups;

    try {
        CGui cGui(&armada, &cCoups);
        cGui.positionnerBateaux();
        cout << "OK : Le positionnement des bateaux fonctionne." << endl;
    } catch (const char* msg) {
        cout << "ERREUR : Le positionnement des bateaux n'a pas fonctionnée." << endl;
        cerr << msg << endl;
    }

}

void testChoisirAttaque() {

    cout << "\n\n********** Test de la méthode choisirAttaque() **********\n\n" << endl;

    CGui cGui;

    pair<int,int> pos = cGui.choisirAttaque();

    cout << "Valeurs saisies : (" << pos.first << ", " << pos.second << ")" << endl;

}

void testAffichage() {

    cout << "\n\n********** Test de l'affichage des grilles' **********\n\n" << endl;

    CArmada armada;

    CBateau bateau1("bateau1", make_pair(1,1), 3);
    CBateau bateau2("bateau2", make_pair(1,1), 3);
    CBateau bateau3("bateau3", make_pair(1,1), 3);
    CBateau bateau4("bateau4", make_pair(1,1), 3);

    armada.ajouterBateau(bateau1);
    armada.ajouterBateau(bateau2);
    armada.ajouterBateau(bateau3);
    armada.ajouterBateau(bateau4);

    pair <int, int> posBat1 = armada.getBateau(0)->getPosition();
    armada.getBateau(0)->tirAdverse(posBat1);
    posBat1.first += armada.getBateau(0)->getTaille()-1;
    armada.getBateau(0)->tirAdverse(posBat1);

    pair <int, int> posBat2 = armada.getBateau(1)->getPosition();
    posBat2.first += armada.getBateau(1)->getTaille()-1;
    armada.getBateau(1)->tirAdverse(posBat2);

    CCoups cCoups;

    pair<int, int> pos1 = make_pair(0,0);
    pair<int, int> pos2 = make_pair(1,1);
    cCoups.ajouterTirMap("touche", pos1);
    cCoups.ajouterTirMap("dansLEau", pos2);
    cCoups.ajouterTirMap("ploufAdverse", pos1);

    try {
        CGui cGui(&armada, &cCoups);
        cGui.positionnerBateaux();
        cout << cGui;
        cout << "OK : L'affichage des grilles a fonctionné." << endl;
    } catch (const char* msg) {
        cout << "ERREUR : L'affichage des grilles a échoué." << endl;
        cerr << msg << endl;
    }

}
