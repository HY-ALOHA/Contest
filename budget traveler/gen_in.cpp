#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <string>
#include <string.h>
#include <assert.h>

#define SPECIAL_CASE 7
#define RANDOM_CASE 20
#define raiseError assert(0)

using namespace std;
typedef long long ll;

/* Global Variable */
std::mt19937 gen;
/////////////////////

ll getRand(ll low, ll high) {
    std::uniform_int_distribution<ll> dis(low, high);
    ll val = dis(gen);
    assert(low <= val && val <= high);
    return val;
}
void generate(string filename, int V, int E, ll B = -1) {
  FILE *fp = fopen(filename.c_str(), "w+");
  fprintf(fp, "%d %d\n", V, E);
  ll edge_sum = 0;
  for (int i=1; i<=E; i++) {

/* Goto */////////////////////
begin:
    int src = getRand(1, V);
    int dst = getRand(1, V);

    if (src == dst) goto begin;
//////////////////////////////

    int w = getRand(0, 1e9);
    edge_sum += ll(w);
    fprintf(fp, "%d %d %d\n", src, dst, w);
  }
  double eps = 1e-5;

  // If not given
  if (B == -1) {
    B = edge_sum / (E+ eps) * V * (0.01 * getRand(10, 1000));
  }

  if (B > 1e16) {
    B = 1e16;
  } else if (B < 0) {
    B = 0;
  }
  assert(0 <= B && B <= 1e16);
  fprintf(fp, "%lld\n", B);

  fclose(fp);
}
void init() {
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  gen = mt19937(rd()); //Standard mersenne_twister_engine seeded with rd()
}
int main(int argc, const char* argv[]) {

  init();
  for (int i=1; i<=SPECIAL_CASE+RANDOM_CASE; i++) {
    string filename;
    filename = "data/" + to_string(i) + ".in";

    if (i<=SPECIAL_CASE) {
      switch (i) {
        case 1:
          generate(filename, 1, 0);
          break;
        case 2:
          generate(filename, 2, 1);
          break;
        case 3:
          generate(filename, 1e5, 1);
          break;
        case 4:
          generate(filename, 1e5, 0);
          break;
        case 5:
          generate(filename, 1e5, 20);
          break;
        case 6:
          generate(filename, 1e5, 1e6, 123);
          break;
        case 7:
          generate(filename, 10, 10, 1e16);
          break;
        default:
          raiseError;
          break;
      }
    } else {
      generate(filename, getRand(1, 1e5), getRand(1, 1e6));
    }
  }
}
