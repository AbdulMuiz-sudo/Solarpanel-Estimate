
#include <iostream>
using namespace std;
// later ask if house or factory
// int house, rooms, car, refrigerators, ac, total_ac, total_fans, total_lights;
int rooms, battery, addstandcost = 0;
const int powHeavy = 0, powLight = 0;
float area, totalpower, totalHeavyEnergy, totalLightEnergy, kw;

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
	return 1300 * num * time * 30;
}

float mischeavyenergy(float num)
{
	float time;

	cout << "Enter hours per day used by these appliances: ";
	cin >> time;
	return 500 * num * time * 30;
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

int sunpeakhours() // to calculate the peak sun hours per day
{
	int sunhours;
	do
	{
		cout << "Please enter the number of sun peak hours: \n";
		cout << "For Upper Pakistan, Enter 5.\n";
		cout << "For Lower Pakistan, eEnter 6.\n";
		cin >> sunhours;
	} while (sunhours < 5 || sunhours > 6);
	return sunhours;
}

float calculationofWh(int sunhours, float total_energy) // to calculate the energy the solar has to generate per month
{
	float totalwh;
	totalwh = (total_energy) / (sunhours * 30);
	return totalwh;
}

int roofsize() // the roof area of the house in sq feet
{
	int roof;
	do
	{
		cout << "Please enter the roof size in square feet: ";
		cin >> roof;

	} while (roof <= 0);
	return roof;
}

int platetype() // the plate type
{
	int typeofplate;
	do
	{
		cout << "Choose one of the following plate options:\n";
		cout << "(1) 575 Watt Plate - Small in size but less efficient.\n";
		cout << "(2) 595 Watt Plate - Large in size and are more efficient.\n";
		cin >> typeofplate;
	} while (typeofplate != 575 && typeofplate != 595);
	return typeofplate;
}

int calculationofplates(float totalwh, int roof, int typeofplate) // to calculate the plates required
{
	int totalplates, n;
	float areaofplates;
	totalplates = totalwh / typeofplate;
	if (typeofplate == 595)
	{
		areaofplates = static_cast<float>(totalplates) * 30; // 30 square feet is size of one panel.
		if (areaofplates > roof)
		{
			do
			{
				cout << "We regret to inform you that there is insufficient space for the current setup. If you are willing to incur additional charges for mounting stands to optimize the installation, please press 1 to proceed, or press 2 to continue without installing the stand." << endl;
				cin >> n;
			} while (n != 1 && n != 2);
			if (n == 1)
				int addstandcost = 1;
			return totalplates;
			else
			{
				return totalplates = roof / 30;
			}
		}
		else{
			totalplates=(totalplates);
		}
	}
	else
	{
		areaofplates = static_cast<float>(totalplates) * 28;
		if (areaofplates > roof)
		{
			do
			{
				cout << "We regret to inform you that there is insufficient space for the current setup. If you are willing to incur additional charges for mounting stands to optimize the installation, please press 1 to proceed, or press 2 to continue without installing the stand." << endl;
				cin >> n;
			} while (n != 1 && n != 2);
			if (n == 1)
				int addstandcost = 1;
			return totalplates;
			else
			{
				return totalplates = roof / 28;
			}
		}
		else{
			totalplates=(totalplates);
		}
	}
	return totalplates;
}

char Invertortype() // to calculate the type of invertor(ongrid/hybrid)
{
	char invertor;
	char ans1, ans2, ans3, ans4, q = 'n';
	do
	{
		cout << " Would you like to include battery storage in your system ? Please press 'Y' for Yes or 'N' for No :";
		cin >> ans1;
		int battery = 1;
	} while (ans1 != 'Y' && ans1 != 'N');
	do
	{
		cout << "Do you require electricity after sunset ? Please press 'Y' for Yes or 'N' for No :";
		cin >> ans2;
	} while (ans2 != 'Y' && ans2 != 'N');
	do
	{
		cout << "Do you want to enable Net Metering ? Please press 'Y' for Yes or 'N' for No :";
		cin >> ans3;
	} while (ans3 != 'Y' && ans3 != 'N');
	do
	{
		cout << "Do you experience load shedding in your area ? Please press 'Y' for Yes or 'N' for No: ";
		cin >> ans4;
	} while (ans4 != 'Y' && ans4 != 'N');
	if (ans1 == 'N' && ans2 == 'N' && ans3 == 'N' && ans4 == 'N')
	{
		invertor = 'O';
	}
	else
	{

		do
		{
			cout << "Would you like to include a Hybrid Inverter with your On - Grid system ? Please press 'Y' for Yes or 'N' for No: ";
			cin >> q;

		} while (q != 'Y' && q != 'N');
		if (q == 'Y')
			invertor = 'H';
		else
			invertor = 'O';
	}
	return invertor;
}

float invertorsize(char invertor, int totalplates, int typeofplate) // to calculate the total size of the invertor
{
	char p;
	float kw = (totalplates * typeofplate)/1000;
	float invertorsize;
	float estkw;
	float diff;
	do
	{
		cout << "Do you plan to expand your solar capacity in the future? Please press 'Y' for Yes or 'N' for No: ";
		cin >> p;
	} while (p != 'Y' && p != 'N');

	if (p == 'N' && invertor == 'O')
	{
		diff = static_cast<float>(kw) - static_cast<int>(kw);
		if (diff == 0)
			invertorsize = kw;
		else
			invertorsize += 1;
	}
	else if (p == 'Y')
	{
		do
		{
			cout << "How many estimated KW would you need? Please provide the amount: ";
			cin >> estkw;
		} while (estkw <= 0);
		kw = kw + estkw;
		diff = static_cast<float>(kw) - static_cast<int>(kw);
		if (diff == 0)
			invertorsize = kw;
		else
			invertorsize += 1;
	}
	return invertorsize;
}

int getHybridDiv(int invertorSize) // to calculate the size of the hybrid invertor
{								   // will only run if invertorType is hybrid
	int hybridKW;
	do
	{
		cout << "Out of " << invertorSize << "KW, how much do you require solely for a hybrid system (must be in integer): ";
		cin >> hybridKW;
	} while (hybridKW < 0 || hybridKW > invertorSize);
	return hybridKW;
	// once returned, pass it as parameter to getOngridDiv function to calculate the remaining KW for ongrid KW
}

int getOngridDiv(int invertorSize, char invertorType, int hybridKW) // to calculate the ongrid invertor size
{																	// will only run if invertorType is hybrid
	int onGridKW;
	if (invertorType == 'O')
		onGridKW = invertorSize;
	else
		onGridKW = invertorSize - hybridKW;
	return onGridKW;
}
float invertorcosts(int onGridKW, int hybridKW, char invertor) // to calculate the total invertor cost
{
	if (invertor == 'H')
	{
		float invertorcost = (onGridKW * 20000) + (hybridKW * 55000);
	}
	else
	{
		float invertorcost = (onGridKW * 20000);
	}

	return invertorcost;
}
float platecost(int totalplates, int typeofplate) // to calculate the total cost of plates
{
	float platecost;
	if (typeofplate == 595)
	{
		platecost = totalplates * 17850;
	}
	else if (typeofplate == 575)
	{
		platecost = totalplates * 16675;
	}
	return platecost;
}
float standcost(int totalplates) // to calculate the total cost of the stands
{
	float standcost;
	if (addstandcost == 1)
	{
		standcost = 1500 * totalplates;
	}
	else
	{
		standcost = 1200 * totalplates;
	}
	return standcost;
}
float labourcosts() // to calculate the total cost of the stands
{
	float labourcosts;
	if (kw <= 20)
	{
		labourcosts = 80000;
	}
	else
	{
		labourcosts = ((kw - 20) * 500) + (80000);
	}
	return labourcosts;
}
float batterycosts() // the total battery cost
{
	float batterycosts;
	if (battery == 1)
	{
		batterycosts = 200000;
		return batterycosts;
	}
	return 0;
}
float othercosts(int totalplates) // to calculate other costs like wires etc
{
	float othercosts = totalplates * 200;
	return othercosts;
}

float costs(float invertorcosts, float platecost, float labourcosts, float othercosts, float batterycosts, float standcost) // to calculate the total cost of the solar system
{
	float totalcost;
	char e;
	do
	{
		cout << "Do you need protection from lighetening by spending on earthing? Please press 'Y' for Yes or 'N' for No: ";
		cin >> e;
	} while (e != 'Y' && e != 'N');
	if (e == 'Y')
	{
		totalcost = invertorcosts + platecost + labourcosts + othercosts + batterycosts + standcost + 25000;
	}
	else
	{
		totalcost = invertorcosts + platecost + labourcosts + othercosts + batterycosts + standcost;
	}

	return totalcost;
}
float energysaved(float total_energy)
{
	float billsaved = (total_energy/1000) * 64;
	return billsaved;
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