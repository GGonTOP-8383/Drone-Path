/*
git add .
git commit -m "Updated code/documentation"
git push


git pull

*/
#include <iostream>
#include <bits/stdc++.h>
#include <string>   
#include <map>
#include <utility>

#define ll long long
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define inf 1e18
#define endl '\n'
#define all(x) x.begin(), x.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define cnst const 
#define str string 
#define rev reverse
#define REzero return 0

cnst ll mod = 1e9 + 7;
cnst ll maxl = 1e18;
cnst ll maxn = 1e6 + 5;
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int r,c;
    cout << "Enter the size of the matrix (rows): "; 
    cin >> r;
    cout << "Enter the size of the matrix (column): ";
    cin >> c;
    int matrix[r][c];
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){         // to get the cost easier 
            matrix[i][j] = i+j;
        }
    }
    int n;
    cout << "Enter the number of drones: ";
    cin >> n;
    cout << "Enter the number of tasks: ";
    int tasks;
    cin >> tasks;
    queue <int>maxtask; // so i cant get the tasks in the mid
    int cnt = 0;        // to know how many waves i need 
    int lastnumber;     // the last number

    for(int i =0;i<r;i++){
        for(int j = 0;j<c;j++){
            cout << i << ',' << j << "     ";
            }
            cout << endl << endl;
        }
        
    

    map <int,pair<int,int>> target;    // get a map with the key as the number of the target   and the value as a pair with the first as the x and second as y
    for(int i = 0;i<tasks;i++){
        int x;
        int y;
        cout << "Enter the target location for the delivery " << i+1 << " (in the maxrix): ";
        cin >> x >> y;
        target.insert({i,{x,y}});
    }
    cout << "calculating the max tasks per time" << endl; 
    while (tasks > 0){
        tasks -= n;
        cnt++;                         // to get the waves each wave (not always the last one) makes all the drones take 1 so each wave can take n tasks
        if (tasks<=n ){
            lastnumber = tasks;        // the last task 
            break;
        }
    }
    
    for(int i = 0;i<cnt;i++){
        maxtask.push(n);
    }
    if (lastnumber) maxtask.push(lastnumber);   // 0 is false
    
    cout << "Done" << endl;
    int cnt2=0;
    int j=0;
    while(!maxtask.empty()){
        ll sum = 0;
        for(int i = 0;i<maxtask.front();i++){
            sum+= matrix[target[j].first][target[j].second];    // the sum in the matrix as in line 38
            j++;    // j so the map index doesnt reset 
        }
        cnt2++;     // cnt2 is the number of waves
        cout << "the wave " << cnt2 << " of drones will cost " << sum << " (1 per meter) " << "and will do ";
        if (cnt > 0){
            cout << n << " tasks" << endl;
            cnt--;
        }
        else{
            cout << maxtask.back() << " tasks" << endl; 
        }
        maxtask.pop();
    }


    cout << "Here are how many are going to be delivered each time" << endl;
    while (!maxtask.empty()){
        cout << maxtask.front() << ' ';
        maxtask.pop();
    }
    
    
    REzero;

}