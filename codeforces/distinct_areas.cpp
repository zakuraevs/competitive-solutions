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

        vector<int> trees;
        for(int tree = 0; tree < n; tree++) {
            int current;
            cin >> current;
            trees.push_back(current);
        }

        unordered_set<double> areas;

        for(int first = 0; first < n; first++) {
            double tree1 = trees[first];
            for(int second = 0; second < n; second++) {
                double tree2 = trees[second];
                if(tree1 == tree2) continue;
                double area = (-tree1 + tree2) / 2.0;
                if(area <= 0.0) continue;
                areas.insert(area);
            }
        }

        cout << areas.size() << endl;
        /*cout << "areas" << endl;
        for(auto a : areas) {
            cout << a << " ";
        }
        cout << endl;*/
    }

    return 0;
}