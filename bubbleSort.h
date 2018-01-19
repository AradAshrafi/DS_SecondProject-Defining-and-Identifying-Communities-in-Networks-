void bubbleSort(Cij *arr, int n) {
    int i, j;
//    bool flag=1;
    for (i = 0; i < n - 1; i++)
//        flag=0;
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].data > arr[j + 1].data) {
                swap(arr[j], arr[j + 1]);
//                flag=1;
            }
}