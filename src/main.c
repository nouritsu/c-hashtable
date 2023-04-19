#include <stdio.h>

#include "./hash_table.h"

int main(void) {
    HashTable* ht = new_hash_table();
    ht_insert(ht, "Aneesh", "Bhave");
    ht_insert(ht, "Neo", "Fernandes");
    ht_insert(ht, "Manas", "Sathe");
    ht_insert(ht, "Manav", "Singh");
    ht_insert(ht, "Sayee", "Mahajan");

    const char* s = "Manav";
    printf("%s : %s\n", s, ht_search(ht, s));

    delete_hash_table(ht);
    return 0;
}
