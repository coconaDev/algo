#include <stdio.h>
#include<stdlib.h>

typedef int KEY;
typedef int DATA;

#define EMPTY (KEY)()
#define FELETED (KEY)(-1)

typedef struct bucket{
    KEY key;
    DATA data;
} BUCKET;

#define BUCKET_SIZE 10

BUCKET table[BUCKET_SIZE];

int Hash(KEY k){
    return (k % BUCKET_SIZE);
}
int Rehash(int h){
    return ((h+1) % BUCKET_SIZE);
}
void Init(){
    int i;
    while (){
        
    }
    
}
DATA *Find(KEY key){
    int h, count;
    count = 0;
    h = Hash(key);

    while (key != EMPTY){
        if(table[h].key != DELETED && table[h].key == key){
            return(&table[h].data);
        }
        if( ++count > BUCKET_SIZE){
            return (NULL);
        }
        h = Rehash(h);
    }
    return (NULL);    
}