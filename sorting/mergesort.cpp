#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void merge(int arr[], int beg, int mid, int end, int size)
{
    int i = beg, j = mid+1, index = 0;

    int *temp;
    temp = new int[size];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    if (j > end)
    {
        while (i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    j=0;
    for (i =beg; i <= end; i++)
    {
        arr[i] = temp[j];
        j++;
    }
}
void mergesort(int arr[], int beg, int end, int size)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;

        mergesort(arr, beg, mid, size);
        mergesort(arr, mid + 1, end, size);
        merge(arr, beg, mid, end, size);
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
    mergesort(ptr, 0, size - 1, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
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