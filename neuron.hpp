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
#include <math.h>
class neuron {
private:
    int NumberOfInput;
    double *WeightInput = new double[0];
    double Output = NULL;
    bool UseSigmoid = true;
    
    double SummFunc(double *MassOfSignal)
    {
        double temp = 0;
        for(int i = 0 ; i < NumberOfInput ; i++)
        {
            temp += MassOfSignal[i]*WeightInput[i];
        }
        return 1/(1+exp(temp));
    }
    
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
    
    void SendSignal(double *MassOfSignal)
    {
        Output = SummFunc(MassOfSignal);
    }
    
    void PrintIfo()
    {
        std::cout<<"Number of input:"<<NumberOfInput<<std::endl;
        std::cout<<"Weight of input:";
        for(int i = 0 ; i < NumberOfInput ; i++)
        {
            std::cout<<WeightInput[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void setWeightOfInput(double *MassOfWeightInput)
    {
        for(int i = 0 ; i < NumberOfInput ; i++)
        {
            this->WeightInput[i] = MassOfWeightInput[i];
        }
    }
    double getOutput()
    {
        return this->Output;
    }
    
};

#endif /* neuron_hpp */
