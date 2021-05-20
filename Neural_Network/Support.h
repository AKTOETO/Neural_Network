#pragma once
#include "Constants.h"
#include <iostream>
#include <iomanip>

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

class Matrix
{
protected:
	int rows, cols;
	vvd matrix;

public:
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		matrix.resize(rows);
		
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i].resize(cols);
		}

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[i].size(); j++)
			{
				matrix[i][j] = double(rand() % 1000) / 1000;
			}
		}
	}

	friend const Matrix operator*(Matrix& mat, const int num)
	{
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				mat.matrix[i][j] *= num;
			}
		}
		return mat;
	}
	
	friend const Matrix operator*(Matrix& mat, Matrix& mat2)
	{
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				mat.matrix[i][j] *= mat2.matrix[i][j];
			}
		}
		return mat;
	}

	friend const Matrix operator+(Matrix& mat, const int num)
	{
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				mat.matrix[i][j] += num;
			}
		}
		return mat;
	}
	
	friend const Matrix operator+(Matrix& mat, Matrix& mat2)
	{
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				mat.matrix[i][j] += mat2.matrix[i][j];
			}
		}
		return mat;
	}

	friend ostream& operator<<(ostream& out, const Matrix& mat)
	{
		 for (vd el : mat.matrix)
		 {
			 out << "| ";
			 for (double num : el)
			 {
				 out << fixed << setprecision(3) << num << " ";
			 }
			 out << "|\n";
		 }
		 out << "\n";
		 return out;
	}
};
