#pragma once

#include <iostream>
#include <algorithm>

template<typename T>
class unidirected_edge
{
private:
	T from_;
	T to_;
	
public:
	/* Costruttore di default */
	unidirected_edge()
		: from_(T()), to_(T())
	{}
	
	/* Costruttore user-defined */
	unidirected_edge(T pfrom_, T pto_) {
		from_ = std::min(pfrom_, pto_);
		to_ = std::max(pfrom_, pto_);
	}
	
	/* Restituisco i valori di from e to */
	T from() const { return from_; }
	T to() const { return to_; }
};

/* Implementazione operator< */
template<typename T>
inline bool operator<(const unidirected_edge<T>& a, const unidirected_edge<T>& b)
{
	if (a.from() != b.from()) {
		return a.from() < b.from();
	}
	else {
		return a.to() < b.to();
	}
}

/* Implementazione operator== */
template<typename T>
inline bool operator==(const unidirected_edge<T>& a, const unidirected_edge<T>& b)
{
	return (a.from() == b.from() && a.to() == b.to());
}

/* Implementazione operator<< */
template<typename T>
inline std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& arco)
{
	os << "[" << arco.from() << " - " << arco.to() << "]";
	return os;
}