//
// Created by Bogdan on 3/10/2018.
//

#include "bst.h"
#include <iostream>

using namespace std;

nod::nod(int number = 0, nod* left = NULL, nod* right = NULL){
    /* Constructorul de initializare cu valori predefinite.
     Poarta rol si de constructor cu parametrii si fara parametrii */
    this->left = left;
    this->right = right;
    this->info = number;
}

nod::nod(const nod& node){
    /* Constructor de copiere */
    if (&node) {
        /* Daca nodul care urmeaza sa fie copiat este diferit de nul,
        copiem datele din el */
        this->info = node.info;
        this->left = node.left;
        this->right = node.right;
    }

    else{
        /* Daca acesta este nul, constructorul se comporta ca cel de initializare */
        this->info = 0;
        this->left = NULL;
        this->right = NULL;
    }
}

nod::~nod() {
    this->left = NULL;
    this->right = NULL;
}

ABC::ABC(){
    this->root = NULL;
}

ABC::ABC(const ABC& abc){
    /* In constructorul de copiere apelam metoda privata recursiva copyHelper */
    root = copyHelper(abc.root);
}

ABC::~ABC() {
    delete root;
}

nod* ABC::copyHelper(nod * toCopy) {
    if (toCopy == NULL)
        return NULL;

    /* Daca nodul curent nu e nul, copiem ambii subarbori ai sai */
    nod* copyNode = new nod(toCopy->getInfo());
    copyNode->setLeftNode( copyHelper(toCopy->getLeftNode()) );
    copyNode->setRightNode( copyHelper(toCopy->getRightNode()) );
    return copyNode;
}

const ABC& ABC::operator=(const ABC & abc) {
    /* Daca pointerul this e diferit de adresa obiectului parametru,
    adica nu apelam in main abc = abc */
    if (this != &abc) {
        if (root == NULL)
            root = new nod(abc.root->getInfo());
        else
            root->setInfo(abc.root->getInfo());

        /* Schimbam fiii obiectului curent, cu fiii parametrului */
        nod *auxLeft = root->getLeftNode();
        root->setLeftNode(new nod( *(abc.root->getLeftNode()) ));
        delete auxLeft;

        nod *auxRight = root->getRightNode();
        root->setRightNode(new nod( *(abc.root->getRightNode()) ));
        delete auxRight;
    }

    return *this;
}

nod* ABC::insertHelper(nod * node, int value) {
    /* Daca arborele este gol, inseram noul nod in radacina */
    if (node == NULL)
        return new nod(value);

    /* Daca noul nod trebuie inserat la stanga */
    if (value < node->getInfo())
        node->setLeftNode( insertHelper(node->getLeftNode(), value) );

    /* Daca noul nod trebuie inserat la dreapta */
    else if (value > node->getInfo())
        node->setRightNode( insertHelper(node->getRightNode(), value) );

    return node;
}

const ABC& ABC::operator+(int value) {
    /* Daca arborele este gol adaugam valoarea direct in radacina,
    altfel inseram normal */

    if (root == NULL)
        root = insertHelper(NULL, value);
    else
        insertHelper(root, value);
    return *this;
}

/* Urmeaza metodele SRD, RSD, SDR obisnuite care primesc ca parametru, in plus, fluxul de date de iesire */
void ABC::SRD(ostream& outStream, nod * node) {
    if (node) {
        SRD(outStream, node->getLeftNode());
        outStream << node->getInfo() << " ";
        SRD(outStream, node->getRightNode());
    }
}

void ABC::RSD(ostream& outStream, nod * node) {
    if (node) {
        outStream << node->getInfo() << " ";
        RSD(outStream, node->getLeftNode());
        RSD(outStream, node->getRightNode());
    }
}

void ABC::SDR(ostream& outStream, nod * node) {
    if (node) {
        SDR(outStream, node->getLeftNode());
        SDR(outStream, node->getRightNode());
        outStream << node->getInfo() << " ";
    }
}

