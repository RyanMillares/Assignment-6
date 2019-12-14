#include "Sorter.h"
#include <iostream>
#include <fstream>
#include <time.h>
//#include <chrono>
using namespace std;
//using namespace std::chrono;
//using time_stamp = time_point<system_clock, milliseconds>;
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
int Sorter::Partition(int start, int end){
  double pivot = unsortedArray[end];
  int i = start - 1;
  for(int j = start; j <= end - 1; ++j){
    if(unsortedArray[j] < pivot){
      i++;
      Swap(i, j);

    }
  }
  Swap(i+1, end);
  return i+1;
}
void Sorter::Swap(int first, int second){
  double hold = unsortedArray[second];
  unsortedArray[second] = unsortedArray[first];
  unsortedArray[first] = hold;
}
//start at 0, size - 1
void Sorter::QuickSort(int start, int end){
  //perform quick sort
  //cal ReadValues() BEFORE function call
  if(end > start){
    int piv = Partition(start, end);
    //create the pivot index
    //move all values less than it before, and others after it
    QuickSort(start, piv - 1);
    //quick sort the numbers before pivot
    QuickSort(piv + 1, end);
    //quick sort numbers after pivot
  }
  /**

  //long int ts = static_cast<long int>(time_point_cast<milliseconds>(system_clock::now()));
  int pivotIndex = start;
  double pivot = unsortedArray[start];
  double hold;
  for(int i = start + 1; i <= end; ++i){
    for(int k = 0; k < arrayLength; ++k){
      cout << unsortedArray[k] << ", ";
    }
    cout << endl;
    hold = unsortedArray[i];
    if(hold < pivot){
      cout << "i: " << i << endl;
      for(int j = i; j > start; --j){
        //uu
        cout << "j: " << j << endl;
        unsortedArray[j] = unsortedArray[j-1];
        pivotIndex++;
        for(int k = 0; k < arrayLength; ++k){
          cout << unsortedArray[k] << ", ";
        }
        cout << endl;

      }
      unsortedArray[start] = hold;

    }
  }
  if(pivotIndex - start > 1){
    cout << "recurse1" << endl;

    QuickSort(start, pivotIndex-1);
  }
  if(end-pivotIndex > 1){
    cout << "recurse2" << endl;
    QuickSort(pivotIndex+1, end);
  }
**/



  /**

  int pivotIndex = 0;
  double pivot = unsortedArray[start];
  double hold, hold1;
  int i,j;
  int segSize = end - start + 1;
  for(i = start + 1; i < end + 1; ++i){
    for(int k = 0; k < arrayLength; ++k){
      cout << unsortedArray[k] << ", ";
    }
    cout << endl;
    hold = unsortedArray[i];
    if(hold < pivot){


      for(j = i; j > start; --j){

        unsortedArray[j + 1] = unsortedArray[j];
      }
      unsortedArray[start] = hold;
      pivotIndex++;
      for(int k = 0; k < arrayLength; ++k){
        cout << unsortedArray[k] << ", ";
      }
      cout << endl;


    }
    else if(hold > pivot){
      for(j = pivotIndex + 1; j < end - 1; ++j){
        //hold1 = unsortedArray[j];

        unsortedArray[j] = unsortedArray[j+1];
      }
      unsortedArray[end] = hold;
      for(int k = 0; k < arrayLength; ++k){
        cout << unsortedArray[k] << ", ";
      }
      cout << endl;

    }
  }
  //recursive call
  if((pivotIndex - start) != 1){
    cout << "yeet1" << endl;
    QuickSort(start, pivotIndex-1);
  }
  if((end - pivotIndex) != 1){
    cout << "yeet2" << endl;
    QuickSort(pivotIndex+1, end);
  }
  for(int k = 0; k < arrayLength; ++k){
    cout << unsortedArray[k] << ", ";
  }
**/

}

void Sorter::InsertionSort(){
  //perform insertion sort

  for(int i = 1; i < arrayLength; ++i){
    double temp = unsortedArray[i];
    int k = i;
    while((k > 0) && (unsortedArray[k -1] >= temp)){
      unsortedArray[k] = unsortedArray[k - 1];
      --k;
    }
    unsortedArray[k] = temp;

  }


}

