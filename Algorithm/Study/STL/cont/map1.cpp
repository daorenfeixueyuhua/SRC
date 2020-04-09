#include <bits/stdc++.h>

using namespace std;

int main()
{
    typedef map<string, float> StringFloatMap;
    StringFloatMap stocks;
    // insert some elements
    stocks["BASF"] = 369.50;
    stocks["VM"] = 431.50;
    stocks["Daimler"] = 819.00;
    stocks["BMW"] = 834.00;
    stocks["Siemenks"] = 842.20;
    // print all elements
    StringFloatMap::iterator pos;
    for (pos = stocks.begin(); pos != stocks.end(); pos++)
    {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;

    // boom (all prices doubled)
    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        pos->second *= 2;
    }

    // print all elements
    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;

    /* rename key from "VW" to "Volkswagen"
     * - only provided by exchanging element
     */
    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");

    // print all elements
    for (pos = stocks.begin(); pos != stocks.end(); ++pos)
    {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    return 0;
}