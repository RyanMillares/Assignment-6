#include "Sorter.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv){
  string filename, firstline;
  int num;
  if(argc > 1){
    filename = argv[1];
  }
  else{
    cout << "No command-line argument provided, try again." << endl;
    exit(0);
  }
  ifstream numStream(filename);
  if(numStream.is_open()){
    if(getline(numStream, firstline)){
      num = stoi(firstline);
    }
  }

  numStream.close();

  Sorter LetsSort(filename, num);
  LetsSort.SortAll();



}
