
#include "pch.h"
#include "functions.h"			
void print(string x)
{
	string Statement = AdjustString(x);
	cout << Statement<<endl;
}

void reverse(string x)
{
	string temp=AdjustString(x);
	vector<string> words;
	StringToVector(words, temp);
	int vec_len = words.size();
	vector<string> words_reverse;
	for (int i = vec_len-1; i>=0; i--)
	{
		words_reverse.push_back(words[i]);
	}
	vec_len = words_reverse.size();
	for (int i = 0; i <= vec_len-1; i++)
	{
		cout << words_reverse[i] << " ";
	}
	cout << endl;
}

void upper(string y)
{
	string x = AdjustString(y);
	int str_len = x.size();
	for (int i = 0; i <= str_len; i++)
	{
		x[i] = toupper(x[i]);
	}
	cout << x << endl;
}

void shuffle(string y)
{
	string x = AdjustString(y);
	int str_len = x.size();
	for (int i = 0; i < str_len; i = i + 2)
	{
		if (x[i + 1] != '\0')
		{
			char temp = x[i];
			x[i] = x[i + 1];
			x[i + 1] = temp;
		}
	}
	cout << x << endl;
}

void shuffleStatement(string x)
{
	string temp = AdjustString(x);
	vector<string> words;
	StringToVector(words, temp);
	int vec_len = words.size();
	for (int i = 1; i < vec_len; i = i + 2)
	{
		string temp = words[i];
		words[i] = words[i - 1];
		words[i - 1] = temp;
	}
	for (int i = 0; i < vec_len; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;
}

void Delete(string x)
{
	string temp = AdjustString(x);
	vector<string> words;
	StringToVector(words, temp);
	int index = stoi(words[0]);
	words.erase(words.begin()+0);
	words.erase(words.begin()+index - 1);
	int vec_len = words.size();
	for (int i = 0; i < vec_len; i++)
	{
		cout << words[i] << " ";
	}
	cout << endl;

}

void Middle(string x)
{
	string temp = AdjustString(x);
	vector<string> words;
	StringToVector(words, temp);
	int vec_len = words.size();
	if (vec_len % 2 == 1)
	{
		cout << words[int(vec_len/2)] << endl;
	}
	else
	{
		cout << words[(vec_len / 2) - 1] << ' ' << words[(vec_len / 2)] << endl;
	} 
}

void Add(string x)
{
	if (!IsNumerical(x))
	{
		cout << "Incorrect Data Type" << endl;
		return;
	}
	string temp = AdjustString(x);
	vector<string> words;
	StringToVector(words, temp);
	int vec_len = words.size();
	int sum = 0;
	for (int i = 0; i < vec_len; i++)
	{
		sum = sum + stoi(words[i]);
	}
	cout << sum << endl;
}

void Random(string x)
{
	if (!IsNumerical(x))
	{
		cout << "Incorrect Data Type" << endl;
		return;
	}
	string temp = AdjustString(x);
	vector<string> words;
	StringToVector(words, temp);
	if (NumberOfArguments(words) != 4)
	{
		cout << "Incorrect Number of Arguments" << endl;
		return;
	}
	vector<int> numbers = StringToInt(words);
	int length = numbers[0];
	int min = numbers[1];
	int max = numbers[2];
	int seed = numbers[3];
	vector<int>rand_num;
	srand(seed);
	for (int i = 0; i < length; i++)
	{
		int temp = rand() % max + min;
		cout << temp << "	";
	}
	cout << '\n';
}






//Extra Functions



string AdjustString(string x)
{
	vector<string>words;
	StringToVector(words, x);
	int vec_len = words.size();
	string statement;

	for (int i = 0; i < vec_len; i++)
	{
		statement=statement+words[i]+" ";
	}
	return statement;
}

void StringToVector(vector<string>&words,string x)
{
	int last_stop = 0;
	int vec_counter = 0;
	int str_len = x.size();
	for (int i = 0; i <= str_len; i++)
	{
		if (x[i] == ' ' || x[i] == '\0' || x[i] == '	')
		{
			string temp = x.substr(last_stop, i - last_stop);;
			words.push_back(temp);
			vec_counter++;
			last_stop = i + 1;
		}
	}
	int vec_len = words.size();
	for (int i = 0; i < vec_len; i++)
	{
		if (words[i] == "\0")
		{
			words.erase(words.begin() + i);
			vec_len--;
			i--;
		}
	}
}

vector<int> StringToInt(vector<string>x)
{
	vector<int> numbers;
	int vec_len = x.size();
	for (int i=0; i < vec_len; i++)
	{
		numbers.push_back(stoi(x[i]));
	}
	return numbers;
}


//Error Handling Functions
bool IsNumerical(string x)
{
	bool IsNumerical = (x.find_first_not_of("	0123456789+- ")==string::npos);
	return IsNumerical;
}

int NumberOfArguments(vector<string>x)
{
	return x.size();
}