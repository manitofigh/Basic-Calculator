#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int userNumAmount;
string detect;

bool inArray(string checkWord, string arr[], int sizeOfArray) { // Function to understand if a word is inside an array
  bool exists = false;
  for (int i = 0; i <= sizeOfArray; i++) {
    if (arr[i] == checkWord)
      exists = true;
  }
  if (exists) return true;
  else return false;
}

double power(double num1, int num2) { // returns the first number to the power of the second number
  double fixedNum = num1;
  for (int i = 1; i < num2; i++) {
    num1 *= fixedNum;
  }
  return num1;
}

int factorial(int num1){ // returns the factorial of any number
     for (int i = num1 - 1; i >= 1; i--){
       num1 *= i;
     }
     return num1;
}

void menuOne (){ // the showing menu if the user only wants to work with one number
   cout << "\nChoose your required operation: " << endl;
   cout << "1) ! (factorial)\n2) √ (root)" << endl;
   cin >> detect;
   transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
}

void menuTwo (){ // the menu if the user wants to work with 2 numbers
    cout << "\nChoose your required operation: " << endl;
    cout << "1) + (sum)\n2) - (substract)\n3) * (multiply)\n4) / (divide)\n5) ^ (power)" << endl;
    cin >> detect;
    transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
}

void menuOther(){ // the menu when need to take 3 or more numbers into calculation
    cout << "\nChoose your required operation: " << endl;
    cout << "1) + (sum)\n2) - (substract)\n3) * (multiply)\n4) / (divide)"<< endl;
    cin >> detect;
    transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
}

int main() {
  double finalNum;
  string arr1[] = {"1", "sum", "+", "1)", "one"};
  string arr2[] = {"2", "subtract", "-", "2)", "two"};
  string arr3[] = {"3", "multiply", "*", "3)", "three"};
  string arr4[] = {"4", "divide", "/", "4)", "four"};
  string arr5[] = {"5", "power", "^", "5)", "five"};
  string arr6[] = {"1", "factorial", "!", "1)", "one"};
  string arr7[] = {"2", "root", "√", "2)", "two"};

  cout << endl;
  cout << "************************************" << endl;
  cout << "***                              ***" << endl;
  cout << "***  Welcome to the calculator!  *** " << endl;
  cout << "***                              *** " << endl;
  cout << "************************************" << endl;
  cout << "\nHow many numbers would you like to enter? ";
  cin >> userNumAmount;
  vector<double> userVector(userNumAmount); // creates a vector with enough indexes for the amount of numbers the user wants to enter
  cout << endl;
  for (int i = 1 ; i <= userNumAmount ; i++){
      cout << "Enter number " << i << " : "; // Takes in all the numbers the user wants to enter one after the other
      cin >> userVector.at(i - 1);
  }
  if (userNumAmount == 0) { // since you need at least one number to use the calc, it will ask to enter a num above 0, incase they entered a num < 1
      do {
          cout << "\nOnly enter an integer above 0: ";
          cin >> userNumAmount;
      }
      while (userNumAmount <= 0);
  }
  else if (userNumAmount == 1) { // if user wanted to work with one number
      menuOne();
      if (inArray(detect, arr6, sizeof(arr6) / sizeof(arr6[0]) - 1)) {
          finalNum = factorial(userVector.at(0));
          cout << "\nThe factorial of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr7, sizeof(arr7) / sizeof(arr7[0]) - 1)) {
          finalNum = sqrt(userVector.at(0));
          cout << "\nThe square root of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else cout << "\nYour input was not evaluated!" << endl << endl;
  }
  else if (userNumAmount == 2) { // if user wanted to work with 2 numbers
      menuTwo();
      if (inArray(detect, arr1, sizeof(arr1) / sizeof(arr1[0]) - 1)) {
          for (int i = 0; i < userNumAmount ; i++) {
              finalNum += userVector.at(i);
          }
          cout << "\nThe sum of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr2, sizeof(arr2) / sizeof(arr2[0]) - 1)) {
          finalNum = userVector.at(0);
          for (int i = 1; i < userNumAmount; i++) {
              finalNum -= userVector.at(i);
          }
          cout << "\nThe subtraction of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr3, sizeof(arr3) / sizeof(arr3[0]) - 1)) {
          finalNum = 1;
          for (int i = 0; i < userNumAmount ; i++) {
              finalNum *= userVector.at(i);
          }
          cout << "\nThe multiplication of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr4, sizeof(arr4) / sizeof(arr4[0]) - 1)) {
          finalNum = userVector.at(0);
          for (int i = 1; i < userNumAmount; i++) {
              finalNum /= userVector.at(i);
          }
          cout << "\nThe division of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr5, sizeof(arr5) / sizeof(arr5[0]) - 1)) {
          finalNum = power(userVector.at(0), userVector.at(1));
          cout << endl;
          cout << userVector.at(0) << " to the power of " << userVector.at(1) << " is: " << finalNum << endl;
      }
      else cout << "\nYour input was not evaluated!" << endl << endl;
  }
  else { // if the numbers to take into calculation were >= 3
      menuOther();
      if (inArray(detect, arr1, sizeof(arr1) / sizeof(arr1[0]) - 1)) {
          for (int i = 0; i < userNumAmount ; i++) {
              finalNum += userVector.at(i);
          }
          cout << "\nThe sum of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr2, sizeof(arr2) / sizeof(arr2[0]) - 1)) {
          finalNum = userVector.at(0);
          for (int i = 1; i < userNumAmount; i++) {
              finalNum -= userVector.at(i);
          }
          cout << "\nThe subtraction of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr3, sizeof(arr3) / sizeof(arr3[0]) - 1)) {
          finalNum = 1;
          for (int i = 0; i < userNumAmount ; i++) {
              finalNum *= userVector.at(i);
          }
          cout << "\nThe multiplication of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr4, sizeof(arr4) / sizeof(arr4[0]) - 1)) {
          finalNum = userVector.at(0);
          for (int i = 1; i < userNumAmount; i++) {
              finalNum /= userVector.at(i);
          }
          cout << "\nThe division of your numbers is: " << finalNum << endl << endl;
      }
      else cout << "\nYour input was not evaluated!" << endl << endl; // in case the chosen operation was not detected in the list of options
  }
}