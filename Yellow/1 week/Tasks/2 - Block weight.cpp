// * количество блоков _N_ не превосходит 10^5;
// * плотность блоков _R_ не превосходит 100;
// * размеры блоков _W_, _H_, _D_ не превосходят 10^4.

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>

using namespace std;

int main() {
    stringstream cin("2 14 \n10000 10000 10000 \n30 40 50");
    
    int16_t N; // < 10^5
    int16_t R; // < 10^2
    cin >> N;
    cin >> R;

    int64_t M = 0; // < 10^19

    for(auto i = 0; i < N; i++) {
        int64_t W, H, D;
        cin >> W >> H >> D;
        M += W * H * D * R; // < 10^19
    }
    
    cout << M;

    return 0;
}