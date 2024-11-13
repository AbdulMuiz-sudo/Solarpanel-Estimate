#include<iostream>
using namespace std;
// later ask if house or factory
int house, rooms, car, refrigerators, ac, total_ac, total_fans, total_lights;
const int powHeavy=1000, powLight = 100;
float area;

float marla()
{
	int a;
	do {
		cout << "Enter size of house in Marla (must be smaller than 20): ";
		cin >> a;
	} while (a<=0);
	a = a / 20.0;
	return a;

}
float kanal()
{
	int b;
	do {
		cout << "Enter size of house in Kanal: ";
		cin >> b;
	} while (b<=0);
	return b;
}

int checkRoom() {
	int rooms;
	do
	{
		cout << "Enter number of rooms that actively use electricity: ";
		cin >> rooms;
	} while (rooms<=0 && rooms>100);
	return rooms;
}

int checkPeople() {
	int num;
	do
	{
		cout << "Enter number of occupants living in this space: ";
		cin >> num;
	} while (num>=0);
	return num;
}

int checkHeavyAppliances() {
	//electric cars, ac, fridge, fans
	int heavyAppliances;
	do
	{
		cout << "Enter number of electric car(s) you wish to charge: ";
		cin >> car;
	} while (car<0);
	do
	{
		cout << "Enter number of refrigerators used: ";
		cin >> refrigerators;
	} while (refrigerators < 0);
	do
	{
		cout << "Enter number of Air conditioners used per room: ";
		cin >> ac;
	} while (ac < 0);
	total_ac = ac * rooms;

	heavyAppliances = car + refrigerators + total_ac;
	return heavyAppliances;
}

int checkLightAppliances() {
	int lightAppliances,fans,lightsPerRoom;
	do
	{
		cout << "Enter number of fans used per room: ";
		cin >> fans;
	} while (fans< 0);
	total_fans = fans * rooms;
	do
	{
		cout << "Enter number of lights used per room: ";
		cin >> lightsPerRoom;
	} while (lightsPerRoom< 0);
	total_lights = lightsPerRoom * rooms;

	lightAppliances = total_lights + total_fans;
	return lightAppliances;
}

float powerUsage(int light, int heavy) {
	int powerUsage, power_light, power_heavy;

	power_light =light * powLight;
	power_heavy = heavy * powHeavy;
	powerUsage = power_light + power_heavy;

	return powerUsage;
}



int main() {
	int lightAppliances, HeavyAppliances, total_power_usage;


	do {
		cout << "Enter whether M or Marla or K for Kanal: ";
		cin >> house;
	} while (house != 'K' && house != 'M');
	if (house == 'M')
		area=marla();
	else
		area= kanal();


	lightAppliances = checkLightAppliances();
	HeavyAppliances = checkHeavyAppliances();
	total_power_usage = powerUsage(lightAppliances, HeavyAppliances);



	return 0;
}