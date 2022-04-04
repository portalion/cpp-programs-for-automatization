#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

int main()
{
	const std::string NAME = "MichalWozniak";
	const std::string END = ".pdf";

	char filename;
	char newName;
	int all;

	std::cout << "Give me letter to change (for example 'E'): ";
	std::cin >> newName;
	std::cout << "\nGive me number of files: "; 
	std::cin >> all;

	filename = newName - 1;

	std::stringstream strs;
	std::string before, after;

	while(all > 0)
	{
		strs << NAME << filename << all << END;
		before = strs.str();
		strs.str(std::string()); //Clear stringstream

		strs << NAME << filename << all << END;
		after = strs.str();
		strs.str(std::string()); //Clear stringstream

		int result = std::rename(before.data(), after.data());
		if (result != 0) std::cerr << "CANNOT RENAME FILE: " << before << '\n';
		all--;
	}
}
