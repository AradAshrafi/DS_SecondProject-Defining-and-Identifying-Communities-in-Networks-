class Cij {
public:
    int i;
    int j;
    double data;
    Cij() {
        data = 0;
    }
};

void swap(Cij &a, Cij &b) {
    Cij temp;
    temp = b;
    b = a;
    a = temp;
}