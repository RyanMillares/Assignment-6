#include "Sorter.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
using time_stamp = time_point<system_clock, milliseconds>;
Sorter::Sorter(){
  unsortedArray = NULL;
}
Sorter::Sorter(string filename, int num){
  unsortedArray = new double[num];
  arrayLength = num;
  name = filename;
}
Sorter::~Sorter(){
  delete unsortedArray;
}

void Sorter::ReadValues(){

  string currentLine;
  ifstream file(name);
  if(file.is_open()){
    getline(file, currentLine);
    for(int i = 0; i < arrayLength; ++i){
      getline(file, currentLine);
      unsortedArray[i] = stod(currentLine);
    }

  }
  file.close();
}

void Sorter::QuickSort(){
  //perform quick sort
  ReadValues();
  long int ts = static_cast<long int>(time_point_cast<milliseconds>(system_clock::now()));



}

void Sorter::InsertionSort(){
  //perform insertion sort
  ReadValues();
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }
  for(int i = 1; i < arrayLength; ++i){
    double temp = unsortedArray[i];
    int k = i;
    while((k > 0) && (unsortedArray[k -1] >= temp)){
      unsortedArray[k] = unsortedArray[k - 1];
      --k;
    }
    unsortedArray[k] = temp;

  }
  cout << "Insertion Sort completed." << endl;
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }
  cout << endl;

}

void Sorter::BubbleSort(){
  //perform bubble sort
  time_t time1, time2;
  int total;
  ReadValues();
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }
  time1 = time(NULL);
  for(int i = 0; i < arrayLength; ++i){
    double temp = 0;
    for(int j = 0; j < arrayLength-1; ++j){
      if(unsortedArray[j] > unsortedArray[j + 1]){
        temp = unsortedArray[j + 1];
        unsortedArray[j + 1] = unsortedArray[j];
        unsortedArray[j] = temp;
      }
    }
  }
  time2 = time(NULL);
  total = time2 - time1;
  cout << "Bubble Sort completed. Time needed: " << total << "ms." << endl;
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }

  cout << endl;

}
void Sorter::SelectionSort(){
  ReadValues();
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }
  int index;
  double temp;
  for(int i = 0; i < arrayLength; ++i){
    index = i;
    for(int j = i + 1; j < arrayLength; ++j){
      if(unsortedArray[j] < unsortedArray[index]){
        index = j;
      }

    }
    if(index != i){
      temp = unsortedArray[i];
      unsortedArray[i] = unsortedArray[index];
      unsortedArray[index] = temp;

    }
  }
  cout << "Selection Sort completed." << endl;
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }
  cout << endl;

}

void Sorter::BeadSort(){
  //perform bead sort
  ReadValues();

}
void Sorter::ShiftArray(){

}
double* Sorter::MakeCopy(){
  //https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
  static double arrayCopy[10];
  for(int i = 0; i < arrayLength; ++i){
    arrayCopy[i] = unsortedArray[i];
  }
  return arrayCopy;
}

void Sorter::SortAll(){
  //does everything
  //ReadValues();
  QuickSort();
  InsertionSort();
  SelectionSort();
  BubbleSort();
  BeadSort();

}
