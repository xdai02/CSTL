#include "cino.h"
int main(){
    str_t s="abcd";
    int k=2;
    int length=str_length(s);
    int copy_length=str_length(s);
    char result[length+1];
    str_clear(result, sizeof(result));
    int i=0;
    char substring[2*k];
    while(length-2*k>=0){
        str_substring(s, i*2*k, i*2*k+k-1, substring, sizeof(substring));
        str_reverse(substring);
        str_concat(result, substring);
        str_substring(s, i*2*k+k, i*2*k+k+k-1, substring, sizeof(substring));
        str_concat(result, substring);
        i++;
        length-=2*k;
    }
    if(length<k&&length>0){
        str_substring(s, i*2*k, copy_length-1, substring, sizeof(substring));
        str_reverse(substring);
        str_concat(result, substring);
    }
    else if(length>=k){
        str_substring(s, i*2*k, i*2*k+k-1, substring, sizeof(substring));
        str_reverse(substring);
        str_concat(result, substring);
        str_substring(s, i*2*k+k, i*2*k+k+k-1, substring, sizeof(substring));
        str_concat(result, substring);
    }
    printf("%s",result);
}