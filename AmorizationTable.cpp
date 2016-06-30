#include <iostream>
#include <string>

using namespace std;

class Loan{
  string name;
  double principle;
  double apr;
  int months;
public:
  Loan();
  void test(){
    cout << name << principle << apr << months << endl;
  }
};

Loan::Loan() {
  cout << "Please enter the name of the Loan: ";
  cin >> name;
  cout << "Please enter the principle: ";
  cin >> principle;
  cout << "Please enter the APR (XX.XX%): ";
  cin >> apr;
  cout << "Please enter the number of months: ";
  cin >> months;
}


int main(){

  Loan loan;
  loan.test();
  return 0;

}
  
