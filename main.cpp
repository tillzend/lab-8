#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


void Array75();

void Matrix43();

void Sort24();
void swap();
void bubbleSort();

int main() {
    int choice = 0;

    while (choice != 4) {

        cout << endl;
        cout << "Choose task: "
            "\n1 - Array75"
            "\n2 - Matrix43"
            "\n3 - Sort24"
            "\n4 - Exit"
            "\n" << endl;

        cin >> choice;

        switch (choice) {
        case 1: {
            Array75();
            break;
        }
        case 2: {
            Matrix43();
            break;
        }
        case 3: {
            Sort24();
            break;
        }
        case 4: {
            cout << "Exit";
            break;
        }
        default: {
            cout << "Wrong number,try again";
        }
        }
    }
}
//task selector

void Array75() {
    int N;
    cout << "enter size of array: ";
    cin >> N;

    vector<int> array(N);

    cout << "enter elements of array:\n";
    for (int i = 0; i < N; ++i) {
        cin >> array[i];
    }

    // find min and max element of array
    auto min_element_it = min_element(array.begin(), array.end());
    auto max_element_it = max_element(array.begin(), array.end());
    int min_index = distance(array.begin(), min_element_it);
    int max_index = distance(array.begin(), max_element_it);

    // identify the range of elements to be rearranged 
    int start_index = min(min_index, max_index);
    int end_index = max(min_index, max_index);

    // rearrange elements in reverse order
    reverse(array.begin() + start_index, array.begin() + end_index + 1);

    // output results in file
    ofstream outfile("array_out_75.txt");
    if (outfile.is_open()) {
        for (int i = 0; i < N; ++i) {
            outfile << array[i] << " ";
        }
        outfile.close();
        cout << "results saved in file: array_out_75.txt\n";
    }
    else {
        cerr << "error\n";
    }
}

void Matrix43() {
    int M, N;
    std::cout << "Enter row (M): ";
    std::cin >> M;
    std::cout << "Enter col (N): ";
    std::cin >> N;

    std::vector<std::vector<int>> matrix(M, std::vector<int>(N));
    std::cout << "Enter element of matrix:\n";
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // find columns by decreasing
    int count = 0;
    for (int j = 0; j < N; ++j) {
        bool sorted = true;
        for (int i = 1; i < M; ++i) {
            if (matrix[i][j] > matrix[i - 1][j]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            ++count;
        }
    }

    // output results in file 
    std::string filename;
    std::cout << "enter name of file in which the result will be saved: " << endl;
    std::cin >> filename;

    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << "columns sorted by decreasing: " << count << std::endl;
        outputFile.close();
        std::cout << "Results saved in file: " << filename << std::endl;
    }
    else {
        std::cerr << "error!" << std::endl;
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Bubble Sorting in Decreasing Order 
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void Sort24() {
    const int size = 7;
    int numbers[size];

    // array filling 
    cout << "Enter " << size << " whole number:\n";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    // sort method 
    bubbleSort(numbers, size);

    // output sorted number 
    cout << "Sorted numbers in decreasing order:\n";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}
