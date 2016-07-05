#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

class Loan{

  const char sep = ' ';
  const int width = 15;
  char name[100];
  double principle;
  double apr;
  int months;
public:
  Loan();
  double monthPay(){
    return ((apr/12) * principle * pow(1 + (apr/12),months)) / (-1 + pow( 1 + (apr/12),months));
  }
  void printTable ();
};

Loan::Loan() {
  cout << "Please enter the name of the Loan: ";
  cin.getline(name, 100);
  cout << "Please enter the principle: ";
  cin >> principle;
  cout << "Please enter the APR (0.XXXX): ";
  cin >> apr;
  cout << "Please enter the number of months: ";
  cin >> months;
}

void Loan::printTable () {
  cout << "*******************************************" << endl;
  cout << "* " << name << " - " << principle << " - " << months << " - " << apr * 100 << "% *" << endl;
  cout << "*******************************************" << endl;
  
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
  double interestThisMonth;
  double principleThisMonth;
  double totalPaid;
  double totalPriPay;
  double totalIntPay;

  cout.setf(ios_base::fixed, ios_base::floatfield);
  cout.precision(2);

  int month;

  for(month = 0; month < months; month++){
    interestThisMonth = remPrinciple * (apr / 12);
    principleThisMonth = monthPayment - interestThisMonth;
    remPrinciple -= principleThisMonth;
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

  Loan loan;
  loan.printTable();
  return 0;

}
  
