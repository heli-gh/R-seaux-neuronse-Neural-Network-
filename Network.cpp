#include "Network.h"

using namespace std;

Network::Network(const int inputDim,const vector<int> hidDim,const int outputDim)
{
    hidDim.push_back(outputDim);
    int h0=inputDim , h1=hidDim[0];
    
    this->couches(vector());
    Layer* couche = new Layer(h0+1,h1); 
    this->couches.emplace_back(move(*couche)); // std::move()
    for (int i=1;i< hidDim.size();i++ )
    {
        h0=h1;
        h1=hidDim[i];
        Layer couche(new Layer(h0+1,h1));
        this->couches.emplace_back(move(couche));
    }
    Output_layer* f = new Output_layer (outputDim,outputDim);
    this->fcouche = *f// Output_layer constructor, est ce que layer peut copy value 
    //this->couches.emplace_back(move(*f)); //problème
    

}

void Network::forward_propagation(Matrix& TrainXset)
{
    /*Forward propagate the provided inputs through the Network
    * update the matrix arete for all the layers
    **/
   //add exception for the matrix*matrix 
   //setNeurones not in diag //image is a vector 
   this->couches[0].setNeurones(AjouterLighe1(TraineXset));
   
   for (int i =1 ; i< this->couches.size() ; i++)
   {
        this->couches[i].activation(this->couches[i-1]);//logique,stockage
   }
   this->fcouche.activation(this->couches[this->couches.size()]);
   //apply function softmax//obtenue resultats
}

double Network::cross_entropy(Matrix& TrainYset){
    /* Calculate cross entropy loss if the predictions and true values are given
    **/
   int batch_size = TrainYset.getrows();
   Matrix z = this->fcouche.getNeurons().applyfunction(log);
   z= z.multiply(TrainYset);
   double error=element_sum(z);
   return (-error/batch_size);

}
void Network::backward_propagation(Matrix& TrainYset){
    /*
     *  Compute deltas of each layer 
     *  delta_L : delta of the final layer 
     **/
    Matrix delta_L=this->fcouche.getNeurones()-TrainYset; //soustraction
    couches(couches.size()-1).setDeltas(delta_L);//setDelta
    for(int i = this-> couches.size()-2;i>=0;i--) 
        couches[i].calculerDelta(couches[i+1]);//dimension
    
}
void Network::update_weight(double learningRate){
    /*batch gradient descent with batch size as number of training examples
    **/
   Matrix z; 
   for (int i=1 ; i<= couches.size()-1;i++){
        z= Matrix.transpose(couches[i-1].getNeurones());//static?
        z= Matrix.multiplication(z,couches[i].getDeltas());//sequence
        z= Matrix.multiplication(z,(learningRate/couches[i].getNeurones().getrows))//double 
        couches[i].setarete(couches[i].getarete()-z);//setget
   }
       /* z= Matrix.transpose(fcouche.getNeurones());//static?
        z= Matrix.multiplication(z,couches[couches.size()-2].getDeltas());//sequence
        z= Matrix.multiplication(z,(learningRate/couches[couches.size()-1].getNeurones().getrows))//double 
        couches[couches.size()].setarete(couches[i].getarete()-z);//setget*/
}
void Network::train(Matrix& TrainX ,Matrix & TrainY,double learningRate,int batch_size,int epochs=10)
{
    /* Train the Neural Network and change weights
        train epochs times with dataset 
    **/
   int e=0;
   while (e< epoches){

    int it =0; 
    double error = 0;
    while (it+ batch_size< Xtrain.getrows()){
        Matrix TrainXset =Matrix(&TrainX[it],&TrainX[it+batch_size]);
         //size 
        Matrix TrainYset = Matrix(&TrainY[it],&TrainY[it]);

        forward_propagation(TrainXset);
        error += cross_entropy(TrainYset);
        backward_propagation(TrainYset);
        update_weight(learningRate);
        it+=batch_size;
    }


    e++;
   }


}
double Network::test(Matrix& TestX, Matrix& TestY,int batchsize)
{
    /* Calculer the validation error over the Test set;
     * 
     */
    int it =0 ;
    double error =0;
    double fiabilite=0;
    int turn =0;

    while (it + batch_size < TestX.getrows())
    {
        Matrix TestXset =Matrix(&TestX[it],&TestX[it+batch_size]);
         //size 
        Matrix TestYset = Matrix(&TestY[it],&TestY[it]);

        forward_propagation(TestXset);
        error += cross_entropy(TestYset);
        fiabilite += calcul_fiabilite(TestYset);

        turn++;
    }
    fiabilite /= turn;
    return fiabilite;
    
}
double Network::calcul_fiabilite(Matrix& Y)
{
    return Matrix.count(fcouche.getresult()-Y)/Y.getrows();//Matrix count
}

