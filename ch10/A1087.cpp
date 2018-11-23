/*
1087 All Roads Lead to Rome（30 分）

Indeed there are many different tourist routes from our city to Rome. You are supposed to find your clients the route with the least cost while gaining the most happiness.
Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers N (2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city. The next N−1 lines each gives the name of a city and an integer that represents the happiness one can gain from that city, except the starting city. Then K lines follow, each describes a route between two cities in the format City1 City2 Cost. Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.
Output Specification:

For each test case, we are supposed to find the route with the least cost. If such a route is not unique, the one with the maximum happiness will be recommanded. If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution exists and is unique.

Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness (take the integer part only) of the recommanded route. Then in the next line, you are supposed to print the route in the format City1->City2->...->ROM.
Sample Input:

6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1

Sample Output:

3 3 195 97
HZH->PRS->ROM

*/
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 220;
const int INF = 100000000;
int graph[MAXV][MAXV];
int weight[MAXV];
bool vis[MAXV] = {false};
int dis[MAXV];
vector<int> pre[MAXV];
map<string, int> ctoi;
map<int, string> itoc;

int n, k, s;
string str;

void dijkstra(int s) {
    fill(dis, dis+MAXV, INF);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && graph[u][v] != INF) {
                if (dis[u] + graph[u][v] < dis[v]) {
                    dis[v] = dis[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + graph[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> tempPath, path;
int numOfPaths = 0, maxWeight = 0;
double maxAvg = 0;

void DFS(int v) {
    if (v == 0) {
        numOfPaths++;
        tempPath.push_back(v);
        int tempWeight = 0;
        for (int i = tempPath.size()-2; i >= 0; i--) {
            int id = tempPath[i];
            tempWeight += weight[id];
        }
        double tempAvg = tempWeight * 1.0 / (tempPath.size()-1);
        if (tempWeight > maxWeight) {
            maxWeight = tempWeight;
            maxAvg = tempAvg;
            path = tempPath;
        } else if (tempWeight == maxWeight) {
            if (tempAvg > maxAvg) {
                maxAvg = tempAvg;
                path = tempPath;
            }
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (vector<int>::iterator i = pre[v].begin(); i != pre[v].end(); i++) {
        DFS(*i);
    }
    tempPath.pop_back();
}

int main() {
    fill(graph[0], graph[0] + MAXV * MAXV, INF);
    cin >> n >> k >> str;
    ctoi[str] = 0;
    itoc[0] = str;
    for (int i = 1; i < n; i++) {
        cin >> str >> weight[i];
        // cout << str << endl;
        ctoi[str] = i;
        itoc[i] = str;
    }
    string str1, str2;
    int id1, id2, w;
    for (int i = 0; i < k; i++) {
        cin >> str1 >> str2 >> w;
        id1 = ctoi[str1]; id2 = ctoi[str2];
        graph[id1][id2] = graph[id2][id1] = w;
    }
    dijkstra(0);
    int des = ctoi["ROM"];
    DFS(des);
    printf("%d %d %d %d\n", numOfPaths, dis[des], maxWeight, (int)maxAvg);
    // cout << numOfPaths << " " << dis[des] << " " << maxWeight << " " << (int)maxAvg << endl;
    for (int i = path.size()-1; i >= 0; i--) {
        int id = path[i];
        cout << itoc[id];
        if (i != 0)
            cout << "->";
    }
}