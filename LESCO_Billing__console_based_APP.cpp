#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<windows.h>

using namespace std;

																	/*
																	
																	
																	maaz hassan:21L-5793
																	M shoaib:21L- 5766
																	
																	*/
int phase1_reg_hour_unit_priceD = NULL;
int phase1_peak_hours_unit_priceD = NULL;
int phase1_percentage_of_taxD = NULL;
int phase1_fixed_chargesD = NULL;

int phase1_reg_hour_unit_priceC = NULL;
int phase1_peak_hours_unit_priceC = NULL;
int phase1_percentage_of_taxC = NULL;
int phase1_fixed_chargesC = NULL;

int phase3_reg_hour_unit_priceD = NULL;
int phase3_peak_hours_unit_priceD = NULL;
int phase3_percentage_of_taxD = NULL;
int phase3_fixed_chargesD = NULL;

int phase3_reg_hour_unit_priceC = NULL;
int phase3_peak_hours_unit_priceC = NULL;
int phase3_percentage_of_taxC = NULL;
int phase3_fixed_chargesC = NULL;

// This function will calculate the string length
int StringLenght(char* str)
{
	int stringLen = 0;
	for (char* temp = str; *temp != '\0'; temp++)
		stringLen++;

	return stringLen;
}   // to calculate lenght of string

// This function will return the string
char* GetStringFromBuffer(char* str)
{
	int strLen = StringLenght(str);
	char* mystr = 0;

	if (strLen > 0)
	{
		mystr = new char[strLen + 1];
		for (int i = 0; i < strLen; i++)
		{
			mystr[i] = str[i];
		}
		mystr[strLen] = '\0';
	}
	return mystr;
}  // function to get string from buffer

// This function will load employee's IDs and Passwords
void LoadEmployeeData(char**& employee_username, char**& employee_password, int& totalemployees)
{
	ifstream input_employeedata("emp.txt");

	if (input_employeedata.is_open())
	{
		employee_username = new char* [4];
		employee_password = new char* [4];

		char temp[100];

		int i = 0;
		while (!input_employeedata.eof())
		{
			input_employeedata.getline(temp, 100, ',');
			employee_username[i] = GetStringFromBuffer(temp);

			input_employeedata.getline(temp, 100);
			employee_password[i] = GetStringFromBuffer(temp);

			
			i++;
			totalemployees = i;
		}
		input_employeedata.close();
	}
	else
	{
		cout << "OPS!! DATA NOT FOUND\n";
	}

	
}

// This function is to show data on console
void ShowEmployeeData(char** employee_username, char** employee_password, int totalemployees)
{
	int index = NULL;
	
	for (; index < totalemployees; index++)
	cout << employee_username[index] << " " << employee_password[index] << endl;
}

// This function will load the data of customer
void LoadCustomerData(int& _totalCustomers,char**& customer_ID, char**& customer_DOB, char**& customer_name, char**& customer_address, char**& customer_ContactNum, char**& customerType, char**& meterType, char**& connectionDate, int*& regular_hours, int*& peak_hours, char**& customerPassword)
{
	ifstream input_customerdata("cus.txt");
	if (input_customerdata.is_open())
	{
		customer_ID = new char* [10];
		customer_DOB = new char* [10];
		customer_name = new char* [10];
		customer_address = new char* [10];
		customer_ContactNum = new char* [10];
		customerType = new char* [10];
		meterType = new char* [10];
		connectionDate = new char* [10];
		regular_hours = new int[10];
		peak_hours = new int [10];
		customerPassword = new char* [10];

		char temp[300];
		int i = 0;
		while (!input_customerdata.eof())
		{
			
			input_customerdata.getline(temp, 100, ',');
			customer_ID[i] = GetStringFromBuffer(temp);

			input_customerdata.getline(temp, 100, ',');
			customer_DOB[i] = GetStringFromBuffer(temp);
			customerPassword[i] = GetStringFromBuffer(temp);


			input_customerdata.getline(temp, 100, ',');
			customer_name[i] = GetStringFromBuffer(temp);

			input_customerdata.getline(temp, 100, ',');
			customer_address[i] = GetStringFromBuffer(temp);

			input_customerdata.getline(temp, 100, ',');
			customer_ContactNum[i] = GetStringFromBuffer(temp);

			input_customerdata.getline(temp, 100, ',');
			customerType[i] = GetStringFromBuffer(temp);

			input_customerdata.getline(temp, 100, ',');
			meterType[i] = GetStringFromBuffer(temp);

			input_customerdata.getline(temp, 100, ',');
			connectionDate[i] = GetStringFromBuffer(temp);

			int number;
			input_customerdata >> number;
			regular_hours[i] = number;
			input_customerdata.ignore();

			input_customerdata >> number;
			peak_hours[i] = number;
			i++;
		}
		_totalCustomers = i;
		input_customerdata.close();
	}
	else
	{
		cout << "OPS!! \n NO DATA FOUND\n";
	}

}

