//libraries
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

//function  
int main();
void bubbleSort(int arr[], int n);
void swap(int *xp, int *yp);
int partition(int arr[], int low, int high);

//This fuction write the sorted arraies to spreadsheet file
void printArray(int arr[], int size, int sortType, int sortRecords)
{
	//variables
	int i, temp, count = 0;
	ofstream myFile;

	/*	 for (i = 1; i < size; i++){
	        cout << arr[i]<<",";
	        temp = arr[i];
	         myFile <<temp<<",";

	    }*/

	if (sortType == 1)
	{
		if (sortRecords == 1)
		{
			//open file
			myFile.open("bubblesort15000Records.csv");

		}
		else if (sortRecords == 2)
		{
			//open file
			myFile.open("bubblesort65000Records.csv");

		}
		else
		{
			//open file
			myFile.open("bubblesort150000Records.csv");
		}
	}

	if (sortType == 2)
	{
		if (sortRecords == 1)
		{
			//open file 
			myFile.open("quicksort15000Records.csv");

		}
		else if (sortRecords == 2)
		{
			//open file
			myFile.open("quicksort65000Records.csv");

		}
		else
		{
			//open file
			myFile.open("quicksort150000Records.csv");
		}
	}

	if (sortType == 3)
	{
		if (sortRecords == 1)
		{
			//open file
			myFile.open("Selectionsort15000Records.csv");

		}
		else if (sortRecords == 2)
		{
			//open file
			myFile.open("Selectionsort65000Records.csv");

		}
		else
		{
			//open file
			myFile.open("Selectionsort150000Records.csv");
		}
	}

	if (sortType == 4)
	{
		if (sortRecords == 1)
		{
			//open file
			myFile.open("Heapsort15000Records.csv");

		}
		else if (sortRecords == 2)
		{
			//open file
			myFile.open("Heapsort65000Records.csv");

		}
		else
		{
			//open file
			myFile.open("Heapsort150000Records.csv");
		}
	}

	if (sortType == 5)
	{
		if (sortRecords == 1)
		{
			//open file
			myFile.open("Insertionsort15000Records.csv");

		}
		else if (sortRecords == 2)
		{
			//open file
			myFile.open("Insertionsort65000Records.csv");

		}
		else
		{
			//open file
			myFile.open("Insertionsort150000Records.csv");
		}
	}

	if (sortType == 6)
	{
		if (sortRecords == 1)
		{
			//open file
			myFile.open("Mergesort15000Records.csv");

		}
		else if (sortRecords == 2)
		{
			//open file
			myFile.open("Mergesort65000Records.csv");

		}
		else
		{
			//open file
			myFile.open("Mergesort150000Records.csv");
		}
	}

	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		myFile << temp << ",";	//right array to the file 

	}

	main();
}

//Menu fuction that give the user a menu
void displaymenu()
{
	cout << "===================================================== \n";
	cout << " \t\tMENU \t \n ";
	cout << "===================================================== \n";
	cout << " 1.Bubble Sort\n";
	cout << " 2.Quick Sort\n";
	cout << " 3.Selection Sort \n";
	cout << " 4.Heap Sort \n";
	cout << " 5.Insertion Sort \n";
	cout << " 6.Merge sort \n";

}

//this fuction sort the array using bubble sort

int bubblesort15(int size)
{
	//variables
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	int size2 = 15000;
	chrono::time_point<std::chrono::system_clock > start, end;

	if (size == 15000)
	{
		ifstream recordfiles("15000Records.txt");	// read file 

		if (recordfiles.is_open())	// test if file open correctly 
		{
			while (recordfiles >> num)	// get records from file 
			{
				recordarray[count] = num;	// store the data from file to an array
				count++;
			}

			recordfiles.close();	// close file after data is read

			start = std::chrono::system_clock::now();	// start the clock fuction 

			for (int i = 0; i < count - 1; i++)	//loop
			{
				for (int j = 0; j < count - i - 1; j++)	//loop
				{
					if (recordarray[j] > recordarray[j + 1])	//test to see if records or less than
					{
						//swap data 
						int temp = recordarray[j];
						recordarray[j] = recordarray[j + 1];
						recordarray[j + 1] = temp;
					}
				}
			}

			end = std::chrono::system_clock::now();	// end clock 

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";	// print out time

			sortType = 1;
			sortRecords = 1;

			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 65000)
	{
		ifstream recordfiles("65000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = 0; j < count - i - 1; j++)
				{
					if (recordarray[j] > recordarray[j + 1])
					{
						//swap(&arr[j], &arr[j+1]);
						int temp = recordarray[j];
						recordarray[j] = recordarray[j + 1];
						recordarray[j + 1] = temp;
					}
				}
			}

			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 1;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 150000)
	{
		ifstream recordfiles("150000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			for (int i = 0; i < count - 1; i++)
			{
				for (int j = 0; j < count - i - 1; j++)
				{
					if (recordarray[j] > recordarray[j + 1])
					{
						//swap(&arr[j], &arr[j+1]);
						int temp = recordarray[j];
						recordarray[j] = recordarray[j + 1];
						recordarray[j + 1] = temp;
					}
				}
			}

			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 1;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

// Swap two elements - Utility function  
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// the fuction part the array send to ti using last element as pivot
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// pivot 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		//please note that if current element is smaller than pivot, increment the low element

		if (arr[j] <= pivot)	// if arr[j] <= pivot we swap 
		{
			i++;	// increment index of smaller element 
			swap(&arr[i], &arr[j]);	//call swap function 
		}
	}

	swap(&arr[i + 1], &arr[high]);	//call swap function 
	return (i + 1);
}

//quicksort algorithm
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		//part the array 
		int pivot = partition(arr, low, high);

		//sort the sub arrays independently 
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);

	}
}

