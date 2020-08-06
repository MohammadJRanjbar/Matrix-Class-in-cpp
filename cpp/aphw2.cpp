#include "aphw2.h"

std::vector < std::vector <double> > getData(const char* FileAddress, bool add_bias)
{	
	
	std::ifstream Grades;
	//open the file 
	Grades.open(FileAddress);
	size_t rows{ 0 };
	size_t cols{ 0 };
	std::string line;
	//find out how may rows and coulmns it has 
	while (std::getline(Grades, line))
		rows++;
	Grades.clear();
	Grades.seekg(0, std::ios_base::beg);
	while (getline(Grades, line, ','))
		cols++;

	cols = (cols - 1) / rows + 1;
	//make a matrix
	std::vector<std::vector<double>> data;
	std::string A{};
	std::string B{};
	Grades.close();
	Grades.open(FileAddress);
	//and convert string that is in file to double and save it in the matrix
	for (size_t i = 0; i < rows; i++)
	{
		std::vector<double>D;
		if (add_bias == true)
		{
			D.push_back(1);
		}
		for (size_t j=1; j < cols; j++)
		{
			getline(Grades, A, ',');
			D.push_back(std::stod(A));
		}
		getline(Grades, B, '\n');
		D.push_back(std::stod(B));
		data.push_back(D);

	}
	Grades.close();
	return data;
}
Matrix findWeights(const char* FileAddress)
{
	std::vector<double> d;
	std::vector<std::vector<double>> x;
	x = getData(FileAddress, 1);
	Matrix M{ x };
	std::array<size_t, 2> A = M.getSize();
	//split the features and grades in two matrices
	Matrix Y{ M.col(A[1] - 1) };
	Matrix X{ M.delCol(A[1] - 1) };
	//with this formula we calculate the weights
	Matrix W{ (((X.T())*X).inv())*(X.T())*Y };
	return W;


}
Matrix predict(const char* FileAddress, Matrix& w, bool disp)
{
	std::vector<std::vector<double>> x;
	x = getData(FileAddress, 1);
	Matrix M{ x };
	std::array<size_t, 2> A = M.getSize();
	//split the features and grades in two matrices
	Matrix X{ M.delCol(A[1] - 1) };
	Matrix Y{ X*w };
	//if we had grade more than 20 or under 0 we give it a logical grade
	A = Y.getSize();
	for (size_t i = 0; i < A[0]; i++)
	{
		if (Y[i][0] > 20)
			Y[i][0] = 20;
		if (Y[i][0] < 0)
			Y[i][0] = 0;
	}
	if (disp == true)
	{
		Y.show();
	}
	return Y;

}
std::optional<double> det(const Matrix& mat )
{
	return mat.det();
}
std::optional<Matrix> inv(Matrix& mat)
{	
	//in inverse function in calss i detrminated that if the det is zeros return a message with a zeros matrix
	return mat.inv();
}
std::optional<Matrix> transpose(Matrix& mat)
{
	return mat.T();
}
size_t findMinNoOfMultiplications(std::vector<Matrix>& v)
{

	std::vector<size_t> S;
	//we make a vector and give it matrices sizes 
	for (size_t i = 0; i < v.size(); i++)
	{
		S.push_back((v[i].getSize())[0]);
	}
	S.push_back((v[v.size() - 1].getSize())[1]);

	size_t n = S.size() ;

	std::vector<std::vector<size_t>> m(n, std::vector<size_t>(n,0));
	return find(1, n - 1,S,m);


}
size_t find(size_t i, size_t j, std::vector<size_t> p, std::vector<std::vector<size_t>>& m)
{
	if (i == j) //only one matrix
		return 0;
	if (m[i][j] != 0) //it's already calculated.
		return m[i][j];
	size_t min = INT_MAX;
	size_t count;

	// place parenthesis at different places  
	// between first and last matrix, recursively  
	// calculate count of multiplications for  
	// each parenthesis placement and return the  
	// minimum count 
	for (size_t k = i; k < j; k++)
	{
		count = find(i, k,p,m) +
			find(k + 1, j, p, m) +
			p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count 
	return min;
}