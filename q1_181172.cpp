#include <iostream>
#include <fstream>
#include "githubuser.h"

using namespace std;


void backup(githubuser *originalArry, githubuser *&backupArry, int userCount, int size)//deep copy of og array to bckuparry
{

	backupArry = new githubuser[size];
	for (int i = 0; i < size; i++)
	{
		backupArry[i].firstName = originalArry[i].firstName;
		backupArry[i].userName = originalArry[i].userName;
		backupArry[i].email = originalArry[i].email;
		backupArry[i].folderCount = originalArry[i].folderCount;
		backupArry[i].gitHubFolders = new string[backupArry[i].folderCount];
		for (int k = 0; k < backupArry[i].folderCount; k++)
		{
			backupArry[i].gitHubFolders[k] = originalArry[i].gitHubFolders[k];
		}
		if (originalArry[i].institute_name != nullptr)
		{
			backupArry[i].institute_name = new string;
			backupArry[i].institute_name = originalArry[i].institute_name;
		}
		if (originalArry[i].qualification_level != nullptr)
		{
			backupArry[i].qualification_level = new string;
			backupArry[i].qualification_level = originalArry[i].qualification_level;
		}

	}



}

void remove(githubuser &user)//removes additional info
{
	user.institute_name = nullptr;
	user.qualification_level = nullptr;

}
void setEduBckGrnd(githubuser &user)//adds new info of user
{
	user.institute_name = new string;
	user.qualification_level = new string;
	cout << user.firstName << "  enter your institution name:" << endl;
	cin >> user.institute_name[0];
	cout << user.firstName << "  enter your qualification level name:" << endl;
	cin >> user.qualification_level[0];


}
void print2(githubuser* arr, int option)//prints arr after addition of new info 
{
	for (int b = 0; b < 1; b++)
	{
		cout << endl << endl;
		cout << "The first name of user " << b + 1 << " is:      " << endl;
		cout << arr[b].firstName;
		cout << endl;
		cout << "The username of user " << b + 1 << " is:       " << endl;
		cout << arr[b].userName;
		cout << endl;
		cout << "The email of user " << b + 1 << " is:     " << endl;
		cout << arr[b].email;
		cout << endl;
		cout << "The foldercount of user " << b + 1 << " is:     " << endl;
		cout << arr[b].folderCount;
		cout << endl;
		cout << "The name of the folder of user " << b + 1 << " is:     " << endl;
		for (int k = 0; k < arr[b].folderCount; k++)
		{
			cout << arr[b].gitHubFolders[k];
			cout << endl;
		}
		if (option == 1)
		{
			cout << "The institues name is:" << endl;
			cout << arr[b].institute_name[0] << endl;
			cout << "The qualification level name is:" << endl;
			cout << arr[b].qualification_level[0] << endl;
		}

	}

}
void print(githubuser* arr, const int size)
//print the users data
{
	for (int b = 0; b < size; b++)
	{
		cout << endl << endl;
		cout << "The first name of user " << b + 1 << " is:     " << endl;
		cout << arr[b].firstName;
		cout << endl;
		cout << "The username of user " << b + 1 << " is:     " << endl;
		cout << arr[b].userName;
		cout << endl;
		cout << "The email of user " << b + 1 << " is:     " << endl;
		cout << arr[b].email;
		cout << endl;
		cout << "The foldercount of user " << b + 1 << " is:    " << endl;
		cout << arr[b].folderCount;
		cout << endl;
		cout << "The name of the folder of user " << b + 1 << " is:      " << endl;
		for (int k = 0; k < arr[b].folderCount; k++)
		{
			cout << arr[b].gitHubFolders[k];
			cout << endl;
		}

	}
}

void readDataFromFile(githubuser* &user, int &size) //reading data from file
{

	ifstream bucky;
	bucky.open("input.txt");
	bucky >> size;
	user = new githubuser[size];
	for (int z = 0; z < size; z++)
	{
		bucky >> user[z].firstName;//reading from file to populate
		bucky >> user[z].userName;
		bucky >> user[z].email;
		bucky >> user[z].folderCount;
		bucky.ignore();
		user[z].gitHubFolders = new string[user[z].folderCount];
		for (int k = 0; k < user[z].folderCount; k++)
		{
			getline(bucky, user[z].gitHubFolders[k]);
		}
	}



}

int main()
{
	int size = 0;
	githubuser* arr1 = nullptr;
	githubuser* arr2 = nullptr;
	int option = 0;

	readDataFromFile(arr1, size);
	print(arr1, size);


	for (int i = 0; i < 2; i++)
	{
		cout << endl << arr1[i].firstName << endl <<"press 0 to exit menu: "<<endl<<"press 1 if you want to enter institutiuon and education level:" << endl << "press 2 if you want to skip entering institutiuon and education level information:" << endl << "press 3 to delete institutiuon and education level information:" << endl << "press 4 to backup all data:" << endl;
		cin >> option;
		while (option != 0)
		{
			if (option == 1)
			{
				setEduBckGrnd(arr1[i]);
				print2(arr1, option);
			}

			if (option == 3)
				remove(*arr1);
			if (option == 2)
			{
				arr1[i].institute_name = nullptr;
				arr1[i].qualification_level = nullptr;

			}
			if (option == 4)
			{
				backup(arr1, arr2, arr1[i].folderCount, size);
			}
		}

	return 0;
}

