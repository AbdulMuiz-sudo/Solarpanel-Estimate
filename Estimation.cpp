#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int battery, addstandcost = 0, totalapp = 0,profile_number = 0, earthing=0;
float area, totalpower, totalHeavyEnergy, totalLightEnergy, kw;
string forename, surname, username, password, confirmpassword, logusername, logpassword;
string usernames[1000], passwords[1000];
 

float marla() {
	// returns Kanals
	float marlasize;
	do
	{
		cout << "Enter size of house in Marla: ";
		cin >> marlasize;
	} while (marlasize < 5 || marlasize > 20);
	marlasize /= 20;

	return marlasize;
}
float kanal() {
	// returns kanals
	float kanalsize;
	do
	{
		cout << "Enter size of house in Kanal: ";
		cin >> kanalsize;
	} while (kanalsize <= 0 || kanalsize > 12);

	return kanalsize;
}
int checkRoom() {
	// return number of rooms that use electricity 
	int rooms;
	do {
		cout << "Enter number of rooms that actively use electricity: ";
		cin >> rooms;
	} while (rooms <= 0 || rooms >= 25);

	return rooms;
}
// heavy Appliances 1) ask number 2) return their energies
float energyCars(float noOfCars) {
	// returns energy in Wh used by all electric cars
	if (noOfCars == 0)
		return 0;
	float time;
	do
	{
		cout << "Enter hours per day taken to charge your car daily: ";
		cin >> time;
	} while (time < 0 || time>24);

	return 7200 * noOfCars * time * 30;
}
float energyFridge(float noOfFridge) {
	// returns energy in Wh used by all refrigerators
	return 400 * noOfFridge * 24 * 30;
}
float energyAC(float noOfAC) {
	// returns energy in Wh used by all AC's
	float time;
	do
	{
		cout << "How many hours a day do you typically run your air conditioner? ";
		cin >> time;
	} while (time < 0 || time>24);

	return 1200 * noOfAC * time * 30;
}
float energyMiscHeavy(float misHeavyAppliances) {
	// returns energy in Wh used by miscellaneous appliances
	float time;
	do
	{
		cout << "Enter hours per day used by these heavy miscellaneous appliances: ";
		cin >> time;
	} while (time < 0 || time>24);

	return 500 * misHeavyAppliances * time * 30;
}
float energyHeavyTotal() {
	// returns total Wh of electric cars, ac, fridge
	int car, refrigerators, ac, mischeavy;
	float energy_car, energy_fridge, energy_AC, energy_mis_heavy;
	do
	{
		cout << "Enter number of electric car(s) you wish to charge: ";
		cin >> car;
	} while (car < 0 || car>static_cast<int>(area * 5));
	energy_car = energyCars(car);
	do
	{
		cout << "Enter number of refrigerators used by the entire house: ";
		cin >> refrigerators;
	} while (refrigerators < 0 || refrigerators> area * 6);
	energy_fridge = energyFridge(refrigerators);
	do
	{
		cout << "Enter number of Air conditioners actively used by the entire house: ";
		cin >> ac;
	} while (ac < 0 || ac> area * 12);
	energy_AC = energyAC(ac);
	do
	{
		cout << "Enter number of heavy miscellaneous appliances used: ";
		cin >> mischeavy;
	} while (mischeavy < 0 || mischeavy > 50);
	energy_mis_heavy = energyMiscHeavy(mischeavy);
	totalapp = car + mischeavy + ac + refrigerators;
	return energy_car + energy_fridge + energy_AC + energy_mis_heavy;
}
// light Appliances 1) ask number 2) return their energies
float energyFans(int noOfFans) {
	// returns Wh of all fans
	float time;
	do
	{
		cout << "Enter the number of hours per day each fan is used: ";
		cin >> time;
	} while (time < 0 || time>24);

	return 50 * noOfFans * time * 30;
}
float energyLights(int noOfLights) {
	// returns Wh of all lights
	float time;
	do
	{
		cout << "Enter the number of hours per day each light is used: ";
		cin >> time;
	} while (time < 0 || time>24);

	return 15 * noOfLights * time * 30;
}
float energyMiscSmall(float misSmallAppl) {
	// returns Wh of all small miscellaneous appliances
	float time;
	do
	{
		cout << "Enter the number of hours per day each appliance uses: ";
		cin >> time;
	} while (time < 0 || time>24);

	return 20 * misSmallAppl * time * 30;
}
float energyLightTotal(int rooms) {
	// returns Wh of all light appliances
	int fans, lightsPerRoom, total_fans, total_lights, miscsmall;
	float energy_Fans, energy_Lights, energy_mis_small;
	do
	{
		cout << "Enter number of fans used per room: ";
		cin >> fans;
	} while (fans < 0);
	total_fans = fans * rooms;
	energy_Fans = energyFans(total_fans);
	do
	{
		cout << "Enter number of lights used per room: ";
		cin >> lightsPerRoom;
	} while (lightsPerRoom < 0);
	total_lights = lightsPerRoom * rooms;
	energy_Lights = energyLights(total_lights);
	do
	{
		cout << "Enter number of small miscellaneous appliances used : ";
		cin >> miscsmall;
	} while (miscsmall < 0);
	energy_mis_small = energyMiscSmall(miscsmall);
	totalapp = totalapp + miscsmall + total_fans + total_lights;
	return energy_Fans + energy_Lights + energy_mis_small;
}
// solar panels
int getSunpeakhours() // to calculate the peak sun hours per day
{
	// returns sun hours 
	int sunhours;
	do
	{
		cout << "Please enter the number of sun peak hours : \n";
		cout << "For Upper Pakistan, Enter 5.\n";
		cout << "For Lower Pakistan, Enter 6.\n";
		cin >> sunhours;
	} while (sunhours < 5 || sunhours > 6);
	return sunhours;
}
float calculationofWh(int sunhours, float total_energy) // to calculate the energy the solar has to generate per month
{
	// returns requirement in watt Hours
	float totalwh;
	totalwh = (total_energy) / (sunhours * 30);
	return totalwh;
}
float roofsize() // the roof area of the house in sq feet
{
	float roofSqFt;
	cout << "According to Pakistani bylaws, 1 Kanal has a 1300 sqft roof and 10 Marla has a 1150 sqft roof." << endl;
	do
	{
		cout << "Please enter the roof size in square feet: ";
		cin >> roofSqFt;
	} while (roofSqFt <= 0 || roofSqFt >= area * 5445 * 0.5); // area in kanal multiplied by sqft in 1 kanal multiplied by average ratio between roof and plot size
	return roofSqFt;
}
int platetype() // returns the plate type
{
	int typeofplate;
	do
	{
		cout << "Choose one of the following plate options:\n";
		cout << "575 Watt Plate - Small in size but less efficient.\n";
		cout << "595 Watt Plate - Large in size but are more efficient.\n";
		cin >> typeofplate;
	} while (typeofplate != 575 && typeofplate != 595);
	return typeofplate;
}
int calculationofplates(float Wh_requirement, float roof_size, int typeofplate) // to calculate the plates required
{
	int totalplates, n;
	float areaofplates;
	totalplates = Wh_requirement / typeofplate;
	if (typeofplate == 595) { // choice is 595
		areaofplates = totalplates * 30; // 30 square feet is size of one panel.
		if (areaofplates > roof_size) {
			do
			{
				cout << "We regret to inform you that there is insufficient space for the current setup. If you are willing to incur additional charges for mounting stands to optimize the installation, please press 1 to proceed, or press 2 to continue without installing the stand." << endl;
				cin >> n;
			} while (n != 1 && n != 2);

			if (n == 1) {
				int addstandcost = 1;
				return totalplates;
			}
			else {
				return totalplates = roof_size / 30.0;
			}
		}
		else {
			return totalplates;
		}
	}
	else { // choice is 575
		areaofplates = totalplates * 28.0;
		if (areaofplates > roof_size) {
			do
			{
				cout << "We regret to inform you that there is insufficient space for the current setup. If you are willing to incur additional charges for mounting stands to optimize the installation, please press 1 to proceed, or press 2 to continue without installing the stand." << endl;
				cin >> n;
			} while (n != 1 && n != 2);
			if (n == 1) {
				int addstandcost = 1;
				return totalplates;
			}
			else {
				return totalplates = roof_size / 28.0;
			}
		}
		else {
			return totalplates;
		}
	}

}
char Invertortype() // calculates the type of invertor(ongrid/hybrid) 
// returns (O/H)
{
	char invertor;
	char ans1, ans2, invertorChoice;

	do
	{
		cout << "Do you require electricity after sunset? (Y/N)";
		cin >> ans1;
	} while (ans1 != 'Y' && ans1 != 'N');

	do
	{
		cout << "Do you experience load shedding in your area? (Y/N)";
		cin >> ans2;
	} while (ans2 != 'Y' && ans2 != 'N');
	if (ans1 == 'N' && ans2 == 'N') {
		invertor = 'O';
	}
	else
	{
		do
		{
			cout << "We recommend that you select a Hybrid invertor.\n";
			cout << "Would you like to include a Hybrid Invertor with your On-Grid system ? (Y/N): ";
			cin >> invertorChoice;
		} while (invertorChoice != 'Y' && invertorChoice != 'N');
		if (invertorChoice == 'Y') {
			battery = 1;
			invertor = 'H';
			cout << "According to your requirements a Hybrid system is suitable.\n";
		}
		else {
			invertor = 'O';
			cout << "According to your requirements an On-Grid system is suitable.\n";
		}
	}
	return invertor;
}
float invertorsize(char invertorType, int totalplates, int typeofplate) // to calculate the total size of the invertor
{
	char p;
	float kw = (totalplates * typeofplate) / 1000;
	float invertorsize;
	float estkw;
	float diff;
	do
	{
		cout << "Do you plan to expand your solar capacity in the future (Y/N)? ";
		cin >> p;
	} while (p != 'Y' && p != 'N');

	if (p == 'N' && invertorType == 'O')
	{
		diff = static_cast<float>(kw) - static_cast<int>(kw);
		if (diff == 0)
			invertorsize = kw;

		else
			invertorsize = kw + 1;
	}
	else if (p == 'Y')
	{
		do
		{
			cout << "How many additional estimated KW would you require in the future? Please provide the amount: ";
			cin >> estkw;
		} while (estkw <= 0 || estkw > kw * 2); // doing this rn
		kw = kw + estkw;
		diff = static_cast<float>(kw) - static_cast<int>(kw);
		if (diff == 0)
			invertorsize = kw;
		else
			invertorsize = kw + 1;
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
{																	// will run in both cases (O and H)
	int onGridKW;
	if (invertorType == 'O')
		onGridKW = invertorSize;
	else
		onGridKW = invertorSize - hybridKW;
	return onGridKW;
}
float invertorcosts(int onGridKW, int hybridKW, char invertorType) // returns the total invertor cost																
{
	if (invertorType == 'H')
		return (onGridKW * 20000) + (hybridKW * 55000);
	else
		return (onGridKW * 20000);
}
float platecost(int plateRequirement, int typeofplate) // to calculate the total cost of plates
{
	if (typeofplate == 595)
		return plateRequirement * 17850;
	else
		return plateRequirement * 16675;
}
float standcost(int totalplates) // returns the total cost of the stands
{
	if (addstandcost == 1)
		return 1500 * totalplates;
	else
		return 1200 * totalplates;
}
float labourcosts() // to calculate the total cost of the stands
{
	float labourcosts;
	if (kw <= 20) {
		labourcosts = 80000;
	}
	else {
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
		cout << "Do you require earthing to protect your appliances from lightning? (Y/N) ";
		cin >> e;
	} while (e != 'Y' && e != 'N');
	if (e == 'Y')
	{
		earthing = 25000;
		totalcost = invertorcosts + platecost + labourcosts + othercosts + batterycosts + standcost + 25000;
	}
	else
	{
		totalcost = invertorcosts + platecost + labourcosts + othercosts + batterycosts + standcost;
	}

	return totalcost;
}
float moneysaved(float total_energy)
{
	float billsaved = (total_energy / 1000) * 64;
	return billsaved;
}

// profile management
int userOption() {
	int option;
	cout << "1: Create New Profile \n2: View All Profiles \n3: Update Profile \n4: Delete Profile \n5: Exit\n";
	do
	{
		cout << "Please select an option from 1 to 5: ";
		cin >> option;
	} while (option < 1 || option>5);
	return option;
}
bool login()
{
	cout << "WELCOME:  " << forename << " " << surname << endl << endl;
	cout << "PLease complete the following fields to successfuly log in to your account: \n\n";
	// check in array
	// if not there, username desnt exist 
	cout << "Please enter your username: ";
	cin >> logusername;
	cout << endl;
	bool usernameExist = false;
	for (int i = 0; i < profile_number; i++) {
		if (logusername == usernames[i]) {
			usernameExist = true;
		}
	}
	if (usernameExist) {
		do {
			cout << "Please enter the password: ";
			cin >> logpassword;
		} while (logpassword != password);
		cout << "WELCOME USER: " << username << endl << endl << endl;
		cout << "PLEASE FILL OUT THE FORM TO RECEIVE AN ACCURATE ESTIMATION OF YOUR SOLAR PANEL REQUIREMENTS. ENSURE THAT YOU PROVIDE PRECISE DETAILS AND FIGURES FOR THE MOST RELIABLE RESULTS. FEEL FREE TO VERIFY YOUR VALUES AGAINST YOUR ELECTRICITY BILLS OR CONSULT WITH A TRUSTED ADVISOR IF NEEDED. " << endl << endl << endl << endl << endl;
		return true;
	}
	return false;
}

void createaccount()
{
	int log;
	cout << "CREATE AN ACCOUNT\n\n";
	cout << "Please complete the following fields to successfully set up your account. Ensure all information provided is accurate to proceed smoothly with the setup process\n";
	cout << endl << "Please enter your forename: ";   // add in file
	cin >> forename;
	cout << endl << "Please enter your surname: ";		// add in file
	cin >> surname;
	cout << endl << "Please enter your desired username as it will appear on your profile: ";	//add in global array
	cin >> username;
	cout << endl << "Please create a secure password for your account: ";
	cin >> password;
	do {
		cout << "Re-enter your password for confirmation: ";
		cin >> confirmpassword;
	} while (password != confirmpassword);

	usernames[profile_number] = username;
	passwords[profile_number] = password;

	profile_number++;
	cout << endl << "Congratulations! Your account has been successfully set up.\n\n";
	ofstream outData;
	outData.open("profiles.txt", ios::app);
	outData << "Profile1: " << username << endl;
	outData << "Name: " << forename << " " << surname << endl;
	outData.close();
}
bool checkFile() {
	ifstream inData("profiles.txt");
	if (!inData) {
		cout << "File doesnt exist. Try another option.\n";
		return false;
	}
	inData.close();
	return true;
}
bool addToFile(int rooms, int plates_requirement, int money_saved, int invertor_cost, int plate_cost, int stand_cost, int labour_cost, int battery_cost, int other_costs, int total_cost) {
	ofstream outData;

	outData.open("profiles.txt", ios::app);
	outData << "Size of house: " << area << " Kanal " << endl;
	outData << "Number of rooms: " << rooms << endl;
	outData << "Number of Appliances: " << totalapp << endl;
	outData << "Number of plates required: " << plates_requirement << endl;
	outData << "Invertor Cost: " << invertor_cost << " PKR" << endl;
	outData << "Plates cost: " << plate_cost << " PKR" << endl;
	outData << "Stand cost: " << stand_cost << " PKR" << endl;
	outData << "Labour cost: " << labour_cost << " PKR" << endl;
	outData << "Battery cost: " << battery_cost << " PKR" << endl;
	outData << "Earthing cost: " << earthing << " PKR" << endl;
	outData << "Other costs: " << other_costs << " PKR" << endl;
	outData << "Total cost has ammounted to: " << total_cost << " PKR" << endl;
	outData << "Money saved in bills: " << money_saved << " PKR" << endl;
	outData.close();

	return true;
}

void SolarCalc(int profile) {
	float total_energy_usage, watt_hr_requirement, roof_size, invertor_size, plate_cost, stand_cost, labour_cost, battery_cost, other_costs, money_saved;

	char house, invertor_type;

	int rooms, sun_hours, plate_type, plates_requirement, check, addacc, total_cost, Ongrid_invertor_size, Hybrid_invertor_size{}, invertor_cost;

	do
	{
		cout << "Please enter house measurement unit (M or Marla or K for Kanal): ";
		cin >> house;
	} while (house != 'K' && house != 'M');
	if (house == 'M')
		area = marla();
	else
		area = kanal();
	rooms = checkRoom();
	total_energy_usage = energyHeavyTotal() + energyLightTotal(rooms);
	sun_hours = getSunpeakhours();
	watt_hr_requirement = calculationofWh(sun_hours, total_energy_usage);
	roof_size = roofsize();
	plate_type = platetype();
	plates_requirement = calculationofplates(watt_hr_requirement, roof_size, plate_type);
	invertor_type = Invertortype();
	invertor_size = invertorsize(invertor_type, plates_requirement, plate_type);
	if (invertor_type == 'H') {
		Hybrid_invertor_size = getHybridDiv(invertor_size);
		Ongrid_invertor_size = getOngridDiv(invertor_size, invertor_type, Hybrid_invertor_size);
	}
	else {
		Ongrid_invertor_size = getOngridDiv(invertor_size, invertor_type, 0);
	}
	invertor_cost = invertorcosts(Ongrid_invertor_size, Hybrid_invertor_size, invertor_type);
	plate_cost = platecost(plates_requirement, plate_type);
	stand_cost = standcost(plates_requirement);
	labour_cost = labourcosts();
	battery_cost = batterycosts();
	other_costs = othercosts(plates_requirement);
	total_cost = costs(invertor_cost, plate_cost, labour_cost, other_costs, battery_cost, stand_cost);
	money_saved = moneysaved(total_energy_usage);
	bool flag = addToFile(rooms, plates_requirement, money_saved, invertor_cost, plate_cost, stand_cost, labour_cost, battery_cost, other_costs, total_cost);
	if (flag)
		cout << "\n\n\nRECORD ADDED TO FILE SUCCESSFULY.\n\n\n";
	else
		cout << "\n\n\nRECORD WAS NOT ABLE TO BE ADDED IN TO THE FILE\n\n\n";
	return;
}

void readfile()
{
	ifstream data("profiles.txt");
	if (!data)
	{
		cout << "File does not exist";
		return;
	}
	string line;
	// Read file line by line
    while (getline(data, line)) {
			cout << line << endl; // Output each line to the console
		}

	data.close();

}




int main() {
	int option;
	bool fileExist = false, loginCheck;
	cout << "WELCOME TO THE SOLAR PANEL ESTIMATOR\n\n\n";
	while (true) {
		option = userOption();
		switch (option)
		{
		case 1:
			// creates a new profile
			createaccount();
			login();
			SolarCalc(profile_number - 1);


			break;
		case 2:
			// views all profiles
			// ask for pw and username
			// check file, if doesnt exist then print No profiles exist and ask options 1-5 again
			/*if (!checkFile())
				break;
			if (!login()) {
				cout << "Failed to Login.";
			}*/

			login();


			readfile();



			break;
		case 3:
			// updates a profile
			// ask for pw and username
			// check file, if doesnt exist then print No profiles exist and ask options 1-5 again
			// if it exists, ask which profile in file


			break;
		case 4:
			// deletes profile
			// ask for pw and username
			// check file, 
				// if doesnt exist then print No profiles exist and ask options 1-5 again
				// if exists, ask which profile in file
					// if profile doesnt exists, print no profile
					// else confirm deletion

			break;
		case 5:
			// exit program
			return 0;
		}
	}


	return 0;
}
