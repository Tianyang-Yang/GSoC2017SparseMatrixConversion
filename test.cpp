//Student: Yang Tianyang 

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void print_matrix_cpp(S4 object) {
	//Type of the sparse matrix
	CharacterVector type = object.slot("class");
	Rcout << "Type:\t" << type << "\n";

	//Dimension of the matrix, 
	//x@Dim in R
	IntegerVector dim = object.slot("Dim");
	Rcout << "Dim:\t" << dim << "\n";

	//Row numbers of non-zero elements, calculated from zero
	//sorted by columns
	//x@i in R
	IntegerVector i = object.slot("i");
	Rcout << "length of i:\t" << i.size() << "\n";
	Rcout << "value of i: " << i << "\n";

	//Accumulated numbers of non-zero elements of columns
	//the number of non-zero elements in ith column obtained by p[i+1]-p[i]
	//x@p in R
	IntegerVector p = object.slot("p");
	Rcout << "length of p:\t" << p.size() << "\n";
	Rcout << "value of p: " << p << "\n";

	//The values of non-zero elements
	//sorted by columns
	//x@x in R
	NumericVector x = object.slot("x");
	Rcout << "length of x:\t" << x.size() << "\n";
	Rcout << "value of x: " << x << "\n";
}