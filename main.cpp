#include <iostream>
#include <set>
#include <vector>
#include<algorithm>
#include <iomanip>

using namespace std;

namespace statist {
    vector<int> ids(1e5+1,0);
    vector<int> pages(1001,0);
    int counter = 0;
    void SetCheer(int id, ostream& out = cout) {
        if (counter == 0) {
            out << 0. << endl;
            return;
        }
        int page_read = ids[id];
        if (page_read == 0) {
            out << 0. << endl;
            return;
        }
        if (counter == 1) {
            out << 1.0 << endl;
            return;
        }
        double number_reader = static_cast<double>(pages[page_read]) -1.;
        double count = static_cast<double>(counter) - 1.;
        double result = 1. - number_reader / count;
        out << setprecision(6) << result << endl;
       
    }
}
int main()
{
    int count;
    cin >> count;
    string command_str;
    int id;
    for (int i = 0; i < count; i++) {
        cin >> command_str >> id;
        if (command_str == "READ") {
            int count_page;
            cin >> count_page;
            int count_page_old = statist::ids[id];
            if (count_page_old == 0) {
                statist::counter++;
            }
            for (int k = count_page_old + 1; k <= count_page; k++) {
                statist::pages[k]++;
            }
            statist::ids[id] = count_page;

        }
        else if (command_str == "CHEER") {
            statist::SetCheer(id);
        }
        
    }

}

