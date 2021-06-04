#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
#include "hashtable.h"
using namespace std;

bool checkArgInHash(HashTable table, string arg)
{
    if (table.Lookup(arg) == "-1")
    {
        return false;
    }
    return true;
}

bool checkIsAlnum(char *dir)
{
    for (int i = 0; i < strlen(dir); i++)
    {
        if (!isalnum(dir[i]))
        {
            return false;
        }
    }
    return true;
}

string processNewPath(HashTable table, char *path)
{
    string ret_path = "";
    string copy = string(path);
    char *token = strtok(path, "/");

    while (token != NULL)
    {
        if (!checkIsAlnum(token))
        {
            if (strcmp(token, "..") == 0 || strcmp(token, ".") == 0)
            {
                if (strcmp(token, "..") == 0 && ret_path != "/")
                {
                    for (int i = 0; i <= strlen(token) + 1; i++)
                    {
                        if (ret_path == "/")
                            break;
                        ret_path.pop_back();
                    }
                }
                token = strtok(NULL, "/");
                continue;
            }
            copy.append(": No such file or directory");
            return copy;
        }
        ret_path.append("/");
        ret_path.append(token);
        token = strtok(NULL, "/");
    }

    if (!checkArgInHash(table, ret_path))
    {
        copy.append(": No such file or directory");
        return copy;
    }
    if (ret_path == "")
        ret_path.append("/");

    return ret_path;
}

string printPath(HashTable table, string curr_path, string new_path)
{

    char new_path_cstr[new_path.size() + 1];
    strcpy(new_path_cstr, new_path.c_str());

    if (new_path_cstr[0] == '/')
    {
        return processNewPath(table, new_path_cstr);
    }

    char *token = strtok(new_path_cstr, "/");

    while (token != NULL)
    {
        if (!checkIsAlnum(token))
        {
            if (strcmp(token, "..") == 0 || strcmp(token, ".") == 0)
            {
                if (strcmp(token, "..") == 0 && curr_path != "/")
                {
                    for (int i = 0; i <= strlen(token) + 1; i++)
                    {
                        if (curr_path == "/")
                            break;
                        curr_path.pop_back();
                    }
                }
                token = strtok(NULL, "/");
                continue;
            }
            new_path.append(": No such file or directory");
            return new_path;
        }

        if (curr_path != "/")
            curr_path.append("/");
        curr_path.append(token);
        token = strtok(NULL, "/");
    }

    if (!checkArgInHash(table, curr_path))
    {
        curr_path.append(": No such file or directory");
        return curr_path;
    }

    return curr_path;
}

int main()
{
    string line;
    HashTable table;
    std::ifstream file;
    file.open("../directories.txt");
    while (getline(file, line))
        table.Insert(line);
    file.close();

    bool cond = true;
    string command;
    string arg1;
    string arg2;

    while (cond)
    {
        cout << "# ";
        cin >> command;
        cin >> arg1;
        cin >> arg2;
        if (command != "mycd")
        {
            cout << "please use command mycd" << endl
                 << endl;
            command.clear();
            arg1.clear();
            arg2.clear();
            continue;
        }

        if (!checkArgInHash(table, arg1))
        {
            cout << "first argument not valid" << endl;
            cout << "here are directories: ";
            table.printTable();
            cout << endl;

            command.clear();
            arg1.clear();
            arg2.clear();

            continue;
        }

        cout << printPath(table, arg1, arg2) << endl;

        command.clear();
        arg1.clear();
        arg2.clear();

        cout << endl;
    }
    return 0;
}