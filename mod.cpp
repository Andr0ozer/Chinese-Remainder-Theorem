#include "mod.h"
#include <iostream>

Mod::Mod()
{
	this->x = 0;
	this->y = 0;
	this->n = 0;
}

Mod::Mod(int x, int y, int n)
{
	this->x = x;
	this->y = y;
	this->n = n;
}

void Mod::setx(int x)
{
	this->x = x;
}

void Mod::sety(int y)
{
	this->y = y;
}

void Mod::setn(int n)
{
	this->n = n;
}

int Mod::getx()
{
	return x;
}

int Mod::gety()
{
	return y;
}

int Mod::getn()
{
	return n;
}

bool Mod::testmod()
{
	if (x % n == y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Mod::print()
{
	if (x != 0)
	{
		cout << x << " = " << y << "(mod " << n << ")" << endl;
	}
	else
	{
		cout << "X = " << y << "(mod " << n << ")" << endl;
	}
}
