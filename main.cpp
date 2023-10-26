#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ifstream f("C:\\Users\\jjosh\\Downloads\\trees.txt");
    string tid, addr;
    int i;

    map<string, string> idmap;
    map<string, string> addrmap;

    if (!f.good())
    {
        cerr << "Bad file" << endl;
        return -1;
    }

    /// load the map
    while (true)
    {
        getline(f, tid);
        if (f.eof())
            break;

        getline(f, addr);

        /// insert into maps here
        idmap.insert(make_pair(tid, addr));
        addrmap.insert(make_pair(addr, tid));
    }

    //cout << "idmap contains " << idmap.size() << " entries." << endl;
    //cout << "addrmap contains " << addrmap.size() << " entries." << endl;
    //cout << "The value associated with 35445 is: " << idmap["35445"] << endl;

    while (i != 3) {
        cout << "Menu: " << endl
            << "1. Find tree address by ID." << endl
            << "2. Find tree ID by address." << endl
            << "3. Exit." << endl;
        cin >> i;
        cout << "Your choice: " << i << endl;

        if (i == 1)
        {
            cout << "Enter the tree ID: ";
            cin >> tid;
            if (idmap[tid].empty())
                cout << "Invalid entry, not found." << endl << endl;
            else
                cout << "The address of this tree is: " << idmap[tid] << endl << endl;
        }
        else if (i == 2)
        {
            cout << "Enter the address: ";
            cin.ignore();
            getline(cin, addr);
            if (addrmap[addr].empty())
                cout << "Invalid entry, not found." << endl << endl;
            else
                cout << "The ID of this tree is: " << addrmap[addr] << endl << endl;
        }
    }
    if (i == 3)
    {
        cout << "Exiting..." << endl;
        return 0;
    }
    return 0;
}
