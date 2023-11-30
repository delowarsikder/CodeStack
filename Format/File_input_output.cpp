#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
  // This program reads no from each line of input.txt file and prints their sum in a file named output.txt file
  ifstream fin("input.txt"); // If file is in a directory like D:\input.txt the use ifstream fin("D:\\input.txt");
  string line;
  int sumOfValues = 0;
  getline(fin, line); // Each getline reads a line and advances file pointer to next line. So we are using it to skip first header line
  while (getline(fin, line))
  {
    // string line = "MRX 10 cse";
    stringstream ss(line);

    string dummy;
    int val;

    ss >> dummy;
    ss >> val;
    cout << val << endl;

    // sumOfValues = val;
    // Printing sum to output.txt file
    ofstream fout("output.txt", fstream::app); /// Overwrties contents of file each time if you want to append data to existing file then use ofstream fout("output.txt",fstream::app)
    fout << val << endl;
  }

  return 0;
}
