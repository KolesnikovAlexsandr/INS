//
//  main.cpp
//  INS
//
//  Created by Sasha on 16/10/2016.
//  Copyright © 2016 Sasha. All rights reserved.
//

#include <iostream>
#include "neuron.hpp"
#include "NeuronLayer.h"

int main(int argc, const char * argv[]) {
    std::cout<<"Start"<<std::endl;
    double *Reaction = new double[2];
    double *Signal = new double[2];
    Signal[0] = 0.5;
    Signal[1] = 0.2;
    NeuronLayer A(2,2);
    A.PrintIfo();
    A.getReaction(Reaction, Signal );
    for(int  i= 0 ; i < 2 ; i++)
    {
        std::cout<<Reaction[i]<<" ";
    }
    return 0;
}
