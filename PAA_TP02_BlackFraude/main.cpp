/*
* Author : Arthur Eugenio Silverio
* Data	 : 25 / 03 / 2022
* See: https://en.wikipedia.org/wiki/BSD_licenses for 2-clause license ("Simplified BSD License")
* Copyright(c) 2022 Arthur Eugenio Silverio. All rights reserved.

* Class: Projeto e Análise de algoritmos
* Professor: Mario Cesar San Felice
*/

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

// typedef int (__cdecl* _CoreCrtNonSecureSearchSortCompareFunction)(void const*, void const*);
int compareLongLongIntegerFunctionInverse(const void* firstValue, const void* secondValue)
{
    return (*(long long int*)secondValue - *(long long int*)firstValue);
}

int main(int argc, char* argv[])
{
    std::string FILE_NAME;

	if (argc != 1)
	{
		std::cout << "Incorrect number of parameters Ex: ./executable" << std::endl;
		return 0;
	}
	std::cin >> FILE_NAME;
	std::ifstream FILE(FILE_NAME);

	long long int discount = 0;

    if (FILE.is_open())
    {
		long long int SizeOfTheVector;
		FILE >> SizeOfTheVector;
        if ((SizeOfTheVector) > 2)
        {
			long long int* VectorOfValues;
			try{
            		VectorOfValues = new long long int[SizeOfTheVector];
			} catch(std::bad_alloc& throw_error) {
				std::cout << "Unable to allocate memory, bad_alloc on :" << throw_error.what() << std::endl;
			}

			for(int i = 0; i < SizeOfTheVector; i++)
			{
				/* It seems to be insecure, consider to 
				change it to while(FILE >> ...) */
				(FILE >> VectorOfValues[i]);
			}
			qsort(VectorOfValues, SizeOfTheVector, sizeof(long long int), compareLongLongIntegerFunctionInverse);
			for(int i = 2; i < SizeOfTheVector; i += 3)
			{
				discount += VectorOfValues[i];
			}
			delete[] VectorOfValues;
		}
		FILE.close();
    }

	std::cout << discount << std::endl;

    return 0;
}