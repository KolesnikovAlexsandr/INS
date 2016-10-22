//
//  NeuronLayer.h
//  INS
//
//  Created by Sasha on 17/10/2016.
//  Copyright © 2016 Sasha. All rights reserved.
//

#ifndef NeuronLayer_h
#define NeuronLayer_h

#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Neuron.hpp"
#include <ctime>
#include <list>

class NeuronLayer {
    
    private:
    
        int NumberOfNeuron;
        int NumberOfInputEachNeuron;
        double *WeightInputOfEachNeuron = new double[0];
        std::list<Neuron> Layer;
    
    public:
    
        NeuronLayer()
        {
            this->NumberOfNeuron = 0;
            this->NumberOfInputEachNeuron = 0;
        }
    
        NeuronLayer(int NumberOfNeuron , int NumberOfInputEachNeuron)
        {
            srand( time( 0 ) );
            this->NumberOfNeuron = NumberOfNeuron;
            this->NumberOfInputEachNeuron = NumberOfInputEachNeuron;
            this->Layer.resize(0);
            this->WeightInputOfEachNeuron = new double [ NumberOfNeuron * NumberOfInputEachNeuron ];
            double *temp = new double[ NumberOfInputEachNeuron ];
            for(int EachNeuron = 0 ; EachNeuron < NumberOfNeuron ; EachNeuron++ )
            {
                for(int EachInputOfNeuron = 0 ; EachInputOfNeuron < NumberOfInputEachNeuron ; EachInputOfNeuron++)
                {
                    this->WeightInputOfEachNeuron[  NumberOfNeuron*EachNeuron + EachInputOfNeuron ] = rand()%10;
                    temp[EachInputOfNeuron] = WeightInputOfEachNeuron[ EachNeuron * NumberOfNeuron + EachInputOfNeuron ];
                }
                this->Layer.push_back(Neuron( NumberOfInputEachNeuron ,temp));
            }

        }
            
        void PrintIfo()
        {
            std::cout<<"Number of neuron:"<<NumberOfNeuron<<std::endl;
            std::cout<<"Number of Input Each Neuron:"<<NumberOfInputEachNeuron<<std::endl;
            auto Neuron = Layer.begin();
            for(int i = 0 ; i< NumberOfNeuron ; i++)
            {
                std::cout<<"Neuron Number "<<i<<std::endl;
                std::advance(Neuron, i);
                Neuron->PrintIfo();
            }
                
        }
    
        void setWeightInputOfEachNeuron(double *weight)
        {
            auto Neuron = Layer.begin();
            double *temp = new double[NumberOfInputEachNeuron];
              for(int EachNeuron = 0 ; EachNeuron < NumberOfNeuron ; EachNeuron++ )
              {
                for(int EachInputOfNeuron = 0 ; EachInputOfNeuron < NumberOfInputEachNeuron ; EachInputOfNeuron++)
                {
                    this->WeightInputOfEachNeuron[  NumberOfNeuron*EachNeuron + EachInputOfNeuron ] = weight[NumberOfNeuron*EachNeuron + EachInputOfNeuron ];
                    temp[EachInputOfNeuron] = WeightInputOfEachNeuron[ EachNeuron * NumberOfNeuron + EachInputOfNeuron ];
                }
                  
                std::advance(Neuron, EachNeuron);
                Neuron->setWeightOfInput(temp);
            }
        
        }
    
    
    
        void getReactionOfLayer(double *Result_mass , double *Signal)
        {
            auto neuron = Layer.begin();
            for(int i = 0 ; i < NumberOfNeuron ; i++)
            {
                std::advance(neuron, i);
                neuron->SendSignal(Signal);
                Result_mass[i]  = neuron->getOutput();
            }
        }
};

#endif /* NeuronLayer_h */
