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
        if (i < num_of_elements) {
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
        bool flag;
        for (int i = 0; i < num_of_elements - 1; i++) {
            flag = 0;
            for (int j = 0; j < num_of_elements - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                    flag = 1;
                }
            }
            if (!flag) break;
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
            output << *&array[i] << endl;
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
    
    const int order = 7;
    const int n = pow(10, order);

    clock_t t1 = clock();
    double max_time_per_element = 0.0;
    double sum_of_max_times = 0.0;
    int num_of_max_times = 0;

    for (int i = 0; i < n; i++) {
        
        data->d1 = rand() % 1000;
        data->d2 = 'a' + rand() % 26;

        clock_t t1_element = clock();
        dynamic_array->add_element(*data);
        clock_t t2_element = clock();
        double time_per_element = (t2_element - t1_element) / (double)CLOCKS_PER_SEC;
            if (time_per_element > max_time_per_element) {
                max_time_per_element = time_per_element;
                num_of_max_times++;
                sum_of_max_times = sum_of_max_times + max_time_per_element;
                cout << "================================================" << endl;
                cout << "Nowy najgorszy czas na indeksie: " << i << endl;
                cout << "Czas: " << max_time_per_element << endl;
                cout << "================================================" << endl;
            }
    }
    clock_t t2 = clock();

    double time = (t2 - t1) / (double)CLOCKS_PER_SEC;

    cout << "\n\n" << "================================================" << endl;
    cout << dynamic_array->display_array();
    cout << "---------------------------------------------" << endl;
    cout << "Czas calkowity: " << time << endl;
    cout << "Czas amortyzowany: " << sum_of_max_times / num_of_max_times << endl;
    cout << "================================================" << endl;

    delete data;
    delete dynamic_array;
    system("pause");
}
