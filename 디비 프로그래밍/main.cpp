//==============================================
// Name:           Jaewook Ahn  
// Student Number: 102354198
// Email:          jahn33@myseneca.ca
// Section:        NCC
// Date:           August 9, 2020
//==============================================
// Milestone :	   2
//==============================================
#include <iostream>
#include <occi.h>
#include <string>
#include <iomanip>

using oracle::occi::Environment;
using oracle::occi::Connection;

using namespace oracle::occi;
using namespace std;
// OCCI Variables
Environment* env = nullptr;
Connection* conn = nullptr;
// User info
string str;
string usr = "dbs211_202c01";
string pass = "13042159";
string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";
// struct Employee
struct Employee {

	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char email[100];
	char phone[50];
	char extension[10];
	char reportsTo[100];
	char jobTitle[50];
	char city[50];

};
//Declare new array for using struct Employee
Employee emp = {};
//Intitalize functions
int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp);
void displayEmployee(Connection* conn, struct Employee emp);
void displayAllEmployees(Connection* conn);
void insertEmployee(Connection *conn, struct Employee emp);
void updateEmployee(Connection *conn, int employeeNumber);
void deleteEmployee(Connection *conn, int employeeNumber);
//clear empties the input buffer
void clear(void) {
	while (getchar() != '\n')
		;
}

int menu(void) {
	//Declare variables
	int selection = 0;
	char after;
	int check = 0;
	int endprocess = 0;
	//Repeat until customer leave the menu.
	while (endprocess == 0) {
		//Menu display
		cout << "********************* HR Menu *********************" << endl;
		cout << "1)	Find Employee" << endl;
		cout << "2)	Employees Report" << endl;
		cout << "3)	Add Employee" << endl;
		cout << "4)	Update Employee" << endl;
		cout << "5)	Remove Employee" << endl;
		cout << "6)	Exit" << endl;
		//Receive input from customers
		cout << "Please select the menu: ";
		int rc = scanf("%d%c", &selection, &after);
		cout << endl;
		//Loop until get appropriate value
		while (check == 0) {
			if ((selection > 6 || selection < 1 || after != '\n' || rc == 0)) {
				cout << "Wrong value. Please type number between 1 to 6." << endl << endl;
				if (after != '\n' || rc == 0)
					clear();
				cout << "Please select the menu: ";
				rc = scanf("%d%c", &selection, &after);
				cout << endl;
			}
			else
				check = 1;
		}
		//Select menu
		int toUpdate = 0;
		int toDelete = 0;
		switch (selection) {
		case 1:
			displayEmployee(conn, emp);
			break;
		case 2:
			displayAllEmployees(conn);
			break;
		case 3:
			cout << "Employee Number: ";
			cin >> emp.employeeNumber;
			cout << "Last Name: ";
			cin >> emp.lastName;
			cout << "First Name: ";
			cin >> emp.firstName;
			cout << "Email: ";
			cin >> emp.email;
			cout << "extension: ";
			cin >> emp.extension;
			cout << "Job Title: ";
			cin >> emp.jobTitle;
			cin.ignore(100, '\n');
			insertEmployee(conn, emp);
			break;
		case 4:
			cout << "Employee Number: ";
			cin >> toUpdate;
			updateEmployee(conn, toUpdate);
			break;
		case 5:
			cout << "Employee Number: ";
			cin >> toDelete;
			deleteEmployee(conn, toDelete);
			break;
		case 6:
			//Leave the menu.
			endprocess = 1;
			break;

		}
	}
	return 0;
}

int findEmployee(Connection* conn, int employeeNumber, struct Employee* emp) {
	//Statement and resultset
	Statement* stmt = nullptr;
	ResultSet* rs = nullptr;
	string Query = "SELECT e.employeenumber, e.lastname, e.firstname, e.email, o.phone, e.extension, e.reportsto, e.jobtitle, o.city FROM employees e INNER JOIN offices o USING(officecode) WHERE employeenumber =";
	//Add employeeNumber to Query
	Query += to_string(employeeNumber);
	//Create Statement and execute Query
	stmt = conn->createStatement(Query);
	rs = stmt->executeQuery();
	// if there is no output, end this function with false.
	if (!rs->next()) {
		return 0;
	}
	// Copy outputs into new struct Employee. Using c_str for converting string to char.
	else {
		emp->employeeNumber = rs->getInt(1);
		strcpy(emp->lastName, rs->getString(2).c_str());
		strcpy(emp->firstName, rs->getString(3).c_str());
		strcpy(emp->email, rs->getString(4).c_str());
		strcpy(emp->phone, rs->getString(5).c_str());
		strcpy(emp->extension, rs->getString(6).c_str());
		strcpy(emp->reportsTo, rs->getString(7).c_str());
		strcpy(emp->jobTitle, rs->getString(8).c_str());
		strcpy(emp->city, rs->getString(9).c_str());
		//terminateStatement
		conn->terminateStatement(stmt);
		return 1;
	}
}

