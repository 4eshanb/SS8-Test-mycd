#include <iostream>
#include <string>
using namespace std;

#define TABLE_SIZE 1024

class HashEntry
{
public:
    int key;
    string value;
    HashEntry(int key, string value);
};

class HashTable
{
private:
    HashEntry **table;

public:
    HashTable();

    int Hash(string key);

    void Insert(string key);

    string Lookup(string key);

    void Delete(string key);

    void printTable();

    //~HashTable();
};

HashEntry::HashEntry(int key, string value)
{
    this->key = key;
    this->value = value;
}

HashTable::HashTable()
{
    table = new HashEntry *[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = NULL;
    }
}

int HashTable::Hash(string key)
{
    int sum = 0;
    for (int i = 0; i < key.size(); i++)
    {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

void HashTable::Insert(string key)
{
    int hash_value = Hash(key);
    if (table[hash_value] != NULL)
        delete table[hash_value];
    table[hash_value] = new HashEntry(hash_value, key);
}

string HashTable::Lookup(string key)
{
    int hash_value = Hash(key);
    if (table[hash_value] == NULL)
    {
        cout << "No value found" << endl;
        return "-1";
    }
    else if (table[hash_value]->value != key)
    {
        cout << "No value found" << endl;
        return "-1";
    }
    return table[hash_value]->value;
}

void HashTable::Delete(string key)
{
    int hash_value = Hash(key);
    if (table[hash_value] == NULL)
    {
        cout << "Element not in hash table" << endl;
        return;
    }
    else
    {
        delete table[hash_value];
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL)
        {
            cout << table[i]->value << endl;
        }
    }
}

/*HashTable::~HashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] != NULL)
            delete table[i];
        delete[] table;
    }
}*/

/*int main()
{
    HashTable table;
    table.Insert("aaaaa", "ting");
    table.Insert("bbbbb", "bling");
    table.Insert("ccccc", "sting");

    table.Lookup("aaaaa");
    table.Lookup("bbbbb");
    table.Lookup("ccccc");

    table.printTable();

    table.Delete("aaaaa");
    table.printTable();

    table.Delete("bbbbb");
    table.printTable();

    table.Delete("ccccc");
    table.printTable();

    table.Delete("aaaaa");
    table.Lookup("aaaaa");
}*/