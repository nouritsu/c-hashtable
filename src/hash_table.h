#ifndef HASH_MAP_H
#define HASH_MAP_H

#define HT_BASE_CAPACITY 53  // Prime number to reduce collisions
#define HT_PRIME1 151
#define HT_PRIME2 163
#define HT_UPSIZE_LOAD 70
#define HT_DOWNSIZE_LOAD 10

typedef struct {
    char *key, *value;
} HashItem;

typedef struct {
    int capacity, base_capacity, size;
    HashItem** items;
} HashTable;

HashTable* new_hash_table();
void ht_insert(HashTable* ht, const char* k, const char* v);
char* ht_search(HashTable* ht, const char* k);
void ht_delete(HashTable* ht, const char* k);
void ht_print(HashTable* ht, const int show_empty);
void delete_hash_table(HashTable* ht);

#endif
