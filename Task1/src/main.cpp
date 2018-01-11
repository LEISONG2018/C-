#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>


template<typename T> void swap_function(std::vector<T>& A, std::vector<T>& B)
{
	using namespace std;
	vector<T> tmp = A;
	A = B;
	B = tmp;
}

/*void swap_function(std::vector<double>& A, std::vector<double>& B)
{
    using namespace std;

    vector<double> tmp = A;
    A = B;
    B = tmp;
}*/

int main()
{
    using namespace std;

    vector<double> data_set_A(1000000);
    vector<double> data_set_B(1000000);

    vector<float> data_set_C(1000000);
    vector<float> data_set_D(1000000);

    fill(data_set_A.begin(), data_set_A.end(), 1.0);
    fill(data_set_B.begin(), data_set_B.end(), 2.0);

    fill(data_set_C.begin(), data_set_C.end(), 3.0);
    fill(data_set_D.begin(), data_set_D.end(), 4.0);

    auto start = chrono::system_clock::now();
    for (int i = 0; i < 50; i++) {
        swap_function(data_set_A, data_set_B);
    }
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "Time used by swap_function(data_set_A, data_set_B): " << elapsed_seconds.count() << "s" << endl;

    start = chrono::system_clock::now();
    for (int i = 0; i < 50; i++) {
        swap_function(data_set_C, data_set_D);
    }
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Time used by swap_function(data_set_C, data_set_D): " << elapsed_seconds.count() << "s" << endl;

    cin.ignore();

    return 0;
}
