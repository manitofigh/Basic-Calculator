#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int number1, number2;
string operation;
arrSum = ["1", "1)", "sum", "summation"];
arrSub = ["2", "2)", "substraction", "substract"];
arrMult = ["3", "3)", "multiply", "multiplication"];
arrDiv = ["4", "4)", "divide", "division"];

bool inArray (string word, string arr[], int arrayLength){
    for (int i = 0; i <= arrayLength; i++){
        if (arr[i] == word){
            return true;
        }
    }
    else return false;
}

int sum(int num1, int num2) {
    return num1 + num2;
}

int deduct(int num1, int num2){
    return num1 - num2;
}

int multiply (int num1, int num2){
    return num1 * num2;
}

int divide(int num1, int num2){
    return num1 / num2;
}

int main(){
    cout << "-----------------------------" << endl;
    cout << "|                            |" << endl;
    cout << "| Welcome to the Calculator! |" << endl;
    cout << "|                            |" << endl;
    cout << "-----------------------------" << endl;
    
    cout << "Enter your first number: ";
    cin >> number1;
    cout << "\n Enter your second number: ";
    cin >> number2;
    cout << "Enter your required operation: " << endl;
    cout << "1) Sum" << endl;
    cout << "2) Substraction" << endl;
    cout << "3) Division" << endl;
    cout << "4) Multiplication" << endl;
    cin >> operation;
    operation = transform(operation.begin(), operation.end(), operation.begin(), ::tolower);
    
    if (inArray(operation, arrSum, sizeof(arrSum) / sizeof(arrSum[0]) - 1){
        cout << "The sum of " << number1 << " and " << number2 << " is: " << sum(number1, number2) << endl;
    }

    else if (inArray(operation, arrSub, sizeof(arrSub) / sizeof(arrSub[0]) - 1){
        cout << "The substraction of " << number1 << " and " << number2 << " is: " << deduct(number1, number2) << endl;
    }

    else if (inArray(operation, arrMult, sizeof(arrMult) / sizeof(arrMult[0]) - 1){
        cout << "The multiplication of " << number1 << " and " << number2 << " is: " << multiply(number1, number2) << endl;
    }

    else if (inArray(operation, arrDiv, sizeof(arrDiv) / sizeof(arrDiv[0]) - 1){
        cout << "The division of " << number1 << " and " << number2 << " is: " << divide(number1, number2) << endl;
    }

    else cout << "Your input could not be validated!" << endl;

}