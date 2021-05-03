#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

#include "Constants.h"
#include "Support.h"

using namespace std;

class Perceptron
{
protected:
	vd weights;
	double current_error = 1;

public:
	Perceptron()
	{
		weights.resize(2);
		for (int i = 0; i < weights.size(); i++)
		{
			weights[i] = double(rand() % 1000) / 1000;
		}
	}

	double guess(vd inputs)
	{
		double sum = 0;
		for (int i = 0; i < weights.size(); i++)
		{
			sum += inputs[i] * weights[i];
		}
		double output = activator(sum);
		return output;
	}	

	void train(vd inputs, double target)
	{
		double _guess = guess(inputs);
		current_error = target - _guess;
		//cout << "error: " << current_error << endl;

		for (int i = 0; i < weights.size(); i++)
		{
			weights[i] += current_error * inputs[i] * learningRate;
		}
		/*cout << "weights: ";
		out_vector(weights);*/
	}

	double get_error()
	{
		return current_error;
	}

	void print_weights()
	{
		cout << "weights: ";
		out_vector(weights);
	}

};


int main()
{
	srand(time(0));
	/*
	* A B A&B
	* 0 0  0
	* 0 1  0
	* 1 0  0
	* 1 1  1
	*/
	vvd inputs = {
		{0, 0},
		{0, 1},
		{1, 0},
		{1, 1}
	};

	vd target = {
		0, 0, 0, 1
	};

	Perceptron p;
	int number_of_train = 2, count_of_epoh = 0;

	while (abs(p.get_error()) > 0.001)
	{
		p.train(inputs[number_of_train], target[number_of_train]);
		count_of_epoh++;
		/*double guess = p.guess(inputs[number_of_train]);
		cout << "guess: " << guess << endl;
		cout << "###########################\n";*/
	}
	cout << "epohs: " << count_of_epoh << endl;
	p.print_weights();
	cout << "error: " << fixed << setprecision(2) << abs(p.get_error()) * 100 << "%\n";
	cout << "guess: " << p.guess(inputs[number_of_train]) << "\n";
	cout << "current target: " << fixed << setprecision(1) << target[number_of_train] << endl;

	return 0;
}
