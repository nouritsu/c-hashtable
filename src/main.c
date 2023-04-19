#include <stdio.h>

#include "./hash_table.h"

int main(void) {
    HashTable* ht = new_hash_table();
    delete_hash_table(ht);
    return 0;
}
