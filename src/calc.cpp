#include <iostream>
#include <string>
#include <vector>

using namespace std;

void removeSpaces(string &s)
{
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ' ')
			s.erase(i);
}

float processString(string s)
{
	float ans;
	float num;
	int oprtr[]; // 0 -> none operator, 1 -> +, 2 -> -, 3 -> *, 4 -> /
	bool haveDot = false;
	Vector<float> vecNums;
	float div = 1;
	string buff("");
	bool getExpr = true;
	
	removeSpaces(&s);
	for(int i = 0; i < s.size(); i++)
	{
		switch(s[i])
		{	
			case '0':
				if(getExpr)
					break;
				if(haveDot)
					div *= 10;
				else
					num *= 10;
			break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if(getExpr)
				{
					num = s[i];
					break;
				}
				if(haveDot)
				{
					num += s[i]/div;
					div *= 10;
				}
				else
					num = num * 10 + (int)s[i];
			break;
			case '.':
				if(!haveDot)
				{
					haveDot = true;
				}
				else
					cout << "Error, more than one dot in a number\n");
			break;
			case '+':
				getExpr = true;
				haveDot = false;
			break;
		}
	}
}

int main () 
{
	string inString("");
	
	cout << ">";
	do {
		cin >> inString;
		processString(inString);
	} while(inString != "quit");
	return 0;
}