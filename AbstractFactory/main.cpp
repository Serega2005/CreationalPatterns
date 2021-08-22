#include<iostream>
using namespace std;

#include"Factory.h"

class SportCar
{
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	SportCar(SportCarFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheel = factory->createWheel();
	}
	~SportCar(){}
	void info()const
	{
		engine->info();
		tank->info();
		wheel->info();
	}
};

class TrackCar
{
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	TrackCar(TrackCarFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheel = factory->createWheel();
	}
	~TrackCar() {}
	void info()const
	{
		engine->info();
		tank->info();
		wheel->info();
	}
};

class SUVCar
{
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	SUVCar(SUVCarFactory* factory)
	{
		this->engine = factory->createEngine();
		this->tank = factory->createTank();
		this->wheel = factory->createWheel();
	}
	~SUVCar() {}
	void info()const
	{
		engine->info();
		tank->info();
		wheel->info();
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	SportCar lamborghini(new SportCarFactory);
	lamborghini.info();
	TrackCar track_tesla(new TrackCarFactory);
	track_tesla.info();
	SUVCar cybertrack(new SUVCarFactory);
	cybertrack.info();
}