#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <cmath>
#include <array>
#include <memory>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>      
#include <random>
#include <optional>

class Matrix
{
private:
	//initializing the matrix size and data
	std::array<size_t, 2> size{ 0,0 };
	std::vector<std::vector<double>> data;


public:

    Matrix(const Matrix &mat) = default;
    Matrix (std::vector<std::vector<double>> d);
    Matrix (size_t m, size_t n, bool ones=true);
    Matrix (std::unique_ptr<std::unique_ptr<double[]>[]>& a, size_t m, size_t n);
    Matrix ();
    Matrix(std::optional<Matrix>);
    Matrix operator-(Matrix a);
    Matrix operator+(Matrix a);  
    std::vector<double>& operator[](size_t i);
    Matrix operator*(Matrix a);
    std::array<size_t, 2> getSize();
    double det() const;
    Matrix inv();
    Matrix T();
    Matrix delCol(size_t i);
    Matrix delRow(size_t i);
    Matrix col(size_t i);
    void save(const char*);
    void load(const char*);
    void show();
};

#endif //APHW2_MATRIX_H