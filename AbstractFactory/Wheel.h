#pragma once
#include<iostream>
using namespace std;

class Wheel
{
protected:
	unsigned int radius;
public:
	Wheel(unsigned int radius) :radius(radius){}
	virtual ~Wheel() {}
	virtual unsigned int get_radius()const = 0;
	void info()const
	{
		cout << typeid(*this).name() << ", radius:" << radius << " wheel\n";
	}
};

class SportWheel :public Wheel
{
public:
	SportWheel() :Wheel(13) {}
	~SportWheel() {}
	unsigned int get_radius()const
	{
		return this->radius;
	}
};

class TrackWheel :public Wheel
{
public:
	TrackWheel() :Wheel(22) {}
	~TrackWheel() {}
	unsigned int get_radius()const
	{
		return this->radius;
	}
};

class SUVWheel :public Wheel
{
public:
	SUVWheel() :Wheel(20) {}
	~SUVWheel() {}
	unsigned int get_radius()const
	{
		return this->radius;
	}
};