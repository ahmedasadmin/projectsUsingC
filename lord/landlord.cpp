// landlord.cpp
// models the finances for an apartment building
# include "landlord.h"

//-------------global functions----------------
void getaLine(string& inStr)     // get line of text
{
	char temp[21];
	cin.get(temp, 20, '\n');
	cin.ignore(20, '\n');
	inStr = temp;
}
//---------------------------------------
char getaChar(){
    char ch = cin.get();
    cin.ignore(80, '\n');
    return ch;

}
//-------------methods for class tenant---------
	tenant::tenant(string n, int aNo): name(n), aptNumber(aNo)
     {/* enpty */}
//-----------------------------------
tenant::~tenant()
{/* empty */}
//------------------------------------
int tenant::getAptNumber()
{return aptNumber;}
//------------------------------------
bool operator < (const tenant& t1, const tenant& t2)
{return t1.name<t2.name;}
//------------------------------------
bool operator == (const tenant& t1, const tenant& t2)
{return t1.name == t2.name;}
//------------------------------------
ostream& operator << (ostream& s, const tenant& t)
{s << t.aptNumber << '\t' << t.name << endl; return s;}
//------------------------------------


//---------method for class tenantInputScreen------------
void tenantInputScreen::getTenant()
{
	cout << "Enter tenant's name (e.g George Smith):";
	getaLine(tName);
	cout << "Enter tenant's apartment number (101): ";
	cin  >> aptNo;
	cin.ignore(80, '\n');
	tenant* ptrTenant = new tenant(tName, aptNo);
	ptrTenantList->insertTenant(ptrTenant);           // send to tenant list
}
//-----------------------------------------------
bool compareTenants::operator ()(tenant* ptrT1,
								tenant* ptrT2) const
								{return *ptrT1 < *ptrT2; }
//-----------------------------------------------
//------------methods for class tenantList---------------
tenantList::~tenantList()
{
	while(!setPtrsTens.empty())
	{
		iter = setPtrsTens.begin();
		delete *iter;
		setPtrsTens.erase(iter);
	}
}       // end ~tenantList()

//--------------------------------------------
void tenantList::insertTenant(tenant* ptrT)
{
	setPtrsTens.insert(ptrT);
}
//-----------------------------------
int tenantList::getAptNo(string tName) // name on list?
{
	int aptNo;
	tenant dummy(tName, 0);
	iter = setPtrsTens.begin();
	while(iter != setPtrsTens.end() )
	{
		aptNo = (*iter)->getAptNumber();
		if(dummy == **iter++)
			return aptNo;
	}
	return -1;
}
//------------------------------------
void tenantList::display()
{
	cout << "\nApt#\tTenant name\n----------------------------\n";
	if(setPtrsTens.empty())
		cout << "***No tenants***";
	else
	{
		iter = setPtrsTens.begin();
		while(iter != setPtrsTens.end() )
			cout << **iter++;
	}
}           // end display


//----------------methods for class rentRow ---------------
rentRow::rentRow(int an) : aptNo(an)         // 1-arg constructor
{fill(&rent[0], &rent[12], 0);}
//------------------------------------------------------
void rentRow::setRent(int m, float am)
{rent[m] = am; }
//---------------------------------------------------
float rentRow::getSumOfRow()
{return accumulate(&rent[0], &rent[12], 0);}
//-----------------------------------------------
bool operator < (const rentRow& t1, const rentRow& t2)
{return t1.aptNo < t2.aptNo;}
//------------------------------------------------
bool operator == (const rentRow& t1, const rentRow& t2)
{return t1.aptNo == t2.aptNo;}
//------------------------------------------------
ostream& operator << (ostream& s, const rentRow& an)
{
	s << an.aptNo << '\t';
	for (int j=0; j<12; j++)
	{
		if(an.rent[j] == 0)
			s << " 0 ";
		else
			s << an.rent[j] << "  ";

	}
	s << endl;
	return s;
}
////////////////////////////////////////////////
bool compareRows::operator () (rentRow* ptrR1,
								rentRow* ptrR2) const
								{return *ptrR1 < *ptrR2;}

//-----------------------method of class rentRecord------------------
rentRecord::~rentRecord()
{
	while(!setPtrsRR.empty() )
	{
		iter = setPtrsRR.begin();
		delete *iter;
		setPtrsRR.erase(iter);
	}
}

