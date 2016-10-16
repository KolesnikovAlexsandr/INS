//
//  neuron.hpp
//  INS
//
//  Created by Sasha on 16/10/2016.
//  Copyright © 2016 Sasha. All rights reserved.
//

#ifndef neuron_hpp
#define neuron_hpp

#include <stdio.h>
#include <iostream>
class neuron {
private:
    int NumberOfInput;
    double *WeightInput = new double[0];
    double Output;
    bool UseSigmoid = true;
    
    
public:
    
    neuron(int NumberOfInput , double *MassOfWeightInput)
    {
        this->NumberOfInput = NumberOfInput;
        this->WeightInput = new double[NumberOfInput];
        for(int i = 0 ; i < NumberOfInput ; i++)
        {
            this->WeightInput[i] = MassOfWeightInput[i];
        }
    }
    
    void PrintIformation()
    {
        std::cout<<"Number of input:"<<NumberOfInput<<std::endl;
        std::cout<<"Weight of input:";
        for(int i = 0 ; i < NumberOfInput ; i++)
        {
            std::cout<<WeightInput[i]<<" ";
        }
        std::cout<<std::endl;
    }
    
    void setNumberOfInput(int NumberOfInput);
    void setWeightOfInput(double WeightOfInput);
    double getOutput();
    
};

#endif /* neuron_hpp */
