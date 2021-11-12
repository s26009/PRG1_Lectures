#include <iostream>
#include <string>
#include <cmath>

int getInteger() {
	auto n = std::string {};
	std::getline(std::cin, n);
	return std::stoi(n);
}

void initHard(int*& a) {
	a = new int[10] { 42 , 9 , -1 , 18 , 59 , 3 , 101 , 31 , 72 , 12 };
}

void printArray(int a[], int n) {
	std::cout << "a[" << n << "] = { ";
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " ";
	}	
	std::cout << "}\n";
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int*& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int*& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int*& arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int linearSearch(int*& arr, int n, int needle) {
	for (int i = 0; i < n; i++) {
		if(arr[i] == needle) return i;
	}	
	return -1;
}

int main(int argc, char *argv[]) {
	int *a;
	int capacity = 10;

	std::cout << "Looking for: ";
	int needle = getInteger();

	initHard(a);
	printArray(a, capacity);
	//quickSort(a, 0, capacity - 1);
	//std::cout << "Sorted:\n";
	//printArray(a, capacity);
	std::cout << "Search result:\n";
	
	//int result = binarySearch(a, 0, capacity - 1, needle);
	int result = linearSearch(a, capacity, needle);
	if(result != -1) {
		std::cout << "a[" << result << "] = " << needle << "\n";
	} else {
		std::cout << "No " << needle << " in a[" << capacity << "]\n";
	}

	return 0;
}
