#pragma once
#include "Constants.h"

// The activation function (sigmoid)
double activator(double num)
{
	return(1 / (1 + exp(-num)));
}

void out_vector(vd vec)
{
	for (auto el : vec)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}
