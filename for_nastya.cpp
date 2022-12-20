#include <stdio.h>

void sort(int *arr, int n, int m){
    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++){
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int temp;
    for(int _ = 0; _ < m; _++){ // ...M раз повторяется процесс...
        // переменная не используется, поэтому название "_" норм
        for (int i = 0 ; i < n; i++){ 
           int j = ((arr[i] - min) * (n - 1) / (max - min)); // формула из задания
           int NOWYOUSEE = arr[i];
           if (i > j && arr[i] > arr[j]){ // элемент i меняется с элементом j если надо
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
           }
           else if (arr[i] < arr[j]){ // элемент i меняется с элементом j если надо (тут i < j, значит надо чтобы arr[i] < arr[j])
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
           }
        }
    }
    int count = 0;
    int correct = 0;
    for (int i = 0; i < n; i++){ // досортировываем пузырьком
        for (int j = 0; j < n - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;  // смысл этого всего - улучшить пузырек => хотим узнать насколько лучше стало
            }
            else correct++; // считаем какая часть массива отсортирована
            if (correct == n){ //если масиив весь отсортирован - выходим
                break;
            }
        }
        if (correct == n){
            break;
        }
        correct = 0;
    }
    printf("%d \n", count); //перед каждым выводом массива пишем сколько раз пузырек поменял чиста местами(он сложности n^2 => мы ходим быстрее чем n^2)
}

int main(){
    int arr[] = {21, 75, 22, 95, 68, 20, 50, 51, 58, 32};
    sort(arr, 10, 5);
    for (int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    int arr1[] = {85, 56, 97, 20, 69, 80, 62, 18, 60, 39};
    sort(arr1, 10, 6);
    for (int i = 0; i < 10; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");
    int arr2[] = {88, 19, 64, 20, 21, 92, 70, 37, 3, 96};
    sort(arr2, 10, 8);
    for (int i = 0; i < 10; i++){
        printf("%d ", arr2[i]);
    }
}
