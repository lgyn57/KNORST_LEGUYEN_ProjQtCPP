#include "file.h"
#include "file.cpp"
#include <stdio.h>
#include <iostream.h>


int main(void)
{
	queue<int> s;

	for (int i = 1; i < 6; i++)
	{
		s.ajout(i*i);
		cout << "Ajout de " << i * i << "\n";
	}

	int valeur;
	for (int j = 0; j < 2; j++)
	{
		s.retrait(valeur);
		cout << "Retrait de " << valeur << "\n";
	}
	return 0;
}

