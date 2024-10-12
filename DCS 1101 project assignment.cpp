// This program is a simple banking system for Jegaraj Banking.
#include<iostream> 
#include<cstdlib> // This header is used for the randomized number.
#include<ctime> // This header is used for the local time and date.
#include<fstream> // This header is used for the text file.
#include<iomanip> // This header is used to add decimal points.
#include<windows.h> // This header is used for the sleep time function.
#pragma warning(disable : 4996) // This header is used to include unsafe commands in visual studio.
using namespace std;
char menu(char option); // This function is for the options menu.
string name(char acc_name[100], string gender); // This function is for name and gender input in account creation.
double create(double& balance); // This function is for age, ic and phone number input, and initial deposit balance.
double deposit(double& balance, double& acc_num); // This function is for cash and cheque deposit.
double withdrawal(double& balance, double& acc_num); // This function is for withdrawal.

int main()
{
	// Declared variables in main function
	char option = 0;
	double acc_num, balance = 0.0;
	char acc_name[100];
	string gender;

	// Function calling
	name(acc_name, gender);
	create(balance);

	// To write the account details text file into the folder
	ofstream outfile;
	outfile.open("Account Details.txt", ios::app);

	// To give the user a randomized account number
	srand(time(0));
	for (int i = 0; i <= 3; i++)
	{
		acc_num = rand();
	}

	// Declaration of user's account number and initial balance
	cout << "\t\tYour account number is : " << acc_num << acc_num << endl;
	cout << "\t\tIntial balance is : RM " << fixed << setprecision(2) << balance << endl;

	outfile << "Account Number : " << fixed << setprecision(0) << acc_num << acc_num << endl;

	Sleep(2000); // Sleep time function as if to show the banking system is processing information.
	cout << "\n\t\tPlease insert your bank card" << endl;
	Sleep(2500); // Sleep time function as if to show the banking system is processing information.
	cout << "\n\t\tReading card" << endl;
	cout << "\t\t............" << endl;
	Sleep(2000); // Sleep time function as if to show the banking system is processing information.

	// The do while command is to ensure the options menu loops until user inputs D/d to exit or to return user back to menu if invalid is inputted.
	do
	{
		// Calling option function 
		option = menu(option);

		// If else command to give the user options to choose in the menu.
		if (option == 'A' || option == 'a')
		{
			// Calling deposit function
			balance = deposit(balance, acc_num);
			cout << "\n\t\tYour updated balance amount is : RM " << fixed << setprecision(2) << balance << endl;
		}

		else if (option == 'B' || option == 'b')
		{
			// Calling withdrawal function
			balance = withdrawal(balance, acc_num);
			cout << "\n\t\tYour updated balance amount is : RM " << fixed << setprecision(2) << balance << endl;

		}

		else if (option == 'C' || option == 'c')
		{
			Sleep(2000); // Sleep time function as if to show the banking system is processing information.
			cout << "\n\t\tYour current balance is : RM " << fixed << setprecision(2) << balance << endl;
			cout << "\t\tYou may withdraw up to : RM " << fixed << setprecision(2) << balance << endl;
			Sleep(2000); // Sleep time function as if to show the banking system is processing information.
		}

		else if (option == 'D' || option == 'd')
		{
			cout << "\n\t\tThank you for using Jegaraj Banking" << endl;
			cout << "\t\tIf you encounter any issues while using our banking system," << endl;
			cout << "\t\tplease do not hesitate to inform our staff at the counter." << endl;
		}

		else
		{
			cout << "\n\t\tInvalid input, please enter a valid option." << endl;
			cout << "\t\tIf you wish to exit this program please enter D" << endl;
		}
	} while (option != 'D' && option != 'd');

	return 0;
}

// The menu function
char menu(char option)
{
	cout << "\n\t\tOptions Menu" << endl;
	cout << "\n\t\tA. Make a deposit" << endl; 
	cout << "\t\tB. Make a withdrawal" << endl;
	cout << "\t\tC. Balance Inquiry" << endl;
	cout << "\t\tD. Exit" << endl;

	cout << "\n\t\tPlease choose what you would like : ";
	cin >> option;

	return option; // To return the option inputted by the user back to the main function
}

