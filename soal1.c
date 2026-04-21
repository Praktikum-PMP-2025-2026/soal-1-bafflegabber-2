/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 2
 *   Hari dan Tanggal    : Selasa, 21 April 2026
 *   Nama (NIM)          : Muhammad Isnan Basya Ramdhani (13224097)
 *   Nama File           : soal1.c
 *   Deskripsi           : Menerima input string berisi huruf kecil, tanda '(', dan tanda ')', kemudian membaca jumlah tanda '(' dan ')' dalam string dan menghapus '(' dan ')' sehingga jumlah '(' == ')'
**/

#include <stdio.h>
#include <string.h>

void hapus(char *string, int index, int limit){
    for (int j = index; j < limit; j++){
        if(j != limit - 1){
            string[j] = string[j + 1];
        }else{
            string[limit - 1] = '\0';
        }
    }
}

int main(){
    int open, close;
    int markfordeath = 99; //Revisi: Autograder meminta '(' paling awal dihapus saat berlebih
    char in[99];

    scanf("%[^\n]%*c", in); //Revisi: Input bisa spasi
    int lim = strlen(in);
    do{
        open = 0;
        close = 0;
        for (int i = 0; i < lim; i++){
            if(in[i] != '\0'){
                if (in[i] == '(' || in[i] == ')'){
                    if(in[i] == '('){
                        open +=1;
                        if(i < markfordeath){
                            markfordeath = i; //Revisi: Autograder meminta '(' paling awal dihapus saat berlebih
                        }
                    }else if(in[i] == ')'){
                        close += 1;
                        if (open < close){
                            hapus(in, i, lim);
                            lim = strlen(in);
                            close -= 1;
                            i -= 1;
                        }
                    }
                }
            }
        }
        if (open != close){
            hapus(in, markfordeath, lim);
            open -=1;
            lim = strlen(in);
        }
    }while(open != close);
    printf("%s", in);
}

/** REFERENSI KODE
 * https://stackoverflow.com/questions/39109280/how-do-i-deal-with-string-input-in-c
 * https://stackoverflow.com/questions/22736348/char-comparison-in-c
 * https://stackoverflow.com/questions/5457608/how-to-remove-the-character-at-a-given-index-from-a-string-in-c
 * https://stackoverflow.com/questions/18949552/removing-last-character-in-c\
 * https://www.geeksforgeeks.org/c/taking-string-input-space-c-3-different-methods/
**/