#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct idRecord {
  int Id;
  int Gross_Monthly_Income, Credit_Card_Payment, Car_Payment,
    Student_Loan_Payments, Appraised_Value, Credit_Score;
  double Down_Payment, Loan_Amount, Monthly_Mortgage_Payment;

  // Constructor
  idRecord(int iD,
           int grossMonthlyIncome,
           int creditCardPayment,
           int CarPayment,
           int studentLoanPayments,
           int appraisedValue,
           int CreditScore,
           double downPayment,
           double loanAmount,
           double monthlyMortgagePayment)
    : Id(iD)
    , Gross_Monthly_Income(grossMonthlyIncome)
    , Credit_Card_Payment(creditCardPayment)
    , Car_Payment(CarPayment)
    , Student_Loan_Payments(studentLoanPayments)
    , Appraised_Value(appraisedValue)
    , Credit_Score(CreditScore)
    , Down_Payment(downPayment)
    , Loan_Amount(loanAmount)
    , Monthly_Mortgage_Payment(monthlyMortgagePayment)
  {
  }

  void display()
  {
    cout << "                     ID: " << Id << endl;
    cout << "   Gross Monthly Income: " << Gross_Monthly_Income << endl;
    cout << "    Credit Card Payment: " << Credit_Card_Payment << endl;
    cout << "           Car Payments: " << Car_Payment << endl;
    cout << "  Student Loan Payments: " << Student_Loan_Payments << endl;
    cout << "        Appraised Value: " << Appraised_Value << endl;
    cout << "           Down Payment: " << Down_Payment << endl;
    cout << "            Loan Amount: " << Loan_Amount << endl;
    cout << "Monthly Mortgage Payment: " << Monthly_Mortgage_Payment << endl;
    cout << "           Credit Score: " << Credit_Score << endl;
  }
};

int main()
{
  ifstream inputFile;
  inputFile.open("D:\\HackUTD\\HackUTD-2023-HomeBuyerInfo.csv");

  if (!inputFile) {
    cerr << "Failed to open the input file." << endl;
    return 1;
  }

  vector<idRecord> idRecords;
  string line;

  while (getline(inputFile, line)) {
    stringstream inputString(line);
    string token;
    vector<string> tokens;

    while (getline(inputString, token, ',')) {
      tokens.push_back(token);
    }

    if (tokens.size() == 10) {
      int iD, grossMonthlyIncome, creditCardPayment, CarPayment,
        studentLoanPayments, appraisedValue, CreditScore;
      double downPayment, loanAmount, monthlyMortgagePayment;

      try {
        iD = stoi(tokens[0]);
        grossMonthlyIncome = stoi(tokens[1]);
        creditCardPayment = stoi(tokens[2]);
        CarPayment = stoi(tokens[3]);
        studentLoanPayments = stoi(tokens[4]);
        appraisedValue = stoi(tokens[5]);
        downPayment = stod(tokens[6]);
        loanAmount = stod(tokens[7]);
        monthlyMortgagePayment = stod(tokens[8]);
        CreditScore = stoi(tokens[9]);

        idRecord record(iD,
                        grossMonthlyIncome,
                        creditCardPayment,
                        CarPayment,
                        studentLoanPayments,
                        appraisedValue,
                        CreditScore,
                        downPayment,
                        loanAmount,
                        monthlyMortgagePayment);
        idRecords.push_back(record);
      }
      catch (const std::exception& e) {
        cerr << "Error while parsing data: " << e.what() << endl;
      }
    }
  }

  for (idRecord& record : idRecords) {
    record.display();
    cout << endl;
  }

  inputFile.close();

  for (const idRecord& record : idRecords) {
    // Check Credit Score
    if (record.Credit_Score >= 640) {
      // Calculate LTV ratio
      double ltv = (record.Loan_Amount / record.Appraised_Value) * 100;

      // Check LTV Ratio
      if (ltv < 80.0) {
        // LTV < 80% is preferred
        // Check DTI Ratio
        double dti =
          (record.Monthly_Mortgage_Payment / record.Gross_Monthly_Income) * 100;
        if (dti <= 36.0 &&
            (dti <= 28.0 || record.Monthly_Mortgage_Payment == 0)) {
          cout << "User with ID " << record.Id
               << " is approved for a home purchase." << endl;
        }
        else {
          cout << "User with ID " << record.Id
               << " is not approved due to the DTI ratio." << endl;
        }
      }
      else if (ltv >= 80.0 && ltv <= 95.0) {
        // LTV between 80% and 95% may require PMI
        cout << "User with ID " << record.Id
             << " may be approved but could require PMI due to the LTV ratio."
             << endl;
      }
      else {
        cout << "User with ID " << record.Id
             << " is not approved due to the high LTV ratio." << endl;
      }
    }
    else {
      cout << "User with ID " << record.Id
           << " is not approved due to the low credit score." << endl;
    }
    cout << endl;
  }
  return 0;
}