// This function will show the data of customer on console
void ShowLaodedCustomers(int _totalCustomers,char** customer_ID, char** customer_DOB, char** customer_name, char** customer_address, char** customer_ContactNum, char** customerType, char** meterType, char** connectionDate, int* regular_hours, int* peak_hours)
{
	//if (customer_ID[index] && customer_DOB[index] && customer_name[index] && customer_address[index] && customer_ContactNum[index] && customerType[index] && meterType[index] && connectionDate[index] && regular_hours[index] && peak_hours[index])
	int index = NULL;
	
	for (; index < _totalCustomers; index++)
	{
		
			cout << customer_ID[index] << " " << customer_DOB[index] << " " << customer_name[index] << " " << customer_address[index] << " " << customer_ContactNum[index] << " " << customerType[index] << " " << meterType[index] << " " << connectionDate[index] << " " << regular_hours[index] << " " << peak_hours[index] << endl;
	}
}

// This function will take the logg in information of user
void Login(char*& loggedin_Username, char*& loggedin_Password)
{
	char buffer[100];

	cout << "Username: ";
	cin.ignore();
	cin.getline(buffer, 100);
	loggedin_Username = GetStringFromBuffer(buffer);

	cout << "Password: ";
	cin.getline(buffer, 100);
	loggedin_Password = GetStringFromBuffer(buffer);
}

