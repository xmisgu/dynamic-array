// dynamic-array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <time.h>
#include <sstream>

using namespace std;

template <typename T>

class DynamicArr {
private:
    unsigned int arr_size;
    unsigned int num_of_elements;
    T* array;
public:
    DynamicArr() {
        arr_size = 1; //array size
        num_of_elements = 0; //number of elements in array
        array = new T[arr_size];
    }

    ~DynamicArr() {
        delete[] array;
    }

    void add_element(const T& new_data) {      
        if (arr_size == num_of_elements) make_arr_bigger();

        array[num_of_elements] = new_data;
        num_of_elements++;
    }

    void make_arr_bigger() {
        arr_size = arr_size * 2;
        T* tmp_arr = new T[arr_size];
        
        for (unsigned int i = 0; i < num_of_elements; i++) {
            tmp_arr[i] = array[i];
        }

        delete[] array;
        array = tmp_arr;
    }

    T find_element(unsigned int i) {
        if (i <= num_of_elements - 1) {
            return array[i];
        }
        else {
            abort();
        }
    }

    void swap_data(unsigned int i, const T& new_data) {
        if (i < num_of_elements) {
            array[i] = new_data;
        }
        else {
            abort();
        }
    }

    void sort() {
        T tmp;
        for (int i = 0; i < num_of_elements - 1; i++) {
            for (int j = 0; j < num_of_elements - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }

    void delete_all() {
        delete[] array;
        arr_size = 1;
        num_of_elements = 0;
        array = new T[arr_size];
    }

    string display_array(unsigned int n = 0) {
        ostringstream output;

        output << "Rozmiar tablicy: " << arr_size << endl;
        output << "Liczba elementow: " << num_of_elements << endl;

        if (n > num_of_elements) n = num_of_elements;

        for (unsigned int i = 0; i < n; i++) {
            output << array[i] << endl;
        }
       

        return output.str();
    }
};

struct ArrData {
    int d1;
    char d2;

    ArrData() {
        d1 = 1;
        d2 = 'a';
    }
};

ostream& operator << (ostream& out, const ArrData& obj) {
    out << "{d1: " << obj.d1 << endl << " d2: " << obj.d2 << "}";
    return out;
}

bool operator > (const ArrData& a, const ArrData& b) {
    return a.d1 > b.d1 || a.d1 == b.d1 && a.d2 > b.d2;
}

int main()
{
    DynamicArr<ArrData>* dynamic_array = new DynamicArr<ArrData>();
    ArrData* data = new ArrData();
    data->d1 = 1;
    data->d2 = 'a';
    dynamic_array->add_element(*data);
    data->d1 = 2;
    data->d2 = 'b';
    dynamic_array->add_element(*data);
    data->d1 = 3;
    data->d2 = 'c';
    dynamic_array->add_element(*data);
    data->d1 = 4;
    data->d2 = 'd';
    dynamic_array->add_element(*data);
    data->d1 = 5;
    data->d2 = 'e';
    dynamic_array->add_element(*data);
    cout << dynamic_array->display_array(10);
    cout << "----------------------------" << endl;
    cout << dynamic_array->find_element(4) << endl;
    cout << "----------------------------" << endl;
    dynamic_array->delete_all();
    cout << dynamic_array->display_array(10);
    cout << "----------------------------" << endl;
    data->d1 = 12;
    data->d2 = 'a';
    dynamic_array->add_element(*data);
    data->d1 = 3;
    data->d2 = 'b';
    dynamic_array->add_element(*data);
    data->d1 = 7;
    data->d2 = 'c';
    dynamic_array->add_element(*data);
    data->d1 = 4;
    data->d2 = 'd';
    dynamic_array->add_element(*data);
    data->d1 = 1;
    data->d2 = 'e';
    dynamic_array->add_element(*data);
    cout << dynamic_array->display_array(10);
    cout << "----------------------------" << endl;
    data->d1 = 10;
    data->d2 = 'g';
    dynamic_array->swap_data(2, *data);
    cout << dynamic_array->display_array(10);
    cout << "----------------------------" << endl;
    dynamic_array->sort();
    cout << dynamic_array->display_array(10);

    system("pause");
}
