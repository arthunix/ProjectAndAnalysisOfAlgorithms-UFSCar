/*
* Author : Arthur Eugenio Silverio
* Data	 : 18 / 04 / 2022
* See: https://en.wikipedia.org/wiki/BSD_licenses for 2-clause license ("Simplified BSD License")
* Copyright(c) 2022 Arthur Eugenio Silverio. All rights reserved.

* Class: Projeto e Análise de algoritmos
* Professor: Mario Cesar San Felice
*/

#include <fstream>
#include <string>
#include <iostream>

#define INT_MAX 2147483647
#define LLONG_MAX 9223372036854775807

long long int
minimumDifference(short int vectorOfValues[], short int SizeOfTheVector) {
    long long int sum=0;

    for(int i = 0; i < SizeOfTheVector; i++)
    {
		sum+=vectorOfValues[i];
	}
    
    bool** DynamicProgrammingTable;
	try{
		DynamicProgrammingTable = new bool*[SizeOfTheVector];
	} catch(std::bad_alloc& throw_error) {
		std::cerr << "Unable to allocate memory, bad_alloc on :" << throw_error.what() << "at minimumDifference()" << std::endl;
		EXIT_FAILURE;
	}
	for(int i = 0; i <= SizeOfTheVector; i++)
	{
		try{
			DynamicProgrammingTable[i] = new bool[sum/2 + 1];
		} catch(std::bad_alloc& throw_error) {
			std::cerr << "Unable to allocate memory, bad_alloc on :" << throw_error.what() << "at minimumDifference()" << std::endl;
			EXIT_FAILURE;
		}
	}

    for(short int i = 0; i <= SizeOfTheVector; i++)
    {
		for(long long int j=0; j < sum/2 + 1; j++)
		{
			if(j==0)
				DynamicProgrammingTable[i][j] = true;
			else if(i==0)
				DynamicProgrammingTable[i][j] = false;
			else if(vectorOfValues[i-1]>j)
				DynamicProgrammingTable[i][j] = DynamicProgrammingTable[i-1][j];
			else
				DynamicProgrammingTable[i][j] = DynamicProgrammingTable[i-1][j] || DynamicProgrammingTable[i-1][j-vectorOfValues[i-1]];
		}
	}
    
	/* We need to minimize the {sum - 2*first} */
    long long int diff = INT_MAX;
    for(int i = 0; i <= sum / 2; i++)
    {
        long long int first = i;
        long long int second = sum - i;
        if((DynamicProgrammingTable[SizeOfTheVector][i] == true) 
			&& (diff > abs(first-second)))
            diff = abs(first-second);
    }
    
    return diff;
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

    if (FILE.is_open())
    {
		short int SizeOfTheVector;
		while(FILE >> SizeOfTheVector)
		{
			if ((SizeOfTheVector) > 2)
			{
				short int* VectorOfValues;
				try{
					VectorOfValues = new short int[SizeOfTheVector];
				} catch(std::bad_alloc& throw_error) {
					std::cout << "Unable to allocate memory, bad_alloc on :" << throw_error.what() << std::endl;
				}

				for(short int i = 0; i < SizeOfTheVector; i++)
				{
					/* It seems to be insecure, consider to 
					change it to while(FILE >> ...) */
					(FILE >> VectorOfValues[i]);
				}

				std::cout << minimumDifference(VectorOfValues, SizeOfTheVector) << std::endl;
				delete[] VectorOfValues;
			}
		}
		FILE.close();
    }

    return 0;
}