#include <fstream>
#include <iostream>
#include <string>
#include "BST.h"

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

using namespace std;

int main(int argc, char* argv[])
{
	VS_MEM_CHECK

	ifstream in(argv[1]);
	ofstream out(argv[2]);
	
	string input;
	bool tIntFString;
	BST<int> intBST;
	BST<string> stringBST;
	out << boolalpha;


	while (in >> input)
	{
		out << input;

		if (input == "INT")
		{
			out << " true" << " ";
			tIntFString = true;
		}

		else if (input == "STRING")
		{
			out << " true" << " ";
			tIntFString = false;
		}

		else if (input == "add")
		{
			in >> input;
			out << " " << input << " ";

			if (tIntFString)
			{
				out << intBST.addNode(atoi(input.c_str()));
			}
			else
			{
				out << stringBST.addNode(input);
			}
		}

		else if (input == "remove")
		{	
			in >> input;
			out << " " << input << " ";

			if (tIntFString)
			{
				out << intBST.removeNode(atoi(input.c_str()));
			}
			else
			{
				out << stringBST.removeNode(input);
			}
		}

		else if (input == "print")
		{
			if (tIntFString)
			{
				out << intBST;
			}
			else
			{
				out << stringBST;
			}
		}

		else if (input == "clear")
		{
			out << " ";
			if (tIntFString)
			{
				out << intBST.clearTree();
			}
			else
			{
				out << stringBST.clearTree();
			}
		}

		else if (input == "size")
		{
			out << " ";
			if (tIntFString)
			{
				out << intBST.getSize();
			}
			else
			{
				out << stringBST.getSize();
			}
		}

		else if (input == "find")
		{
			in >> input;
			out << " " << input << " ";

			if (tIntFString)
			{
				out << intBST.findNode(atoi(input.c_str()));
			}
			else
			{
				out << stringBST.findNode(input);
			}
		}

		else if (input == "tree")
		{
			out << " ";
			if (tIntFString)
			{
				out << intBST.iterTree();
			}
			else
			{
				out << stringBST.iterTree();
			}
		}
		out << endl;
	}

	intBST.clearTree();
	stringBST.clearTree();

	return 0;
}