//quickSort2

void quickSort2(int size)
{
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	chrono::time_point<std::chrono::system_clock > start, end;

	if (size == 15000)
	{
		ifstream recordfiles("15000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			
			start = std::chrono::system_clock::now();	// start the clock fuction 
			
			quickSort(recordarray, 0, count - 1);

			end = std::chrono::system_clock::now();	// end clock 
			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";	// print out time

			sortType = 2;
			sortRecords = 1;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 65000)
	{
		ifstream recordfiles("65000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			quickSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 2;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 150000)
	{
		ifstream recordfiles("150000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			quickSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 2;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// go through the array
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

void selectionsort(int size)
{
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	chrono::time_point<std::chrono::system_clock > start, end;

	if (size == 15000)
	{
		ifstream recordfiles("15000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			
			selectionSort(recordarray, count);
			
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 3;
			sortRecords = 1;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 65000)
	{
		ifstream recordfiles("65000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			selectionSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 3;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 150000)
	{
		ifstream recordfiles("150000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			selectionSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 3;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

void heapify(int arr[], int n, int i)
{
	int largest = i;	// Initialize largest as root
	int l = 2 *i + 1;	// left = 2*i + 1
	int r = 2 *i + 2;	// right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void heapsort(int size)
{
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	chrono::time_point<std::chrono::system_clock > start, end;

	if (size == 15000)
	{
		ifstream recordfiles("15000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			heapSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";
			sortType = 4;
			sortRecords = 1;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 65000)
	{
		ifstream recordfiles("65000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			heapSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 4;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 150000)
	{
		ifstream recordfiles("150000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			heapSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 4;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/*Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void insertionsort(int size)
{
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType, sortRecords;
	chrono::time_point<std::chrono::system_clock > start, end;

	if (size == 15000)
	{
		ifstream recordfiles("15000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			insertionSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";
			sortType = 5;
			sortRecords = 1;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 65000)
	{
		ifstream recordfiles("65000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			insertionSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";
			sortType = 5;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 150000)
	{
		ifstream recordfiles("150000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			insertionSort(recordarray, count);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 5;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{
	// Create L ? A[p..q] and M ? A[q+1..r]
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1], M[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		M[j] = arr[q + 1 + j];

	// Maintain current index of sub-arrays and main array
	int i, j, k;
	i = 0;
	j = 0;
	k = p;

	// Until we reach either end of either L or M, pick larger among
	// elements L and M and place them in the correct position at A[p..r]
	while (i < n1 && j < n2)
	{
		if (L[i] <= M[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = M[j];
			j++;
		}

		k++;
	}

	// When we run out of elements in either L or M,
	// pick up the remaining elements and put in A[p..r]
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = M[j];
		j++;
		k++;
	}
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// m is the point where the array is divided into two subarrays
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		// Merge the sorted subarrays
		merge(arr, l, m, r);
	}
}

void mergesort(int size)
{
	ifstream recordfiles;
	int recordarray[size];
	int num, count, sortType = 5, sortRecords = 1;
	chrono::time_point<std::chrono::system_clock > start, end;

	if (size == 15000)
	{
		ifstream recordfiles("15000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			mergeSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";
			sortType = 5;
			sortRecords = 1;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 65000)
	{
		ifstream recordfiles("65000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			mergeSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 5;
			sortRecords = 2;
			printArray(recordarray, count, sortType, sortRecords);

		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else if (size == 150000)
	{
		ifstream recordfiles("150000Records.txt");
		if (recordfiles.is_open())
		{
			while (recordfiles >> num)
			{
				recordarray[count] = num;
				count++;
			}

			recordfiles.close();
			start = std::chrono::system_clock::now();
			mergeSort(recordarray, 0, count - 1);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double> elapsed_seconds = end - start;
			std::time_t end_time = std::chrono::system_clock::to_time_t(end);

			std::cout << "finished computation at " << std::ctime(&end_time) <<
				"elapsed time: " << elapsed_seconds.count() << "s\n";

			sortType = 5;
			sortRecords = 3;
			printArray(recordarray, count, sortType, sortRecords);
		}
		else
		{
			cout << "Can't open the file";
			exit;

		}
	}
	else
	{
		cout << "Can't open the file";
		exit;
	}
}

void exitProgram()
{
	cout << " Good Bye";
	exit(0);
}

void displaymenu2(int choice)
{
	int confirm;
	int records;

	if (choice == 1)
	{
		cout << " \n\t\t\t Bubble Sort\n";
		cout << " 1: 15,000 array record entries\n";
		cout << " 2: 65,000 array record entries\n";
		cout << " 3. 150,000 array record entries \n";
		cout << " 4. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 15000;
		}
		else if (confirm == 2)
		{
			records = 65000;

		}
		else if (confirm == 3)
		{
			records = 150000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		bubblesort15(records);
		auto start = high_resolution_clock::now();

	}
	else if (choice == 2)
	{
		cout << " \n\t\t\t Quick Sort\n";
		cout << " 1: 15,000 array record entries\n";
		cout << " 2: 65,000 array record entries\n";
		cout << " 3. 150,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 15000;
		}
		else if (confirm == 2)
		{
			records = 65000;

		}
		else if (confirm == 3)
		{
			records = 150000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		quickSort2(records);
		auto start = high_resolution_clock::now();

	}
	else if (choice == 3)
	{
		cout << " \n\t\t\t Selection Sort  \n";
		cout << " 1: 15,000 array record entries\n";
		cout << " 2: 65,000 array record entries\n";
		cout << " 3. 150,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 15000;
		}
		else if (confirm == 2)
		{
			records = 65000;

		}
		else if (confirm == 3)
		{
			records = 150000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		selectionsort(records);
		auto start = high_resolution_clock::now();

	}
	else if (choice == 4)
	{
		cout << " \n\t\t\t Heap Sort\n";
		cout << " 1: 15,000 array record entries\n";
		cout << " 2: 65,000 array record entries\n";
		cout << " 3. 150,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 15000;
		}
		else if (confirm == 2)
		{
			records = 65000;

		}
		else if (confirm == 3)
		{
			records = 150000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		heapsort(records);
		auto start = high_resolution_clock::now();

	}
	else if (choice == 5)
	{
		cout << " \n\t\t\t Insertion Sort\n";
		cout << " 1: 15,000 array record entries\n";
		cout << " 2: 65,000 array record entries\n";
		cout << " 3. 150,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 15000;
		}
		else if (confirm == 2)
		{
			records = 65000;

		}
		else if (confirm == 3)
		{
			records = 150000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		insertionsort(records);
		auto start = high_resolution_clock::now();

	}
	else if (choice == 6)
	{
		cout << "\n \t\t\t Merge Sort\n";
		cout << " 1: 15,000 array record entries\n";
		cout << " 2: 65,000 array record entries\n";
		cout << " 3. 150,000 array record entries \n";
		cout << " 4. Back \n";
		cout << " 5. Exit \n";
		cin >> confirm;
		if (confirm == 1)
		{
			records = 15000;
		}
		else if (confirm == 2)
		{
			records = 65000;

		}
		else if (confirm == 3)
		{
			records = 150000;

		}
		else if (confirm == 4)
		{
			exitProgram();

		}

		mergesort(records);
		auto start = high_resolution_clock::now();

	}
}

int main()
{
	string st[20];
	int itemcount = 0;

	//function to display Menu

	displaymenu();
	int yourchoice;
	string confirm;
	do {
		cout << "Enter your choice(1-6):";
		cin >> yourchoice;

		if (yourchoice >= 1 || yourchoice <= 6)
		{
			displaymenu2(yourchoice);

		}
		else
		{
			cout << "Wrong Choice";
			cout << "Press y or Y to continue, Press any other Key to Exit:";
			cin >> confirm;
		}
	} while (confirm == "y" || confirm == "Y");
	return 0;
}