// Function for first half of account creation
string name(char acc_name[100], string gender)
{
	// Declared variable in name function
	char option;
	cout << "\n\t\t=============================================================" << endl;
	cout << "\t\t\t\tWelcome to J Banking" << endl;
	cout << "\t\t\t\tAutomated Banking System" << endl;
	cout << "\t\t=============================================================" << endl;
	cout << "\n\t\tPlease create a new bank account" << endl;
	cout << "\n\t\tEnter account holders name : ";
	cin.getline(acc_name, 99); // To impose a limit on how many characters can the user input.

	// To write the first half of account details text file into the folder
	ofstream outfile;
	outfile.open("Account Details.txt", ios::out);

	// Do while command to loop the function is user inputs an invalid value
	do 
	{
		cout << "\n\t\tSelect your gender" << endl;
		cout << "\t\tEnter A for Male" << endl;
		cout << "\t\tEnter B for Female" << endl;
		cout << "\t\tAnswer : ";
		cin >> option;

		// If else command to give the user an option between male or female
		if (option == 'A' || option == 'a')
		{
			gender = "Male";
		}

		else if (option == 'B' || option == 'b')
		{
			gender = "Female";
		}

		else
		{
			cout << "\n\t\tInvalid input, please enter a valid option." << endl;
		}
	} while (option != 'A' && option != 'a' && option != 'B' && option != 'b');

	// To write out first half of account creation in the text file
	outfile << "Account holder : " << acc_name << endl;
	outfile << "Gender : " << gender << endl;

	return acc_name, gender; // Returning account name and gender back to the main function
}

// Function for second half of account creation
double create(double& balance)
{
	// Declared variables in create function
	double age;
	string ic, phonenum;
	
	// To show local date and time in text file
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);

	// To write the second half of the account details text file into the folder
	ofstream outfile;
	outfile.open("Account Details.txt", ios::app);

	// Do while command to loop if user inputs and invalid age
	do
	{
		cout << "\n\t\tPlease enter your age : ";
		cin >> age;

		// If else command to detect value inputted by user and give them appropriate response
		if (age < 0)
			cout << "\t\tPlease enter a valid age!" << endl;

		else if (age == 0)
			cout << "\t\tPlease enter a valid age!" << endl;

		else if (age > 0 && age < 16)
			cout << "\t\tPlease ensure you have an adult to help you throught this process" << endl;
	} while (age < 0 || age == 0);

	cout << "\n\t\tPlease enter your Identification Number (IC) : ";
	cin >> ic;

	cout << "\t\tPlease enter your phone number : ";
	cin >> phonenum;

	// Do while command so that user deposits a valid initial balance
	do
	{
		cout << "\t\tPlease set the intial balance to be added in your bank account : ";
		cin >> balance;

		// If else to detect value to be deposited by user and give the appropriate response
		if (balance < 0 || balance == 0)
		{
			cout << "\n\t\tPlease enter an intial balance which is more than 0!" << endl;
		}

		else
		{
			cout << "\n\t\tCompiling Results" << endl;
			cout << "\t\t................." << endl;
			Sleep(2000); // Sleep time function as if to show the banking system is processing information.
			cout << "\n\t\tNew account has been created at " << asctime(ti) << endl;

			// To write out second half of account creation in the text file
			outfile << "Identification Number : " << ic << endl;
			outfile << "Age : " << age << endl;
			outfile << "Phone Number : " << phonenum << endl;
			outfile << "Initial balance placed into account : RM " << fixed << setprecision(2) << balance << endl;
			outfile << "Transaction successful at " << asctime(ti);
			return balance; // To return the balance back to the main function
		}
	} while (balance < 0 || balance == 0);

}

