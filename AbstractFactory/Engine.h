#pragma once
#include<iostream>
using namespace std;

class Engine
{
protected:
	unsigned int power;
public:
	Engine(unsigned int power):power(power){}
	virtual ~Engine(){}
	virtual unsigned int get_power()const = 0;
	void info()const
	{
		cout << typeid(*this).name() << endl;
		cout << "Engine power:\t" << power << endl;
	}
};

class SportEngine :public Engine
{
public:
	SportEngine():Engine(500){}
	~SportEngine(){}
	unsigned int get_power()const
	{
		return this->power;
	}
};

class TrackEngine :public Engine
{
public:
	TrackEngine():Engine(1000){}
	~TrackEngine(){}
	unsigned int get_power()const
	{
		return this->power;
	}
};

class SUVEngine :public Engine
{
public:
	SUVEngine() :Engine(250) {}
	~SUVEngine() {}
	unsigned int get_power()const
	{
		return this->power;
	}
};