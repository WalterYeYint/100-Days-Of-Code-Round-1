#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>

using namespace std;
typedef vector<int> candidate;

class Data
{
private:
    
public:
    vector <pair<double, double>> cityCoords;
    vector <vector<double>> cost;
    int N;
    char s[30];
    Data() {
        cout << "Insert the no of cities" << endl;
        scanf("%d" ,&N);

        cityCoords.push_back(make_pair(0, 0));
        vector<double> T;
        cost.push_back(T);

        for (int i = 0; i < N; i++)
        {
            double x, y;
            cout << "Insert the " << i << "th " << "x and y" << endl;
            scanf("%lf%lf", &x, &y);
            cityCoords.push_back(make_pair(x, y));
        }
        for (int i = 0; i < N; i++)
        {
            vector<double> V(N+1);
            for (int j = 1; j < N; j++)
            {
                scanf("%lf", &V[j]);
            }
            cost.push_back(V);
        }
        
        
    }
    ~Data() {}
};

/*
class StimulatedAnnealing
{
private:
    
public:
    candidate best;
    double minTour;
    Data data;
    StimulatedAnnealing(){
        minTour = 0.0;
    }
    double randProb(){
        double p = (rand() / (RAND_MAX + 1.0));
        return p;
    }
    void run(){
        vector <int> V(data.N);
        for(int i=0; i<data.N; i++){
            V[i] = i + 1;
        }
        candidate c = data.genRand(V);
        best = c;
        minTour = data.tourCost(c);
    }
    ~StimulatedAnnealing();
};
*/

int main(void){
    time_t sysTime;
    srand(Time(&sysTime));
    SimulatedAnnealing SA;
    SA.run();
    return 0;
}