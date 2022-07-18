/*
* Author : Arthur Eugenio Silverio
* Data	 : 15 / 02 / 2022
* See: https://en.wikipedia.org/wiki/BSD_licenses for 2-clause license ("Simplified BSD License")
Copyright(c) 2021 Arthur Eugenio Silverio. All rights reserved.

* Class: Projeto e Análise de algoritmos
* Professor: Mario Cesar San Felice
*/

#include <iostream>
#include <fstream>
#include <string>

bool RecursiveGeneticEquivalence(std::string StringToAnalyseA, std::string StringToAnalyseB, int SizeOfTheStringToAnalyse, int StartOfTheStringToAnalyse = 0)
{
	if (!(StringToAnalyseA.compare(StringToAnalyseB)))
	{
		return true;
	}
	else
	{
		if (SizeOfTheStringToAnalyse == 1)
		{
			return false;
		}
	}

	std::string Al = StringToAnalyseA.substr(StartOfTheStringToAnalyse, SizeOfTheStringToAnalyse / 2);
	std::string Ar = StringToAnalyseA.substr((SizeOfTheStringToAnalyse / 2), SizeOfTheStringToAnalyse / 2);
	std::string Bl = StringToAnalyseB.substr(StartOfTheStringToAnalyse, SizeOfTheStringToAnalyse / 2);
	std::string Br = StringToAnalyseB.substr((SizeOfTheStringToAnalyse / 2), SizeOfTheStringToAnalyse / 2);

	return (((RecursiveGeneticEquivalence(Al, Bl, SizeOfTheStringToAnalyse / 2) && (RecursiveGeneticEquivalence(Ar, Br, SizeOfTheStringToAnalyse / 2))))
		|| ((RecursiveGeneticEquivalence(Al, Br, SizeOfTheStringToAnalyse / 2) && (RecursiveGeneticEquivalence(Ar, Bl, SizeOfTheStringToAnalyse / 2)))));
}

int main(int argc, char* argv[])
{
	std::string FILE_NAME;

	if (argc != 1)
	{
		std::cout << "Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel" << std::endl;
		return 0;
	}
	std::cin >> FILE_NAME;
	std::ifstream FILE(FILE_NAME);

	if (FILE.is_open())
	{
		int SizeOfTheStrings;
		std::string ReadStringA;
		std::string ReadStringB;
		while (FILE >> SizeOfTheStrings >> ReadStringA >> ReadStringB)
		{
			if (SizeOfTheStrings != 0)
			{
				if (RecursiveGeneticEquivalence(ReadStringA, ReadStringB, SizeOfTheStrings))
				{
					std::cout << "SIM" << std::endl;
				}
				else
				{
					std::cout << "NAO" << std::endl;
				}
			}
		}
		FILE.close();
	}

	return 0;
}