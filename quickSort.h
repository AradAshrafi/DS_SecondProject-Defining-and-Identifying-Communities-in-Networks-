void quickSort(Cij* arr, int left,int right) {


    int i = left, j = right;

    Cij tmp;

    Cij pivot = arr[(left + right) / 2];


    while (i <= j) {

        while (arr[i].data < pivot.data)

            i++;

        while (arr[j].data > pivot.data)

            j--;

        if (i <= j) {

            tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

            i++;

            j--;

        }

    };

    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);
}