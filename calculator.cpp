#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool inArray(string checkWord, string arr[], int sizeOfArray) {
  bool exists = false;
  for (int i = 0; i <= sizeOfArray; i++) {
    if (arr[i] == checkWord)
      exists = true;
  }
  if (exists)
    return true;
  else
    return false;
}

float sum(float num1, float num2) { return num1 + num2; }

float substract(float num1, float num2) { return num1 - num2; }

float multiply(float num1, float num2) { return num1 * num2; }

float divide(float num1, float num2) { return num1 / num2; }

float power(float num1, int num2) {
  float fixedNum = num1;
  for (int i = 1; i < num2; i++) {
    num1 *= fixedNum;
  }
  return num1;
}

int main() {
  string arr1[] = {"1", "sum", "+", "1)"};
  string arr2[] = {"2", "substract", "-", "2)"};
  string arr3[] = {"3", "multiply", "*", "3)"};
  string arr4[] = {"4", "divide", "/", "4)"};
  string arr5[] = {"5", "power", "^", "5)"};
  string detect;
  float n1, n2;
  cout << "\n -------------------------------- \n";
  cout << " \n|   Welcome to the calculator!  |" << endl;
  cout << "\n -------------------------------- \n";
  cout << "\nEnter your first number: ";
  cin >> n1;
  cout << "\nEnter your second number: ";
  cin >> n2;
  cout << "Choose your required operation: " << endl;
  cout << "1) + (sum)\n2) - (substract)\n3) * (multiply)\n4) / (divide)\n5) ^ (power)"
       << endl;
  cin >> detect;
  transform(detect.begin(), detect.end(), detect.begin(), ::tolower);
  if (inArray(detect, arr1, sizeof(arr1) / sizeof(arr1[0]) - 1)) {
    cout << "The sum of " << n1 << " and " << n2 << " is : " << sum(n1, n2) << endl;
  }

  else if (inArray(detect, arr2, sizeof(arr2) / sizeof(arr2[0]) - 1)) {
    cout << "The substraction of " << n1 << " and " << n2 << " is : " << substract(n1, n2) << endl;
  }

  else if (inArray(detect, arr3, sizeof(arr3) / sizeof(arr3[0]) - 1)) {
    cout << "The multiplication of " << n1 << " and " << n2 << " is : " << multiply(n1, n2) << endl;
  }

  else if (inArray(detect, arr4, sizeof(arr4) / sizeof(arr4[0]) - 1)) {
    cout << "The division of " << n1 << " and " << n2 << " is : " << divide(n1, n2) << endl;
  }
  
  else if (inArray(detect, arr5, sizeof(arr5) / sizeof(arr5[0]) - 1)) {
    cout <<  n1 << " to the power of " << n2 << " is : " << power(n1, n2) << endl;
  }

  else
    cout << "Your input was not evaluated!" << endl;
}