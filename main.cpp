//
//  main.cpp
//  INS
//
//  Created by Sasha on 16/10/2016.
//  Copyright © 2016 Sasha. All rights reserved.
//

#include <iostream>
#include "neuron.hpp"


int main(int argc, const char * argv[]) {
    double *weight = new double[2];
    double *Signal = new double[2];
    std::cout<<"Start"<<std::endl;
    weight[0] = 0.1;
    weight[1] = 0.2;
    Signal[0] = 1;
    Signal[1] = 0;

    
    //std::cout<<A.getOutput()<<std::endl;
    return 0;
}
