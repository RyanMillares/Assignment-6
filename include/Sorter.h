#include <iostream>
using namespace std;
class Sorter{
public:
  Sorter();
  Sorter(string filename, int num);
  ~Sorter();

  void ReadValues();
  void QuickSort();
  void InsertionSort();
  void SelectionSort();
  void BubbleSort();
  void BeadSort();

  void SortAll();
  void ShiftArray();
  double* MakeCopy();

  string name;
  int arrayLength;
  double* unsortedArray;


};
