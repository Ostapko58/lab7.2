#pragma once
#include<iostream>
using namespace std;
#define N 256

class Set
{
private:
	int data[N];
	void insertByDefault() {
		for (int i = 0; i < N; i++)
		{
			data[i] = 0;
		}
	}
public:
	Set() {
		insertByDefault();
	}
	Set(Set* set) {
		for (int i = 0; i < N; i++)
		{
			this->data[i] = set->data[i];
		}
	}
	Set(unsigned char * values, int size) {
		insertByDefault();
		for (int i = 0; i < size; i++)
		{
			data[(int)values[i]] = 1;
		}

	}
	Set(unsigned char value) {
		insertByDefault();
		data[(int)value] = 1;
	}
	void showData() {
		for (int i = 0; i < N; i++)
		{
			if (data[i]!=0)
			{
				cout << (unsigned char)i << "  ";
			}			
		}
		cout << endl;
	}
	void insertValue(unsigned char value) {
		if (isPresent((int)value))
		{
			throw exception("Is already exists");
		}
		data[(int)value] = 1; 
	}
	void removeValue(unsigned char value) {
		if (!isPresent((int)value))
		{
			throw exception("Is`n already exists");
		}
		data[(int)value] = 0;
	}

	

	Set unionaWithSet(Set set) {
		Set result;
		for (int i = 0; i < N; i++)
		{
			
			result.data[i] = set.data[i]|this->data[i];
			

		}
		return result;
	}

	Set IntersectionWithSet(Set set) {
		Set result;
		for (int i = 0; i < N; i++)
		{
			result.data[i] = set.data[i] & this->data[i];
		}
		return result;
	}

	Set ComplementWithSet(Set set) {
		Set result;
		for (int i = 0; i < 256; i++)
		{
			if (set.data[i]==1)
			{
				result.data[i] = 0;
				continue;
			}

			result.data[i] = this->data[i];
		}
		return result;
	}

	int size() {
		int counter = 0;
		for (int i = 0; i < 256; i++)
		{
			if (data[i] == 1) counter++;
		}
		return counter;
	}

	bool isPresent(int value) {
		return data[value] == 1;
	}
	
	bool isPresent(Set set) {
		for (int i = 0; i < 256; i++)
		{
			if (set.data[i]==1&&this->data[i]!=1)
			{
				return false;
			}
		}
		return true;
	}
};

