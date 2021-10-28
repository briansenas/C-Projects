#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comparePair(const pair<float, float> obj1, const pair<float, float> obj2) {
    bool result = true;
    if (obj1.first > obj2.first)
        result = false;
    else if (obj1.first == obj2.first) {
        if (obj1.second >= obj2.second)
            result = false;
    }
    return result;
}

ostream &operator<<(ostream &out, const vector<pair<float, float>> &obj) {
    out << "< ";
    for (auto &num : obj) {
        out << "( " << num.first << ", " << num.second << " )" << " ";
    }
    out << " >";
    return out;
}

ostream &operator<<(ostream &out, const vector<pair<pair<float, float>, int>> &obj) {
    out << "{ ";
    for (typename vector<pair<pair<float, float>, int>>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << "< ";
        out << "( " << it->first.first << ", " << it->first.second << " )";
        out << " un total de: " << it->second;
        out << " > ";
    }
    out << " }";
    return out;
}

vector<pair<pair<float, float>, int>> contar(const vector<pair<float, float>> &v) {
    vector<pair<float, float>> v2 = v;
    sort(v2.begin(),v2.end(),comparePair);
    vector<pair<pair<float, float>, int>> res;
    int count = 0;
    pair<float, float> old_num = v2[0];
    for (unsigned int i = 0; i < v2.size(); i++) {
        if (v2[i] == old_num) {
            count++;
        } else {
            res.push_back(make_pair(old_num, count));
            count = 1;
            old_num = v2[i];
            if( i == v2.size()-1)
                res.push_back(make_pair(old_num,count));
        }
    }
    return res;
}



int main() {
    //SAMPLES
    vector<pair<float, float>> vec1 = {{0, 0},
                                       {1, 2},
                                       {0, 0},
                                       {2, 1},
                                       {1, 2}};
    vector<pair<pair<float, float>, int>> res1;
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Vector: " << vec1 << endl;
    res1 = contar(vec1);
    cout << "Resultado: " << res1 << endl;
    cout << "############# End Test Sample ##############" << endl;
}