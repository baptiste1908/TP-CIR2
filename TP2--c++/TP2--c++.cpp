#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include<string>
#include<sstream>

#define multiplier(x,y) ((x) * (y))

using namespace std;
using std::cout;
using std::cin;


int main()
{
	setlocale(LC_ALL, "fr-FR");

	// EXERCICE 1

	int a;
	int b;
	cout << "Entrez une valeur :" << endl;
	cin >> a;
	cout << "Entrez une autre valeur :" << endl;
	cin >> b;
	cout << multiplier(a + 1, b + 1) << endl;
	
	// LEs 2 lignes suivantes permettent d'effacer l'écran de la console
	system("PAUSE");
	system("CLS");

	// EXERCICE 2

	int c;
	cout << "Entrer un nombre entre 1 et 9 :" << endl; // comme un printf
	cin >> c; // comme un scanf
	
	for (int i = 1; i <= 10; i++) {
		cout << multiplier(c, i) << " | ";
	}
	cout << endl;
	system("PAUSE");
	system("CLS");

	// 2e version de la table de multiplication 
	cout << "Avec la librairie iomanip : " << endl;
 	for (int i = 1; i <= 10; i++) {
		cout << setw(50) << multiplier(c, i) << endl; // la valeur dans setw(..) permet de placer ou l'on veut la colonne de nombre sur la page
	}
	system("PAUSE");
	system("CLS");

	//EXERCICE 3 :  Ecrire un programme C++ qui analyse un texte à partir d’un fichier en affichant le nombre de lignes, de mots et de lettres (l’utilisation de la classe «stringstream» est préconisée voire impératif).

	ifstream file;
	file.open("text.txt");
	string line;
	string word;

	int nbline = 0;
	int nbword = 0;
	int nblettres = 0;

	int tab[255] = {};

	if (file.is_open()) {  // On ouvre le fichier texte
		while (!file.eof()) { // tant qu'il n'est pas fermé
			getline(file, line); // on récupere le nombre de lignes
			nbline++;			// On incrémente alors notre nombre de lignes
			stringstream ss(line);   // stringstream permet à une chaîne de caractères d'être traitée comme un flux 
			while (ss >> word) {    // tant que la ligne à des mots 
				for (auto &c : word) { // on regarde les mots
					c = tolower(c);				// met tt en minuscule
					if (isalpha(c)) ++tab[c];  // isalpha permet de voir si le caractere est alphabéthique et post-incrémente le tableau
				}
				nbword++; // on incremente alors le nombre de mot
				nblettres += word.size(); // on incremente ensuite le nombre de lettre en fonction de la taille des mots
				}
			}
		}
	file.close();  // Enfin, on ferme le fichier 
	// Et on affiche les lettres, lignes, mots.
	cout << "Le nombre de line est de " << nbline << endl;
	cout << "Le nombre de mots est de " << nbword << endl;
	cout << "Le nombre de lettres est de " << nblettres << endl;

	system("PAUSE");
	system("CLS");

	for (auto i = 0; i < 255; i++)
	{
		if (tab[i]) cout << char(i) << " : " << tab[i] << endl;
	}
	system("PAUSE");
	system("CLS");
}


	