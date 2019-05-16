#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "classes.h"
#include <vector>

using namespace std;

extern vector<patron*>patrons;
extern vector<media*>medias;
extern vector<rental*>rentals;

//The initial menut aht is looped
int displayMenu(int select)
{
	cout << "\n---Welcome to the Smallsville Library System---" << endl;
	cout << "\n1: Add Patron" << endl;
	cout << "2: Add Media" << endl;
	cout << "3: Remove Patron" << endl;
	cout << "4: Remove Book" << endl;
	cout << "5: List All Patrons" << endl;
	cout << "6: List All Media" << endl;
	cout << "7: List All Patrons With Fines" << endl;
	cout << "8: Edit Patron Info" << endl;
	cout << "9: Edit Media Info" << endl;
	cout << "10: Checkout Media" << endl;
	cout << "11: Report Media as Lost" << endl;
	cout << "12: Report Media as Overdue" << endl;
	cout << "13: Return Media" << endl;
	cout << "14: Remove Fines" << endl;
	cout << "15: Print All Overdue Media" << endl;
	cout << "16: Print Address Label" << endl;
	cout << "Anything Else: Exit System\n" << endl;
	cout << "Please enter the number of one of the above actions: ";
	cin >> select;
	return select;
}

media::media()
{
}

patron::patron()
{
}

rental::rental()
{
}

int patron::getIDnum()
{
	return IDnum;
}

int media::getAQnum()
{
	return AQnum;
}
void patron::addPatron()
{
	//Will loop this part as long as a valid ID is entered
	do{
	cout << "Enter an ID number for the patron (1-999999): ";
	cin >> IDnum;} while ((IDnum<=0)||(IDnum>=999999));
	cout << "Enter the first name of the patron: ";
	cin >> namefirst;
	cout << "Enter the last name of the patron: ";
	cin >> namelast;
	cout << "Enter the phone number of the patron: ";
	cin >> phone;
	cout << "Enter the email address of the patron: ";
	cin >> email;
	cout << endl;
	cin.ignore();
	cout << "Address: Enter the street: ";
	cin.getline(street,50);
	cout << "Address: Enter the city: ";
	cin >> city;
	cout << "Address: Enter the state: ";
	cin >> state;
	cout << "Address: Enter the Zip Code: ";
	cin >> zip;
}

void media::addMedia()
{
	//Loops the first question as long as a valid ID is entered
	do{
	cout << "Enter the Acquisition number of the media (1-999999): ";
	cin >> AQnum;} while ((AQnum<=0)||(AQnum>=999999));
	cin.ignore();
	cout << "Enter the title of the media: ";
	cin.getline(title,30);
	cout << "Enter the author or director of the media: ";
	cin.getline(author,20);
	cout << "Enter the value of the media: ";
	cin >> value;
}

void patron::setIDnum(int set)
{
	IDnum=set;
}
void removePatron(patron p[])
{

	int tempID;
	cout <<"\nEnter the ID number for the patron to delete: ";
	cin >> tempID;
	for(int i=0;patrons.size();i++)
	{
		if((tempID==p[i].getIDnum())&&(p[i].getFine()==0)&&(p[i].getChecking()==false))
		{
			//sets ID to 0, effectively deleting it. Adding a new patron will imediately replace the rest of the information
			patrons[i]->setIDnum(0);
			cout << "\nPatron deleted!" << endl;
			return;
		}
		else
		{
			cout << "\nPatron does not exist, is currently checking out something, or has outstanding fines and cannot be removed"  << endl;
		}
	}
}

void media::setAQnum(int set)
{
	AQnum=set;
}

void removeMedia(media b[])
{
        int tempID;
        cout <<"\nEnter the AQ number for the media to delete: ";
        cin >> tempID;
        for(int i=0;medias.size();i++)
        {
                if((tempID==b[i].getAQnum())&&(b[i].checkout==false))
                {
			//sets ID to 0, adding a new book will replace the rest of the information
                        medias[i]->setAQnum(0);
			cout <<"\nMedia deleted!" << endl;
                        return;
                }
		cout << "\nIncorrect media AQ number or this media is currently checked out and cannot be deleted" << endl;
        }
}

void patron::listPatrons()
{
	//lists the respective patron's ID, name, phone, and email
	if(IDnum!=0)
	cout << setfill('0') << setw(6) << IDnum << "\t\t" << namelast << ", " << namefirst << "\t" << phone << "\t" << email << endl;
}

