#include <iostream>
using namespace std;
#define STR_ARR_SIZE 2

struct letter{
    char ltr;
    int am;
    string bin;
    letter(){
        bin = "0";
    }
};

int is_present(letter *lt, int lt_size, int check){
    for(int i = 0; i < lt_size; i++){
        if((int)lt[i].ltr == check) return i;
    }
    return -1;
}

letter* arr_sort(letter *lt, int arr_size){
    for(int i = 0; i < arr_size; i++){
        for(int j = i; j > 0; j--){
            if(lt[j-1].am > lt[j].am) {
                swap(lt[j-1].am, lt[j].am);
                swap(lt[j-1].ltr, lt[j].ltr);
            }
        }
    }
    return lt;
}

letter* huffman(letter *lt, int lt_size){
    letter* temp = new letter[lt_size/2];
    for(int i = 0; i < lt_size/2; i++){
        int j = i*2;
        temp[i].am = lt[j].am + lt[j+1].am;
        lt[j].bin.append("0");
        lt[j+1].bin.append("1");
    }
    if(lt_size % 2 != 0){
        huffman(temp, lt_size/2);
    }
}

int main() {

    string input;
    cout << "Input a string" << endl;
    getline(cin, input);

    int lt_size = 1;
    letter *lt = new letter[lt_size];

    lt[0].ltr = input[0];
    lt[0].am = 1;
    for(int i = 1; i < input.size(); i++){
        int curr = (int)input[i];
        int is = is_present(lt, lt_size, curr);
        if(is >= 0){
            lt[is].am++;
        }
        else{
            if(curr != 32) {
                lt_size++;
                letter *lt_tmp = new letter[lt_size];
                for(int j = 0; j < lt_size-1; j++){
                    lt_tmp[j] = lt[j];
                }
                delete[] lt;
                lt = lt_tmp;
                lt[lt_size-1].ltr = (char)curr;
                lt[lt_size-1].am = 1;
            }
        }
    }

    cout << "Count Arr" << endl;
    for(int i = 0; i < STR_ARR_SIZE; i++){
        for(int j = 0; j < lt_size; j++){
            if( i == 0) cout << lt[j].ltr<< " ";
            else cout << lt[j].am << " ";
        }
        cout << endl;
    }
    arr_sort(lt, lt_size);
    cout << "Sorted Array" << endl;
    for(int i = 0; i < STR_ARR_SIZE; i++){
        for(int j = 0; j < lt_size; j++){
            if( i == 0) cout << lt[j].ltr<< " ";
            else cout << lt[j].am << " ";
        }
        cout << endl;
    }

    cout << "ogo" << endl;
    return 0;
}
