#include <iostream>
using namespace std;

void insert(int arr[], int n, int num, int pos);
void deleteElement(int arr[], int n, int num);
int search(int arr[], int n, int num);
void sort(int arr[], int n);
void displayArray(int arr[], int n);

int main() {
	int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n + 1];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int num, pos;
    cout << "Enter the number to insert and position: ";
    cin >> num >> pos;

    cout << "Array before insertion: ";
    displayArray(arr, n);

    insert(arr, n, num, pos);
    n++;
    
    cout << "\nArray after insertion: ";
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    cout << "\n\nEnter the number to delete: ";
    cin >> num;
    deleteElement(arr, n, num);
    n--;

    cout << "Array after deletion: ";
    displayArray(arr, n);

    cout << "\n\nEnter the number to search: ";
    cin >> num;
    int index = search(arr, n, num);
    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    cout << "\nArray before sorting: ";
    displayArray(arr, n);
    
    sort(arr, n);
    
    cout << "\nArray after sorting: ";
    displayArray(arr, n);

    return 0;

}

void insert(int arr[], int n, int num, int pos) {
	for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];

    arr[pos] = num;
}

int search(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void deleteElement(int arr[], int n, int num) {
    int pos = search(arr, n, num);
    if (pos == -1) {
        cout << "Element not found, nothing to delete." << endl;
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

void displayArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
}


