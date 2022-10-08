// landlord.h
// header file for landlord.cpp    -- contains class declaration, etc 
  // for set (microsoft only)

# include <iostream>
# include <vector>
# include <set>
# include <string>
# include <algorithm>        // for sort()
# include <numeric>         // for accumulate()
using namespace std;
// global methods

void getaLine(string& inStr);         // get line of text
char getaChar();                      // get a character


//----------------------class tenant------------------------------
class tenant{
	private:
	string name;      // tenant's name
	int aptNumber;
	
	//       other information ...
	public:
	tenant(string n, int aNo);
  
	~tenant();
	int getAptNumber();
	//          needed for use in 'set'
	friend bool operator < (const tenant&, const tenant&);
	friend bool operator ==  (const tenant&, const tenant&);
	
	//      for I/O
	friend ostream& operator << (ostream&, const tenant&);
	
}; //       end of tenant class.


//-------------------------compareTenant-----------------------
class compareTenants           // function object -- compare tenants
{
	public:
	bool operator () (tenant*, tenant*) const;
}; //         end of compare_tenant  class

//-----------------------tenantList----------------------------
class tenantList{
	private:
	//       set of pointer to tenants
	set<tenant*, compareTenants> setPtrsTens;
	set<tenant*, compareTenants>::iterator iter;
	
	public:
	~tenantList();          // destructor (deletes tenants)
	void insertTenant(tenant*);
	int getAptNo(string);
	void display();              // display tenant list 
	
};     //         end tenant list
 
//-------------------------classtenantinput---------------------
class tenantInputScreen{
	private:
	tenantList*   ptrTenantList;
	string tName;
	int aptNo;
	
	public:
	tenantInputScreen(tenantList* ptrTL) : ptrTenantList(ptrTL)
	{   /* empty */ }
	void getTenant();
};      // end class tenantInputScreen 

//-------------------class rentrow---------------------------
class rentRow{
	private:
	int aptNo;
	float rent[12];
	
	public:
	rentRow(int);
	void setRent(int, float);           // record rent for one month 
	float getSumOfRow();
	//      need to store     in   'set'
	
	friend bool operator < (const rentRow&, const rentRow&);
	friend bool operator == (const rentRow&, const rentRow&);
	
	//     for output 
	
	friend ostream& operator << (ostream&, const rentRow&);
	
};        //              end class rentRow

//--------------compare rows------------------------------ 
class compareRows{
	public:
	bool operator ()(rentRow*, rentRow*) const;
}; //              end of comparerows 

//--------------rentRecord---------------------------------
class rentRecord{
	private:
	// set of pointer to rentRow oblects (one per tenant)
	set<rentRow*, compareRows> setPtrsRR;
	set<rentRow*, compareRows>::iterator iter;
	
	public:
	~rentRecord();
	void insertRent(int, int, float);
	void display();
	float getSumOfRents();         // sum all rents in record 
};       //       end class rentRecord

//-----------------------class rentInputScreen---------------------
class rentInputScreen{
	private:
	tenantList* ptrTenantList;
	rentRecord* ptrRentRecord;
	
	
	string renterName;
	float rentPaid;
	int month;
	int aptNo;
	
	public:
	rentInputScreen(tenantList* ptrTL, rentRecord* ptrRR):
	ptrTenantList(ptrTL), ptrRentRecord(ptrRR)
	{/* empty */}
	void getRent();             
};         // end class rentInputScreen


//----------------------------class expense-------------------
class expense{
	public:
	int month, day;
	string category, payee;
	float amount;
	expense (){
		
	}
	expense(int m, int d, string c, string p, float a):
		month(m), day(d), category(c), payee(p), amount(a)
		{/* empty */}
		
		// needed for  use in 'set'
		friend bool operator < (const expense&, const expense&);
		friend bool operator == (const expense&, const expense&);
		
		// needed for output
		friend ostream& operator << (ostream&, const expense&);
		
};    //       end class expense
class compareDates   // function object--compares expense
{
	public:
	bool operator () (expense*, expense*) const;
};
//-----------------------class compareCategories-----------------
class compareCategories{
	public:
	bool operator () (expense*, expense*) const;
};//        end class compareCategories 

//------------------------class expenseRecord--------------------
class expenseRecord{
	private:
	// vector of pointers to expenses
	vector<expense*> vectPtrsExpenses;
	vector<expense*>::iterator iter;
	
	public:
	~expenseRecord();
	void insertExp(expense*);
	void display();
	float displaySummary();
};     //             end class expenseRecord 

//--------------------------class expenseInputScreen-------------
class expenseInputScreen{
	private:
	expenseRecord* ptrExpenseRecord;
	
	public:
	expenseInputScreen(expenseRecord*);
	void getExpense();
};       //      end class expensInputScreen
//---------------------class annualReport-----------------------
class annualReport{
	private:
	rentRecord* ptrRR;
	expenseRecord* ptrER;
	float expenses, rents;
	
	public:
	annualReport(rentRecord*, expenseRecord*);
	void display();
}; //       end of class annualReport

//--------------------------class userInterface--------------------
class userInterface{
	private:
	tenantList*			ptrTenantList;
	tenantInputScreen*	ptrTenantInputScreen;
	rentRecord*			ptrRentRecord;
	rentInputScreen*    ptrRentInputScreen;
	expenseRecord*		ptrExpenseRecord;
	expenseInputScreen* ptrExpenseInputScreen;
	annualReport*		ptrAnnualReport;
	char ch;
	
	public:
	userInterface();
	~userInterface();
	void interact();
}; //          end class userInterface