void media::setType(int set)
{
	if(set==1)
	{
		strcpy(type,"Book");
		loanP=21;
		overdueFee=0.29;
	}
	if(set==2)
	{
		strcpy(type,"DVD");
		loanP=7;
		overdueFee=0.59;
	}
	if(set==3)
	{
		strcpy(type,"Audiobook");
		loanP=14;
		overdueFee=0.49;
	}
	if(set==4)
	{
		strcpy(type,"Reference");
		loanP=21;
		overdueFee=0.49;
	}
}



void media::listMedia()
{
	//lists the respective book's AQ, author, and title
	if(AQnum!=0)
	cout << setfill('0') << setw(6) << AQnum << "\t\t" << author << ", " << title << "\t\t" << type << endl;
}

void patron::listFines()
{
	if(IDnum!=0)
        {
		if(fines!=0)
		cout << setfill('0') << setw(6) << IDnum << "\t\t" << namelast << ", " << namefirst << "\t\t" << fines << endl;

	}
}

void patron::editInfo()
{
	//Prints menu for what the user would like to edit
	char selection;
	do{
	cout << "\n1: ID Number" << endl;
	cout << "2: Name" << endl;
	cout << "3: Phone Number" << endl;
	cout << "4: Email Address" << endl;
	cout << "5: Address" << endl;
	cout << "Anything else: Return to Main Menu" << endl;
	cout << "\nEnter the number for what you would like to change: ";
	cin >> selection;
	switch (selection)
	{
		case '1':
			cout << "Enter the new ID number: ";
			cin >> IDnum;
			break;
		case '2':
			cout << "Enter the first name: ";
			cin >> namefirst;
			cout << "Enter the last name: ";
			cin >> namelast;
			break;
		case '3':
			cout << "Enter the new phone number: ";
			cin >> phone;
			break;
		case '4':
			cout << "Enter the new Email Addres: ";
			cin >> email;
			break;
		case '5':
			cin.ignore();
			cout << "Enter the street: ";
			cin.getline(street,50);
			cout << "Enter the city: ";
			cin >> city;
			cout << "Enter the state: ";
			cin >> state;
			cout << "Enter the zip code: ";
			cin >> zip;
			break;
		default: cout << "\nInvalid option" << endl; selection = '6'; break;
	}
	}while(selection=='6');
}

void media::editInfo()
{
	//Prints the menu for what the user would like so edit
	char selection;
	do{
	cout << "\n1: AQ Number" << endl;
        cout << "2: Title" << endl;
        cout << "3: Author or Director" << endl;
        cout << "4: Value" << endl;
	cout << "5: Return to Main Menu" << endl;
	cout << "\nEnter the number for what you would like to change: ";
	cin >> selection;
        switch (selection)
        {
                case '1':
                        cout << "Enter the new AQ number: ";
                        cin >> AQnum;
                        break;
                case '2':
			cin.ignore();
                        cout << "Enter the title of the media: ";
                        cin.getline(title,30);
                        break;
                case '3':
			cin.ignore();
                        cout << "Enter the name of the author or director: ";
                        cin.getline(author,20);
                        break;
                case '4':
			cin.ignore();
			cout << "Enter the new value: ";
			cin >> value;
			break;
		case '5': break;
		default: cout << "\nInvalid option" << endl; selection = '6'; break;
        }
	}while (selection=='6');

}

int patron::getFine()
{
	return fines;
}

void patron::setChecking(int set)
{
	if(set==0)
	{
		checkingOut=true;
	}
	else
	checkingOut=false;
}

int media::getLoanp()
{
	return loanP;
}

void rental::checkout(patron p[],media b[])
{
	//sets checking to true
	cout << "Enter the ID number of the patron to check the media out to: ";
        cin >> patronID;
        for(int i=0;patrons.size();i++)
        {
                if((patronID==p[i].getIDnum())&&(patronID!=0))
                {
                        if(p[i].getFine()==0)
                        {
                                p[i].setChecking(0);
                                break;
                        }
                }
                patronID=-1;
        }
        if(patronID==-1)
        {
                cout << "\nIncorrect Patron ID number entered or Patron's account is on hold from outstanding fines" << endl;
                return;
        }

	//sets the book to checkout status
	cout << "Enter the AQ number of the media to check out: ";
	cin >> bookAN;
	for(int i=0;medias.size();i++)
	{
		if((bookAN==b[i].getAQnum())&&(bookAN!=0))
		{
			if(b[i].checkout!=true)
			{
				b[i].checkout=true;
				rentalPer=b[i].getLoanp();
				break;
			}
			bookAN=-1;
		}
	}
	if(bookAN==-1)
	{
		cout << "\nIncorrect Media AN number entered or medi is currently checked out" << endl;
		for(int i=0;patrons.size();i++)
       		{
                	if((patronID==p[i].getIDnum()))
                	{
                        	p[i].setChecking(1);
                	}
        	}
		return;
	}
}