//-------------------------------------------------------
void rentRecord::insertRent(int aptNo, int month, float amount)
{
	rentRow searchRow(aptNo);
	iter = setPtrsRR.begin();      // search setPtrsRR

	while(iter != setPtrsRR.end())
	{
		if(searchRow==**iter)
		{
			(*iter)->setRent(month,amount);
			return;
		}
		else
			iter++;
	}
	rentRow* ptrRow = new rentRow(aptNo);
	ptrRow->setRent(month, amount);
	setPtrsRR.insert(ptrRow);
}

//----------------------------------------
void rentRecord::display()
{
	cout << "\nAptNo\t Jan	 Feb   Mar   Apr   May   Jun   "
		 <<           "Jul   Aug   Sep   Oct   Nov   Dec\n"
		 << "-------------------------------------------------"
		 << "------------------------------------------------\n";
	if (setPtrsRR.empty() ){
	cout << "***No rents***\n";
	}
	else
	{
		iter = setPtrsRR.begin();
		while(iter != setPtrsRR.end() )
			cout << **iter++;
	}
}
//-----------------------------------
float rentRecord::getSumOfRents()
{
	float sumRents = 0.0;
	iter = setPtrsRR.begin();
	while (iter != setPtrsRR.end() )
	{
		sumRents +=(*iter)->getSumOfRow();
		iter++;
	}
	return sumRents;
}
//----------------------------------------
//-----------------------methods for class rentInputScreen-----------------------
void rentInputScreen::getRent()
{
	cout << "Enter tenant's name; ";
	getaLine(renterName);
	aptNo = ptrTenantList->getAptNo(renterName);
	if (aptNo > 0)
	{
		cout << "Enter amount paid(345.67):";
		cin  >> rentPaid;
		cin.ignore(80, '\n');
		month--;
		ptrRentRecord->insertRent(aptNo, month, rentPaid);
	}
	else
		cout << "No tenant with that name.\n";
}
//-----------------------------------------------
//------------------method for class expense-----------------
bool operator < (const expense& e1, const expense& e2)
{
	if (e1.month == e2.month)
		return e1.day < e2.day;
	else
		return e1.month < e2.month;
}
//--------------------------------------------
bool operator == (const expense& e1, const expense& e2)
{return e1.month == e2.month && e1.day == e2.day;}
//------------------------------------------------
ostream& operator << (ostream& s, const expense& exp)
{
	s << exp.month << '/' << exp.day << '\t' << exp.payee << '\t';
	s << exp.amount << '\t' << exp.category << endl;
	return s;
}
//------------------------------------
bool compareDates:: operator () (expense* ptrE1,
									expense* ptrE2) const
					{return *ptrE1 < *ptrE2; }
//---------------------------------------------------
bool compareCategories::operator () (expense* ptrE1,
									expense*  ptrE2) const
									{return ptrE1->category < ptrE2->category;}
//----------------------methods for class expenseRecord------------
expenseRecord::~expenseRecord()
{
	while (!vectPtrsExpenses.empty() )
	{
		iter = vectPtrsExpenses.begin();
		delete *iter;
		vectPtrsExpenses.erase(iter);
	}
}
//------------------------------------------------
void expenseRecord::insertExp(expense* ptrExp)
{vectPtrsExpenses.push_back(ptrExp);}
//--------------------------------------------------
void expenseRecord::display()
{
	cout << "\nData\tPayee\t\tAmount\tCategory\n"
		 << "--------------------------------------\n";
	if (vectPtrsExpenses.size() == 0)
		cout << "***No expense***\n";
	else{
		sort(vectPtrsExpenses.begin(),
		vectPtrsExpenses.end(), compareDates() );
	iter = vectPtrsExpenses.begin();
	while(	iter != vectPtrsExpenses.end() )
		cout << **iter++;
	}
}
//---------------------------------------------
float expenseRecord::displaySummary()      // used by annualReport
{
	float totalExpenses = 0;
	if (vectPtrsExpenses.size() == 0)
	{
		cout << "\t All categories\t0\n";
		return 0;
	}
	sort(vectPtrsExpenses.begin(),
			vectPtrsExpenses.end(), compareCategories());
	// for each category, sum the entries

	iter = vectPtrsExpenses.begin();
	string tempCat = (*iter)->category;
	float sumCat =  0.0;
	while(iter != vectPtrsExpenses.end() )
	{
		if (tempCat == (*iter)->category)
			sumCat += (*iter)->amount;
		else{
			cout << '\t' << tempCat << '\t' << sumCat << endl;
			totalExpenses += sumCat;
			tempCat = (*iter)->category;
			sumCat = (*iter)->amount;
		}
		iter++;
	}     // end while
	totalExpenses += sumCat;
	cout << '\t' << tempCat << '\t' << sumCat << endl;
	return totalExpenses;
}         // end of display summary
//--------------------------------------

