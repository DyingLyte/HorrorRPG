#pragma once
class Player
{

	
public:
	double sanity;
	double durability;
	double observation;
	bool hasWeapon = false;
	Player(double sanity, double durability, double observation);
	bool sanityCheck(int s);
	bool durabilityCheck(int d);
	bool obserCheck(int o);

	void displayStats() const;
};