ostream& operator<<(ostream& outStream, const ABC& abc) {
    ABC bst = abc;

    /* Apelam metodele private RSD, SRD, SDR pentru a afisa arborele */
    outStream << endl << "Preordine (RSD): ";
    bst.RSD(outStream, bst.getRoot());
    outStream << endl;

    outStream << "Inordine (SRD): ";
    bst.SRD(outStream, bst.getRoot());
    outStream << endl;

    outStream << "Postordine (SDR): ";
    bst.SDR(outStream, bst.getRoot());
    outStream << endl;

    return outStream;
}

istream& operator>>(istream& inStream, ABC& abc){
    int verticesNumber;

    do{
        /* Citim numarul de noduri cu restrictia ca acesta sa fie pozitiv si nenul */
        cout << endl << "Introduceti numarul de noduri din arbore: ";
        inStream >> verticesNumber;
    } while (verticesNumber <= 0);

    for (int i = 0; i < verticesNumber; i++){
        int value;

        do{
            /* Citim valoarea de adaugat in arbore cu restrictia ca aceasta sa nu fie deja in arbore */
            cout << "Introduceti elementul cu nr " << i + 1 <<": ";
            inStream >> value;
        } while (abc.isValueInTree(value));

        /* Daca am trecut de restrictii, adaugam valoarea in arbore prin folosirea operatorului supraincarcat "+" */
        abc = abc + value;
    }
    return inStream;
}

nod* ABC::findMinNode(nod* node) {
    /* Metoda privata care cauta nodul cel mai din stanga arborelui ( adica nodul cu valoare minima ) */
    if (node == NULL)
        return NULL;
    while (node->getLeftNode())
        node = node->getLeftNode();
    return node;
}

nod* ABC::deleteNode(nod * node, int value) {
    /* Cautam nodul care trebuie sa fie sters din arbore */
    if (node == NULL)
        return NULL;
    else if (value < node->getInfo())
        node->setLeftNode( deleteNode(node->getLeftNode(), value) );
    else if (value > node->getInfo())
        node->setRightNode( deleteNode(node->getRightNode(), value) );
    else{
        /* Am gasit nodul de sters si verificam cati fii are */
        if (node->getLeftNode() && node->getRightNode()){
            /* Daca nodul are doi fii, locul ii va fi luat de minimul din dreapta */
            nod* auxNode = findMinNode(node->getRightNode());
            node->setInfo(auxNode->getInfo());

            /* Dupa ce am schimbat informatia din nodul de sters, completam subarborele lui drept */
            node->setRightNode( deleteNode(node->getRightNode(), node->getInfo()) );
        }
        else{
            /* Daca nodului ii lipseste cel putin un fiu, verificam cazurile
            ( 1 fiu drept / 1 fiu stang / 0 fii ) */
            nod* auxNode = node;
            if (node->getLeftNode() == NULL)
                node = node->getRightNode();
            else if (node->getRightNode() == NULL)
                node = node->getLeftNode();

            delete auxNode;
            auxNode = NULL;
        }
    }
    return node;
}

void ABC::deleteNode(int value) {
    root = deleteNode(root, value);
}

int ABC::treeHeight(nod* node){
    if (node == NULL)
        return 0;

    int leftHeight = 0, rightHeight = 0;

    /* Daca nodul are fiu drept sau stang, parcurgem recursiv subarborele respectiv pentru a-i afla inaltimea */
    if (node->getLeftNode())
        leftHeight = treeHeight( node->getLeftNode() );
    if (node->getRightNode())
        rightHeight = treeHeight( node->getRightNode() );

    return 1 + max(leftHeight, rightHeight);
}

int ABC::treeHeight(){
    return treeHeight(root);
}

void ABC::printLeaves(nod* node){
    if (node == NULL)
        return;

    /* Daca am gasit un nod frunza ( adica nu are nici fiu stang, nici fiu drept ) il afisam */
    if (node->getLeftNode() == NULL && node->getRightNode() == NULL){
        cout << node->getInfo() << " ";
        return;
    }

    /* Daca nu am gasit nodul, parcurgem recursiv subarboriele stang, respectiv cel drept */
    if (node->getLeftNode())
        printLeaves(node->getLeftNode());
    if (node->getRightNode())
        printLeaves(node->getRightNode());
}

