#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

void Delete_arr(int***& arr, int& size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            delete[]arr[i][j];
        }
    }
    for (int i = 0; i < size; i++)
    {
        delete[]arr[i];
    }
    delete[] arr;
}
void print(int***& arr, int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Mass " << i << ": ";
        for (int j = 0; j < size; j++)
        {
            cout << "Mass " << j << ": ";
            for (int k = 0; k < size; k++)
            {
                cout << "Mass (" << k << "): ";
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}
void CIN(int***& arr, int& size)
{
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int* [size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = new int[size];
        }
    }

    for (int z = 0; z < size; z++)
    {
        for (int y = 0; y < size; y++)
        {
            for (int x = 0; x < size; x++)
            {
                arr[z][y][x] = count;
                count++;
            }
        }
    }
}
void add(int***& arr, int& size)
{
    int*** tmp = new int** [size];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = new int* [size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            tmp[i][j] = new int[size];
        }
    }
    for (int z = 0; z < size; z++)
    {
        for (int y = 0; y < size; y++)
        {
            for (int x = 0; x < size; x++)
            {
                tmp[z][y][x] = arr[z][y][x];
            }
        }
    }
    Delete_arr(arr, size);
    size = 5;
    arr = new int** [size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new int* [size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = new int[size];
        }
    }
    for (int z = 0; z < size; z++)
    {
        for (int y = 0; y < size; y++)
        {
            for (int x = 0; x < size; x++)
            {
                if ((x < size - 2) && (z < size - 2) && (y < size - 2))
                {
                    arr[z][y][x] = tmp[z][y][x];
                }
                else
                {
                    arr[z][y][x] = rand() % 55;
                }
            }
        }
    }

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = 0; j < size - 2; j++)
        {
            delete[]tmp[i][j];
        }
    }
    for (int i = 0; i < size - 2; i++)
    {
        delete[]tmp[i];
    }
    delete[]tmp;
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int size = 3;
    int*** arr = new int** [size];
    CIN(arr, size);
    print(arr, size);
    add(arr, size);
    cout << endl;
    print(arr, size);
    Delete_arr(arr, size);
    return 0;
}