bool patron::getChecking()
{
	return checkingOut;
}

void patron::getLName()
{
	cout << namelast;
}
void media::getTitle()
{
	cout << title;
}

void rental::printOverdue(patron p[], media b[])
{
	//checks if the book is overdue, then matches up the patron name and book title and prints them out
	if(overdue==true)
	{
		for(int i=0;patrons.size();i++)
		{
			if(p[i].getIDnum()==patronID)
			{
				for(int j=0;j<medias.size();i++)
				{
					if(b[j].getAQnum()==bookAN)
					{
						b[j].getTitle();
						cout << "\t\t";
						p[i].getLName();
						cout << "\t\t" << daysOver << endl;
						return;
					}
				}
			}
		}
	}
}

void patron::printLabel()
{
	//prints a patron's name and address in the format of a mailing label
	cout << '\n' << namefirst << " " << namelast << endl;
	cout << street << endl;
	cout << city << ", " << state << " " << zip << '\n' << endl;
}

void patron::removeFines()
{
	//removes part of or all of the fine, does not go into negative
	float paid;
	cout << namelast << ", " << namefirst << endl;
	cout << "Fine: " << fines << '\n' << endl;
	cout << "Enter the amount being paid: ";
	cin >> paid;
	if((fines-paid)>0)
	{
		fines -= paid;
		cout << "Fines remaining: " << fines << endl;
	}
	else
	{
		fines=0.00;
		cout << "All fines paid, account no longer on hold" << endl;
	}
}

void patron::addFines(float fine)
{
	fines += fine;
}

int rental::getBookAN()
{
	return bookAN;
}
float media::getValue()
{
	return value;
}

void rental::reportLost(patron p[], float value)
{
	//adds a fine equal to the value of the media
	for(int i=0;patrons.size();i++)
	{
		if(p[i].getIDnum()==patronID)
		{
			p[i].addFines(value);
			p[i].setChecking(1);
			overdue=false;
		}
	}
	cout << "\nFine has been added to Patron's account" << endl;
}

void rental::reportOverdue()
{
	//Asks how long a media is checken out, then will check to see if it's overdue
	int dayschecked;
	cout << "\nThe fines for overdue media go as follows:\n\nBook: $0.29 per day after 21 days\nDVD: $0.59 per day after 7 days\nAudiobook: $0.49 per day after 14 days\nReference: $0.39 per day after 21 days\n\nEnter the number of days the book as been checked out: ";
	cin >> dayschecked;
	if(rentalPer-dayschecked>=0)
	cout << "This media is not overdue for another " << rentalPer-dayschecked << " day(s)" << endl;
	else
	{
		daysOver=dayschecked-rentalPer;
		cout << "This media is currently " << daysOver << " days overdue" << endl;
		overdue=true;
	}
}

float media::getOverdue()
{
	return overdueFee;
}

void rental::returnMedia(patron p[], media b[])
{
	//checks to see if book is in fact checked out, then adds overdue fines if needed
	for(int i=0;i<medias.size();i++)
	{
		if(b[i].getAQnum()==bookAN)
		{
			if(b[i].checkout!=true)
       			{
            			cout << "This media is currently not checked out";
            			break;
        		}
			else
			{
				b[i].checkout=false;
				if(overdue==true)
				{
					cout << "Overdue fine being added to patron's account: $" << daysOver*b[i].getOverdue() << endl;
					for(int j=0;i<patrons.size();i++)
      					{
                				if(p[j].getIDnum()==patronID)
                				{
                        				p[j].addFines(b[i].getOverdue()*daysOver);
                       					p[j].setChecking(1);
                     					overdue=false;
               		 			}
		        		}
				}
				rentID=0;
        		}
		}
	}

}



