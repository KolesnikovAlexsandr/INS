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

class NeuronLayer {
    
    private:
        int NumberOfNeuron;
        int NumberOfInputEachNeuron;
        double *WeightInputOfEachNeuron = new double[0];
        neuron *Layer;
    
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
            this->Layer = new neuron[NumberOfNeuron];
            this->WeightInputOfEachNeuron = new double [ NumberOfNeuron * NumberOfInputEachNeuron ];
            for(int i = 0 ; i< NumberOfNeuron ; i++)
            {
                for(int j = 0 ; j < NumberOfInputEachNeuron ; j++)
                {
                    this->WeightInputOfEachNeuron[ i * NumberOfNeuron + j ] = 0.1;
                }
            }
            double temp = *new double[NumberOfInputEachNeuron];
            for(int i = 0 ; i < NumberOfNeuron ; i++)
            {
                for(int j = 0 ; j < NumberOfInputEachNeuron ; j++)
                {
                    temp[j] = WeightInputOfEachNeuron[ i * NumberOfNeuron + j ];
                }
                this->Layer[i](NumberOfInputEachNeuron, temp);
            }
        }
            
        void PrintIfo()
        {
            std::cout<<"Number of neuron:"<<NumberOfNeuron<<std::endl;
            std::cout<<"Number of Input Each Neuron:"<<NumberOfInputEachNeuron<<std::endl;
            std::cout<<"Weight of input:";
            for(int i = 0 ; i< NumberOfNeuron ; i++)
            {
                std::cout<<"Neuron Number "<<i<<std::endl;
                for(int j = 0 ; j < NumberOfInputEachNeuron ; j++)
                {
                    std::cout<<"Weight of Input"<<WeightInputOfEachNeuron[i*NumberOfNeuron+j] << " ";
                }
                std::cout<<std::endl;
        }
    }
};
#endif /* NeuronLayer_h */
