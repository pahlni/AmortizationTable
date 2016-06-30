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


int main(){

  Loan loan;
  cout << loan.monthPay() << endl;
  return 0;

}
  
