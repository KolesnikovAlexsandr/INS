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
#include "neuron.hpp"
#include <ctime>
#include <list>

class NeuronLayer {
    
    private:
    
        int NumberOfNeuron;
        int NumberOfInputEachNeuron;
        double *WeightInputOfEachNeuron = new double[0];
        std::list<neuron> Layer;
    
    public:
    
        NeuronLayer()
        {
            this->NumberOfNeuron = 0;
            this->NumberOfInputEachNeuron = 0;
        }
    
        NeuronLayer(int NumberOfNeuron , int NumberOfInputEachNeuron)
        {
            srand(time(0));
            this->NumberOfNeuron = NumberOfNeuron;
            this->NumberOfInputEachNeuron = NumberOfInputEachNeuron;
            this->Layer.resize(0);
            this->WeightInputOfEachNeuron = new double [ NumberOfNeuron * NumberOfInputEachNeuron ];
            for(int i = 0 ; i< NumberOfNeuron ; i++)
            {
                for(int j = 0 ; j < NumberOfInputEachNeuron ; j++)
                {
                    this->WeightInputOfEachNeuron[ i * NumberOfNeuron + j ] = rand()%10;
                }
            }
            double *temp = new double[NumberOfInputEachNeuron];
            for(int i = 0 ; i < NumberOfNeuron ; i++)
            {
                for(int j = 0 ; j < NumberOfInputEachNeuron ; j++)
                {
                    temp[j] = WeightInputOfEachNeuron[ i * NumberOfNeuron + j ];
                }
                this->Layer.push_back(neuron( NumberOfInputEachNeuron ,temp));
            }
        }
            
        void PrintIfo()
        {
            std::cout<<"Number of neuron:"<<NumberOfNeuron<<std::endl;
            std::cout<<"Number of Input Each Neuron:"<<NumberOfInputEachNeuron<<std::endl;
            auto neuron = Layer.begin();
            for(int i = 0 ; i< NumberOfNeuron ; i++)
            {
                std::cout<<"Neuron Number "<<i<<std::endl;
                std::advance(neuron, i);
                neuron->PrintIfo();
            }
                
        }
    
        void setWeightInputOfEachNeuron(double *weight)
        {
            for(int i = 0 ; i < NumberOfNeuron ; i++)
            {
                for(int j = 0 ; j < NumberOfInputEachNeuron ; j++)
                {
                    this->WeightInputOfEachNeuron[ i * NumberOfNeuron + j ] = weight[i * NumberOfNeuron + j];
                }
            }
            
            double *temp = new double[NumberOfInputEachNeuron];
            auto neuron = Layer.begin();
            for( int i = 0 ; i < NumberOfNeuron ; i++ )
            {
                for( int j = 0 ; j < NumberOfInputEachNeuron ; j++ )
                {
                    temp[ j ] = WeightInputOfEachNeuron[ i * NumberOfNeuron + j ];
                }
                std::advance(neuron, i);
                neuron->setWeightOfInput(temp);
            }
        }
    
    
    
        void getReaction(double *Result_mass , double *Signal)
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
