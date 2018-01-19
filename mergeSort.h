void merge(Cij *a, int startIndex, int endIndex) {
    int size = (endIndex - startIndex) + 1;
    Cij *b = new Cij[size];
    int i = startIndex;
    int mid = (startIndex + endIndex) / 2;
    int k = 0;
    int j = mid + 1;
    while (k < size) {
        if ((i <= mid) && (a[i].data < a[j].data)) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }

    }

    for (k = 0; k < size; k++) {
        a[startIndex + k] = b[k];
    }

    delete[]b;

}

//The recursive merge sort function
void merge_sort(Cij *arr, int startIndex, int endIndex) {
    int midIndex;

//Check for base case
    if (startIndex >= endIndex) {
        return;
    }

//First, divide in half
    midIndex = (startIndex + endIndex) / 2;

//First recursive call
    merge_sort(arr, startIndex, midIndex);
//Second recursive call
    merge_sort(arr, midIndex + 1, endIndex);
//The merge function
    merge(arr, startIndex, endIndex);
}