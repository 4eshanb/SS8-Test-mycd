#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

class HashEntry
{
public:
    HashEntry(std::string key, std::string value);
};

class HashTable
{
private:
    HashEntry **table;

public:
    HashTable();

    int Hash(std::string key);

    void Insert(std::string key);

    std::string Lookup(std::string key);

    void Delete(std::string key);

    void printTable();

    //~HashTable();
};

#endif