// This function will verify the employee's usernmae and password
bool Employee_Verification(char** employee_username, char** employee_password, char* loggedin_Username, char* loggedin_Password, int totalEmployees, int& foundIndex)
{
	bool correctUsername = false;
	bool correctPassword = false;

	for (int i_index = NULL; i_index < totalEmployees; i_index++)
	{
		char* temp = employee_username[i_index];
		
		if (StringLenght(temp) == StringLenght(loggedin_Username))
		{
			for (int j_index = NULL; j_index < StringLenght(temp); j_index++)
			{
				correctUsername = false;
				if (temp[j_index] == loggedin_Username[j_index])
				{
					correctUsername = true;
				}
			}

			if (correctUsername == true)
			{
				char* temp2 = employee_password[i_index];

				for (int j_index = NULL; j_index < StringLenght(temp2); j_index++)
				{
					correctPassword = false;
					if (temp2[j_index] == loggedin_Password[j_index])
					{
						correctPassword = true;
						foundIndex = i_index;
					}
					else
					{
						foundIndex = NULL;
					}
				}
			}

			if (correctPassword == true)
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

// This function will let the employyee to change his password
void ChangePassword(char**& employee_username, char**& employee_password, int totalEmployees)
{
	char buffer[100];
	cout << "Enter Your Username: ";
	cin >> buffer;
	char* loggedin_Username = GetStringFromBuffer(buffer);

	cout << "Enter your current Pssword: ";
	cin >> buffer;
	char* loggedin_Password = GetStringFromBuffer(buffer);

	int foundIndex = NULL;
	if (Employee_Verification(employee_username, employee_password, loggedin_Username, loggedin_Password, totalEmployees,foundIndex ) == true)
	{
		employee_password[foundIndex] = NULL;
		cout << "Enter new Password: ";
		cin.ignore();
		cin.getline(buffer, 100);
		employee_password[foundIndex] = GetStringFromBuffer(buffer);
		
		ofstream put("emp.txt");
		for (int index = 0; index < totalEmployees; index++)
		{
			put << employee_username[index] << "," << employee_password[index] << endl;
		}
		put.close();
	}
	else
	{
		cout << "No Such Username Exist\n";
	}
}

// This function will regenerate the tarrif file after change
void Put_Tarriff(ofstream& put)
{
	put<<"1Phase"<<","<< phase1_reg_hour_unit_priceD << "," <<phase1_peak_hours_unit_priceD << "," << phase1_percentage_of_taxD << "," << phase1_fixed_chargesD << endl;
	put<< "1Phase" << "," << phase1_reg_hour_unit_priceC << "," << phase1_peak_hours_unit_priceC << "," << phase1_percentage_of_taxC<< "," << phase1_fixed_chargesC << endl;
	put<<"3Phase" << "," << phase3_reg_hour_unit_priceD << "," << phase3_peak_hours_unit_priceD << "," << phase3_percentage_of_taxD << "," << phase3_fixed_chargesD << endl;
	put << "3Phase" << "," << phase3_reg_hour_unit_priceC << "," << phase3_peak_hours_unit_priceC << "," << phase3_percentage_of_taxC << "," << phase3_fixed_chargesC << endl;
	
}

// This function will input tarriff attributes of domestic phase 1 customer
void Phase1_Tarrif_for_D(int& phase1_reg_hour_unit_priceD, int& phase1_peak_hours_unit_priceD, int& phase1_percentage_of_taxD, int& phase1_fixed_chargesD, ifstream& tarriff_input)
{
	char buffer[100];
	tarriff_input.getline(buffer, 100, ',');

	tarriff_input >>phase1_reg_hour_unit_priceD;

	tarriff_input.ignore();
	tarriff_input >> phase1_peak_hours_unit_priceD;

	tarriff_input.ignore();
	tarriff_input >> phase1_percentage_of_taxD;

	tarriff_input.ignore();
	tarriff_input >> phase1_fixed_chargesD;
	
}

// This function will update tarriff attributes of domestic phase 1 customer
void Phase1_Tarrif_for_D(int& phase1_reg_hour_unit_priceD, int& phase1_peak_hours_unit_priceD, int& phase1_percentage_of_taxD, int& phase1_fixed_chargesD)
{
	cout << "Enter Regular Hour Unit Price: ";
	cin>> phase1_reg_hour_unit_priceD;
	
	phase1_peak_hours_unit_priceD = 0;

	cout << "Enter Percentage of Tax: ";
	cin >> phase1_percentage_of_taxD;
	
	cout << "Enter Fixed Charges";
	cin >> phase1_fixed_chargesD;
	

}

// This function will input tarriff attributes of commercial phase 1 customer
void Phase1_Tarrif_for_C(int& phase1_reg_hour_unit_priceC, int& phase1_peak_hours_unit_priceC, int& phase1_percentage_of_taxC, int& phase1_fixed_chargesC, ifstream& tarriff_input)
{
	char buffer[100];
	tarriff_input.getline(buffer, 100, ',');

	tarriff_input >> phase1_reg_hour_unit_priceC;

	tarriff_input.ignore();
	tarriff_input >> phase1_peak_hours_unit_priceC;

	tarriff_input.ignore();
	tarriff_input >> phase1_percentage_of_taxC;

	tarriff_input.ignore();
	tarriff_input >> phase1_fixed_chargesC;
}

// This function will update tarriff attributes of commercial phase 1 customer
void Phase1_Tarrif_for_C(int& phase1_reg_hour_unit_priceC, int& phase1_peak_hours_unit_priceC, int& phase1_percentage_of_taxC, int& phase1_fixed_chargesC)
{
	cout << "Enter Regular Hour Unit Price: ";
	cin >> phase1_reg_hour_unit_priceC;

	phase1_peak_hours_unit_priceD = 0;

	cout << "Enter Percentage of Tax: ";
	cin >> phase1_percentage_of_taxC;

	cout << "Enter Fixed Charges";
	cin >> phase1_fixed_chargesC;
}

// This function will input tarriff attributes of domestic phase 3 customer
void Phase3_Tarrif_for_D(int& phase3_reg_hour_unit_priceD, int& phase3_peak_hours_unit_priceD, int& phase3_percentage_of_taxD, int& phase3_fixed_chargesD, ifstream& tarriff_input)
{
	char buffer[100];
	tarriff_input.getline(buffer, 100, ',');

	tarriff_input >> phase3_reg_hour_unit_priceD;

	tarriff_input.ignore();
	tarriff_input >> phase3_peak_hours_unit_priceD;

	tarriff_input.ignore();
	tarriff_input >> phase3_percentage_of_taxD;

	tarriff_input.ignore();
	tarriff_input >> phase3_fixed_chargesD;
}

// This function will update tarriff attributes of domestic phase 3 customer
void Phase3_Tarrif_for_D(int& phase3_reg_hour_unit_priceD, int& phase3_peak_hours_unit_priceD, int& phase3_percentage_of_taxD, int& phase3_fixed_chargesD)
{
	cout << "Enter Regular hours Price: ";
	cin>> phase3_reg_hour_unit_priceD;

	cout << "Enter Peak Hours Price: ";
	cin >> phase3_peak_hours_unit_priceD;

	cout << "Enter Pecentage of Tax: ";
	cin>> phase3_percentage_of_taxD;

	cout << "Enter Fixed Charges: ";
	cin >> phase3_fixed_chargesD;
}

// This function will input tarriff attributes of commercial phase 3 customer
void Phase3_Tarrif_for_C(int& phase3_reg_hour_unit_priceC, int& phase3_peak_hours_unit_priceC,int& phase3_percentage_of_taxC, int& phase3_fixed_chargesC,ifstream& tarriff_input)
{
	char buffer[100];

	tarriff_input.getline(buffer, 100, ',');

	tarriff_input >> phase3_reg_hour_unit_priceC;

	tarriff_input.ignore();
	tarriff_input >> phase3_peak_hours_unit_priceC;

	tarriff_input.ignore();
	tarriff_input >> phase3_percentage_of_taxC;

	tarriff_input.ignore();
	tarriff_input >> phase3_fixed_chargesC;

}

// This function will update tarriff attributes of commercial phase 3 customer
void Phase3_Tarrif_for_C(int& phase3_reg_hour_unit_priceC, int& phase3_peak_hours_unit_priceC, int& phase3_percentage_of_taxC, int& phase3_fixed_chargesC)
{
	cout << "Enter Regular hours Price: ";
	cin >> phase3_reg_hour_unit_priceC;

	cout << "Enter Peak Hours Price: ";
	cin >> phase3_peak_hours_unit_priceC;

	cout << "Enter Pecentage of Tax: ";
	cin >> phase3_percentage_of_taxC;

	cout << "Enter Fixed Charges: ";
	cin >> phase3_fixed_chargesC;

}

// This function will prompt employyee to enter billing info of every customer
void BillingInfo(char**& id, int totalCustomers, char** meterType, char** customerType, bool*& Status,int*& TotalBill)
{
	int* BillingMonth = new int[totalCustomers];
	
	int* SalesTax = new int[totalCustomers];;
	int* FixedCharges = new int[totalCustomers];;
	//TotalBill = new int[totalCustomers];;
	int* DueDate = new int[totalCustomers];;
	Status = new bool[totalCustomers];;


	int* reading_entry_date = new int [totalCustomers];

	int* currentRegular_meterReading = new int[totalCustomers];
	int* currentPeak_meterReading = new int[totalCustomers];

	int* Regular_costperunit = new int[totalCustomers];
	int* Peak_costperunit = new int[totalCustomers];

	
	int* regularconsumedunits = new int[totalCustomers];
	int* peakconsumedunits = new int[totalCustomers];

	int* currentmeterRead = new int[totalCustomers];
	int* previousmeterRead = new int[totalCustomers];

	for (int i = 0; i < totalCustomers; i++)
	{
		previousmeterRead[i] = 0;
	}
	int* costperunits = new int[totalCustomers];
	int* consumedUnits = new int[totalCustomers];

	ofstream OutputBill("BillingInfo.txt");
	if (OutputBill.is_open())
	{
		for (int index = NULL; index < totalCustomers; index++)
		{
			char buffer[100];
			OutputBill << id[index] << ",";

			int number;
			cout << "Billing Month: ";
			cin >> number;
			BillingMonth[index] = number;
			OutputBill << BillingMonth[index] << ",";

			currentmeterRead[index] = 0;
			//OutputBill << currentmeterRead[index] << ",";

			cout << "Reading Entry Date: ";
			cin >> number;
			reading_entry_date[index] = number;
			//OutputBill << reading_entry_date[index] << ",";

			if (meterType[index][0] == '1')
			{
				cout << "Current Meter Reading for regular hours:  ";
				cin >> number;
				currentRegular_meterReading[index] = number;
				//OutputBill << currentRegular_meterReading[index] << ",";
				

				if (customerType[index][0] == 'D')
				{
					FixedCharges[index]= phase1_fixed_chargesD;
					//OutputBill << FixedCharges[index]<<",";
					
					Peak_costperunit[index] = phase1_peak_hours_unit_priceD;
					//OutputBill << Peak_costperunit[index]<<",";

					Regular_costperunit[index] = phase1_reg_hour_unit_priceD;
					//OutputBill << Regular_costperunit[index]<<",";

					consumedUnits[index] = currentRegular_meterReading[index];
					OutputBill << consumedUnits[index] << ",";

					int currentmonthunits = consumedUnits[index] - previousmeterRead[index];
					//OutputBill << previousmeterRead[index] << ",";
					//OutputBill << currentmonthunits << ",";

					SalesTax[index] = phase1_percentage_of_taxD;
					//OutputBill << SalesTax[index]<<",";

					TotalBill[index] = currentmonthunits * SalesTax[index] / 100 + FixedCharges[index];
					OutputBill << TotalBill[index] <<",";
				}
				else
				{
					if (customerType[index][0] == 'C')
					{
						FixedCharges[index] = phase1_fixed_chargesC;

						Peak_costperunit[index] = phase1_peak_hours_unit_priceC;

						Regular_costperunit[index] = phase1_reg_hour_unit_priceC;
						//OutputBill << Regular_costperunit[index] << ",";


						consumedUnits[index] = currentRegular_meterReading[index];
						OutputBill << consumedUnits[index] << ",";

						int currentmonthunits = consumedUnits[index] - previousmeterRead[index];
						//OutputBill << previousmeterRead[index] << ",";
						//OutputBill << currentmonthunits;
						

						SalesTax[index] = phase1_percentage_of_taxC;
						TotalBill[index] = currentmonthunits * SalesTax[index] / 100 + FixedCharges[index];
						OutputBill << TotalBill[index] << ",";
					}
				}
			}
			else
			{
				if (meterType[index][0] == '3')
				{
					cout << "Current Meter Reading for regular hours:  ";
					cin >> number;
					currentRegular_meterReading[index] = number;
					//OutputBill << currentRegular_meterReading[index] << ",";

					cout << "Current Meter Reading for Peak Hours: ";
					cin >> number;
					currentPeak_meterReading[index] = number;


					if (customerType[index][0] == 'D')
					{
						FixedCharges[index] = phase3_fixed_chargesD;
						//OutputBill << FixedCharges[index] << ",";

						// price
						Peak_costperunit[index] = phase3_peak_hours_unit_priceD;
						//OutputBill << Peak_costperunit[index] << ",";

						// price
						Regular_costperunit[index] = phase3_reg_hour_unit_priceD;
						//OutputBill << Regular_costperunit[index] << ",";

						consumedUnits[index] = currentRegular_meterReading[index] + currentPeak_meterReading[index];
						OutputBill << consumedUnits[index] << ",";

						int currentmonthunits = consumedUnits[index] - previousmeterRead[index];
						//OutputBill << previousmeterRead[index] << ",";
						//OutputBill << currentmonthunits << ",";

						SalesTax[index] = phase3_percentage_of_taxD;
						//OutputBill << SalesTax[index] << ",";

						TotalBill[index] = currentmonthunits * SalesTax[index] / 100 + FixedCharges[index];
						OutputBill << TotalBill[index] << ",";
					}
					else
					{
						if (customerType[index][0] == 'C')
						{
							FixedCharges[index] = phase3_fixed_chargesC;
							// Price
							Peak_costperunit[index] = phase3_peak_hours_unit_priceC;
							//OutputBill << Peak_costperunit[index] << ",";


							Regular_costperunit[index] = phase3_reg_hour_unit_priceC;
							//OutputBill << Regular_costperunit[index] << ",";

							consumedUnits[index] = currentRegular_meterReading[index] + currentPeak_meterReading[index];
							OutputBill << consumedUnits[index] << ",";

							int currentmonthunits = consumedUnits[index] - previousmeterRead[index];

							SalesTax[index] = phase3_percentage_of_taxC;
							TotalBill[index] = currentmonthunits * SalesTax[index] / 100 + FixedCharges[index];
							OutputBill << TotalBill[index] << ",";
						}
					}
				}
			}

			DueDate[index] = reading_entry_date[index] + 7;
			OutputBill << DueDate[index] << ",";
			Status[index] = false;
			OutputBill << Status[index] << endl;

		}

	}
	else
	{
		cout << "BillingInfo File cannot be openned.\n";
	}


}

// This function will load the customer's billing info
void LaodBillInfo(char**& ID, int*& BillingMonth, int*& ConsumedUnits, int*& Totalbill, int*& DueDate, bool *&Status,int totalcustomers)
{
	char buffer[100];
	ifstream input("BillingInfo.txt");
	if (input.is_open())
	{
		for (int i = 0; i < totalcustomers; i++)
		{
			input.getline(buffer, 100, ',');
			ID[i] = GetStringFromBuffer(buffer);

			int number;
			
			input >> BillingMonth[i];
			input.ignore();

			input >> ConsumedUnits[i];
			input.ignore();

			input >> Totalbill[i];
			input.ignore();

			input >> DueDate[i];
			input.ignore();

			input >> Status[i];

		}
	}
}

// This function will show bill info
void ViewBill(char** id, bool* Status,int* TotalBill, int index)
{
	cout << id[index] << " ";
	if (Status[index] == true)
		cout << "Paid" << " ";
	else
		cout << "Un-Paid" << " ";
	cout << " " << TotalBill[index] << endl;
}

// This function will show the status of all paid and upaid customers along with their bills
void VeiwCustomerBill(char** ID, char* id, int totalcustomers,bool* status, char** meterType, char** customerType, int* TotalBill)
{
	bool found = false;
	for (int i = 0; i < totalcustomers; i++)
	{
		char* temp = ID[i];

		for (int j = 0; j < strlen(temp); j++)
		{
			found = false;
			if (temp[j] == id[j])
			{
				found = true;
			}
		}
		if (found == true)
		{
			if (status[i] == 1)
				cout << "Status of " << temp << " is Paid" << " ";
			else
				if (status[i] ==0)
					cout << "Status of " << temp << " is Un-Paid" << " ";
			cout << "\nBill: " << TotalBill[i] << endl;
			cout << "Customer Type: "<<customerType[i] << endl;
			cout << "Meter Type: "<<meterType[i] << endl;
			
		}
	}
}

// This function will show the bill statistics
void BillStatistics(char** ID, bool* status, int totalcustomers, int* totalbill)
{
	int unpaid = NULL;
	int paid = NULL;
	for (int i = 0; i < totalcustomers; i++)
	{
		if (status[i] == 0)
		{
			cout <<ID[i] << "'s" << " bill " << totalbill[i] << " is unpaid";
			unpaid = unpaid + totalbill[i];
			cout << endl;
		}
		
		if (status[i] == 1)
		{
			cout << endl;
			cout  <<ID[i] << "'s" << " bill " << totalbill[i] << " is Paid";
			paid = paid + totalbill[i];
			cout << endl;
		}
		
	}
	
	cout<<"Total amount of unapid bills is: "<<unpaid;
	cout<<endl;
	cout<<"Total amount of paid bills is: "<<paid;
}

// This function will led the employyee to change the status of customers who paid bill
void ChangeStatus(int index, bool* status)
{
	status[index] = 1;
}

// This function will lead the employyeee to register new customer
void Register_New_Customer(int& totalcustomer)
{
	ofstream put;
	put.open("cus.txt", std::fstream::app);
	string data;
	cout << "Enter ID: ";
	cin >> data;
	put << endl << data << ",";

	cout << "Enter Date Of Birth: ";
	cin >> data;
	put << data << ",";

	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, data);
	put << data << ",";

	cout << "Enter Address: ";
	getline(cin, data);
	put << data << ",";

	cout << "Enter Contact Number: ";
	cin >> data;
	put << data << ",";

	cout << "Enter Customer Type: ";
	cin >> data;
	put << data << ",";

	cout << "Enter Meter Type: ";
	cin >> data;
	put << data << ",";

	cout << "Enter Cd: ";
	cin >> data;
	put << data << ",";

	cout << "Enter Regular Hours Consumption: ";
	cin >> data;
	put << data << ",";

	cout << "Enter Peak Hours Consumption: ";
	cin >> data;
	put << data;

	totalcustomer++;
}

// This function will find the customer and will return index
int FindCustomer(char** ID, char* id, int totalcustomers)
{
	bool found = false;
	for (int i = 0; i < totalcustomers; i++)
	{
		char* temp = ID[i];

		found = false;
		for (int j = 0; j < strlen(temp); j++)
		{
			if (temp[j] == id[j])
				found = true;
			else
				break;
		}
		if (found == true)
		{
			return i;
		}
	}

	
}

// This function will verify customers log in ID and password
bool Verify_Customer(char** ID, char** customerpassword, char* loggedin_username, char* loggedin_password, int total_customers,int& foundIndex)
{
	bool customerID = false;
	bool customer_Password = false;
	
	for (int index = NULL; index < total_customers; index++)
	{
		char* temp = ID[index];
		char* newString = temp;
		if (temp[0] == '\n')
		{
			int len = StringLenght(temp);

			newString = new char[len];

			int counter = 1;
			int index = NULL;
			for (;index < len; index++)
			{
				newString[index] = temp[counter];
				counter++;
			}
			newString[index] = '\0';
		}
		temp = newString;
		int check = NULL;
		if (StringLenght(temp) == StringLenght(loggedin_username))
		{
			for (int j_index = NULL; j_index < StringLenght(temp); j_index++)
			{
				customerID = false;

				if (temp[j_index] == loggedin_username[j_index])
				{
					customerID = true;
					check++;
				}

			}

			if (check == StringLenght(loggedin_username))
			{
				check = NULL;
				char* _temp = customerpassword[index];
				if (StringLenght(_temp) == StringLenght(loggedin_password))
				{
					for (int j_index = NULL; j_index < StringLenght(_temp); j_index++)
					{
						customer_Password = false;

						if (_temp[j_index] == loggedin_password[j_index])
						{
							customer_Password = true;
							check++;
						}
					}
					if (check == StringLenght(loggedin_password))
					{
						foundIndex = index;
						return true;
					}
				}
				else
				{
					return false;
				}
			}
			
		}

		
		
	}
}

int main()
{
	//							D A T A    I N I T I A L I Z A T I O N
	// Employee Information
	char** employee_Username = NULL; // 2D array to load employees list
	char** employee_password = NULL; // 2D array to load employees's password
	// Customer Information
	char** ID = NULL; // customer ID
	char** DOB = NULL; // Date of Birth of customer 
	char** name = NULL; // Name of customer
	char** address = NULL;	// Address of customer
	char** contactNumber = NULL; // contact number
	char** customerType = NULL; // customer type i.e. either commercial or domestic
	char** meterType = NULL; // meter type i.e. 1phase meter or 3phase meter
	char** connectionDate = NULL; // connection date
	char** customerPassword = NULL;	//customer's passwords array

	int* regular_hours = NULL; // meter reading in regular hours
	int* peak_hours = NULL; // meter reading on peak hours
	int option = NULL; // choice
	int totalCustomers = NULL;
	int totalEmployees = NULL;

	int* TotalBill = new int[10]; 
	int* BillingMonth = new int[totalCustomers];
	int* ConsumedUnits = new int[totalCustomers];
	int* totalbill = new int[totalCustomers];
	int* DueDate = new int[totalCustomers];
	
	bool* billStatus = new bool[10];
	bool* Status = new bool[totalCustomers];

									// Laoding Customers Data
	LoadCustomerData(totalCustomers,ID, DOB, name, address, contactNumber, customerType, meterType, connectionDate, regular_hours, peak_hours,customerPassword);
	//ShowLaodedCustomers(totalCustomers, ID, DOB, name, address, contactNumber, customerType, meterType, connectionDate, regular_hours, peak_hours);
									
										// Loading Tarriff Data

	ifstream input_tarriff("TarrifTaxInfo.txt");
	Phase1_Tarrif_for_D(phase1_reg_hour_unit_priceD, phase1_peak_hours_unit_priceD, phase1_percentage_of_taxD, phase1_fixed_chargesD, input_tarriff);
	Phase1_Tarrif_for_C(phase1_reg_hour_unit_priceC, phase1_peak_hours_unit_priceC, phase1_percentage_of_taxC, phase1_fixed_chargesC, input_tarriff);
	Phase3_Tarrif_for_D(phase3_reg_hour_unit_priceD, phase3_peak_hours_unit_priceD, phase3_percentage_of_taxD, phase3_fixed_chargesD, input_tarriff);
	Phase3_Tarrif_for_C(phase3_reg_hour_unit_priceC, phase3_peak_hours_unit_priceC, phase3_percentage_of_taxC, phase3_fixed_chargesC, input_tarriff);
	
									// Laoding Bill Info
	char** id = new char* [totalCustomers];
	LaodBillInfo(id, BillingMonth, ConsumedUnits, totalbill, DueDate, Status, totalCustomers);
	

	cout << "\t\t\t\t\t	Welcome\n";
	cout<<"\t\t\t\t\t Are you Employee or Customer \n \n";
	cout << "\t\t\t\t\t For Employee Press 0  \n\t\t\t\t\t For Customer Press 1\n \n";
	cin >> option;

	
	if (option == 0)
	{
		LoadEmployeeData(employee_Username, employee_password,totalEmployees);
		//ShowEmployeeData(employee_Username, employee_password, totalEmployees);
		
		char* loggedin_Username;
		char* loggedin_Password;
		Login(loggedin_Username,loggedin_Password);

		int foundEmployee = NULL;
		if (Employee_Verification(employee_Username, employee_password, loggedin_Username, loggedin_Password, totalEmployees,foundEmployee) == true)
		{
			cout << "Login Successfull\n";
			cout << "Press any Number (1-7) to continue......";
			cin >> option;
			
			while (option != 0)
			{
				cout << "\n\nFor Changing Password Press 1\nFor Registering new Customer Press 2\nFor Entring Billing Information Press 3\nFor Veiw Bill of Customer Press 4\n";
				cout << "For Veiwing Statistics of Bills Press 5\nFor Updating Tarriff Information Press 6\nFor Changing Status of customer Press 7\nFor Exit Press 0\n";
				cin >> option;
				if (option == 1)
				{
					totalEmployees--;
					ChangePassword(employee_Username, employee_password, totalEmployees);
					cout << endl << "Password Changed Successfully\n";
				}
				else
				{
					if (option == 2)
					{
						Register_New_Customer(totalCustomers);
						cout << endl << "New Customer Registered Successfully\n";
					}
					else
					{

						if (option == 3)
						{
							BillingInfo(ID, totalCustomers, meterType, customerType, billStatus, TotalBill);
							cout << "Updated\n";
						}
						else
						{
							if (option == 4)
							{
								cout << "Enter ID: ";
								char buffer[100];
								cin >> buffer;
								char* id;
								id = GetStringFromBuffer(buffer);
								VeiwCustomerBill(ID, id, totalCustomers, Status, meterType, customerType, totalbill);

							}
							else
							{
								if (option == 5)
								{
									BillStatistics(ID, Status, totalCustomers, totalbill);
								}
								else
								{
									if (option == 6)
									{
										int choice;
										cout << "Press 5  to Start: ";
										cin >> choice;

										while (choice != 0 && choice != 6)
										{
											cout << "For Phase One and Domestic Customer Press 1\n For Phase One and Commercial Customer Press 2\nFor Phase 3 and Domestic Customer Press 3\nFor Phase 3 and Commercial Customer Press 4\n";
											cin >> choice;

											if (choice == 1)
											{
												Phase1_Tarrif_for_D(phase1_reg_hour_unit_priceD, phase1_peak_hours_unit_priceD, phase1_percentage_of_taxD, phase1_fixed_chargesD);
											}
											else
											{
												if (choice == 2)
												{
													Phase1_Tarrif_for_C(phase1_reg_hour_unit_priceC, phase1_peak_hours_unit_priceC, phase1_percentage_of_taxC, phase1_fixed_chargesC);
												}
												else
												{
													if (choice == 3)
													{
														Phase3_Tarrif_for_D(phase3_reg_hour_unit_priceD, phase3_peak_hours_unit_priceD, phase3_percentage_of_taxD, phase3_fixed_chargesD);
													}
													else
													{
														if (choice == 4)
														{
															Phase3_Tarrif_for_C(phase3_reg_hour_unit_priceC, phase3_peak_hours_unit_priceC, phase3_percentage_of_taxC, phase3_fixed_chargesC);
														}
													}
												}
											}

										}
										ofstream put("TarrifTaxInfo.txt");
										Put_Tarriff(put);
									}
									else
									{
										if (option == 7)
										{

											cout << "Enter Customer ID: ";
											char buffer[100];
											cin >> buffer;

											char* _id = GetStringFromBuffer(buffer);

											int index = FindCustomer(ID, _id, totalCustomers);
											ChangeStatus(index, Status);
											//ViewBill(ID, Status, totalbill, index);

										}
										else
										{
											if (option == 0)
											{
												cout << "THANKS\n";
												cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Monochrome Production\n\n";
												break;
											}
										}
									}
								}
							}
						}
					}
				}


			}
		}
		else
		{
			cout << "Incorrect User ID OR Password\n";
			return -1;
		}
	}
	else
	{
		if (option == 1)
		{
			char* loggedin_username;
			char* loggedin_password;

			char buffer[100];
			cout << "User ID: ";
			cin.ignore();
			cin.getline(buffer, 100);			
			loggedin_username = GetStringFromBuffer(buffer);

			cout << endl << endl;

			cout << "Password: ";
			cin.getline(buffer, 100);
			loggedin_password = GetStringFromBuffer(buffer);

			int foundcustomer = NULL;
			if (Verify_Customer(ID, customerPassword, loggedin_username, loggedin_password, totalCustomers,foundcustomer) == true)
			{
				cout << "Press 5 to Start: ";
				cin >> option;
				while (option != 2)
				{
					cout << "1. Veiw Bill\n2. To Exit";
					cin >> option;
					if (option == 1)
					{
						cout << endl << endl;
						ViewBill(id, Status, totalbill, foundcustomer);
						cout << endl << endl;
					}
					else
					{
						if (option == 2)
						{
							cout << "THANKS\t\t\t\t\t\t\t\t\t MONOCHROME PRODUCTION\n\n";
						}
					}
				}

			}			
		}
		else
		{
			cout << "You made Wrong choice\n";
			return -2;
		}
	}
	
	
	//system("pause");
}

