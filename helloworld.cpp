#include <iostream>
using namespace std;
// later ask if house or factory
// int house, rooms, car, refrigerators, ac, total_ac, total_fans, total_lights;
int rooms;
const int powHeavy, powLight;
float area, totalpower, totalHeavyEnergy, totalLightEnergy;

float marla()
{
	float marlasize;
	do
	{
		cout << "Enter size of house in: \n";

		cin >> marlasize;
	} while (marlasize < 5 && marlasize > 20);
	marlasize /= 20;
	return marlasize;
}
float kanal()
{
	float kanalsize;
	do
	{
		cout << "Enter size of house in Kanal: ";
		cin >> kanalsize;
	} while (kanalsize <= 0);
	return kanalsize;
}

int checkRoom()
{
	int rooms;
	do
	{
		cout << "Enter number of rooms that actively use electricity: ";
		cin >> rooms;
	} while (rooms <= 0 && rooms > 100); // SASTA KAAM SEHI KARO
	return rooms;
}

int checkPeople()
{
	int num;
	do
	{
		cout << "Enter number of occupants living in this space: ";
		cin >> num;
	} while (num <= 0);
	return num;
}
float energycars(float num)
{
	float time;
	cout << "Enter hours per day taken to charge your car daily: ";
	cin >> time;
	return 7200 * num * time * 30;
}
float energyfri(float num)
{
	float time;
	cout << "Enter hours per day taken to charge your car daily: ";
	cin >> time;
	return 600 * num * time * 30;
}
float energyac(float num)
{
	float time;
	cout << "Enter hours per day taken to charge your car daily: ";
	cin >> time;
	return 1500 * num * time * 30;
}

float mischeavyenergy(float num)
{
	float time;

	cout << "Enter hours per day used by these appliances: ";
	cin >> time;
	return 700 * num * time * 30;
}
float totalHeavyenergy()
{
	// electric cars, ac, fridge
	int car, refrigerators, ac, total_ac, mischeavy;
	do
	{
		cout << "Enter number of electric car(s) you wish to charge: ";
		cin >> car;
	} while (car < 0);

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
	do
	{
		cout << "Enter number of heavy miscellaneous appliances used : ";
		cin >> mischeavy;
	} while (mischeavy < 0);

	return totalHeavyEnergy = energycars(car) + energyfri(refrigerators) + energyac(ac) + mischeavyenergy(mischeavy);
}
float energyfans(int num)
{
	float time;

	cout << "Enter hours per day used by these fans: ";
	cin >> time;
	return 50 * num * time * 30;
}
float energylights(int num)
{

	float time;

	cout << "Enter hours per day used by these light: ";
	cin >> time;
	return 15 * num * time * 30;
}
float miscsmallenergy(float num)
{
	float time;

	cout << "Enter hours per day used by these appliances: ";
	cin >> time;
	return 20 * num * time * 30;
}

float checkLightAppliances()
{
	int lightAppliances, fans, lightsPerRoom, total_fans, total_lights, miscsmall;
	do
	{
		cout << "Enter number of fans used per room: ";
		cin >> fans;
	} while (fans < 0);
	total_fans = fans * rooms;

	do
	{
		cout << "Enter number of lights used per room: ";
		cin >> lightsPerRoom;
	} while (lightsPerRoom < 0);
	total_lights = lightsPerRoom * rooms;
	do
	{
		cout << "Enter number of small miscellaneous appliances used : ";
		cin >> miscsmall;
	} while (miscsmall < 0);

	totalLightEnergy = energyfans(total_fans) + energylights(total_lights) + miscsmallenergy(miscsmall);
	return totalLightEnergy;
}

// float powerUsage(int light, int heavy) {
//	float powerUsage, power_light, power_heavy;
//
//	power_light = light * powLight;
//	power_heavy = heavy * powHeavy;
//	powerUsage = power_light + power_heavy;
//
//	return powerUsage;
// }

