// SimilarPassword.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(int x, int y) 
{ 
	return (x < y); 
}

int Similar(string p)
{
	vector<int> operV;
	int oper;
	int minOper, vowels = 0, consonants = 0;
	int len = p.length();
	for (int i = 0; i < len; i++)
	{
		if (p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' ||
			p[i] == 'u')
		{
			vowels++;
		}
		else
		{
			if ((97 < (int)p[i]) && ((int)p[i] < 101))
			{
				if ((int)p[i] - 97 < 101 - (int)p[i])
					oper = (int)p[i] - 97;
				else
					oper = 101 - (int)p[i];
			}
			else if ((101 < (int)p[i]) && ((int)p[i] < 105))
			{
				if (((int)p[i] - 101) < (105 - (int)p[i]))
					oper = (int)p[i] - 101;
				else
					oper = 105 - (int)p[i];
			}
			else if (105 < (int)p[i] && (int)p[i] < 111)
			{
				if ((int)p[i] - 105 < 111 - (int)p[i])
					oper = (int)p[i] - 105;
				else
					oper = 111 - (int)p[i];
			}
			else if (111 < (int)p[i] && (int)p[i] < 117)
			{
				if ((int)p[i] - 111 < 117 - (int)p[i])
					oper = (int)p[i] - 111;
				else
					oper = 117 - (int)p[i];
			}	
			else
			{
				oper = (int)p[i] - 117;
			}
			operV.push_back(oper);
		}
	}
	
	sort(operV.begin(), operV.end(), compare);

	consonants = len - vowels;

	if (consonants == vowels)
		minOper = 0;
	else if (consonants > vowels)
	{
		minOper = len/2 - vowels;
		int j = 0, sum = 0;
		while (j < minOper)
		{
			sum += operV[j];
			j++;
		}
		minOper = sum;
	}

	return minOper;
}

int main()
{
	string psw = "lostss";
	int num = Similar(psw);

	cout << num << endl;

	return 0;
}
