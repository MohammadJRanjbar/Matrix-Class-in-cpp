#ifndef APHW2_APHW2_H
#define APHW2_APHW2_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include <array>
#include <optional>
#include "Matrix.h"
#include <climits>

std::vector<std::vector<double>> getData(const char* address,bool add_bias=true);
std::optional<double> det(const Matrix&);
std::optional<Matrix> inv(Matrix&);
std::optional<Matrix> transpose(Matrix&);
Matrix findWeights(const char*);
Matrix predict(const char*, Matrix& w, bool disp=false);
size_t findMinNoOfMultiplications(std::vector<Matrix>& v);
size_t find(size_t, size_t, std::vector<size_t>, std::vector<std::vector<size_t>>&);

#endif //APHW2_APHW2_H
