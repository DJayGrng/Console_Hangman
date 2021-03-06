// Project 4.cpp : Defines the entry point for the console application.
//Created by-Djay Grng
//

#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
void printTree(int guess)//Prints the Hangman
{
	cout << "\n\n\n";
	if (guess == 1)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "-------\n";
	}
	if (guess == 2)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << " * |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "-------\n";
	}
	if (guess == 3)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << " * |\n";
		cout << " | |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "-------\n";
	}
	if (guess == 4)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << " * |\n";
		cout << "-| |\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "-------\n";
	}
	if (guess == 5)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << " * |\n";
		cout << "-|-|\n";
		cout << "   |\n";
		cout << "   |\n";
		cout << "-------\n";
	}
	if (guess == 6)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << " * |\n";
		cout << "-|-|\n";
		cout << "/  |\n";
		cout << "   |\n";
		cout << "-------\n";
	}
	if (guess == 7)
	{
		cout << "  _\n";
		cout << " | |\n";
		cout << " * |\n";
		cout << "-|-|\n";
		cout << "/ \\|\n";
		cout << "   |\n";
		cout << "-------\n";
	}
}
int guess(string name, char caps[])//Makes the user guess
{
	int num,count=0;
	cout << name << endl;
	char guess;
	cout << "Make a guess ?\t";
	cin >> guess;
	for (int i = 0; i < name.length(); i++)
	{
		if (guess == tolower(name[i]))
		{
			caps[i] = guess;
			  count = 1;
		}
	}
	if (count == 1)
		return 1;
	else
		return -1;
}
void readFile(string file)//Inputs file from user
{
	int ans;
	char choice,caps[20];
	string capital,name;
	ifstream infile(file);
	int cnt = 0, random,tries=1;
	if (infile.fail())
	{
		cout << "Sorry, file could not be opened !!";
		return;
	}
	infile.clear();
	infile.ignore();
	while (getline(infile, capital))
	{
		cnt++;
	}
	random = rand() % cnt + 1;
	infile.close();
	infile.open(file);
	cnt = 0;
	while (getline(infile,capital))
	{
		cnt++;
		if (cnt == random)
		{
			cout << capital << endl;
			for (int i = 0; i < capital.length() ; i++)
			{
				if (capital[i] == ' ')
				{
					caps[i] = ' ';
					cout << " ";
				}
				if (capital[i] == ',')
				{
					caps[i] = ',';
					cout << ",";
				}
				if (capital[i] != ',' && capital[i] != ' ')
				{
					caps[i] = '-';
					cout << "-";
				}
		   }
			cout << endl;
			break;
		}
	}
	printTree(tries);
	do {
		ans = guess(capital, caps);
		if (ans == 1)
		{
			cout << capital << "\t";
			cout << caps;
			for (int i = 0; i < sizeof(caps); i++)
			{
				caps[0] = toupper(caps[0]);
				if (caps[i] == ' ')
				{
					i++;
					caps[i] = toupper(caps[i]);
				}
			}
				if (caps == capital )
				{
					tries = 10;
				}
		}
		else
		{
			tries++;
		}
		printTree(tries);
	} while (tries != 7 && tries!=10);
	if (tries == 7)
		cout << "Sorry you failed !! The name was : " << capital << endl;
	else
		cout << "Congrats !! You won !!\n";
	infile.close();
}
int main()
{
	srand((unsigned)time(0));
	char ans;
	do
	{
		readFile("capitals.txt");//calls file
		cout << "Do you wanna work more?(y/n)\t";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	system("pause");
    return 0;
}

