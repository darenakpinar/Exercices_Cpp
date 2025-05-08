#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
using namespace std;

int main() {
    // 1. Console I/O: customer order with spaces
    cout << "Enter order description (e.g., '2x Widget, express'): ";
    string order;
    getline(cin, order);
    cout << "Order received: " << order << "\n\n";

    // 2. File I/O: append to log file and read last entries
    {
        ofstream logf("app.log", ios::app);
        time_t now = time(nullptr);
        logf << put_time(localtime(&now), "%Y-%m-%d %H:%M:%S")
             << " - " << order << '\n';
    }
    vector<string> lines;
    {
        ifstream logfr("app.log");
        string line;
        while (getline(logfr, line)) lines.push_back(line);
    }
    cout << "Last 2 log entries:" << endl;
    for (int i = max(0, (int)lines.size() - 2); i < (int)lines.size(); ++i)
        cout << "  " << lines[i] << endl;
    cout << "\n";

    // 3. String stream: parse product CSV
    string csv = "1001,Widget,19.99";
    istringstream ss(csv);
    string id, name, priceStr;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, priceStr, ',');
    double price = stod(priceStr);
    cout << "Parsed CSV -> ID: " << id
         << ", Name: " << name
         << ", Price: $" << fixed << setprecision(2) << price << "\n\n";

    // 4. peek() and putback(): simple sum parser
    cout << "Enter sum (e.g., 12+34): ";
    char c = cin.peek();                  // inspect next char without extracting
    if (isdigit(static_cast<unsigned char>(c))) {
        int a, b;
        cin >> a;
        cin >> c; // consume '+'
        cin >> b;
        cout << a << " + " << b << " = " << (a + b) << "\n\n";
    } else {
        cout << "Invalid format." << "\n\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // 5. Unformatted I/O: read PNG signature bytes
    ifstream img("image.png", ios::binary);
    if (img) {
        unsigned char header[8];
        img.read(reinterpret_cast<char*>(header), sizeof(header));
        cout << "PNG signature bytes:";
        for (auto byte : header) {
            cout << " " << hex << uppercase << setw(2)
                 << setfill('0') << (int)byte;
        }
        cout << dec << "\n";
    } else {
        cerr << "Warning: Could not open 'image.png'. Skipping header read." << "\n";
    }

    return 0;
}
