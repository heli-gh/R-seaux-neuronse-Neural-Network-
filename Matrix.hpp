#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

class Matrix
{
private:
    
    

public:
    double **weight;
    int nbColumns;
    int nbRows;
    //! Constructeur (le parametre fait reference a la methode d initialisation de la matrice)
    
    /**
    @brief Constructeur par défaut de la classe, on a une matrice vide
    */
    Matrix();   

    /**
    @brief Constructeur de la classe, tous les poids de la matrice sont nuls
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */
    Matrix(int nbRowsParam, int nbColumnsParam);

    /**
    @brief Constructeur de la classe
    @param weightParam : le tableau 2D de double des poids
    @param nbRowsParam : le nombre de ligne de la matrice
    @param nbColumnsParam : le nombre de colonne de la matrice
    */
    Matrix(double **weightParam, int nbRowsParam, int nbColumnsParam);

    /**
    @brief Constructeur par copie
    @param other : la matrice que l'on copie
    */
    Matrix(const Matrix &other);

    //! Surcharge opérateur :
    /**
    @brief Surcharge de l'opérateur d'égalité
    @param A : la matrice à laquelle est égale la matrice que l'on revoie
    */
    Matrix &operator=(const Matrix &A);

    /**
    @brief Surcharge de l'opérateur d'addition
    @param A : la matrice que l'on additionne à droite de la matrice sur laquelle on appelle : this + A
    */
    Matrix operator+(const Matrix &A);

    /**
    @brief Surcharge de l'opérateur de soustraction
    @param A : la matrice que l'on soustrait à droite de la matrice sur laquelle on appelle : this + A
    */
    Matrix operator-(const Matrix& A);

    /**
    @brief Surcharge de l'opérateur de multiplication
    @param A : la matrice que l'on multiplie à droite de la matrice sur laquelle on appelle : this * A
    */
    Matrix operator*(const Matrix &A);

    /**
    @brief Affichage de la matrice this
    */
    void affichage();

    //! Destructeur (attention allocation dynamique)
    /**
    @brief Destructeur de la classe : libère la mémoire allouée pour le tableau 2D de double
    */
    ~Matrix();

    // Set & Get
    /**
    @brief Retourne un pointeur sur le tableau 2D de double
    */
    double **getPoids();

    /**
    @brief Retourne le poids à la position (i,j) dans le tableau des poids
    @param i : Ligne du double que l'on veut récupérer
    @param j : Colonne du double que l'on veut récupérer
    */
    double getPoidsIndex(int i, int j);

    /**
    @brief Retourne le nombre de ligne de la matrice
    */
    int getnbRows();

    /**
    @brief Retourne le nombre de colonne de la matrice
    */
    int getnbColumns();

    /**
    @brief Modifier l'un des poids du tableau 2D de poids
    @param i : la ligne du poids que l'on modifie
    @param j : la colonne du poids que l'on modifie
    @param poids : la nouvelle valeur du poids
    */
    void setPoids(int i, int j, double poids);

    /**
    @brief Modifier le nombre de ligne de la matrice
    @param R : le nouveau nombre de ligne
    */
    void setnbRows(int R);

    /**
    @brief Modifier le nombre de colonne de la matrice
    @param C : le nouveau nombre de colonne
    */
    void setnbColumns(int C);

    //! Modifier les poids pour qu'ils suivent des lois
    /**
    @brief Modifier les poids de la matrice pour qu'ils suivent une loi normale (mu,stddev)
    @param mu : la moyenne de la loi normale
    @param stddev : l'écart type de la loi normale
    */
    void creerGaussien(double mu, double stddev);

    /**
    @brief Modifier les poids de la matrice pour qu'ils suivent une loi uniforme (a,b)
    @param a : la borne inférieure de l'intervalle
    @param b : la borne supérieure de l'intervalle
    */
    void creerUniforme(double a, double b);

    //! Operations elementaires
    /**
    @brief Renvoyer la transposée de la matrice this
    */
    Matrix transposition();

    /**
    @brief Renvoyer le produit entre la constante et la matrice this
    @param c : la constante qui multiplie la matrice
    */
    Matrix cstMultMat(const double &c);

    /**
    @brief Renvoyer une matrice obtenue en faisant le produit entre un vecteur colonne et un vecteur ligne : this*A
    @param this : le vecteur colonne
    @param A : le vecteur ligne
    */
    Matrix vecteurMultVecteurT(const Matrix &A);

    /**
    @brief Renvoyer le produit scalaire :  < @param this , @param A >
    @param this : le vecteur ligne
    @param A : le vecteur colonne
    */
    double vecteurDot(const Matrix &A);

    /**
    @brief Renvoyer le produit matriciel d'Hadamard :  this * A
    @param this : la matrice à gauche du produit matriciel
    @param A : la matrice à droite du produit matriciel
    */
    Matrix multiplicationHadamard(const Matrix &A);

    /**
    @brief Renvoyer la ligne de la plus petite valeur du vecteur colonne
    @param this : le vecteur colonne
    */
    int elementGrand();

    /**
    @brief Ajouter une ligne vide à la fin de la matrice this
    */
    void ajouterLigneVide();

    /**
    @brief Ajouter la ligne @param Ligne en bas de la matrice this
    @param Ligne : un vecteur ligne
    */
    void ajouterLigne(const Matrix &Ligne);

    /**
    @brief Ajouter une colonne vide à la fin de la matrice this
    */
    void ajouterColonneVide();

    /**
    @brief Ajouter la colonne @param Colonne à droite de la matrice this
    @param Colonne : un vecteur colonne
    */
    void ajouterColonne(Matrix Colonne);

    /**
    @brief Renvoie une matrice composée uniquement des colonnes de @param debut à @param fin de la matrice this
    @param debut : indice de la première colonne à garder
    @param fin : indice de la dernière colonne à garder
    */
    Matrix troncature(int debut,int fin);

    /**
    @brief Faire la somme des éléments de la matrice
    */
    double element_sum();

    /**
    @brief Applique la fonction @param function sur chaque élément de la matrice
    @param function : fonction que l'on applique sur chaque élément de la matrice
    */
    void apply_function(double(*function)(double));
};

#endif
