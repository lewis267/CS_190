#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

using namespace std;

class day {

public:
    vector<int> pies; // pies on this day (cost)
    vector<int> purchased; // flag to indicate availability
    
    int day_number;
    int cheapest = -1; // the index of the cheapest pie
    int n_purchased = 0;

    day(int number, vector<int> ps) : pies(ps), purchased(ps.size(), 0), day_number(number) {
        set_cheapest();
    }

    int buy_pie() { return buy_pie(cheapest); }
    int buy_pie(int index) {
        if (index < 0 || index > (int)pies.size()) {
            throw out_of_range("in buy pie");
            return -1;
        }
        else if (this->purchased[index] == 1) {
            throw exception();
            return -2;
        }
        else {
            // buy the pie
            purchased[index]++;
            n_purchased++;
            
            // set cheapest
            set_cheapest();
            
            pvs();
            cout << "Bought index: " << index 
                <<  ", value: " << pies[index] 
                << ", day: " << day_number;

            // return the value of the purchased pie
            return pies[index];
        }
    }
    
    void pvs() {
        cout << endl;
        for (vector<int>::const_iterator i = pies.begin(); i != pies.end(); ++i) cout << *i << ' ';
        cout << endl;
        for (vector<int>::const_iterator i = purchased.begin(); i != purchased.end(); ++i) cout << *i << ' ';
        cout << endl;
    }

    // gets the additive cost of a purchase of another
    int cost() {
        //set_cheapest();
        if (cheapest < 0) return -1;
        int tax = ((n_purchased + 1)*(n_purchased + 1)) - (n_purchased*n_purchased); // additional tax
        return cheapest + tax;
    }

private:
    void set_cheapest() {
        // set cheapest
        int min = numeric_limits<int>::max();
        int idx = -1;
        for (int i = 0; i < (int)pies.size(); i++) {
            if (purchased[i] == 1) continue;
            if (min > pies[i] || min == -1) { min = pies[i]; idx = i; }
        }
        cheapest = idx;
        cout << endl << "   Cheapest is now at " << idx << " for day " << day_number;
    }
};

int dorec(int number, vector<day> days) {
    if (number == 0) {
        // we take the cheapest of that day
        int res = days[0].buy_pie();
        if (res < 0) {
            cout << "Error: " 
            << ((res == -1) ? "index out of bounds" : "already purchased") 
            << endl;
            return 0;
        }
        else { // update the running total
            return res + 1;
        }
    }
    else { // we take the cheapest of all previous days
        int min = numeric_limits<int>::max();
        int idx = -1;

        for (int i = 0; i <= number; i++) {
            int cost = days[i].cost();

            if (cost > 0 && min > cost) {
                min = cost;
                idx = i;
            }
        }

        //cout << " buying pie at index " << idx << " of value " << min <<
        days[idx].buy_pie();
        return min;
    }
}

void work(int N, int M, vector<vector<int>> Cij) {
    int tot = 0;

    vector<day> days;
    for (int i = 0; i < N; i++) {
        days.push_back(day(i, Cij[i]));
        tot += dorec(i, days);
    }

    cout << tot << endl;
}
    

void input() {
    int T;
    cin >> T; // get the times
    
    int x = 1;
    int N, M;
    while (T--) {

        vector<vector<int>> Cij;

        cin >> N >> M;
        for (int i = 0; i < N; i++) {

            vector<int> js;
            for (int j = 0; j < M; j++) {
                int ij;
                cin >> ij;
                js.push_back(ij);
            }
            
            Cij.push_back(js);
        }

        cout << "Case #" << x++ << ": ";

        // Do stuff
        work(N, M, Cij);       
    }
}


int main() {
    input();

    return 0;
}
