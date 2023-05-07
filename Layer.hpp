#ifndef __LAYER_HPP__
#define __LAYER_HPP__

#include "Matrix.hpp"
#include "Neurone.hpp"

#include <list>
using std::list;

class Layer
{
private:
    list<Neurone> neurones;
    //! Nombre de neurones que l'on a en entrée
    int Nbe;
    //! Nombre de neurones que l'on a en sortie
    int Nbs;   
    
    //! Vecteur des biais de la couche
    Matrix biais;
    
    /**
    @brief Fonction qui permet d'appliquer la fonction d'activation aux éléments d'un vecteur
    @param colParam : le vecteur auquel on veut appliquer la fonction d'activation
    
    */
    void activation(Matrix<double> col);
    
    

    //! Matrice contenant les poids des aretes reliant cette couche a la suivante
    Matrix arete;
    
    //! Matrice contenant les delta de chaque poids 
    Matrix delta;
    
    //! Vecteur des entrees
    Matrix entree;
    
    //! Vecteur des sorties
    Matrix sortie;
    
    //! Vecteur des etiquettes
    Matrix etiq;
    
     //! Vecteur des delta_j
    Matrix d;
    
    
    
    
    
    /**
        @brief Permet de definir la fonction d'activation
        @param xParam : le reel pour lequel on souhaite calculer la fonction d'activation

    */

    double fonctionActivation(double x);
    
    
     
    /**
        @brief Permet de definir la derivee de la fonction d'activation
        @param xParam : le reel pour lequel on souhaite calculer la derivee de la fonction d'activation

    */
    
    double Layer::dfonctionActivation(double x);
     
        
   
    /**
        @brief Getters
    
    */

    /**
         @brief Retourne le vecteur des entrees
    
    */  
    Matrix<double> getEntree();
    
    /**
        @brief Retourne la matrice des poids
    
    */

    Matrix<double> getPoids();
    
    
    /**
        @brief Retourne le vecteur des sorties
    
    */
    
    Matrix<double> getSortie();
    
    /**
        @brief Retourne la matrice des delta
    
    */

    Matrix<double> getDelta() ;
    

    /**
         @brief Retourne le vecteur des etiquettes
    
    */

    Matrix<double> getEtiq();
    
    
    /**
        @brief Retourne le vecteur des delta_j
    
    */

    Matrix<double> getD();    
    
    //! Setter
    
    /**
    @brief Permet de donner des valeurs aux élèments de la matrice des poids des neurones de la couche 
    @param eParam : matrice
    */
    void setPoids(Matrix<double> s);
    
    /**
    
    @brief Permet de donner des valeurs aux élèments la matrice des poids des neurones de la couche
    
    */
        
    void PoidsAleatoires();
    
    
     /**
        @brief Permet de donner une valeur au vecteur des entrees de la couche
        @param eParam : vecteur 
   
    */
    void setEntree(Matrix<double> e);
    
    
    /**
        @brief Permet de donner une valeur au vecteur des etiquettes des neurones de la couche
        @param eParam : vecteur 
    */
    
    void setEtiquette(Matrix<double> et);
    
    
    

public:
    
    //! Constructeurs
    
    /**
    @brief Constructeur de la classe, la couche n'a aucun neurone
       
    */

    Layer();
   

    /**
        @brief Constructeur de la classe, la couche a Nbe neurones
        @param NbeParam : le nombre de neurones de la couche
        @param NbsParam : le nombre de neurones de la couche suivante
    */
    Layer(int Nbe, int Nbs);
    
    


    /**
        @brief Fonction qui permet de remplir le vecteur des sorties
    
    */
    Matrix<double>Layer::sortie()

   
    /**
        @brief Fonction qui Permet de calculer la matrice des deltas pour la mise a jour des poids
        @param LParam : Couche qui suit la couche actuelle
    
    */
    void calculerDelta(Layer L);
    
    //! Affiche les poids de la matrice de poids
    /**
        @brief Permets d'afficher la matrice des poids
    
    */

    void displayWeight();
   

    //! Destructeur
    ~Layer();
};

#endif