// Function for cash and cheque deposit
double deposit(double& balance, double& acc_num)
{
	// To show local date and time in text file
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);

	// Declared variables in deposit function
	char option;
	double amo_dep, che_num, che_amo;

	// Do while command to ask if user wants to do a cash or cheque deposit and loop if invalid value is inputted
	do
	{
		cout << "\n\t\tDeposit cash or cheque?" << endl;
		cout << "\n\t\tEnter A for cash deposit" << endl;
		cout << "\t\tEnter B for cheque deposit" << endl;
		cout << "\t\tAnswer : ";
		cin >> option;

		if (option == 'A' || option == 'a')
		{
			// To write deposit cash receipt text file into the folder
			ofstream outfile;
			outfile.open("Deposit Cash Receipt.txt", ios::out);

			// If else command for file opening
			if (!outfile)
			{
				cout << "File could not be opened!";
				return -1;
			}

			cout << "\n\t\tHow much would you like to deposit? : ";
			cin >> amo_dep;
			
			// If else command to detect invalid deposit value inputted by user
			if (amo_dep == 0 || amo_dep < 0)
			{
				cout << "\n\t\tInvalid deposit amount, please deposit more than 0";
			}
			else
			{
				balance = balance + amo_dep;
				cout << "\n\t\tPlease place cash in the opening" << endl;
				cout << "\t\t................................" << endl;
				Sleep(2000); // Sleep time function as if to show the banking system is processing information.
				cout << "\n\t\tRM " << fixed << setprecision(2) << amo_dep << " has been deposited into account ";
				cout << fixed << setprecision(0) << acc_num << acc_num << endl;
				cout << "\t\tTransaction successful at " << asctime(ti) << endl;

				Sleep(2000); // Sleep time function as if to show the banking system is processing information.
				cout << "\n\t\tDo you require a receipt?" << endl;
				cout << "\t\tIf you need a reciept enter A, if do you do not need a receipt enter anything else : ";
				cin >> option;

				// If else command to give the user a choice to print a receipt or not
				if (option == 'A' || option == 'a')
				{
					cout << "\n\t\tPrinting Receipt" << endl;
					cout << "\n\t\t................" << endl;
					Sleep(2000); // Sleep time function as if to show the banking system is processing information.
					cout << "\n\t\tReceipt has been printed, Thank you for using Jegaraj Banking" << endl;

					// To write cash deposit details into the text file
					outfile << "RM " << fixed << setprecision(2) << amo_dep << " has been deposited into account ";
					outfile << fixed << setprecision(0) << acc_num << acc_num << endl;
					outfile << "Transaction successful at " << asctime(ti) << endl;
					outfile << "Thank you for using Jegaraj Banking";

					outfile.close();
				}
				else
				{
					cout << "\n\t\tThank you for using Jegaraj Banking" << endl;
					return balance; // To return the balance back to the main function
				}

			}
		}

		else if (option == 'B' || option == 'b')
		{
			// To write out the deposit cheque receipt text file into the folder
			ofstream outfile;
			outfile.open("Deposit Cheque Receipt.txt", ios::out);

			// If else command for file opening
			if (!outfile)
			{
				cout << "File could not be opened!";
				return -1;
			}

			cout << "\n\t\tPlease enter the cheque number : ";
			cin >> che_num;

			cout << "\t\tHow much is written in the cheque? : ";
			cin >> che_amo;

			// If else command to detect invalid deposit value inputted by user
			if (che_amo == 0 || che_amo < 0)
			{
				cout << "\n\t\tInvalid deposit amount, please deposit more than 0";
			}
			else
			{
				balance = balance + che_amo;
				cout << "\n\t\tPlease place cheque in the opening" << endl;
				cout << "\t\t.................................." << endl;
				Sleep(2000); // Sleep time function as if to show the banking system is processing information.
				cout << "\n\t\tCheque " << fixed << setprecision(0) << che_num << " containing";
				cout << " RM " << fixed << setprecision(2) << che_amo << " successfully deposited into account ";
				cout << fixed << setprecision(0) << acc_num << acc_num << endl;
				cout << "\t\tTransaction successful at " << asctime(ti);

				Sleep(2000); // Sleep time function as if to show the banking system is processing information.
				cout << "\n\t\tDo you require a receipt?" << endl;
				cout << "\t\tIf you need a reciept enter A, if do you do not need a receipt enter anything else : ";
				cin >> option;

				// If else command to give the user a choice to print a receipt or not
				if (option == 'A' || option == 'a')
				{
					cout << "\n\t\tPrinting Receipt" << endl;
					cout << "\t\t................" << endl;
					Sleep(2000); // Sleep time function as if to show the banking system is processing information.
					cout << "\n\t\tReceipt has been printed, Thank you for using Jegaraj Banking" << endl;

					// To write cheque deposit details into the text file
					outfile << fixed << setprecision(0) << "Cheque " << che_num << " containing";
					outfile << " RM " << fixed << setprecision(2) << che_amo << " successfully deposited into account ";
					outfile << fixed << setprecision(0) << acc_num << acc_num << endl;
					outfile << "Transaction successful at " << asctime(ti) << endl;
					outfile << "Thank you for using Jegaraj Banking";

					outfile.close();
				}
				else
				{
					cout << "\n\t\tThank you for using Jegaraj Banking" << endl;
					return balance; // To return the balance back to the main function
				}

			}
		}

		else
		{
			cout << "\n\t\tInvalid input, please enter a valid option." << endl;
		}
	} while (option != 'A' && option != 'a' && option != 'B' && option != 'b');

	return balance; // To return the balance back to the main function
}


