#include <stdio.h>

#include "./hash_table.h"
#include "./prime.h"

int main(void) {
    puts("-------------------- HashTable Test --------------------");

    puts("> Creating new HashTable!");
    HashTable* ht = new_hash_table();
    puts("> Successfully created new HashTable!\n");

    puts("> Inserting 9 { Company Names : Stock Symbol } pairs");
    ht_insert(ht, "Apple", "APPL");
    ht_insert(ht, "Microsoft", "MSFT");
    ht_insert(ht, "Alphabet", "GOOG");
    ht_insert(ht, "Amazon", "AMZN");
    ht_insert(ht, "Hathaway", "BRK.A");
    ht_insert(ht, "Nvidia", "NVDA");
    ht_insert(ht, "Tesla", "TSLA");
    ht_insert(ht, "Meta", "META");
    ht_insert(ht, "Visa", "V");
    puts("> Successfully Inserted 9 Key-Value pairs\n");

    puts("> Printing HashTable");
    ht_print(ht, 0);
    puts("> Sucessfully printed HashTable\n");

    puts("> Deleting keys Visa and Microsoft from HashTable");
    ht_delete(ht, "Visa");
    ht_delete(ht, "Microsoft");
    puts("> Successfully deleted keys\n");

    puts("> Printing HashTable");
    ht_print(ht, 0);
    puts("> Successfully printed HashTable\n");

    puts("> Deleting HashTable");
    delete_hash_table(ht);
    puts("> Successfully deleted HashTable");

    puts("--------------------------------------------------------");
    return 0;
}
