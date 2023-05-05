#ifndef NETWORK_H
#define NETWORK_H
#include "Matrix.h"
#include "Layer.h"

using namespace std;

class Network{

    public:
            Network(int intputDim, vector<int> hidDim, int outputDim);
            void setCouche(Layer L);
            void dispaly_result();
            void calcul_fiabilite(Matrix TestYset);
            void train(Matrix TrainXset,Matrix TrainYset, double leaningRate);
            double test(Matrix TestXset);

    private: 
            vector<Layer> couches;
            Output_layer fcouche;
            void forward_propagation(Matrix TrainXset);
            void backward_propagation(Matrix TrainYset);
            void update_poids(double learningRate);
            double cross_entropy(Matrix TrainYset);

};
#endif
