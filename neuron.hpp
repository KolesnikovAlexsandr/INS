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
    double ActivationThreshold = 0;
    bool UseSigmoid = true;
    bool UseActivationfunc = false;
    double TrainingSpeed = 0.1;
    
    double SummFunc(double *MassOfSignal)
    {
        double temp = 0;
        for(int i = 0 ; i < NumberOfInput ; i++)
        {
            temp += MassOfSignal[i]*WeightInput[i];
        }
        return temp;
    }
    
    /*bool BackPropagation(double DesiredOutput , double *MassOfSignal)
    {
        double delta = 1;
        int counter = 0;
        while(getOutput() != DesiredOutput && delta > 0.000001 && counter < 1000)
            {
                SendSignal(MassOfSignal);
                delta = Output*(1 - Output)*(DesiredOutput - Output);
                for( int i = 0 ; i < NumberOfInput ; i++)
                {
                    WeightInput[i] +=TrainingSpeed*delta*Output;
                }
                counter++;
            }
        return true;
    }*/
public:
    neuron()
    {
        this->NumberOfInput = 0;
        this->WeightInput = 0;
    }
    
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
        if(UseSigmoid)
        {
            Output = 1/(1+exp(SummFunc(MassOfSignal)));
        }
        else if(UseActivationfunc)
        {
            if( SummFunc(MassOfSignal) > ActivationThreshold)
            {
                Output = 1;
            }
            else
            {
                Output = 0;
            }
        }
        else
        {
            Output = SummFunc(MassOfSignal);
        }
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
    
    void setActivationThreshold(double ActivationThreshold)
    {
        this->ActivationThreshold = ActivationThreshold;
    }
    void setModeSigmoid()
    {
        this->UseSigmoid = true;
        this->UseActivationfunc = false;
    }
    void setModePerceptron()
    {
        this->UseSigmoid = false;
        this->UseActivationfunc = true;
    }
    double getOutput()
    {
        return this->Output;
    }
    
};

#endif /* neuron_hpp */
