#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    string data;
};

int main() {

    ifstream infile("inlet.in");
    ofstream outfile("outlet.out", ios::binary);

    vector<string> dataList;
    vector<int> randIndex;

    string line;
    while (getline(infile, line)) {
        size_t pos = line.find(';');

        string data = line.substr(0, pos);
        int rindex = stoi(line.substr(pos + 1));

        dataList.push_back(data);
        randIndex.push_back(rindex);
    }

    int n = dataList.size();
    vector<ListNode*> nodes(n);

    for (int i = 0; i < n; i++) {
        nodes[i] = new ListNode();
        nodes[i]->data = dataList[i];
    }

    // -------- SET PREV AND NEXT --------
    for (int i = 0; i < n; i++) {

        if (i > 0)
            nodes[i]->prev = nodes[i - 1];

        if (i < n - 1)
            nodes[i]->next = nodes[i + 1];
    }
    for (int i = 0; i < n; i++) {

        if (randIndex[i] != -1)
            nodes[i]->rand = nodes[randIndex[i]];
    }

    ListNode* head = (n > 0) ? nodes[0] : nullptr;

    outfile.write((char*)&n, sizeof(n));

    for (int i = 0; i < n; i++) {

        int len = nodes[i]->data.size();

        outfile.write((char*)&len, sizeof(len));
        outfile.write(nodes[i]->data.c_str(), len);

        int rindex = randIndex[i];
        outfile.write((char*)&rindex, sizeof(rindex));
    }

    infile.close();
    outfile.close();

    return 0;
}
