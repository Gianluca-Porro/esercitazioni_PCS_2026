#include <iostream>
#include <cstdlib>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include "gradiente_coniugato.hpp"

double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(int argc, char **argv) {
	const double tol = 1.0e-15;
	unsigned int n = 3;
	
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	
	if (std::abs(B.determinant()) < tol) {
		std::cerr << "Matrice causale con determinante nullo\n";
		return EXIT_FAILURE;
	}
	
	Eigen::MatrixXd A = B.transpose() * B;
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
	
	Eigen::VectorXd b = A * x_ex;
	
	/* x_0 */
	Eigen::VectorXd x = Eigen::VectorXd::Zero(n);
	
	const unsigned int it_max = 10000;
	const double r_tol = 1.0e-12;
	
	std::cout.precision(2);
    std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;
	
	unsigned int it = gradiente_coniugato(A, x, b, r_tol, it_max);
	
	Eigen::VectorXd r = b - A * x;
	double r_norm = r.norm();
	
	const auto err_rel = (x_ex.norm() == 0.0) ? (x - x_ex).norm() :
												(x - x_ex).norm() / x_ex.norm();
	
	std::cout.precision(4);
    std::cout<< std::scientific<< "it"<< "/"<< "it_max"<< std::endl;
    std::cout<< std::scientific<< it<< "/"<< it_max<< std::endl;
    std::cout<< std::scientific<< "r"<< "/"<< "r_tol"<< std::endl;
    std::cout<< std::scientific<< r.norm() / r_norm<< "/"<< r_tol<< std::endl;
    std::cout<< std::scientific<< "err_rel"<< std::endl;
    std::cout<< std::scientific<< err_rel<< std::endl;
    std::cout<< std::scientific<< "soluzione"<< std::endl;
    std::cout<< std::scientific<< x << std::endl;
	
	/* Controllo fallimento */
	double r_rel = r.norm() / b.norm();
	
	double cond = condA(A);
	
	if (it >= it_max) {
		std::cerr << "Le iterazioni hanno superato la soglia massima\n";
		return EXIT_FAILURE;
	}
	
	if (r_rel > r_tol) {
		std::cerr << "Residuo relativo troppo grande\n";
		return EXIT_FAILURE;
	}
	
	if (err_rel > cond * r_rel) {
		std::cerr << "Errore numerico\n";
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;
}