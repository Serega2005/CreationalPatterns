#pragma once
#include<iostream>
using namespace std;

#include"Engine.h"
#include"Tank.h"
#include"Wheel.h"

class AbstractFactory
{
public:
	virtual Engine* createEngine() = 0;
	virtual Tank* createTank() = 0;
	virtual Wheel* createWheel() = 0;
};

class SportCarFactory: public AbstractFactory
{
public:
	Engine* createEngine()
	{
		return new SportEngine;
	}
	Tank* createTank()
	{
		return new SportTank;
	}
	Wheel* createWheel()
	{
		return new SportWheel;
	}
};

class TrackCarFactory : public AbstractFactory
{
public:
	Engine* createEngine()
	{
		return new TrackEngine;
	}
	Tank* createTank()
	{
		return new TrackTank;
	}
	Wheel* createWheel()
	{
		return new TrackWheel;
	}
};

class SUVCarFactory : public AbstractFactory
{
public:
	Engine* createEngine()
	{
		return new SUVEngine;
	}
	Tank* createTank()
	{
		return new SUVTank;
	}
	Wheel* createWheel()
	{
		return new SUVWheel;
	}
};