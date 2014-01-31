//Main File

#include "Array.h"
#include <iostream>
#include <ctime>
using namespace std;


void afterSort(Array&, int);            //displays the array after a sort algorithm is used
void getSortTime(Array&, int);          //displays the sort time for a sort algorithm
void bubbleSort(Array &);               //bubble sort to sort array
void insertionSort(Array & arr);        //slection sort to sort array
void merge(Array&, int, int, int);      //function necessary to merge two arrays
void mergeSort(Array&, int, int);      //merge sort to sort array
void mergeSort(Array&);                 //default fucntion call to merge sort
void quickSort(Array&, int, int);       //quick sort to sort array
void quickSort(Array&);                 //default function call to quick sort


int main() {

  int x, choice;

  cout << "How many elements would you like? " << endl;
  cin >> x;

  Array a(x);

  while (choice != 4) {

      cout << "\n-----------------Menu-----------------\n"
           << "[1] Display Array\n"
           << "[2] Sort Array\n"
           << "[3] Check Sort Time\n"
           << "[4] End Program\n\n";

      cin >> choice;

       switch (choice) {
           case 1:
              cout << a;
              break;
          case 2:

              while (choice >= 1 && choice <= 5) {
                  cout << "Select a type of sort\n"
                       << "[1] - Insertion Sort\n"
                       << "[2] - Bubble Sort\n"
                       << "[3] - Merge Sort\n"
                       << "[4] - Quick Sort\n"
                       << "[5] - Exit\n\n";

                  cin >> choice;

                      if (choice == 1) {
                           afterSort(a, 1);
                           break;
                      }
                      else if (choice == 2) {
                           afterSort(a, 2);
                           break;
                      }
                      else if (choice == 3) {
                           afterSort(a, 3);
                           break;
                      }
                      else if (choice == 4) {
                           afterSort(a, 4);
                           break;
                      }
                      else if (choice == 5)
                           break;
                      else
                           cout << "\aError - Please Try Again\n";
              } // end while

              break;
          case 3:
              cout << "\nSelect a type of sort to evaluate sort time\n"
                   << "[1] - Insertion Sort\n"
                   << "[2] - Bubble Sort\n"
                   << "[3] - Merge Sort\n"
                   << "[4] - Quick Sort\n"
                   << "[5] - Exit\n\n";

              cin >> choice;

                      if (choice == 1) {
                           getSortTime(a, 1);
                           break;
                      }
                      else if (choice == 2) {
                           getSortTime(a, 2);
                           break;
                      }
                      else if (choice == 3) {
                           getSortTime(a, 3);
                           break;
                      }
                      else if (choice == 4) {
                           getSortTime(a, 4);
                           break;
                      }
                      else if (choice == 5)
                           break;
                      else
                           cout << "\aError - Please Try Again\n";
              break;
        case 4:
               cout << "\nGoodbye, Have a Nice Day :D\n";
               break;
        default:
                cout << "\n\aIncorrecct data entry - please try again\n";
                break;

    } // end switch

  } // end while


return 0;

}

void afterSort(Array& arr, int pick) {
    if (pick == 1){
       insertionSort(arr);
       cout << arr;
    }

    else if (pick == 2) {
       bubbleSort(arr);
       cout << arr;
    }
    else if (pick == 3) {
       mergeSort(arr);
       cout << arr;
    }
    else {
        quickSort(arr);
        cout << arr;
    }

}

void getSortTime(Array& arr, int pick) {

    time_t start, end;
    double dif;

    if (pick == 1) {
       time (&start);
       insertionSort(arr);
       time (&end);
       dif = difftime(end, start);
       cout << "It takes " << dif << " seconds to sort "
            << "using insertion sort\n";
    }

    else if (pick == 2) {
       time (&start);
       bubbleSort(arr);
       time (&end);
       dif = difftime(end, start);
       cout << "It takes " << dif << " seconds to sort "
            << "using bubble sort\n";
    }
    else if (pick == 3) {
       time (&start);
       mergeSort(arr);
       time (&end);
       dif = difftime(end, start);
       cout << "It takes " << dif << " seconds to sort "
            << "using merge sort\n";
    }
    else {
       time (&start);
       quickSort(arr);
       time (&end);
       dif = difftime(end, start);
       cout << "It takes " << dif << " seconds to sort "
            << "using quick sort\n";
    }

}

void insertionSort(Array & arr) {
   for (int i = 1; i < arr.size(); ++i) {

       int nextItem = arr[i];
       int j = i;

       for(; (j > 0) && (arr[j - 1] > nextItem); --j)
             arr[j] = arr[j - 1];

       arr[j] = nextItem;

   } // end for

}

/*bubble sort obtained from
http://mathbits.com/mathbits/compsci/arrays/bubble.htm */
void bubbleSort(Array & arr) {
    bool exchanges;
   do {
      exchanges = false;  // assume no exchanges
      for (int i = 0; i < arr.size()-1; i++) {
         if ( arr[i] > arr[i + 1] ) {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            exchanges = true;  // after exchange, must look again
         }
      }
   } while (exchanges);
} // end bubbleSort


void merge(Array& arr, int first, int mid, int last) {

    Array tempArray(arr.size());  //temporary array
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 =  last;

    int index = first1;

    for (; (first1 <= last1) && (first2 <= last2); index++) {
        if (arr[first1] < arr[first2]) {
             tempArray[index] = arr[first1];
             ++first1;
        }
        else {
             tempArray[index] = arr[first2];
             ++first2;
        } // end if
    } // end for

    //finish off the first subarray, if necessary
    for(; first1 <= last1; ++first1, ++index)
          tempArray[index] = arr[first1];

    //finish off the second subarray if necesary
    for (; first2 <= last2; ++first2, ++index)
          tempArray[index] = arr[first2];

    //copy the result back into the original
    for (index = first; index <= last; index++)
        arr[index] = tempArray[index];
} // end merge

void mergeSort(Array& arr, int first, int last) {
    if (first < last) {
       int mid = (first + last) / 2;  //index of mid point

       //sort left
       mergeSort(arr, first, mid);

       //merge right
       mergeSort(arr, mid + 1, last);

       //merge the halves
       merge(arr, first, mid, last);

    } // end if
} // end mergeSort

void mergeSort(Array& arr) {
    mergeSort(arr, 0, arr.size()-1);
} // end mergeSort default function


/* obtained quicksort implmenetation from
  http://www.algolist.net/Algorithms/Sorting/Quicksort */
void quickSort(Array & arr, int left, int right) {
     int i = left, j = right;
     int tmp;
     int pivot = arr[(left + right) / 2];

     /* partition */
     while (i <= j) {
           while (arr[i] < pivot)
                 i++;
           while (arr[j] > pivot)
                 j--;
           if (i <= j) {
                 tmp = arr[i];
                 arr[i] = arr[j];
                 arr[j] = tmp;
                 i++;
                 j--;
           }
     };

     /* recursion */
     if (left < j)
           quickSort(arr, left, j);
     if (i < right)
           quickSort(arr, i, right);
}

void quickSort(Array & arr) {
    quickSort(arr, 0, arr.size()-1);
}
