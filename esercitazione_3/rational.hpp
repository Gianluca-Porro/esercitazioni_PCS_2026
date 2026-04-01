#include <iostream>
#include <concepts>

/* Definisco la funzione che mi peremtte di calcolare il MCD tra due numeri */
template<typename I>
I MCD(I a, I b) {
	while (b != 0) {
		I resto = a % b;
		a = b;
		b = resto;
	}
	return a;
}

/* Definisco la funzione che mi peremtte di calcolare il mcm tra due numeri */
template<typename I>
I mcm(I a, I b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	else {
		return (a * b)/ MCD(a, b);
	}
}

template<typename I> requires std::integral <I>
class rational
{
	I num_;
	I den_;
	
public:
	/* Costruttore di default */
	rational()
		: num_(0), den_(1)
	{}

	/* Costruttore user-defined */
	rational(I num, I den)
		: num_(num), den_(den)
	{
		if (num > 0 && den == 0) {
			num_ = 1;
			den_ = 0;
		}
		else if (num < 0 && den == 0) {
			num_ = -1;
			den_ = 0;
		}
		else if (num == 0 && den == 0) {
			num_ = 0;
			den_ = 0;
		}
		else {
			I comune = MCD(num, den);
			num_ = num / comune;
			den_ = den / comune;
			
			if (den_ < 0) {
				num_ = num_ * (-1);
				den_ = den_ * (-1);
			}
		}
	}
	
	/* Restituisco i valori di num e den */
	I num() const { return num_; }
	I den() const { return den_; }
	
	/* Implementazione "+=" */
	rational& operator+=(const rational& other) {
		num_ = num_*(mcm<I>(den_, other.den_)/den_) + other.num_*(mcm<I>(den_, other.den_)/other.den_);
		den_ = mcm<I>(den_, other.den_);
		
		*this = rational(num_, den_);
		
		return *this;
	}

	/* Implementazione "+" */
	rational operator+(const rational& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	
	/* Implementazione "-=" */
	rational& operator-=(const rational& other) {
		num_ = num_*(mcm<I>(den_, other.den_)/den_) - other.num_*(mcm<I>(den_, other.den_)/other.den_);
		den_ = mcm<I>(den_, other.den_);
		
		*this = rational(num_, den_);
		
		return *this;
	}
	
	/* Implementazione "-" */
	rational operator-(const rational& other) const {
		rational ret = *this;
		ret -= other;
		return ret;
	}
	
	/* Implementazione "*=" */
	rational& operator*=(const rational& other) {
		num_ = num_*other.num_;
		den_ = den_*other.den_;
		
		*this = rational(num_, den_);
		
		return *this;
	}
	
	/* Implementazione "*" */
	rational operator*(const rational& other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}
	
	/* Implementazione "/=" */
	rational& operator/=(const rational& other) {
		num_ = num_*other.den_;
		den_ = den_*other.num_;
		
		*this = rational(num_, den_);
		
		return *this;
	}
	
	/* Imlementazione "/"  */
	rational operator/(const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}
	
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
	if (r.num() == 1 && r.den() == 0) {
		os << "Inf";
	}
	else if (r.num() == -1 && r.den() == 0) {
		os << "-Inf";
	}
	else if (r.num() == 0 && r.den() == 0) {
		os << "NaN";
	}
	else if (r.num() == 0 && r.den() != 0) {
		os << 0;
	}
	else if (r.den() == 1) {
		os << r.num();
	}
	else {
		os << r.num() << "/" << r.den();
	}
	return os;
}