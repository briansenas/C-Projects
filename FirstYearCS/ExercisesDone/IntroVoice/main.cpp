#include <iostream>
#include <string>
#include <ctime>
#include <stdafx.h>
#include <sapi.h>

int main(int argc, char* argv[])
{	std::string Response[] = {
		"HELLO",
		"HOW ARE YOU?",
		"BYE.",
		"AWSOME.",
		"SHAZAM!!!"
	};

	srand((unsigned) time(NULL));

	std::string sInput = "";
	std::string sResponse = "";

	int nSelection =0;

	srand((unsigned) time(NULL));

	while(1) {
		std::cout << ">";
		std::getline(std::cin, sInput);

		nSelection = rand() % 5;
		sResponse = Response[nSelection];
		std::cout << sResponse << std::endl;

		if(sInput == "q")   //a way to break the loop !
		{	std::cout << "CYA LATER XD";
			break;
		}
	}
char temp;
cin >> temp; //simple pause before exiting

return 0;
}
