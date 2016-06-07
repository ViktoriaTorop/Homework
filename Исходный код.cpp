#include<algorithm>
#include<iomanip>
#include<iostream>
#include<vector>

struct mercury {
    double one_mg, price;
    double weight;
};

int main() {
    long long int N, W;
    double w;
    double p;
    std::cin >> N >> W;
    std::vector<mercury> inform;
    mercury temp;
    double result = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> p >> w;
        if (w == 0) {
            result += p;
        }
        else {
            temp.one_mg = p / w;
            temp.price = p;
            temp.weight = w;
            inform.push_back(temp);
        }
    }
    std::sort(inform.begin(), inform.end(), [](mercury& first, mercury& second) {
        return first.one_mg > second.one_mg;
    });
    long long int counter = 0;
    for (int k = 0; k < inform.size(); ++k) {
        if ((counter + inform[k].weight) < W) {
            counter += inform[k].weight;
            result += inform[k].price;
        }
        else {
            result += (W - counter) * inform[k].one_mg;
            break;
        }
    }
    std::cout << std::setprecision(6) << std::fixed;
    std::cout << result;
    return 0;
}
