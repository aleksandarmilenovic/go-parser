#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct ParserNode
{
	std::string player;
	std::string move;

	ParserNode(const std::string& pl, const std::string& mv)
	{
		player = pl;
		move = mv;
	}
};

std::vector<ParserNode> nodeList;

void readCharByChar(const std::string& in)
{
	bool semiColon = false;
	std::string temp("");
	std::string potez("");

	for (int i = 0; i < in.length(); i++)
	{
		if (semiColon == true && in[i] == ';')
		{
			i++;
			temp += in[i];
			i += 2;
			potez += in[i];
			i++;
			potez += in[i];

			nodeList.push_back(ParserNode(temp, potez));

			temp = "";
			potez = "";
		}

		if (in[i] == ';' && semiColon == false)
		{
			semiColon = true;
		}
	}
}

int main(void)
{
	std::ifstream file;
	std::string fileName;

	std::cout << "Enter the file name: ";
	std::getline(std::cin, fileName);

	file.open(fileName);

	std::string tmp("");

	std::string fileIn("");

	while (!file.eof())
	{
		std::getline(file, tmp);
		fileIn += tmp;
	}

	std::cout << fileIn;

	readCharByChar(fileIn);
	
	for (int i = 0; i < nodeList.size(); i++)
	{
		std::cout << "Player: " << nodeList[i].player << std::endl;
		std::cout << "Move: " << nodeList[i].move << std::endl;
	}

	file.close();
	std::cin.get();
	return 000;
}