#include <iostream>
#include<Windows.h>
#include"Set.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned char ch[] = { 'c','&','1','ж','3'};
	Set set(ch,5);
	set.showData();
	unsigned char ch2[] = { 'c','&','2','5'};
	Set set2(ch2, 4);
	set2.showData();
	unsigned char ch3[] = { 'c','1','3' };
	Set set3(ch3, 3);

	cout << "Union" << endl;
	Set unionSet = set.unionaWithSet(set2);
	unionSet.showData();
	cout << "Intersection" << endl;
	Set intersectionSet = set.IntersectionWithSet(set2);
	intersectionSet.showData();
	cout << "Complement" << endl;
	Set complementSet = set.ComplementWithSet(set2);
	complementSet.showData();

	cout << "set size = " << set.size() << endl;

	cout << "is present 1" << endl;
	set.isPresent('y') ? cout << "true\n" : cout << "false\n";
	set.insertValue('y');
	cout << "is present 2" << endl;
	set.isPresent('y') ? cout << "true\n" : cout << "false\n";
	set.removeValue('y');
	cout << "is present 3" << endl;
	set.isPresent('y') ? cout << "true\n" : cout << "false\n";

	cout << "is present set3" << endl;
	set.isPresent(set3) ? cout << "true\n" : cout << "false\n";
	

}