void displayEmployee(Connection* conn, struct Employee emp) {
	int check = 0;
	int employeeNumber;
	char after;
	//Get EmployNumber from customer
	cout << "Enter EmployNumber: ";
	int rc = scanf("%d%c", &employeeNumber, &after);
	//Loop until get appropriate value
	while (check == 0) {
		if (after != '\n' || rc == 0) {
			cout << "Wrong value." << endl;
				clear();
			cout << "Enter EmployNumber: ";
			rc = scanf("%d%c", &employeeNumber, &after);
		}
		else
			check = 1;
	}
	//If the program could find Employee, display data.
	if (findEmployee(conn, employeeNumber, &emp)) {
		cout << endl << "-------------- Employee Information -------------" << endl;
		cout << "employeeNumber = " << emp.employeeNumber << endl;
		cout << "lastName =  " << emp.lastName << endl;
		cout << "firstName = " << emp.firstName << endl;
		cout << "email = " << emp.email << endl;
		cout << "phone = " << emp.phone << endl;
		cout << "extension = " << emp.extension << endl;
		cout << "reportsTo = " << emp.reportsTo << endl;
		cout << "jobTitle = " << emp.jobTitle << endl;
		cout << "city = " << emp.city << endl << endl;
	}
	//If the program couldn't find Employee, display message.
	else {
		cout << "Employee " << employeeNumber << " does not exit.\n";
	}
}

void displayAllEmployees(Connection* conn) {
	//Statement2 and resultset2
	Statement* stmt2 = conn->createStatement();
	ResultSet* rs2 = stmt2->executeQuery("SELECT e.employeenumber, e.firstname || ' ' || e.lastname AS name, e.email, o.phone, e.extension, m.firstname || ' ' || m.lastname AS mname FROM employees e LEFT OUTER JOIN employees m on e.reportsto = m.employeenumber JOIN offices o ON e.officecode = o.officecode ORDER BY e.officecode");

	
	cout << "E	 Employee Name 	     Email 			        Phone 		  Ext	      Manager" << endl;
	cout << "----------------------------------------------------------------------------------------------------------" << endl;
	// if there is no output, display message.
	if (!rs2->next()) {
		cout << "There is no employees' information to be displayed" << endl;
	}
	//if there is output, show the data and then loop until there is no data.
	else {
		cout << left << setw(9) << rs2->getInt(1) << setw(20) << rs2->getString(2) << setw(35) << rs2->getString(3) << setw(18) << rs2->getString(4) << setw(12) << rs2->getString(5) << endl;
		while (rs2->next()) {
			cout << left << setw(9) << rs2->getInt(1) << setw(20) << rs2->getString(2) << setw(35) << rs2->getString(3) << setw(18) << rs2->getString(4) << setw(12) << rs2->getString(5) << setw(20) << rs2->getString(6) << endl;
		}
	}
	//terminateStatement
	conn->terminateStatement(stmt2);
}

void insertEmployee(Connection *conn, struct Employee emp) {
	//if Employee exists, end the process
	if (findEmployee(conn, emp.employeeNumber, &emp)) {
		cout << "An employee with the same employee number exists." << endl;
	}
	//if Employee doesn't exist, execute the query.
	else {
		//Statement3 and resultset3
		Statement* stmt3 = conn->createStatement();
		ResultSet* rs3 = stmt3->executeQuery("INSERT ALL INTO EMPLOYEES(employeeNumber, lastname, firstname, email, extension, officecode, reportsto, jobTitle) VALUES('" + to_string(emp.employeeNumber) + "', '" + emp.lastName + "', '" + emp.firstName + "', '" + emp.email + "', '" + emp.extension + "', '1', '1002', '" + emp.jobTitle + "') SELECT* FROM dual");
		//terminateStatement
		conn->terminateStatement(stmt3);
		cout << "The new employee is added successfully." << endl;
	}
}

void updateEmployee(Connection* conn, int employeeNumber) {
	//Declare new extension variable.
	string new_extension;
	//if Employee doesn't exist, end the process.
	if (!(findEmployee(conn, employeeNumber, &emp))) {
		cout << "An employee doesn't exist. You might have typed wrong number." << endl;
	}
	//if Employee exists, get the new extension from user and execute the query.
	else {
		cout << "Enter the new extension: ";
		cin >> new_extension;
		//Statement4 and resultset4
		Statement* stmt4 = conn->createStatement();
		ResultSet* rs4 = stmt4->executeQuery("UPDATE EMPLOYEES SET extension = '" + new_extension + "'" + " WHERE employeeNumber = '"+ to_string(employeeNumber) +"'");
		//terminateStatement
		conn->terminateStatement(stmt4);
		cout << "The new extension is updated successfully." << endl;
	}
}


void deleteEmployee(Connection* conn, int employeeNumber) {
	//if Employee doesn't exist, end the process.
	if (!(findEmployee(conn, employeeNumber, &emp))) {
		cout << "An employee doesn't exist. You might have typed wrong number." << endl;
	}
	//if Employee exists, execute the query.
	else {
		//Statement5 and resultset5
		Statement* stmt5 = conn->createStatement();
		ResultSet* rs5 = stmt5->executeQuery("DELETE FROM EMPLOYEES WHERE employeenumber = '" + to_string(employeeNumber) + "'");
		//terminateStatement
		conn->terminateStatement(stmt5);
		cout << "The employee is deleted." << endl;
	}
}

int main(void) {
	//Create environment and connection
	try {
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		//call menu
		menu();
		//Terminate connection and environment
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	//If there is and error, display the message including the error_code. 
	catch (SQLException & sqlExcp) {
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}