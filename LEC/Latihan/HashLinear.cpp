#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxSize = 26;

struct data{
    char name[100];
    int age;
};

struct data *dataArr[maxSize];

int hashFunc(const char name[]){
    int first = name[0];
    int last = name[strlen(name)-1];
    int res = (first + last) % maxSize;
    return res;
}

void insert(const char name[], int age){
    struct data *temp = (struct data*)malloc(sizeof(data));
    strcpy(temp->name, name);
    temp->age = age;

    int idx = hashFunc(name);
    if (dataArr[idx] == 0){
        dataArr[idx] = temp;
    } else {
        int currIdx = idx + 1;
        while (dataArr[currIdx] != NULL){
            currIdx++;
            if (currIdx >= idx){
                currIdx = 0;
            }
            
            if (currIdx == idx){
                break;;
            }
        }
        if (currIdx == idx) printf("The array is full\n");
        else
        dataArr[currIdx] = temp;
    }
}

void display(){
    for (int i = 0; i < maxSize; i++){
        if (dataArr[i] != NULL){
            printf("%s - %d\n", dataArr[i]->name, dataArr[i]->age);
        }
    }
}

int main(){
    insert("Jason", 20);
    insert("Aryo", 21);
    insert("Budi", 22);
    insert("Michael", 23);
    insert("Nelson", 24);
    insert("Cantik", 25);
    display();
}