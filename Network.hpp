#ifndef NETWORK_H
#define NETWORK_H
#include "Matrix.hpp"
#include "Layer.hpp"
#include "OutputLayer.hpp"
#include <vector>

using namespace std;

class Network{

    public:
            Network(int intputDim, vector<int> hidDim, int outputDim);
            //Network(int intputDim, vector<int> hidDim, int outputDim,vector<char*> fonctions_activations);
            void setCouche(Layer L);
            void dispaly_result();
            void calcul_fiabilite(Matrix TestYset);
            void train(Matrix TrainXset,Matrix TrainYset, double leaningRate);
            double test(Matrix TestXset);
            ~Network();

    private: 
            vector<Layer> couches;
            OutputLayer fcouche;
            void forward_propagation(Matrix TrainXset);
            void backward_propagation(Matrix TrainYset);
            void update_poids(double learningRate);
            double cross_entropy(Matrix TrainYset);


};
#endif
