#include<iostream>
#include<vector>

using namespace std;

int pickingNumbers(vector<int> a) {

    int* arr_for_storing_longest_subArray_with_given_condition = new int[a.size()];
    int arr_size = 0;
    //Intializing the dynamic array with -1.
    for (int i = 0, j = a.size() - 1; i <= j; i++, j--) {
        arr_for_storing_longest_subArray_with_given_condition[i] = -1;
        arr_for_storing_longest_subArray_with_given_condition[j] = -1;
    }
    vector<int> vec_for_subArrays;
    //Calculating the biggest subarray with given condition in question.
    for (int i = 0; i < a.size(); i++) {
        arr_size = 0;
       vec_for_subArrays.erase(vec_for_subArrays.begin(),vec_for_subArrays.end());
       vec_for_subArrays.push_back(a[i]);
        for (int j = i + 1; j < a.size(); j++) {

            if (a[j] - a[i] == 1 || a[j] - a[i] == 0 || a[j] - a[i] == -1) {
               vec_for_subArrays.push_back(a[j]);

            }
        }
        //Checking for the size of last filled arr.
        for (int k = 0; k < a.size(); k++) {
            if (arr_for_storing_longest_subArray_with_given_condition[k] != -1) {
                arr_size++;
            }
            else {
                break;
            }
        }
        //if last filled array is smaller than new vector than
        //replace it.
        if (vec_for_subArrays.size() > arr_size) {
            for (int k = 0; k <vec_for_subArrays.size(); k++) {
                arr_for_storing_longest_subArray_with_given_condition[k] = vec_for_subArrays[k];
            }
        }

    }
    return arr_size;
}

int main() {

    vector<int> a = { 4,6,5,3,3,1 };
    cout << pickingNumbers(a);
    return 0;
}