char sunpeakhours()
{
	int sunhours;
	do
	{
		cout << "Number of Sun Peak Hours(F0R UPPER PAKISTAN 5|FOR LOWER PAKISTAN 6):" << " ";
		cin >> sunhours;
	} while (sunhours < 5 || sunhours > 6);
	return sunhours;
}
float calculationofWh(int sunhours, float total_energy)
{
	float totalwh;
	totalwh = (total_energy) / (sunhours * 30);
	return totalwh;
}
int roofsize()
{
	int roof;
	do
	{
		cout << "Enter the Roof size(in sq feet):" << " ";
		cin >> roof;

	} while (roof < 0);
	return roof;
}
int platetype(){
	int typeofplate;
	do
	{
		cout << "TYPE OF PLATE(575 OR 595):" << " ";
		cin >> typeofplate;
	} while (typeofplate != 575 && typeofplate != 595);
	return typeofplate;
}
int calculationofplates(float totalKwh, int roof,int typeofplate)
{
	int  totalplates;
	float areaofplates;
	totalplates = totalKwh * 1000 / typeofplate;
	if (typeofplate == 595)
	{
		areaofplates = totalplates * 30;
		if (areaofplates > roof)
		{
			int n = 1;
			while (n == 1)
			{
				cout << "You dont have enough space.press 1 to proceed if you can bear additional charges for stands:" << endl;
				cin >> n;
				// increase additional stand charges
			}
			totalplates = roof / 30;
		}
	}
	else
	{
		areaofplates = totalplates * 28;
		if (areaofplates > roof)
		{
			int n = 1;
			while (n == 1)
			{
				cout << "You dont have enough space.press 1 to proceed if you can bear additional charges for stands:" << endl;
				cin >> n;
				// increase additional stand charges and labour
			}
			totalplates = roof / 28;
		}
	}
	return totalplates;
}
char Invertortype()
{
	char invertor;
	char ans1, ans2, ans3, ans4, q = 'no';
	do
	{
		cout << "Do you need any battery storage?(yes/no):" << " ";
		cin >> ans1;
	} while (ans1 != 'yes' && ans1 != 'no');
	do
	{
		cout << "Do you require electricity after sunset?(yes/no):" << " ";
		cin >> ans2;
	} while (ans2 != 'yes' && ans2 != 'no');
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
	if (ans1 == 'no' && ans2 == 'no' && ans3 == 'no' && ans4 == 'no')
	{
		invertor = 'OG';
		return invertor;
	}
	else
	{
		while (q == 'no')
		{

			cout << "Do you want to include Hybrid invertor with your On-Grid?(yes/no):" << " ";
			cin >> q;
			invertor = 'OG';
		}
		invertor = 'OGH';
	}
	return invertor;
}
char invertorbrand(char invertor)
{
	char freq, features, brand;
	char invertorbrand;
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
	if (invertor == 'OG' && features == 'yes' && freq == 'no')
	{
		do
		{
			cout << "We recommend you to use an exp invertor brand like Hawawei.Are you fine with it?(yes/no):" << " ";
			cin >> brand;
		} while (brand != 'yes' && brand != 'no');
		if (brand == 'yes')
		{
			invertorbrand = 'exp';
		}
		else
		{
			invertorbrand = 'nor';
		}
	}
	else
	{
		do
		{
			cout << "do you want to install an expensive brand of invertor like Hawawei?(yes/no):" << " ";
			cin >> brand;
		} while (brand != 'yes' && brand != 'no');
		if (brand == 'yes')
		{
			invertorbrand = 'exp';
		}
		else
		{
			invertorbrand = 'nor';
		}
	}
	return invertorbrand;
}
float invertorsize(char invertor, int totalplates, int typeofplate)
{
	char p;
	float kwh = totalplates * typeofplate;
	float invertorsize;
	float estkwh;
	float k;
	do
	{
		cout << "do you plan to expand your solar capacity in future?(yes/no):" << " ";
		cin >> p;
	} while (p != 'yes' && p != 'no');
	if (p == 'no' && invertor == 'OG')
	{
		
		invertorsize = kwh;
	}
	else if (p == 'yes')
	{
		cout << "how many estimated kwh would you need?(yes/no):" << " ";
		cin >> estkwh;
		kwh = kwh + estkwh;
		if (invertor == 'OGH')
		{
			float Hybrid,On_grid;
			do
			{
				cout << "Out of "<<kwh<< "how much do want on your hybrid invertor:"<<" ";
				cin >> k;
			} while (k != 'yes' && k != 'no');
			Hybrid=k;
			On_grid=(kwh-k);
			invertorsize=On_grid;
		}
		else if (invertor=='OG')
		{
			invertorsize=kwh;
		}
		
	}
}
float costs(int totalplates,int typeofplate,char invertorbrand,char invertor,float invertorsize,){
	float platecost;
	//int eartingcosts=price
	//int labourcosts=perkanalprice*housesize
	//standcosts
	//batterycosts
	//netmeteringcosts
	//wire and other asscesories costs
if (typeofplate==595)
{
	//platecost=totalplates*price
}
else if (typeofplate==575)
{
	//platecost=totalplates*price
}


}

int main()
{
	int lightAppliances, HeavyAppliances, total_energy_usage, house;

	do
	{
		cout << "Enter whether M or Marla or K for Kanal: ";
		cin >> house;
	} while (house != 'K' && house != 'M');
	if (house == 'M')
		area = marla();
	else
		area = kanal();
	total_energy_usage = totalHeavyEnergy + totalLightEnergy;

	/*lightAppliances = checkLightAppliances();
	HeavyAppliances = checkHeavyAppliances();
	total_power_usage = powerUsage(lightAppliances, HeavyAppliances)*/
	;

	return 0;
}