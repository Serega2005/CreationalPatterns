#include<iostream>
#include<string>
#include<ctime>
#include<map>
using namespace std;

class Human
{
	unsigned int hp;
	unsigned int damage;
	unsigned int armor;
public:
	Human(unsigned int hp, unsigned int damage, unsigned int armor)
	{
		this->hp = hp;
		this->damage = damage;
		this->armor = armor;
	}
	virtual ~Human()
	{
		cout << "No human - No problem" << endl;
	}
	virtual void info()const
	{
		cout << "\n--------------------------------\n";
		cout << typeid(*this).name() << endl;
		cout << "HP:\t" << hp << endl;
		cout << "Armor:\t" << armor << endl;
		cout << "Damage:\t" << damage << endl;
	}
};
class Traveller : public Human
{
public :
	Traveller(unsigned int hp, unsigned int damage, unsigned int armor) :
		Human(hp, damage, armor)
	{

	}
	~Traveller(){}

};
class PoliceOfficer :public Human
{
	std::string weapon;
public:
	PoliceOfficer(unsigned int hp, unsigned int damage, unsigned int armor, const std::string weapon):
		Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~PoliceOfficer(){}
	void info()const
	{
		Human::info();
		cout << "Weapon:" << weapon << endl;
	}
};
class Bandit :public Human
{
	std::string weapon;
public:
	Bandit(unsigned int hp, unsigned int damage, unsigned int armor, const std::string weapon = "") :
		Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~Bandit(){}
	void info()const
	{
		Human::info();
		cout << "Weapon:" << weapon << endl;
	}
};
class HumanFactory
{
public:
	enum HumanType
	{
		Traveller,
		PoliceOfficer,
		Bandit
	};
	static std::map<size_t, std::string> weapons;
	static Human* humanFactory(HumanType human_type)
	{
		switch (human_type)
		{
		case Traveller:     return new class Traveller(100, rand() % 10 + 10, 0);
		case PoliceOfficer: return new class PoliceOfficer(100, rand() % 10 + 20, 100, "Beretta");
		case Bandit:
			return new class Bandit(rand() % 50 + 50, rand() % 10 + 30, rand() % 20 + 80, weapons[rand() % (weapons.size())]);
		}
	}
};
std::map<size_t, std::string> HumanFactory::weapons =
{
	std::pair<size_t, std::string>(0, ""),
	std::pair<size_t, std::string>(0, "Knife"),
	std::pair<size_t, std::string>(0, "Beretta"),
	std::pair<size_t, std::string>(0, "Glok-18"),
	std::pair<size_t, std::string>(0, "SPAS-12"),
	std::pair<size_t, std::string>(0, "Ingram"),
	std::pair<size_t, std::string>(0, "M4A1"),
	std::pair<size_t, std::string>(0, "AK-47")
};

class Transport
{
	unsigned int endurance;
	unsigned int capacity;
public:
	Transport(unsigned int endurance, unsigned int capacity)
	{
		this->endurance = endurance;
		this->capacity = capacity;
	}
	virtual ~Transport()
	{
		cout << "No transport - No ñrash" << endl;
	}
	virtual void info()const
	{
		cout << "\n--------------------------------\n";
		cout << typeid(*this).name() << endl;
		cout << "Endurance:\t" << endurance << endl;
		cout << "Capacity:\t" << capacity << endl;
	}
};
class TravellerTransport : public Transport
{
public:
	TravellerTransport(unsigned int endurance, unsigned int damage) :
		Transport(endurance, damage){ }
	~TravellerTransport() {}

};
class PoliceOfficerTransport :public Transport
{
	std::string t_weapon;
public:
	PoliceOfficerTransport(unsigned int endurance, unsigned int damage, const std::string t_weapon) :
		Transport(endurance, damage)
	{
		this->t_weapon = t_weapon;
	}
	~PoliceOfficerTransport() {}
	void info()const
	{
		Transport::info();
		cout << "Weapon:" << t_weapon << endl;
	}
};
class BanditTransport :public Transport
{
	std::string t_weapon;
public:
	BanditTransport(unsigned int endurance, unsigned int damage, const std::string t_weapon = "") :
		Transport(endurance, damage)
	{
		this->t_weapon = t_weapon;
	}
	~BanditTransport() {}
	void info()const
	{
		Transport::info();
		cout << "Weapon:" << t_weapon << endl;
	}
};
enum TransportType
{
	TravellerTransport,
	PoliceOfficerTransport,
	BanditTransport
};
std::string t_weapons[] =
{
	"",
	"Grenade",
	"Flash",
	"Smok",
	"Beretta",
	"Glok-18",
	"SPAS-12",
	"Ingram",
	"M4A1",
	"AK-47"
};
Transport* TransportFactory(TransportType Transport_type)
{
	switch (Transport_type)
	{
	case TravellerTransport:     return new class TravellerTransport(300, rand() % 2+2);
	case PoliceOfficerTransport: return new class PoliceOfficerTransport(300, rand() % 4+4, "Beretta");
	case BanditTransport:
		return new class BanditTransport(rand() % 150 + 150, rand() % 4+2, t_weapons[rand() % (sizeof(t_weapons) / sizeof(std::string))]);
	}
}

