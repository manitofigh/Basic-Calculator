#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

unsigned int userNumAmount;
string detect;
double temp;

bool inArray(string checkWord, string arr[], int sizeOfArray) { // Function to understand if a word is inside an array
  bool exists = false;
  for (int i = 0; i <= sizeOfArray; i++) {
    if (arr[i] == checkWord)
      exists = true;
  }
  return exists;
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
   cout << "1) ! (factorial)\n2) √ (root)\n3) sin (in degrees)\n4) cos (in degrees)\n5) tan (in degrees)\n6) cot (in degrees)" << endl;
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
  string arr8[] = {"3", "sin", "3)", "three"};
  string arr9[] = {"4", "cos", "4)", "four"};
  string arr10[] = {"5", "tan", "5)", "five"};
  string arr11[] = {"6", "cot", "6)", "six"};

  cout << endl;
  cout << "************************************" << endl;
  cout << "***                              ***" << endl;
  cout << "***  Welcome to the calculator!  *** " << endl;
  cout << "***                              *** " << endl;
  cout << "************************************" << endl;
  cout << "\nHow many numbers would you like to enter? ";
  cin >> userNumAmount;
  if (userNumAmount <= 0) { // since you need at least one number to use the calc, it will ask to enter a num above 0, incase they entered a num < 1
      do {
          cout << endl << "Only enter an integer above 0: ";
          cin >> userNumAmount;
      }
      while (userNumAmount <= 0);
  }
  vector<double> userVector(userNumAmount); // creates a vector with enough indexes for the amount of numbers the user wants to enter
  cout << endl;
  for (int i = 1 ; i <= userNumAmount ; i++){
      cout << "Enter number " << i << " : "; // Takes in all the numbers the user wants to enter one after the other
      cin >> userVector.at(i - 1);
  }
  if (userNumAmount == 1) { // if user wanted to work with one number
      menuOne();
      if (inArray(detect, arr6, sizeof(arr6) / sizeof(arr6[0]) - 1)) { // sizeof(arr) / sizeof(arr[0]) returns the number of elements inside the array.
          finalNum = factorial(userVector.at(0));
          cout << "\nThe factorial of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr7, sizeof(arr7) / sizeof(arr7[0]) - 1)) {
          finalNum = sqrt(userVector.at(0));
          cout << "\nThe square root of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr8, sizeof(arr8) / sizeof(arr8[0]) - 1)) {
          finalNum = sin(userVector.at(0) * M_PI / 180); // the trig function takes angles in radiant so I multiply by PI and divide by 180 to turn to degrees
          cout << "\nSinus of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr9, sizeof(arr9) / sizeof(arr9[0]) - 1)) {
          finalNum = cos(userVector.at(0) * M_PI / 180);
          cout << "\nCosine of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr10, sizeof(arr10) / sizeof(arr10[0]) - 1)) {
          finalNum = tan(userVector.at(0) * M_PI / 180);
          cout << "\nTangent of " << userVector.at(0) << " is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr11, sizeof(arr11) / sizeof(arr11[0]) - 1)) {
          finalNum = 1/tan(userVector.at(0) * M_PI / 180);
          cout << "\nCotangent of " << userVector.at(0) << " is: " << finalNum << endl << endl;
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
          finalNum = userVector.at(0); // have to set finalNum to the first value in the vector or it will not have anything to deduct from.
          for (int i = 1; i < userNumAmount; i++) {
              finalNum -= userVector.at(i);
          }
          cout << "\nThe subtraction of your numbers is: " << finalNum << endl << endl;
      }
      else if (inArray(detect, arr3, sizeof(arr3) / sizeof(arr3[0]) - 1)) {
          finalNum = 1; // since by default it is set to 0, if it's assigned to 1, it will return 0 no matter what 
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