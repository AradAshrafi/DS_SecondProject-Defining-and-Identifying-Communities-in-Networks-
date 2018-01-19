void insertionSort(Cij* arr, int n)
{
    int i, j;
    Cij key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        //move it to find it's place
        while (j >= 0 && arr[j].data > key.data)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}