//------------methods for class expenseInputScreen--------------
expenseInputScreen::expenseInputScreen(expenseRecord* per):
								ptrExpenseRecord(per)
								{ }
//------------------------------------------------
void expenseInputScreen::getExpense()
{
	int month, day;
	string category, payee;
	float amount;

	cout << "Enter month (1-12) ";
	cin >> month;
	cin.ignore(80, '\n');
	cout << "Enter day (1-31) ";
	cin >> day;
	cin.ignore(80, '\n');
	cout << "Enter expense category (Rapairing, Utilities):" ;
	getaLine(category);

	cout << "Enter payee"
		 << "(Bob's Hadware, Big Electric Co):";
		getaLine(payee);
		cout << "Enter amount (39.95):";
		cin >> amount;
		cin.ignore(80, '\n');
		expense* ptrExpense = new
			expense(month, day, category, payee, amount);
			ptrExpenseRecord->insertExp(ptrExpense);
}
//----------methods for class annualReport-----------------------------
annualReport::annualReport(rentRecord* pRR,
							expenseRecord* pER):
							ptrRR(pRR), ptrER(pER)
		{/* empty */}
//---------------------------------------------
void annualReport::display(){
	cout << "Annual Summary\n---------------------\n";
	cout << "Income\n";
	cout << "\tRent\t\t";
	rents = ptrRR->getSumOfRents();
	cout << rents << endl;

	cout << "Expenses\n";
	expenses = ptrER->displaySummary();
	cout << "\nBalance\t\t\t" << rents - expenses << endl;
}
//-------------- methods for class userInterface-----------------
userInterface::userInterface()
{
	// these reports exist for the life
	ptrTenantList    = new tenantList;
	ptrRentRecord    = new rentRecord;
	ptrExpenseRecord = new expenseRecord;
}
//----------------------------------------
userInterface::~userInterface()
{
	delete ptrTenantList;
	delete ptrRentRecord;
	delete ptrExpenseRecord;
}
//-----------------------------------------
void userInterface::interact()
{
	while(true)
	{
		cout << "Enter 'i' to input data, \n"
			 << "	   'd' to display a report, \n"
			 << "	   'q' to quit program: ";
		ch = getaChar();
		if (ch== 'i')
		{
			cout << "Enter 't' to add tenant, \n"
				 << "	   'r' to record rent payment, \n"
				 << "	   'e' to record expense: ";
				 ch = getaChar();
				 switch(ch)
				 {
					 // input screens exist only while being used
					 case 't': ptrTenantInputScreen =
						new tenantInputScreen(ptrTenantList);
						ptrTenantInputScreen->getTenant();
						delete ptrTenantInputScreen;
						break;
					case 'r': ptrRentInputScreen= new rentInputScreen(ptrTenantList, ptrRentRecord);
						ptrRentInputScreen->getRent();
						delete ptrRentInputScreen;
						break;
					case 'e': ptrExpenseInputScreen =
							new expenseInputScreen(ptrExpenseRecord);
							ptrExpenseInputScreen->getExpense();
							delete ptrExpenseInputScreen;
							break;
					default:
					cout << "Unknown input option\n";
					break;

				 } // end switch


		}         // end if
		else if (ch == 'd')
		{
			cout << "Enter 't' to display tenants, \n"
				 << "	   'r' to display rents\n"
				 << " 	   'e' to display expenses, \n"
				 << " 	   'a' to display annual report:";
			ch = getaChar();
			switch(ch)
			{
				case 't': ptrTenantList->display();
				break;
				case 'r': ptrRentRecord->display();
				break;
				case 'e': ptrExpenseRecord->display();
				break;
				case 'a':
				ptrAnnualReport = new annualReport(ptrRentRecord,
											ptrExpenseRecord);
				ptrAnnualReport->display();
				delete ptrAnnualReport;
				break;
				default: cout << "Unknown display option \n";
				break;
			} // end switch
		}     // end elseif
		else if (ch=='q')
			return;
		else
			cout << "Unkown option. Enter only 'i' 'd' or 'q' \n";
	}        // end while
}		// end interact
