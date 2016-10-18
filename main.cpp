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
    NeuronLayer A(2,2);
    A.PrintIfo();
    return 0;
}
