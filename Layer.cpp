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

Layer::Layer(int Nbe, int Nbs)
{
      this->Nbe=Nbe;
      this->Nbs=Nbs;
}

//! Fonctions


 Matrix Layer::Sortie() {
	 //! Matrice des poids ce sont les precedentes (de la couche avant)
    
     //! produit matrice vecteur avec W : matrice des poids , I vecteur des entrees, X, vecteur des sortiesX = W * I


 
    sortie = arete * entree;
     //! Applique la fonction d'activation a toutes les sorties
	
    activation(sortie);
    
    return sortie;
}


void Layer::activation(Matrix col) {

	for (int i = 0; i < (col.nbRows); i++) {
		
	//! Applique la fonction d'activation a toutes les neurones du vecteur en entree
     sortie.weight[i][0] = fonctionActivation(col.weight[i][0]);
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
	return d;
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
		for(int j=1;j<=arete.nbColumns;j++)
		{
			//Calcul de la somme pondérées des poids pour le neurone de sortis j
			Ij=L.arete.weight[j][0];
			s=0;
			for(int k=0;k<arete.nbRows;k++)
			{
				Ij=Ij+arete.weight[k][j]*sortie[j][0];
				s=s+L.d.weight[k][0]*arete.weight[k][j];
			}
			dj=dfonctionActivation(Ij)*s;
			d.weight[0][j]=dj;
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

//! Genere et assigne des poids aleatoires à cette couche
//! Donne un intervalle entre -1/sqrt(numInput) a +1/sqrt(numInput)
void Layer::PoidsAleatoires() {
	;
}


double Layer::fonctionActivation(double x) {
  
  //Fonction sigmoide standard 
    return 1 / (1 + std::exp(-x));
}


double Layer::dfonctionActivation(double x) {
  
  //Derivee de la fonction d'activation
	
    return fonctionActivation(x)*(1-fonctionActivation(x));
}

Layer::~Layer()
{
}
