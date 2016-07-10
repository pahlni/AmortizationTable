/**
 * File for creating an Amortization Table from user input.
 *
 * @file AmorizationTable.c
 * @author Nicholas Pahl
 * @date July 11, 2016
 */

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

/**
 * Class containing loan functions.
 */ 
class Loan{

  const char sep = ' ';
  const int width = 15;
  char name[100];
  double principle;
  double apr;
  int months;
  double extra;
public:
  //constructor for loan.
  Loan();
  //calculates monthly pay.
  double monthPay(){
    return ((apr/12) * principle * pow(1 + (apr/12),months)) / (-1 + pow( 1 + (apr/12),months));
  }
  //displays table
  void printTable ();
};

//gets info from user 
Loan::Loan() {
  cout << "Please enter the name of the Loan: ";
  cin.getline(name, 100);
  cout << "Please enter the principle: ";
  cin >> principle;
  cout << "Please enter the APR (0.XXXX): ";
  cin >> apr;
  cout << "Please enter the number of months: ";
  cin >> months;
  cout << "Please enter the amount extra willing to pay each month: ";
  cin >> extra;
}

void Loan::printTable () {
  //prints floats with 2 decimal points
  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout.precision(2);

  //table info print
  cout << "*******************************************" << endl;
  cout << "* " << name << " - " << principle << " - " << months << " - " << apr * 100 << "% - " << extra << " extra *" << endl;
  cout << "*******************************************" << endl;
  
  //table header print
  cout << left << setw(width) << setfill(sep) << "month";
  cout << left << setw(width) << setfill(sep) << "monthly pay";
  cout << left << setw(width) << setfill(sep) << "pri remain";
  cout << left << setw(width) << setfill(sep) << "pri paid";
  cout << left << setw(width) << setfill(sep) << "int paid";
  cout << left << setw(width) << setfill(sep) << "total paid";
  cout << left << setw(width) << setfill(sep) << "total pri paid";
  cout << left << setw(width) << setfill(sep) << "total int paid" << endl;

  double monthPayment = monthPay();
  double remPrinciple = principle;
  double interestThisMonth = 0;
  double principleThisMonth = 0;
  double totalPaid = 0;
  double totalPriPay = 0;
  double totalIntPay = 0;
 

  int month;

  //print all the rows
  for(month = 0; month < months && remPrinciple != 0; month++){
    interestThisMonth = remPrinciple * (apr / 12);
    principleThisMonth = monthPayment - interestThisMonth + extra;

    //catches the last amount to be paid
    if(principleThisMonth > remPrinciple){
      principleThisMonth = remPrinciple;
      remPrinciple = 0;
      monthPayment = principleThisMonth + interestThisMonth;
    }
    else{
      remPrinciple -= principleThisMonth;
    }
    totalPaid += interestThisMonth + principleThisMonth;
    totalPriPay += principleThisMonth;
    totalIntPay += interestThisMonth;
    
    cout << left << setw(width) << setfill(sep) << month;
    cout << left << setw(width) << setfill(sep) << monthPayment;
    cout << left << setw(width) << setfill(sep) << remPrinciple;
    cout << left << setw(width) << setfill(sep) << principleThisMonth;
    cout << left << setw(width) << setfill(sep) << interestThisMonth;
    cout << left << setw(width) << setfill(sep) << totalPaid;
    cout << left << setw(width) << setfill(sep) << totalPriPay;
    cout << left << setw(width) << setfill(sep) << totalIntPay << endl;
  }
}

int main(){
  //gathers loan info
  Loan loan;
  //prints table
  loan.printTable();
  return 0;

}
  
