# Matrix-Class-in-cpp
In this homework you're going to estimate an AP student's grade again! but in a different method using Linear Algebra! As you might have guessed, you will be doing this by using some matrices and functions defined on them like determinant, inverse, transpose , etc. There are some Questions in this serie. Remember to write their answer in your report file. You must not alter any of the given prototypes, but you're free to add whatever you want to both Matrix.cpp, Matrix.h and aphw2.cpp, aphw2.h files. By the way, you must write ALL of your codes in those 4 files! You must not alter the main.cpp again!
# Matrix Class
Implement a Matrix class that represents a mathematical matrix. It must have a private data variable which is the data of the matrix. Besides, you must have the size of the matrix too. So your class will also have a private size variable which is a 2-element array of size_t. You must implement it with a std::array<size_t,2> data type. The first element of size will be number of rows and the second one will be number of columns. As it might have passed your mind, so far, user doesn't have any access to size since it is private, so you must implement getSize() function for the user in the public part.
# Matrix Properties
Matrix class must have the following constructors.
``` c++
Matrix(const Matrix& mat);
Matrix(std::vector<std::vector<double>> data);
Matrix (std::unique_ptr<std::unique_ptr<double[]>[]> data, size_t m, size_t n);
```
