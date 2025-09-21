#include <fstream>
#include <iostream>
#include <cstring> 

void warn() {
    std::cout << "error!" << std::endl;
}

void mask(int a[52], char *st){
    for (int i = 0; i < 52; i++){
        a[i] = 0;
    }
    for (int i = 0; i < std::strlen(st); i++){
        if (st[i] >= 'a' && st[i] <='z'){
            a[(int)st[i] - 'a'] = 1;
        } else{
            a[(int)st[i] - 'A' + 26] = 1;
        }
    }
}

int main(int argc, char** argv) {
    if (strcmp(argv[3], "--file") != 0) {
        warn();
        return 1;
    }
    if (strcmp(argv[1], "--word") != 0) {
        warn();
        return 1;
    }
    char* str = argv[2];
    //
    std::ifstream fin(argv[4]);
    //
    char wrd[1000];
    int msk_str[52];
    mask(msk_str, str);
    int su = 0;
    while (fin >> wrd) {
        int msk_wrd[52];
        mask(msk_wrd, wrd);
        int fl = 1;
        for (int i = 0; i < 52; i++) {
            if (msk_wrd[i] < msk_str[i]) {
                fl = 0;
            }
        }
        su += fl;
    }
    std::cout << su << std::endl;
    return 0;
}
