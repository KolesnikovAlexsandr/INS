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

class NeuronLayer {
    int NumberOfNeuron;
    int NumberOfInputEachNeuron;
    neuron Layer  = new neuron[0];
public:
    NeuronLayer()
    {
        this->NumberOfNeuron = 0;
        this->NumberOfInputEachNeuron = 0;
    }
    NeuronLayer(int NumberOfNeuron , int NumberOfInputEachNeuron)
    {
        this->NumberOfNeuron = NumberOfNeuron;
        this->NumberOfInputEachNeuron = NumberOfInputEachNeuron;
        this->Layer = new neuron[NumberOfNeuron];
        for(int i = 0 ; i < NumberOfNeuron ; i++)
        {
            Layer[i]()
        }
    }
};
#endif /* NeuronLayer_h */
