#include <iostream>
#include <vector>

using namespace std;

void work(int N, int M, vector<vector<int>> Cij) {

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
            for (int j = 0; i < M; j++) {
                int ij;
                cin >> ij;
                js.push_back(ij);
            }
            
            Cij.push_back(js);
        }

        cout << "Case #" << x++ << ": ";

        // Do stuff with Cij's
        work(N, M, Cij);       
    }
}


int main() {
    
    return 0;
}
