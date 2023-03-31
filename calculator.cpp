#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int userNumAmount;
string detect;
float finalNum;

bool inArray(string checkWord, string arr[], int sizeOfArray) {
  bool exists = false;
  for (int i = 0; i <= sizeOfArray; i++) {
    if (arr[i] == checkWord)
      exists = true;
  }
  if (exists) return true;
  else return false;
}

float power(float num1, int num2) {
  float fixedNum = num1;
  for (int i = 1; i < num2; i++) {
    num1 *= fixedNum;
  }
  return num1;
}

 int factorial(int num1){
     for (int i = num1 - 1; i >= 1; i--){
       num1 *= i;
     }
     return num1;
 }

void menuOne (){
    cout << "Choose your required operation: " << endl;
    cout << "1) ! (factorial)" << endl;
    cin >> detect;
    transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
}

void menuTwo (){
    cout << "Choose your required operation: " << endl;
    cout << "1) + (sum)\n2) - (substract)\n3) * (multiply)\n4) / (divide)\n5) ^ (power)" << endl;
    cin >> detect;
    transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
}

void menuOther(){
    cout << "Choose your required operation: " << endl;
    cout << "1) + (sum)\n2) - (substract)\n3) * (multiply)\n4) / (divide)"<< endl;
    cin >> detect;
    transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
}

int main() {
  string arr1[] = {"1", "sum", "+", "1)", "one"};
  string arr2[] = {"2", "substract", "-", "2)", "two"};
  string arr3[] = {"3", "multiply", "*", "3)", "three"};
  string arr4[] = {"4", "divide", "/", "4)", "four"};
  string arr5[] = {"5", "power", "^", "5)", "five"};
//  string arr6[] = {"6", "factorial", "!", "6)", "six"};
  cout << "\n -------------------------------- \n";
  cout << " \n|   Welcome to the calculator!  |" << endl;
  cout << "\n -------------------------------- \n";
  cout << "How many numbers would you like to enter? ";
  cin >> userNumAmount;
  vector<float> userVector(userNumAmount);
  for (int i = 1 ; i <= userNumAmount ; i++){
      cout << "Enter number " << i << " : ";
      cin >> userVector.at(i - 1);
  }
  if (userNumAmount == 0) {
      do {
          cout << "Only enter an integer above 0: ";
          cin >> userNumAmount;
      }
      while (userNumAmount <= 0);
  }
  else if (userNumAmount == 1) {
      cout << "\nThe only supported operation on a single number is factorial!" << endl;
      cout << "The factorial of " << userVector.at(0) << " is : " << factorial(userVector.at(0));
  }
  else if (userNumAmount == 2) {
      menuTwo();
  }
  else {
      menuOther();
      if (inArray(detect, arr1, sizeof(arr1) / sizeof(arr1[0]) - 1)) {
          for (int i = 0; i < userNumAmount ; i++) {
              finalNum += userVector.at(i);
          }
          cout << "The sum of your numbers is: " << finalNum << endl;
      }
      else if (inArray(detect, arr2, sizeof(arr2) / sizeof(arr2[0]) - 1)) {
          for (int i = 0; i < userNumAmount; i++) {
              finalNum -= userVector.at(i);
          }
          cout << "The subtraction of your numbers is: " << finalNum << endl;
      }
      else if (inArray(detect, arr3, sizeof(arr3) / sizeof(arr3[0]) - 1)) {
          for (int i = 0; i < userNumAmount ; i++) {
              finalNum *= userVector.at(i);
          }
          cout << "The multiplication of your numbers is: " << finalNum << endl;
      }
      else if (inArray(detect, arr4, sizeof(arr4) / sizeof(arr4[0]) - 1)) {
          for (int i = 0; i < userNumAmount; i++) {
              finalNum /= userVector.at(i);
          }
          cout << "The division of your numbers is: " << finalNum << endl;
      }

  }

  }
//  cout << "\nEnter your first number: ";
//  cin >> n1;
//  cout << "\nEnter your second number: ";
//  cin >> n2;
//  transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
//  if (inArray(detect, arr1, sizeof(arr1) / sizeof(arr1[0]) - 1)) {
//    cout << "The sum of " << n1 << " and " << n2 << " is : " << sum(n1, n2) << endl;
//  }
//
//  else if (inArray(detect, arr2, sizeof(arr2) / sizeof(arr2[0]) - 1)) {
//    cout << "The substraction of " << n1 << " and " << n2 << " is : " << substract(n1, n2) << endl;
//  }
//
//  else if (inArray(detect, arr3, sizeof(arr3) / sizeof(arr3[0]) - 1)) {
//    cout << "The multiplication of " << n1 << " and " << n2 << " is : " << multiply(n1, n2) << endl;
//  }
//
//  else if (inArray(detect, arr4, sizeof(arr4) / sizeof(arr4[0]) - 1)) {
//    cout << "The division of " << n1 << " and " << n2 << " is : " << divide(n1, n2) << endl;
//  }
//
//  else if (inArray(detect, arr5, sizeof(arr5) / sizeof(arr5[0]) - 1)) {
//    cout <<  n1 << " to the power of " << n2 << " is : " << power(n1, n2) << endl;
//  }
//
//  else
//    cout << "Your input was not evaluated!" << endl;
}