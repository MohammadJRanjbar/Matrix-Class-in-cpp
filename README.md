# Matrix-Class-in-cpp
In this homework you're going to estimate an AP student's grade again! but in a different method using Linear Algebra! As you might have guessed, you will be doing this by using some matrices and functions defined on them like determinant, inverse, transpose , etc. There are some Questions in this serie. Remember to write their answer in your report file. You must not alter any of the given prototypes, but you're free to add whatever you want to both Matrix.cpp, Matrix.h and aphw2.cpp, aphw2.h files. By the way, you must write ALL of your codes in those 4 files! You must not alter the main.cpp again!
# Matrix Class
Implement a Matrix class that represents a mathematical matrix. It must have a private data variable which is the data of the matrix. Besides, you must have the size of the matrix too. So your class will also have a private size variable which is a 2-element array of size_t. You must implement it with a std::array<size_t,2> data type. The first element of size will be number of rows and the second one will be number of columns. As it might have passed your mind, so far, user doesn't have any access to size since it is private, so you must implement getSize() function for the user in the public part.
# Matrix Properties
Matrix class must have the following constructors.
``` c++
Matrix(const Matrix& mat);
Matrix(std::vector<std::vector<double>> data);
Matrix(std::unique_ptr<std::unique_ptr<double[]>[]> data, size_t m, size_t n); where m and n are the number of rows and columns.
Matrix (size_t m, size_t n, bool ones=true); where m and n are number of rows and columns. if ones flag is true, each element of the matrix must be 1. Otherwise, it must be 0.
```
Matrix class must have the following member variables.

* data: Elements of your matrix. This variable must be private.
size: Number of rows and columns of your matrix, packed in a 2-element array. This variable must be private.
It must also have the following member functions.

* getSize: This function returns a 2-element array representing size of the matrix.

``` c++
std::array<size_t, 2> getSize();
```
* det: This function must return a double representing determinant of the matrix. If the matrix is not in the square form, it must return 0 and print a proper message.
``` c++
double det(); 
```
* inv: This function must return a matrix object representing inverse of the matrix. In the case the matrix not being square, you must print a proper message and return a matrix of all 0s with the same dimensions as the matrix.
``` c++
Matrix inv();
```
