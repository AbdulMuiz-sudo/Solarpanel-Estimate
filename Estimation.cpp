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
// abdullah's work
char sunpeakhours()
{
    int sunhours;
    do
    {
        cout << "Number of Sun Peak Hours(For ISB & KPK=5 | FOR PUNJAB=6 | FOR SINDH=7):" << " ";
        cin >> sunhours;

    } while (sunhours < 5 && sunhours > 7);
    return sunhours;
}
float calculationofKWh(int sunhours)
{
    float totalKwh;
    totalKwh = (sunhours * 30) / powerusage;
    return totalKwh;
}
int calculationofplates(float totalKwh)
{
    int typeofplate, totalplates;
    do
    {
        cout << "TYPE OF PLATE(575 OR 595):" << " ";
        cin >> typeofplate;
    } while (typeofplate != 575 && typeofplate != 595);
    totalplates = totalKwh / typeofplate;
    return totalplates;
}
char Invertortype()
{
    char invertor;
    char ans1,ans2,ans3,ans4;
    do
    {
        cout << "Do you need any battery storage?(yes/no):" << " ";
        cin >> ans1;
    } while (ans1 != 'yes' && ans1 != 'no');
    do
    {
        cout << "Do you require electricity after sunset?(yes/no):" << " ";
        cin >> ans2;
    } while (ans2!= 'yes' && ans2 != 'no');
     do
    {
        cout << "Do you want Net metereing?(yes/no):" << " ";
        cin >> ans3;
    } while (ans3 != 'yes' && ans3 != 'no');
     do
    {
        cout << "Do you have load shedding in your area?(yes/no):" << " ";
        cin >> ans4;
    } while (ans4 != 'yes' && ans4 != 'no');
    if (ans1=='yes'&&ans2=='yes'&&ans3=='yes'&&ans4=='yes')
    {
         invertor='Hybrid';
         return invertor;
    }
    else{
        invertor='On-Grid';
        return invertor;
    }
}
char invertorbrand(){
    char freq,features;
      do
    {
        cout << "is your grid frequency less than 250?(yes/no):" << " ";
        cin >> freq;
    } while (freq != 'yes' && freq != 'no');
     do
    {
        cout << "do you need advanced features?(yes/no):" << " ";
        cin >> features;
    } while (features != 'yes' && features != 'no');
    

}
