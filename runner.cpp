#include <bits/stdc++.h>
using namespace std;

// Headers
void QuickSort(vector<double>& array, int l, int r);
int Partition(vector<double>& array, int Left, int Right);

void heapify(vector<double> &array, int n, int i);
void HeapSort(vector<double> &array, int n);

void merge(vector<double> &array, int l, int m, int r);
void MergeSort(vector<double> &array, int l,int r);

// Main
int main() {
    for(int i = 0; i < 4; i++) {
        ifstream fi;
        ofstream fo;
        string fi_path, fo_path;
        if(i==0) fo_path = "values/QuickSort.txt";
        else if(i==1) fo_path = "values/HeapSort.txt";
        else if(i==2) fo_path = "values/MergeSort.txt";
        else fo_path = "values/IntroSort.txt";

        fo.open(fo_path);
        for(int j = 1; j < 11; j++) {
            srand(time(NULL));
            clock_t start, end;
            double running_time;

            fi_path = "data/data" + to_string(i) + ".txt";
            fi.open(fi_path);

            vector<double> array(1000000);
            for(int id = 0; id < 1000000; id++) fi >> array[id];

            if(i == 0) {
                start = clock();
                QuickSort(array, 0, 1000000 - 1);
                end = clock();
            }

            else if(i == 1) {
                start = clock();
                HeapSort(array, 1000000);
                end = clock();
            }

            else if(i == 2) {
                start = clock();
                MergeSort(array, 0, 1000000 - 1);
                end = clock();
            }

            else {
                start = clock();
                sort(array.begin(), array.end());
                end = clock();
            }

            running_time = (double)(end - start) / CLOCKS_PER_SEC;
            fo << running_time << " ";
            fi.close();
        }
        fo.close();
    }
}

// Footers
void QuickSort(vector<double>& array, int l, int r) {
    if(l >= r) return;
    int p = Partition(array, l, r);
    QuickSort(array, l, p);
    QuickSort(array, p + 1, r);
}

int Partition(vector<double>& array, int Left, int Right) {
    int index = rand() % (Right - Left + 1) + Left;
    double pivot = array[index];
    int i = Left - 1, j = Right + 1;
    while(true){
        do{
            ++i;
        }while(array[i] < pivot);

        do{
            --j;
        }while(array[j] > pivot);

        if(i < j) swap(array[i], array[j]);
        else return j;
    }
}

void heapify(vector<double> &array, int n, int i) {
    int l = 2 * i + 1, r = 2 * i + 2;
    int largest = i;

    if(l < n && array[l] > array[largest]) largest = l;
    if(r < n && array[r] > array[largest]) largest = r;

    if(largest != i) {
        swap(array[i], array[largest]);
        heapify(array, n, largest);
    }
}

void HeapSort(vector<double> &array, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) heapify(array, n, i);
    for(int i = n - 1; i >= 0; i--) {
        swap(array[i], array[0]);
        heapify(array, i, 0);
    }
}

void merge(vector<double> &array, int l, int m, int r) {
    vector<double> one(array.begin() + l, array.begin() + m + 1);
    vector<double> two(array.begin() + m + 1, array.begin() + r + 1);
    int i = 0, j = 0;
    while(i < one.size() && j < two.size()) {
        if(one[i] <= two[j]) {
            array[l] = one[i];
            ++l; ++i;
        }
        else{
            array[l] = two[j];
            ++l; ++j;
        }
    }

    while(i < one.size()) {
        array[l] = one[i];
        ++l; ++i;
    }

    while(j < two.size()) {
        array[l] = two[j];
        ++l; ++j;
    }
}

void MergeSort(vector<double> &array, int l,int r) {
    if(l >= r) return;
    int mid = (l + r) / 2;
    MergeSort(array, l, mid);
    MergeSort(array, mid + 1, r);
    merge(array, l, mid, r);
}