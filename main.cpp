#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;

//Можно создавать любое количество любых вспомогательных классов, структур и методов для решения задачи.

void heapify (int *arr, int array_size, int current)
{
    int max = current, left = current * 2 + 1, right = current * 2 + 2;

    if (right < array_size && arr[right] > arr[max])
        max = right;

    if (left < array_size && arr[left] > arr[max])
        max = left;

    if (max != current)
    {
        swap(arr[current], arr[max]);

        heapify(arr, array_size, max);
    }
}

void buildHeap(int *arr, int array_size)
{
    for (int i = array_size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, array_size, i);
    }
}

//Функция сортировки на куче
//Необходимо реализовать данную функцию.
//Результат должен быть в массиве numbers.
void heapSort(int *numbers, int array_size)
{
    buildHeap(numbers, array_size);

    for (int i = array_size - 1; i >=0; i--)
    {
        swap(numbers[0], numbers[i]);
        heapify(numbers, i, 0);
    }
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    heapSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}