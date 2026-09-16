#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool makeNumber(string text, double& number)
{
    try
    {
        size_t position;
        number = stod(text, &position);

        if (position != text.length())
        {
            return false;
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}


int main(int argc, char* argv[])
{
    double loan = 0.0;
    double interestRate = 0.0;
    double monthlyPayment = 0.0;

    double monthlyRate = 0.0;
    double interest = 0.0;
    double principal = 0.0;
    double totalInterest = 0.0;

    int month = 0;

    string input;


    if (argc == 1)
    {
        cout << "Loan Amount: ";
        cin >> input;

        while (!makeNumber(input, loan) || loan <= 0)
        {
            cout << "Warning: Invalid loan." << endl;
            cout << "Loan Amount: ";
            cin >> input;
        }


        cout << "Interest Rate (% per year): ";
        cin >> input;

        while (!makeNumber(input, interestRate) || interestRate < 0)
        {
            cout << "Warning: Invalid interest rate." << endl;
            cout << "Interest Rate (% per year): ";
            cin >> input;
        }


        cout << "Monthly Payments: ";
        cin >> input;

        while (!makeNumber(input, monthlyPayment) || monthlyPayment <= 0)
        {
            cout << "Warning: Invalid payment." << endl;
            cout << "Monthly Payments: ";
            cin >> input;
        }
    }

    else
    {
        if (argc >= 2)
        {
            if (!makeNumber(argv[1], loan) || loan <= 0)
            {
                cout << "Warning: Invalid loan." << endl;
                return 1;
            }
        }
        else
        {
            cout << "Warning: Invalid loan." << endl;
            return 1;
        }


        if (argc >= 3)
        {
            if (!makeNumber(argv[2], interestRate) || interestRate < 0)
            {
                cout << "Warning: Invalid interest rate." << endl;
                return 1;
            }
        }
        else
        {
            cout << "Warning: Missing interest rate." << endl;
            return 1;
        }


        if (argc >= 4)
        {
            if (!makeNumber(argv[3], monthlyPayment) || monthlyPayment <= 0)
            {
                cout << "Warning: Invalid payment." << endl;
                return 1;
            }
        }
        else
        {
            cout << "Warning: Missing payment." << endl;
            return 1;
        }


        cout << "Loan Amount: " << argv[1] << endl;
        cout << "Interest Rate (% per year): " << argv[2] << endl;
        cout << "Monthly Payments: " << argv[3] << endl;
    }


    monthlyRate = interestRate / 12.0 / 100.0;


    if (monthlyPayment <= loan * monthlyRate)
    {
        cout << "Warning: Insufficient payment." << endl;
        return 1;
    }


    cout << fixed << setprecision(2);

    cout << endl;

    cout << "*****************************************************************\n";
    cout << "\tAmortization Table\n";
    cout << "*****************************************************************\n";
    cout << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";


    cout << 0
         << "\t$" << loan
         << "\t\tN/A\tN/A\tN/A\t\tN/A"
         << endl;


    while (loan > 0)
    {
        month++;

        interest = loan * monthlyRate;

        double payment = monthlyPayment;


        if (loan + interest <= monthlyPayment)
        {
            payment = loan + interest;
        }


        principal = payment - interest;

        loan = loan - principal;


        if (loan < 0.005)
        {
            loan = 0.0;
        }


        totalInterest = totalInterest + interest;


        cout << month
             << "\t$" << loan
             << "\t\t$" << payment
             << "\t" << interestRate / 12.0
             << "\t$" << interest
             << "\t\t$" << principal
             << endl;
    }


    cout << "*****************************************************************\n";

    cout << endl;
    cout << "It takes " << month << " months to pay off the loan." << endl;
    cout << "Total interest paid is: $" << totalInterest << endl;


    return 0;
}
