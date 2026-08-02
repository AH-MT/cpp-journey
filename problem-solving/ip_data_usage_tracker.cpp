/*
    Title: Network Data Usage Aggregator

    Problem:
    Write a C++ program that reads network traffic log entries.
    Each entry contains an IP address and its data usage.

    Since an IP address may appear multiple times, the program:
    1. Stores the original entries in an unordered_multimap.
    2. Calculates the total data usage for each unique IP address.
    3. Stores the final result in a map, so the output is sorted
       lexicographically by IP address.

    Input Format:
    - The first line contains an integer n, representing the number of log entries.
    - The next n lines contain:
        <IP_Address> <Data_Usage>

    Output Format:
    - Each unique IP address followed by its total data usage,
      sorted by IP address.

    Example Input:
    3
    1.2.3.4 2
    1.3 4
    1.2.3.4 5
    Example Output:
    1.2.3.4 7
    1.3 4
*/
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_multimap<string, int> info;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string ip;
        int dataUsage;

        cin >> ip >> dataUsage;
        info.insert({ip, dataUsage});
    }
    map<string, int> finalInfo;

    while (!info.empty()) {
        auto firstIp = info.begin();
        string currentIp = firstIp->first;
        auto range = info.equal_range(currentIp);
        int totalUsage = 0;


        for (auto it = range.first; it != range.second; ++it) {
            totalUsage += it->second;
        }
        finalInfo.insert({currentIp, totalUsage});
        info.erase(currentIp);
    }

    for (const auto& pair : finalInfo) {
        cout << pair.first << " " << pair.second << endl;
    }
    return 0;
}








