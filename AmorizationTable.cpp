#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Loan{
  string name;
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
  cin >> name;
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
  cout << "month\tmonthly payment\tprinciple remaining\tprinciple paid\tinterest paid\ttotal paid\ttotal principle paid\ttotal interest paid" << endl;

  double monthPayment = monthPay();
  double remPrinciple = principle;
  double interestThisMonth;
  double principleThisMonth;
  double totalPaid;
  double totalPriPay;
  double totalIntPay;

  int month;

  for(month = 0; month < months; month++){
    interestThisMonth = remPrinciple * (apr / 12);
    principleThisMonth = monthPayment - interestThisMonth;
    remPrinciple -= principleThisMonth;
    totalPaid += interestThisMonth + principleThisMonth;
    totalPriPay += principleThisMonth;
    totalIntPay += interestThisMonth;
    
    cout << month << "\t" << monthPayment << "\t\t" << remPrinciple << "\t\t\t" << principleThisMonth << "\t\t" << interestThisMonth << "\t\t" << totalPaid << "\t\t" << totalPriPay << "\t\t\t" << totalIntPay << endl;
  }
}

int main(){

  Loan loan;
  loan.printTable();
  return 0;

}
  