// Function for withdrawal
double withdrawal(double& balance, double& acc_num)
{
	// Declared variables in withdrawal function
	char option;
	double with_amo;

	// To show local date and time in text file
	time_t tt;
	struct tm* ti;
	time(&tt);
	ti = localtime(&tt);

	// To write the withdrawal cash receipt text file into the folder
	ofstream outfile;
	outfile.open("Withdrawal Cash Receipt.txt", ios::out);

	// If else command for file opening
	if (!outfile)
	{
		cout << "File could not be opened!";
		return -1;
	}

	cout << "\n\t\tYou may withdraw an amount up to : " << fixed << setprecision(2) << balance << endl;
	cout << "\t\tHow much would you like to withdraw?: ";
	cin >> with_amo;

	// If else command to detect invalid withdraw value inputted by user
	if (with_amo == 0 || with_amo < 0)
	{
		cout << "\t\tInvalid withdrawal amount, kindly withdraw more than 0";
	}
	// If else command to detect whether user inputted a withdraw value higher than the balance 
	else if (with_amo > balance)
	{
		cout << "\t\tInsufficient balance!" << endl;
		cout << "\t\tYou are able to withdraw up to : " << fixed << setprecision(2) << balance;
	}
	else
	{
		balance = balance - with_amo;
		cout << "\n\t\tRM " << fixed << setprecision(2) << with_amo << " has been withdrawn from account ";
		cout << fixed << setprecision(0) << acc_num << acc_num << endl;
		cout << "\t\tTransaction successful at " << asctime(ti);
		Sleep(500); // Sleep time function as if to show the banking system is processing information.
		cout << "\n\t\tPlease collect cash from the opening" << endl;
		cout << "\t\t...................................." << endl;
		Sleep(2000); // Sleep time function as if to show the banking system is processing information.

		cout << "\n\t\tDo you require a receipt?" << endl;
		cout << "\t\tIf you need a reciept enter A, if do you do not need a receipt enter anything else : ";
		cin >> option;

		// If else command to give the user a choice to print a receipt or not
		if (option == 'A' || option == 'a')
		{
			cout << "\n\t\tPrinting Receipt" << endl;
			cout << "\t\t................" << endl;
			Sleep(2000); // Sleep time function as if to show the banking system is processing information.
			cout << "\n\t\tReceipt has been printed, Thank you for using Jegaraj Banking" << endl;

			// To write withdrawal details into the text file
			outfile << "RM " << fixed << setprecision(2) << with_amo << " has been withdrawn from account ";
			outfile << fixed << setprecision(0) << acc_num << acc_num << endl;
			outfile << "Transaction successful at " << asctime(ti);
			outfile << "Thank you for using Jegaraj Banking";

			outfile.close();
		}
		else
		{
			cout << "\n\t\tThank you for using Jegaraj Banking" << endl;
			return balance; // To return the balance back to the main function
		}
	}
	return balance; // To return the balance back to the main function
}