//#define FACTORY_CHECK_1
//#define FACTORY_CHECK_2
//#define FACTORY_TRANSPORT
#define FACTORY_HUMAN

void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
#ifdef FACTORY_CHECK_1
	Human* t = humanFactory(Traveller);
	t->info();

	Human* p = humanFactory(PoliceOfficer);
	p->info();

	Human* b = humanFactory(Bandit);
	b->info();
#endif // FACTORY_CHECK_1
	
#ifdef FACTORY_HUMAN
	//cout << sizeof(HumanType) << endl;
	const int n = 10;
	Human* human[n]{};
	unsigned int traveller_count = 0;
	unsigned int police_officer_count = 0;
	unsigned int bandit_count = 0;
	for (int i = 0; i < n; i++)
	{
		human[i] = HumanFactory::humanFactory(HumanFactory::HumanType(rand() % 3));
		human[i]->info();
		if (typeid(*human[i]) == typeid(class Traveller))traveller_count++;
		if (typeid(*human[i]) == typeid(class PoliceOfficer))police_officer_count++;
		if (typeid(*human[i]) == typeid(class Bandit))bandit_count++;
	}
	cout << "Travellers: " << traveller_count << endl;
	cout << "PoliceOfficer: " << police_officer_count << endl;
	cout << "Bandit: " << bandit_count << endl;
	for (int i = 0; i < n; i++)
	{
		delete human[i];
	}
#endif // FACTORY_HUMAN

#ifdef FACTORY_CHECK_2
	Transport* t_t = TransportFactory(TravellerTransport);
	t_t->info();

	Transport* p_t = TransportFactory(PoliceOfficerTransport);
	p_t->info();

	Transport* b_t = TransportFactory(BanditTransport);
	b_t->info();
#endif // FACTORY_CHECK_2

#ifdef FACTORY_TRANSPORT
	cout << sizeof(TransportType) << endl;
	const int n = 10;
	Transport* transport[n]{};
	unsigned int traveller_transport_count = 0;
	unsigned int police_officer_transport_count = 0;
	unsigned int bandit_transport_count = 0;
	for (int i = 0; i < n; i++)
	{
		transport[i] = TransportFactory(TransportType(rand() % 3));
		transport[i]->info();
		if (typeid(*transport[i]) == typeid(class TravellerTransport))traveller_transport_count++;
		if (typeid(*transport[i]) == typeid(class PoliceOfficerTransport))police_officer_transport_count++;
		if (typeid(*transport[i]) == typeid(class BanditTransport))bandit_transport_count++;
	}
	cout << "TravellersTransport: " << traveller_transport_count << endl;
	cout << "PoliceOfficerTransport: " << police_officer_transport_count << endl;
	cout << "BanditTransport: " << bandit_transport_count << endl;
	for (int i = 0; i < n; i++)
	{
		delete transport[i];
	}
#endif // FACTORY_TRANSPORT


}