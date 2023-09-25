#include <iostream>
#include <iomanip>
#include <locale>
#include <fstream>
#include<string>
#include<sstream>

#pragma once 


#define multiplier(x,y) (x * y)

using namespace std;
using std::cout;
using std::cin;


// Pour faire un triangle il faut :
// 1 : verifier la hauteur
// 2 : verifier la largeur
// 3 : On d�finit l'aire
// 4 : On d�finit le p�rimetre
// 5 : On fait une fct qui affiche 'hauteur/largeur/aire/p�rimetre)
// 6 : On dessine le p�rimetre
// 7 : On dessine l'aire


class Rectangle
{
private:
	int width;
	int height;
public:	
	void setWidth(int width);
	void setHeight(int height);
	int getArea();
	int getPerimeter();
	void print();
	void drawArea(const char& pattern);
	void drawPerimeter(const char& pattern);
};

void Rectangle::setWidth(int w) {

	if (w > 10) {
		cout << "La taille doit etre inferieur a 10 !" << endl;
		cout << "width : " << endl;
		cin >> w;
	}
	if (w <= 10)
	{
		width = w;
	}

	
}













void TextRectangle::setHeight(int h)
{
	if (h > 10)
	{
		cout << "Height must be <= 10" << endl;
		cout << "Height : " << endl;
		cin >> h;
	}
	if (h <= 10)
	{
		height = h;
	}
}
int TextRectangle::getArea()
{
	return width * height;
}

int TextRectangle::getPerimeter()
{
	return 2 * width + 2 * height;
}
void TextRectangle::print()
{
	cout << "Width : " << width << endl;
	cout << "Height : " << height << endl;
	cout << "Area : " << getArea() << endl;
	cout << "Perimeter : " << getPerimeter() << endl;
}

void TextRectangle::drawArea(const char& pattern)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << pattern;
		}
		cout << endl;
	}
}

void TextRectangle::drawPerimeter(const char& pattern)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				cout << pattern;
			}
			else
			{
				if (i == 0 || i == height - 1)
				{
					cout << pattern;
				}
				else
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
}
 

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
	cout << multiplier(a, b) << endl;
	
	// LEs 2 lignes suivantes permettent d'effacer l'�cran de la console
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

	//EXERCICE 3 :  Ecrire un programme C++ qui analyse un texte � partir d�un fichier en affichant le nombre de lignes, de mots et de lettres (l�utilisation de la classe �stringstream� est pr�conis�e voire imp�ratif).

	ifstream file;
	file.open("text.txt");
	string line;
	string word;

	int nbline = 0;
	int nbword = 0;
	int nblettres = 0;

	int tab[255] = {};

	if (file.is_open()) {  // On ouvre le fichier texte
		while (!file.eof()) { // tant qu'il n'est pas ferm�
			getline(file, line); // on r�cupere le nombre de lignes
			nbline++;			// On incr�mente alors notre nombre de lignes
			stringstream ss(line);   // stringstream permet � une cha�ne de caract�res d'�tre trait�e comme un flux 
			while (ss >> word) {    // tant que la ligne � des mots 
				for (auto &c : word) { // on regarde les mots
					c = tolower(c);				// met tt en minuscule
					if (isalpha(c)) ++tab[c];  // isalpha permet de voir si le caractere est alphab�thique et post-incr�mente le tableau
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

	// Exercice 4 


	//char rect;
	//int w, h;
	//TextRectangle rectangle;
	//cout << "Enter a width : " << endl;
	//cin >> w;
	//cout << "Enter a height : " << endl;
	//cin >> h;
	//rectangle.setWidth(w);
	//rectangle.setHeight(h);
	//rectangle.print();
	//cout << "Entrez un caract�re : ";
	//cin >> rect;
	//cout << endl;
	//rectangle.drawArea(rect);
	//cout << endl;
	//rectangle.drawPerimeter(rect);


}


	