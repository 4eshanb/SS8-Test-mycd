def process_path(table, curr_path, new_path):
    filtered_ls = filter(None, new_path.split('/'))
    res_path = ""
    for dir in filtered_ls:
        if dir == "..":
            for i in range(len(dir) + 2):
                if (curr_path == "/"):
                    break
                curr_path = curr_path[:-1]

        elif dir == '.':
            continue

        elif not dir.isalnum():
            return new_path + ": No such file or directory"

        else:
            if new_path[0] == "/":
                res_path += "/" + dir
            elif curr_path != "/":
                curr_path += "/" + dir
            elif curr_path == "/":
                curr_path += dir

    res_path = curr_path

    if hash(res_path) not in table:
        return res_path + ": No such file or directory"

    return res_path


def main():
    table = {}
    file = open("../directories.txt", "r")
    for line in file:
        line = line.strip('\n')
        table[hash(line)] = line

    while(True):
        inp = input("# ")
        command, arg1, arg2 = inp.split(" ")
        if command != "mycd":
            print("Use mycd command\n")
            continue

        if hash(arg1) not in table:
            print("first argument not valid")
            print("here are the directories:")
            for i in table:
                print(table[i])
            continue

        print(process_path(table, arg1, arg2) + "\n")


if __name__ == "__main__":
    main()