void Sorter::BubbleSort(){
  //perform bubble sort
  //time_t time1, time2;
  int total = 0;


  //time1 = time(NULL);
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
  //time2 = time(NULL);
  //total = time2 - time1;




}
void Sorter::SelectionSort(){


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


}
void Sorter::MergeSort(int start, int end){
  if(end > start){
    int middle = start + (end = start)/2;
    //sort left and right from middle
    MergeSort(start, middle);
    MergeSort(middle + 1, end);
    //merge them together
    Merge(start, middle, end);
  }
  //perform merge Sort

}
void Sorter::Merge(int start, int middle, int end){
  int size1 = (middle - start) + 1;
  int size2 = (end - middle);
  //the TEMP arrays
  int left[size1];
  int right[size2];
  //copy left half into left array
  for(int i = 0; i < size1; ++i){
    left[i] = unsortedArray[start + i];
  }
  //copy right half into right array
  for(int j = 0; j < size2; ++j){
    right[j] = unsortedArray[(middle + 1) + j];
  }
  int firstIdx = 0;
  int secndIdx = 0;
  int newIdx = start;
  while((firstIdx < size1) && (secndIdx < size2)){
    if(left[firstIdx] <= right[secndIdx]){
      unsortedArray[newIdx] = left[firstIdx];
      firstIdx++;
    }
    else{
      unsortedArray[newIdx] = right[secndIdx];
      secndIdx++;
    }
    newIdx++;
  }
  //finish copying remaining elements
  //left array
  while(firstIdx < size1){
    unsortedArray[newIdx] = left[firstIdx];
    firstIdx++;
    newIdx++;
  }
  //right array
  while(secndIdx < size2){
    unsortedArray[newIdx] = right[secndIdx];
    secndIdx++;
    newIdx++;
  }

}

/**
double* Sorter::MakeCopy(){
  //https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm
  static double arrayCopy[10];
  for(int i = 0; i < arrayLength; ++i){
    arrayCopy[i] = unsortedArray[i];
  }
  return arrayCopy;
}
**/

void Sorter::SortAll(){
  clock_t start,end;
  float totalTime;
  cout << "Imported array contains " << arrayLength << " double values." << endl;
  cout << "---------------------------------------" << endl;
  //does everything

  ReadValues();


  start = clock();
  QuickSort(0, arrayLength-1);
  cout << endl;
  end = clock();
  cout << endl;
  totalTime = (float(end-start)/CLOCKS_PER_SEC)*1000;
  cout << "Quick sort start: 0ms" << endl;
  cout << "Quick sort end: " << totalTime << "ms" << endl;

  ReadValues();
  start = clock();
  InsertionSort();
  end = clock();
  cout << endl;
  totalTime = (float(end-start)/CLOCKS_PER_SEC)*1000;
  cout << "Insertion sort start: 0ms" << endl;
  cout << "Insertion sort end: " << totalTime << "ms" <<endl;

  ReadValues();
  start = clock();
  SelectionSort();
  end = clock();
  cout << endl;
  totalTime = (float(end-start)/CLOCKS_PER_SEC)*1000;
  cout << "Selection sort start: 0ms" << endl;
  cout << "Selection sort end: " << totalTime << "ms" <<endl;

  ReadValues();
  start = clock();
  BubbleSort();
  end = clock();
  cout << endl;
  totalTime = (float(end-start)/CLOCKS_PER_SEC)*1000;
  cout << "Bubble sort start: 0ms" << endl;
  cout << "Bubble sort end: " << totalTime << "ms" << endl;

  ReadValues();

  start = clock();
  MergeSort(0, arrayLength-1);
  end = clock();
  cout << endl;
  
  cout << endl;
  totalTime = (float(end-start)/CLOCKS_PER_SEC)*1000;
  cout << "Merge sort start: 0ms" << endl;
  cout << "Merge sort end: " << totalTime << "ms" << endl;



}
