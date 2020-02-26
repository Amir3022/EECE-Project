#include "pch.h"
#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

using namespace std;

void print(string);
void reverse(string);
void upper(string);
void shuffle(string);
void shuffleStatement(string);
void Delete(string);
void Middle(string);
void Add(string);
void Random(string);


//Extra Functions
string AdjustString(string);
void StringToVector(vector<string>&,string);
vector<int> StringToInt(vector<string>);

//Error Handling Functions
bool IsNumerical(string);
int NumberOfArguments(vector<string>);
