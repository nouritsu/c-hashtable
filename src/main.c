#include <stdio.h>

#include "./hash_table.h"
#include "./prime.h"

int main(void) {
    HashTable* ht = new_hash_table();
    ht_insert(ht, "Aneesh", "Bhave");
    ht_print(ht, 1);
    ht_insert(ht, "Neo", "Fernandes");
    ht_print(ht, 1);
    ht_insert(ht, "Manas", "Sathe");
    ht_print(ht, 1);
    ht_insert(ht, "Manav", "Singh");
    ht_print(ht, 1);
    ht_insert(ht, "Sayee", "Mahajan");
    ht_print(ht, 1);
    ht_insert(ht, "Archis", "Bhave");
    ht_print(ht, 1);
    ht_insert(ht, "Sabreen", "Bhave");
    ht_print(ht, 1);

    delete_hash_table(ht);
    return 0;
}
