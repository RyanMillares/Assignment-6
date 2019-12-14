#include <iostream>
using namespace std;
class Sorter{
public:
  Sorter();
  Sorter(string filename, int num);
  ~Sorter();

  void ReadValues();
  void QuickSort(int start, int end);
  void InsertionSort();
  void SelectionSort();
  void BubbleSort();

  void MergeSort();
  int Partition(int start, int end);
  void Swap(int first, int second);

  void SortAll();

  //double* MakeCopy();

  string name;
  int arrayLength;
  double* unsortedArray;


};
