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
void ht_insert(HashTable*, const char*, const char*);
char* ht_search(HashTable*, const char*);
void ht_delete(HashTable*, const char*);
void ht_print(HashTable*, const int);
void delete_hash_table(HashTable*);
