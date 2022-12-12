#include <stdio.h>

int main(){
    char st[255];
    char prev = ' ';
    char now;
    int i = 0;
    st[0] = ' ';
    scanf(" %c", &now);
    while (now != '\0'){
        if (now == ' '){
            continue;
        }
        if(prev == ' '){
            prev = now;
            continue;
        }
        if (now == st[i]){
            i--;
            prev = ' ';
        }
        else{
            st[i] = prev;
            prev = now;
            i++;
        }
        scanf("%c", &now);
    }
    for (int j = 0;j < i;j++){
        printf("%c", st[j]);
    }
    return 0;
}
