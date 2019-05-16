class patron
{
	private:
		int IDnum;
		char namefirst[20];
		char namelast[20];
		char phone[20];
		char email[20];
		char street[50];
		char city[20];
		char state[20];
		char zip[10];
		float fines;
		bool checkingOut;
	public:
		patron();
		int getIDnum();
		void setIDnum(int);
		void getLName();
		void addPatron();
		void listPatrons();
		void listFines();
		void editInfo();
		void printLabel();
		void removeFines();
		void addFines(float);
		int getFine();
		bool getChecking();
		void setChecking(int);
};

class media
{
	private:
		char title[30];
		char author[20];
		int AQnum;
		float overdueFee;
		char type[12];
		float value;
		int loanP;
	public:
		media();
		void setAQnum(int);
		int getAQnum();
		int getLoanp();
		float setValue(float);
		float getValue();
		float getOverdue();
		bool checkout;
		void setType(int);
		void getTitle();
		void addMedia();
		void listMedia();
		void editInfo();
};

class book:public media
{
	private:
		int loanP;
		float overdueFee;
	public:
		book():media()
		{
			loanP=21;
			overdueFee=0.29;
		}
		
};

class dvd:public media
{
	private:
		int loanP;
		float overdueFee;
	public:
		dvd():media()
		{
			loanP=7;
			overdueFee=0.59;
		}
		
};

class audiobook:public media
{
	private:
		int loanP;
		float overdueFee;
	public:
		audiobook():media()
		{
			loanP=14;
			overdueFee=0.49;
		}
		
};

class reference:public media
{
	private:
		int loanP;
		float overdueFee;
	public:
		reference():media()
		{
			loanP=21;
			overdueFee=0.39;
		}
		
};

class rental
{
	private:
		int patronID;
		int bookAN;
		int rentalPer;
		int daysOver;
		float fine;
		bool overdue;
	public:
		int rentID;
		rental();
		void checkout(patron*, media*);
		void printOverdue(patron*, media*);
		void reportLost(patron *, float);
		int getBookAN();
		void reportOverdue();
		void returnMedia(patron *, media*);

};
