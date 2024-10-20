#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void generate_P(int pos, int k, int last_digit, int D, ll current, vector<ll> &P_list) {
    if(pos == k){
        P_list.push_back(current);
        return;
    }
    for(int digit = last_digit; digit <= D-1; digit++) {
        generate_P(pos +1, k, digit, D, current *10 + digit, P_list);
    }
}

void generate_Q(int pos, int k, int last_digit, int D, ll current, vector<ll> &Q_list) {
    if(pos ==k) {
        Q_list.push_back(current);
        return;
    }
    for(int digit =1; digit <= last_digit; digit++) {
        generate_Q(pos +1, k, digit, D, current *10 + digit, Q_list);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("cottontail_climb_part_2_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int test_case=1; test_case <=T; test_case++){
        ll A, B;
        ll M;
        cin >> A >> B >> M;
        ll count =0;
        for(int L=1; L <=19; L+=2){
            int k = (L-1)/2;
            ll min_L = (L ==1) ? 1 : pow(10, L-1);
            ll max_L = (L ==1) ? 9 : pow(10, L) -1;
            ll lower = max(A, min_L);
            ll upper = min(B, max_L);
            if(lower > upper){
                continue;
            }
            if(L ==1){
                for(int D=1; D <=9; D++){
                    ll N = D;
                    if(N >= lower && N <= upper && N % M ==0){
                        count +=1;
                    }
                }
                continue;
            }
            for(int D=1; D <=9; D++){
                if(D ==1 && k >0){
                    continue; 
                }

                vector<ll> P_list;
                if(k >0){
                    generate_P(0, k, 1, D, 0, P_list);
                }

                vector<ll> Q_list;
                if(k >0){
                    generate_Q(0, k, D-1, D, 0, Q_list);
                }
                if(P_list.empty() || Q_list.empty()){
                    continue;
                }
                for(auto P : P_list){
                    for(auto Q : Q_list){
                        ll N = P * (ll)pow(10, k+1) + D * (ll)pow(10, k) + Q;
                        if(N >= lower && N <= upper && N % M ==0){
                            count +=1;
                        }
                    }
                }
            }
        }
        cout << "Case #" << test_case << ": " << count << "\n";
    }
}
