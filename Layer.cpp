#include "Layer.hpp"
#include <random>
#include <iostream>

//! TACHES: Telecharger et configurer visual studio

//! Constructeurs de layer 

Layer::Layer()
{
      this->Nbe=0;
      this->Nbs=0; 
}

Layer::Layer(int ne, int ns, Matrix nentree, Matrix narete, Matrix nbiais, Matrix netiq, Matrix ndelta)
{
	 
      Nbe=ne;
      Nbs=ns;
	  arete=narete;
	  biais=nbiais;
	  etiq=netiq;
	  delta=ndelta;
	  entree=nentree;


}

//! Fonctions


 Matrix Layer::Sortie() {
	 //! Matrice des poids ce sont les precedentes (de la couche avant)
    
     //! produit matrice vecteur avec W : matrice des poids , I vecteur des entrees, X, vecteur des sorties X = W * E
	
    sortie = arete * entree;

	//! Cette sortie ne prend pas en compte les w_0 du coup on va les rajouter:

	for(int i=0;i<sortie.getnbRows();i++)
			sortie.weight[i][0]=sortie.weight[i][0]+biais.weight[i][0];

	//! sauvegarde la valeur du produit matriciel sortie*entree avant transformation avec la fonction d'activation 

	I=sortie;

     //! Applique la fonction d'activation a toutes les sorties
	
    activation(sortie);
    
    return sortie;
}


void Layer::activation(Matrix col) {

	for (int i = 0; i < (col.nbRows); i++) {
		
	//! Applique la fonction d'activation a toutes les neurones du vecteur en entree
     sortie.weight[i][0] = Fonction.sigmoid(col.weight[i][0]);
	}
}

Matrix Layer::getEntree() {
	return entree;
}

Matrix Layer::getPoids() {
	return arete;
}

Matrix Layer::getSortie() {
	return sortie;
}

Matrix Layer::getDelta() {
	return delta;
}

Matrix Layer::getEtiq() {
	return etiq;
}


Matrix Layer::getD() {
	return delta;
}

 void Layer::setEntree(Matrix e) {
	entree = e;
    }

 void Layer::setEtiquette(Matrix et) {
	etiq = et;
    }

void Layer::setPoids(Matrix w) {
	arete = w;
    }

void Layer::calculerDelta(Layer L)
{
	double Ij;
	double dj;
	double s;
	double n=1;
	
	
	for (int i=0;i<arete.nbRows;i++)
	{
		for(int j=0;j<=arete.nbColumns;j++)
		{
			//Calcul de la somme pondérées des poids pour le neurone de sortis j
			Ij=L.arete.weight[j][0];
			s=0;
			for(int k=0;k<arete.nbRows;k++)
			{
				s=s+L.delta.weight[k][0]*arete.weight[k][j];
			}
			dj=Fonction.sigmoid_derivative(I.weight[j][0])*s;
			delta.weight[0][j]=dj;
			if (j-1==0)
				delta.weight[i][j-1]=n*dj * L.biais.weight[j-1][0];
			else
				delta.weight[i][j-1]=n*dj*sortie.weight[i][0];
			
		}
		
	
	
	}
}

void Layer::displayWeight()
{
	std::cout<<"Affichage de la matrice des poids"<<std::endl;
	for (int i=0;i<arete.nbRows;i++)
	{
		std::cout<<"Neurone_entree "<<i+1<<std::endl;
		for (int j=0;j<arete.nbColumns;i++)
		{	
			if(j==0)
				std::cout<<"w_0= "<<arete.weight[i][0]<<std::endl;
			else
				std::cout<<"w_"<<j<<"= "<<arete.weight[i][j]<<std::endl;
		}
		
	}
}


Layer::~Layer()
{
}
