#include <iostream>
#include <random>
#include <ctime>
#include <vector>
using namespace std;

// Random number generator
unsigned int seed = time(NULL);
mt19937 engine(seed);
uniform_int_distribution<int> randomInt(1, 100);

vector<int> generateVector(int size)
{
    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        v.push_back(randomInt(engine));
    }
    return v;
}

void insertionSort(vector<int>& a, int n)
{
    for (int i = 1; i <= n; ++i) {
        int key = a[i];
        // Insert a[i] into the sorted sequence a[1..i-1]
        int j = i - 1;
        while (j > 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
    }
}

int main()
{
    int size;
    cin >> size;
    vector<int> v = generateVector(size + 1);
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    insertionSort(v, v.size() - 1);
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}