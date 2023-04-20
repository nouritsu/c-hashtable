# About
A simple string:string HashTable implementation in C.  
Made it by following this [guide](https://github.com/jamesroutley/write-a-hash-table), helped me better understand how hash tables and hash functions work.  
Not intended for professional use.

# Usage
## In your project
To use, download the repository and copy all files except main.c from src over to your project directory.  
Then include hash_table.h in your project and that's it!  

## Just to test
Download repository, run build.py using Python 3.XX to run build script  
Executable will be in `<repository>/bin`
Build and run -
```
python build.py run
```
Just build -
```
python build.py
```
Done!



# Complexities
## Time
| Operation 	| Best 	| Worst 	| Average 	|
|:---------:	|:----:	|:-----:	|:-------:	|
|   Access  	|  N/A 	|  N/A  	|   N/A   	|
|   Insert  	| Ω(1) 	|  O(n) 	|   Θ(1)  	|
|   Search  	| Ω(1) 	|  O(n) 	|   Θ(1)  	|
|   Delete  	| Ω(1) 	|  O(n) 	|   Θ(1)  	|

## Space
Worst Case - O(n)

# API Guide
## Functions (in hash_table.h)
|   Function Name   	|                              Description                              	|                   Parameters                   	|   Returns   	|
|:-----------------:	|:---------------------------------------------------------------------:	|:----------------------------------------------:	|:-----------:	|
|   new_hash_table  	|              Create a new HashTable struct (constructor)              	|                     (none)                     	| HashTable\* 	|
|     ht_insert     	|           Insert a key(k) value(v) pair into a HashTable(ht)          	| HashTable\* ht, const char\* k, const char\* v 	|    (none)   	|
|     ht_search     	| Search for a key(k) in a HashTable(ht), returns value at key if found 	|         HashTable\* ht, const char\* k         	|   (char*)   	|
|     ht_delete     	|                 Delete item at key(k) in HashTable(ht)                	|         HashTable\* ht, const char\* k         	|    (none)   	|
|      ht_print     	|  Print HashTable(ht), boolean value show_empty to show empty indices  	|      HashTable\* ht, const int show_empty      	|    (none)   	|
| delete_hash_table 	|             Destroy an existing HashTable(ht) (destructor)            	|                 HashTable\* ht                 	|    (none)   	|

## Constants (in hash_table.h)
|   Constant Name  	|                                            Description                                           	|
|:----------------:	|:------------------------------------------------------------------------------------------------:	|
| HT_BASE_CAPACITY 	|                      Internal array is initialized to size HT_BASE_CAPACITY.                     	|
|  HT_UPSIZE_LOAD  	|  Percentage value. After internal array is more than HT_UPSIZE_LOAD% full, table will be upsized 	|
| HT_DOWNSIZE_LOAD 	| Percent value. After internal array is less than HT_DOWNSIZE_LOAD% full, table will be downsized 	|

# Known Issues
* When deleting an item that does not exist in the table, the delete function will search through the entire internal array for item due to collision handling method.
