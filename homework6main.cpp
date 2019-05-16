/*
Bryan Cagle
CSCE 1040
Homework 7
*/
#include <iostream>
#include <vector>
#include "classes.h"

using namespace std;

int displayMenu(int);
void removePatron(patron*);
void removeMedia(media*);

vector<patron*>patrons;
vector<media*>medias;
vector<rental*>rentals;

int main()
{
	patron *p = new patron[10];
	media *b = new media[10];
	rental *r = new rental[10];

	int select,tempid;
	char mediaselect;
	while(1)
	{
		select=displayMenu(select);
		switch(select)
		{
			case 1: //runs the add patron function for the first available patron
				for (int i=0;i<patrons.size()+1;i++)
				{
					if(p[i].getIDnum()==0)
					{
						p[i].addPatron();
						patrons.push_back(&p[i]); //pushes ithe patron's info into the vector
						break;
					}
				} break;
			case 2: //runs the add book function for the first available book
				for (int i=0;i<medias.size()+1;i++)
				{
					if(b[i].getAQnum()==0)
					{
						cout <<"\n1:Book\n2:DVD\n3:Audio Book\n4:Reference\n" << endl;
        					cout << "Enter the type of media: ";
        					cin >> mediaselect;
        					switch(mediaselect) //Redfines the media class into the child class depending on what the user selects
        					{
                				   case '1': b[i] = book(); b[i].setType(1); break;
       			          	           case '2': b[i] = dvd(); b[i].setType(2); break;
     					           case '3': b[i] = audiobook(); b[i].setType(3); break;
             					   case '4': b[i] = reference(); b[i].setType(4); break;
				        	}
						 b[i].addMedia();
						medias.push_back(&b[i]);
						break;
					}
				} break;
			case 3: removePatron(p); break;
			case 4: removeMedia(b); break;
			case 5: //prints a list of patrons
				cout << "\n-------------------------List of Patrons------------------------------\nID Number" << '\t' << "Last Name, First Name" << '\t' << "Phone Number" << '\t' << "Email Address" << " \n----------------------------------------------------------------------" << endl;
				for(int i=0;i<patrons.size();i++)
				{
					if((p[i].getIDnum()!=0))
					{
						p[i].listPatrons();
					}
				}
				break;
			case 6: //prints a list of books
				cout << "\n-----------------List of Media----------------\nAQ Number" << '\t' << "Author, Title" << '\t' << "Type of Media\n----------------------------------------------" << endl;
                                for(int i=0;i<medias.size();i++)
                                {
					if(b[i].getAQnum()!=0)
					{
                                       	 b[i].listMedia();
					}
                                }
                                break;
			case 7: //lists all patrons that have a fine greater than 0
				 cout << "\n-------------List of Patrons with Fines-------------\nID Number" << '\t' << "Last Name, First Name" << "\t" << "Amount Owed\n----------------------------------------------------" << endl;
                                for(int i=0;i<patrons.size();i++)
                                {
                                       	p[i].listFines();
                                }
                                break;
			case 8: //runs function for the ID number entered
				cout << "Enter the ID number of the Patron: ";
				cin >> tempid;
				for(int i=0;i<patrons.size();i++)
				{
					if((p[i].getIDnum()==tempid)&&(tempid!=0))
					p[i].editInfo();
					else
					cout << "\nThe ID number you have entered is either invalid  not on record" << endl;
				}
				break;
			case 9://runs function for the AQ number entered
				cout << "Enter the AQ number of the Media: ";
                                cin >> tempid;
                                for(int i=0;i<medias.size();i++)
                                {
                                        if(b[i].getAQnum()==tempid)
                                        {
						b[i].editInfo();
						break;
					}
					else
                                        {
						cout << "\nThe AQ number you have entered is not on record" << endl;
						break;
					}
                                }
				cin.ignore();
                                break;
			case 10: //sets rental ID and rental
				for (int i=0;i<rentals.size()+1;i++)
                                {
                                        if(r[i].rentID==0)
                                        {
                                                r[i].checkout(p,b);
						rentals.push_back(&r[i]);
						r[i].rentID=i;
						break;
                                        }
                                } break;
			case 11: //removes rental, media, adds fine to patron
				cout << "Enter the AQ number of the Media that is lost: ";
                                cin >> tempid;
                                for(int i=0;i<medias.size();i++)
                                {
                                        if(b[i].getAQnum()==tempid)
					{
						for (int j=0;i<rentals.size();i++)
                        	        	{
                        		                if(r[j].getBookAN()==b[i].getAQnum())
                	                	        {
                	                        	        r[j].reportLost(p,b[i].getValue());
								//ERASE HERE
								b[i].setAQnum(0);
        	                               		}
		                                }
						break;

					}
					else
					cout << "\nThe AQ number you have entered is not on record" << endl;
                                }
                                break;
			case 12: //reports media as overdue by set number of days, will add fine if media is overdue
				cout << "Enter the AQ number of the Media that is overdue: ";
                                cin >> tempid;
                                for(int i=0;i<medias.size();i++)
                                {
                                        if(b[i].getAQnum()==tempid)
                                        {
                                                for (int j=0;i<rentals.size();i++)
                                                {
                                                        if(r[j].getBookAN()==b[i].getAQnum())
                                                        {
                                                                r[j].reportOverdue();
								break;
                                                        }
							cout << "\nThe AQ number you have entered is not on record" << endl;
                                                }
                                        }
                                }
                                break;
			case 13://runs return media function for the certain media
				cout <<"Enter the AN of the media being returned";
				cin >> tempid;
				for (int i=0;i<rentals.size();i++)
                                {
                                        if((r[i].getBookAN()==tempid)&&(tempid!=0))
                                        {
                                                r[i].returnMedia(p,b);
						break;
                                        }
                                }
				//ERASE RENTAL
                                break;
			case 14: //pays the finesof a patron with fines
				cout << "Enter the ID number of the patron whose fines are being paid: ";
                                cin >> tempid;
                                for(int i=0;i<patrons.size();i++)
                                {
                                        if((p[i].getIDnum()==tempid)&&(p[i].getFine()!=0))
                                        p[i].removeFines();
                                        else
                                        cout << "\nThe ID number you have entered is not on record or the patron has no outstanding fines" << endl;
                                }
                                break;
			case 15: //lists books with an overdue status
				cout << "\n----------- List of Overdue Books -----------\n" << "Book" << "\t\t" << "Patron" << "\t\t" << "Days Overdue" << endl;
				for (int i=0;i<rentals.size();i++)
                                {
                                        if(r[i].rentID==0)
                                        {
                                                r[i].printOverdue(p,b);
                                        }
                                }
				break;
			case 16: //prints label in mailing address format
				cout << "Enter the ID number of the patron to print an address label for: ";
                                cin >> tempid;
                                for(int i=0;i<patrons.size();i++)
                                {
                                        if(p[i].getIDnum()==tempid)
                                        p[i].printLabel();
                                        else
                                        cout << "\nThe ID number you have entered is not on record" << endl;
                                }
                                break;
			default: cout<<"\nThank you for using the Smallsville Library System\n" << endl; return(0);
		}
	}
	delete[] p;
	delete[] b;
	delete[] r;
}

