/*
 * Algorithm for finding if a given point is inside simple polygon.
 * Input: Point A and array of points that represent polygon.
 * Output: True if the point is inside polygon, false if it is not.
 */

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool is_inside_polygon(pair<double, double> A, vector<pair<double, double>> points){
    int i;
    pair<double, double> u0, u1;
    bool inside = false;
    int j = points.size() - 1;
    int n = points.size();

    for(i = 0; i < n-1; i++){
        u0 = points[i];
        u1 = points[j];
        if(A.second < u1.second){
            if(u0.second < A.second){
                if((A.second - u0.second) * (u1.first - u0.first) >
                    (A.first - u0.first) * (u1.second - u0.second)){
                        inside = !(inside);
                }
            }
        } else if(A.second < u0.second){
            if((A.second - u0.second) * (u1.first - u0.first) <
                (A.first - u0.first) * (u1.second - u0.second)){
                    inside = !(inside);
            }
        }
        j = i;
    }

    return inside;
}

int main(){
    int x, y;
    pair<double, double> A;
    vector<pair<double, double>> points;
    cin >> A.first >> A.second;

    while((cin >> x) && (cin >> y)){
        points.push_back(make_pair(x,y));
    }

    if(is_inside_polygon(A, points)){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
