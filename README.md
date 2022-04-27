# Concept of the QuickSort
Quick Sort is a sorting method which uses the idea of "Divide and Conquer". This strategy aims to rearrange the elements so that the smaller ones precede the larger. Then, sorts the two generated sublists (the list of the smaller numbers and the list of larger numbers) recursively until the list is fully ordered.

# Partition Method
The Partition is a method used to rearrange the elements using a pivot. It is used a "For Loop" to iterate for each element in the list. If this element is lower and just after the pivot, the pivot and the element are swapped. If the element after the pivot is larger than it, it swaps the position of the pivot with the larger number and then the larger number swaps position with the found lower element.
        
    int partition(int* myArray, int iniPos, int finPos) {

      int pivot = iniPos;
      for (int i = iniPos + 1; i < finPos; i++) {
          if (myArray[i] <= myArray[pivot]) {
              if (myArray[pivot] < myArray[pivot + 1]) {
                  // First swap (pivot and after pivot)
                  myArray[pivot] = myArray[pivot + 1] - myArray[pivot];
                  myArray[pivot + 1] = myArray[pivot + 1] - myArray[pivot];
                  myArray[pivot] = myArray[pivot + 1] + myArray[pivot];

                  // Seccond swap (with the smaller element)
                  myArray[pivot] = myArray[i] - myArray[pivot];
                  myArray[i] = myArray[i] - myArray[pivot];
                  myArray[pivot] = myArray[i] + myArray[pivot];

                  pivot++;
              }
              else if (myArray[i] == myArray[pivot + 1]) {
                  // Just swap once
                  myArray[pivot] = myArray[pivot + 1] - myArray[pivot];
                  myArray[pivot + 1] = myArray[pivot + 1] - myArray[pivot];
                  myArray[pivot] = myArray[pivot + 1] + myArray[pivot];

                  pivot++;
              }
          }
      }
      return pivot;
    }

# QuickSort Method
The QuickSort uses the Partition method and two recursions to order the list. This way it creates various sub-lists by diving the original list in smaller pieces.

        void quickSort(int* myArray, int iniPos, int finPos) {
            if (iniPos < finPos) {
            int pivot = partition(myArray, iniPos, finPos);
            quickSort(myArray, iniPos, pivot);
            quickSort(myArray, pivot+1, finPos);
            }
        }
