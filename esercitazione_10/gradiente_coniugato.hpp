#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>

inline unsigned int gradiente_coniugato (const Eigen::MatrixXd& A, Eigen::VectorXd& x, const Eigen::VectorXd& b, double r_tol, unsigned int it_max) {
	Eigen::VectorXd r = b - A * x;
	Eigen::VectorXd p = r;
	double r_norm = r.norm();
	
	unsigned int it = 0;
	while (it < it_max && (r.norm() > r_tol * r_norm)) {
		/* alpha_k */
		double alpha_k = p.dot(r) / p.dot(A*p);
		
		/* Aggiornamento x */
		x = x + alpha_k * p;
		
		/* Aggiornamento r */
		r = r - alpha_k * (A*p);
		
		/* beta_k */
		double beta_k = p.dot(A*r) / p.dot(A*p);
		
		/* Aggiornamento p */
		p = r - beta_k * p;
		
		it++;
	}
	
	return it;
}