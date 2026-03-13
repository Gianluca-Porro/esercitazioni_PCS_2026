#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
	string filename = argv[argc - 1];
	ifstream ifs(filename); // Apre il file in input
	if ( ifs.is_open() ) { // Controllo che il file sia aperto in modo corretto
		while (!ifs.eof() ) { // Fino alla fine del file
			string città;
			double temp1, temp2, temp3, temp4;
			ifs >> città >> temp1 >> temp2 >> temp3 >> temp4;
			
			if ( ifs.fail() ) break; // Così evito l'inserimento dell'ultima media una seconda volta
			
			double media = (temp1+temp2+temp3+temp4)/4.0;
			cout << città << " " << media << "\n";
		}
	}
	else {
		cerr << "errore di inserimento del file o errore di lettura\n"; // Messaggio di errore se if risulta falso
	}
	return 0;
}