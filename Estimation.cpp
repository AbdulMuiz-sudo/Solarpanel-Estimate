char Invertortype() // calculates the type of invertor(ongrid/hybrid) 
// returns (O/H)
{
	char invertor;
	char ans1, ans2, invertorChoice;

	do {

		cout << "\nDo you require electricity after sunset? (Y/N)";
		cin >> ans1;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid input! Kindly enter character\n";
		}
		else if (ans1 != 'Y' && ans1 != 'N')
		{
			cout << "Kindly enter 'N' or 'Y' only!" << endl;
		}
	} while (ans1 != 'Y' && ans1 != 'N' || cin.fail());

	do {

		cout << "\nDo you experience load shedding in your area? (Y/N)";
		cin >> ans2;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid input! Kindly enter character.\n";
		}
		else if (ans2 != 'Y' && ans2 != 'N')
		{
			cout << "Kindly enter 'N' or 'Y' only!" << endl;
		}
	} while (ans2 != 'Y' && ans2 != 'N' || cin.fail());

		do {

			cout << "\t\t\nWe recommend selecting a Hybrid inverter for optimal performance.\n";
			cout << "\nWould you like to incorporate a Hybrid Invertor with your On-Grid system ? (Y/N): ";
			cin >> invertorChoice;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nInvalid input! Kindly enter character.\n";
			}
			else if (invertorChoice != 'Y' && invertorChoice != 'N')
			{
				cout << "Kindly enter 'N' or 'Y' only!" << endl;
			}
		} while ((invertorChoice != 'Y' && invertorChoice != 'N') || cin.fail());





		if (invertorChoice == 'Y') {
			battery = 1;
			invertor = 'H';
			cout << "\t\t\Based on your requirements, a hybrid system combined with an on-grid setup is suitable.\n\n";
		}
		else {
			invertor = 'O';
			cout << "\nBased on your requirements, an On - Grid system is the most suitable option.\n";
		}
	
	return invertor;
}
float invertorsize(char invertorType, int totalplates, int typeofplate) // to calculate the total size of the invertor
{
	char p;
	float kw = (static_cast<float>(totalplates) * typeofplate) / 1000;
	float invertorsize = 0;
	float estkw;
	float diff;


	do {

		cout << "\nDo you plan to expand your solar capacity in the future (Y/N)? ";
		cin >> p;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\nInvalid input! Kindly enter character.\n";
		}
		else if (p != 'Y' && p != 'N')
		{
			cout << "Kindly enter 'N' or 'Y' only!" << endl;
		}
	} while ((p != 'Y' && p != 'N') || cin.fail());

     if (p == 'Y')
	{

		do {


			cout << "\nHow many additional estimated kW will you require in the future ? Please specify the amount: ";
			cin >> estkw;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nInvalid input! Kindly enter integer value.\n";
			}
			else if (estkw <= 0 || estkw > kw * 2)
			{
				cout << "Kindly enter value between 0 and " << kw * 2 << endl;
			}
		} while (estkw <= 0 || estkw > kw * 2 || cin.fail());


		kw = kw + estkw;
		diff = static_cast<float>(kw) - static_cast<int>(kw);
		if (diff == 0)
			invertorsize = kw;
		else
			invertorsize = kw + 1;
	}
    else if (p=='N')
    {
        diff = static_cast<float>(kw) - static_cast<int>(kw);
		if (diff == 0)
			invertorsize = kw;

		else
			invertorsize = kw + 1;
    }
    
	return invertorsize;
}
