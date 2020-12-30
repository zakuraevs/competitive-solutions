#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {

        int n;
        cin >> n;

        if(n == 1) {
            int note;
            cin >> note;
            cout << 1 << endl;
            continue;
        }

        vector<int> notes;
        for(int note = 0; note < n; note++) {
            int current;
            cin >> current;
            notes.push_back(current);
        }

        unordered_set<int> distinct;
        unordered_set<int> repetitions;

        for(int j = 0; j < n; j++) {
            int current = notes[j];
            if(!(distinct.find(current) == distinct.end())) {
                repetitions.insert(current);
            } else {
                distinct.insert(current);
            }
        }

        int distinct_count = distinct.size();
        int repetitions_count = repetitions.size();

        vector<int> repetitions_vector;

        for(auto r : repetitions) {
            repetitions_vector.push_back(r);
        }

        int distanced_repetitions_count = 0;

        if(repetitions_count == 1) {
            distanced_repetitions_count = 1;
        } else if(repetitions_count > 1) {
            for(int j = 1; j < repetitions_count; j++) {
                if(abs(repetitions_vector[j] - repetitions_vector[j-1]) > 1) {
                    distanced_repetitions_count++;
                }
            }
            distanced_repetitions_count++;
        }


        cout << distinct_count + distanced_repetitions_count << endl;
        /*cout << "repetitions: " << endl;
        for(auto r : repetitions_vector) {
            cout << r << " ";
        }
        cout << endl;
        cout << "distanced repetitions: " << distanced_repetitions_count << endl;*/

    }

    return 0;
}