#pragma once

#ifndef MOD

#define MOD

using namespace std;
class Mod
{
public:

	Mod();
	
	Mod(int x, int y, int n);

	void setx(int x);

	void sety(int y);

	void setn(int n);

	int getx();

	int gety();

	int getn();

	bool testmod();

	void print();

private:
	// x = y (mod n)
	int x;
	int y;
	int n;
};
#endif MOD