void ABC::printLeaves(){
    printLeaves(root);
}

bool ABC::isValueInTree(nod* node, int value){
    /* Daca am ajuns pe nul, iseamna ca valoarea nu a fost gasita in arbore */
    if (node == NULL)
        return false;

    /* Apelam recursiv metoda pentru a gasi valoarea cautata, iar daca nu ajungem pe nul, returnam true */
    if (value < node->getInfo())
        return isValueInTree(node->getLeftNode(), value);
    if (value > node->getInfo())
        return isValueInTree(node->getRightNode(), value);

    return true;
}

bool ABC::isValueInTree(int value){
    return isValueInTree(root, value);
}

void displayMenu(){
    cout << endl << endl << "1) Adaugare element ( + ) " << endl;
    cout << "2) Citire arbore ( >> ) " << endl;
    cout << "3) Afisare arbore ( << ) " << endl;
    cout << "4) Stergere element " << endl;
    cout << "5) Inaltime arbore " << endl;
    cout << "6) Afisare lista frunze " << endl;
    cout << "7) Testare citire, stocare intr-o structura si afisare a n arbori" << endl << endl;
    cout << "0) Iesire " << endl << endl;
}

int main() {
    ABC abc;
    ABC* forest;

    int optiune;
    int number;

    displayMenu();
    cout << "Introduceti optiunea aleasa: ";
    cin >> optiune;
    cout << endl;

    while (optiune){
        switch (optiune){
            case 0: break;

            case 1: // Operatorul "+"
                cout << endl << "Introduceti numarul de adaugat in arbore: ";
                cin >> number;
                if (abc.isValueInTree(number)){
                    cout << endl << "Valoarea introdusa exista deja in arbore ";
                    break;
                }
                abc = abc + number;
                break;

            case 2: // Operatorul ">>"
                cin >> abc;
                break;

            case 3: // Operatorul "<<"
                if (abc.getRoot() == NULL){
                    cout << endl << "Arborele este gol";
                    break;
                }

                cout << abc;
                break;

            case 4: // Sterge nod
                if (abc.getRoot() == NULL){
                    cout << endl << "Arborele este gol";
                    break;
                }
                cout << endl << "Introduceti elementul de sters din arbore: ";
                cin >> number;
                if (abc.isValueInTree(number) == false){
                    cout << endl << "Valoarea introdusa nu se afla in arbore ";
                    break;
                }
                abc.deleteNode(number);
                break;

            case 5: // Inaltimea arborelui
                if (abc.getRoot() == NULL){
                    cout << endl << "Arborele este gol";
                    break;
                }

                cout << endl << "Inaltimea arborelui este " << abc.treeHeight();
                break;

            case 6: // Afisarea frunzelor arborelui
                if (abc.getRoot() == NULL){
                    cout << endl << "Arborele este gol";
                    break;
                }
                cout << endl << "Lista frunzelor arborelui: ";
                abc.printLeaves();
                break;

            case 7: // Citirea, stocarea si afisarea unui vector de arbori
                cout << endl << "Introduceti numarul de arbori care urmeaza sa fie cititi: ";
                cin >> number;

                forest = new ABC[number];
                for (int i = 0; i < number; i++){
                    cout << endl << "SE VOR INTRODUCE DATELE PENTRU ARBORELE NR. " << i + 1;
                    cin >> forest[i];
                }

                for (int i = 0; i < number; i++){
                    cout << endl << "ARBORELE NR. " << i + 1 << ": ";
                    cout << forest[i];
                }
                break;

            default: // Cazul care nu apartine intervalului [0, 7]
                cout << endl << "Optiunea introdusa nu este valida";
                break;
        }

        displayMenu();
        cout << "Introduceti optiunea aleasa: ";
        cin >> optiune;
        cout << endl;
    }
    return 0;
}
