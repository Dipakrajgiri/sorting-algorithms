#include <iostream>

#include <chrono>
using namespace std::chrono;
using namespace std;
void selectionsort(int arr[], int size)
{
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {

            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
int main()
{
    int *ptr, size;
    cout << "enter the size of array";
    cin >> size;
    ptr = new int[size];
    cout << "enter elements of array";
    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }
    cout << "array before sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
auto start = high_resolution_clock::now();
    selectionsort(ptr, size);
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
    cout << endl
         << "array after sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }

cout <<endl<< "Time taken : "
     << duration.count() << " microseconds" << endl;
    return 0;
}