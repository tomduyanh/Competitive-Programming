#include <bits/stdc++.h>
using namespace std;
std::vector<int> RotateRight(const std::vector<int>& vect,
                             unsigned int no_rotations) {
  // TODO
  int n = vect.size();
  if (n == 0) return vect;
  unsigned int k = no_rotations % n;
  if (k == 0) return vect;
  std::vector<int> rotated;
  unsigned int m = 0;
  for (int i = n - k; i < n; ++i) rotated.push_back(vect[i]);
  for (int i = 0; i < n - k; ++i) rotated.push_back(vect[i]);
  return rotated;
}

std::vector<int> RotateChunks(const std::vector<int>& vect,
                              unsigned int chunk_size,
                              unsigned int no_rotations) {
  // TODO
  std::vector<int> rotated;
  if (chunk_size == 0 || vect.size() == 0) return rotated;
  int n = vect.size();
  unsigned int k = no_rotations % chunk_size;
  int nn = n % chunk_size;
  unsigned int kk = 0;
  if(nn != 0) kk = no_rotations % nn;
//  cout << kk << endl;
  for (int i = 0; i < n; i += chunk_size) {
    if (i + (unsigned int)chunk_size <= n) {
      std::vector<int> temp = RotateRight({vect.begin() + i, vect.begin() + i + chunk_size}, k);
//      for(auto i : temp) cout << i << " ";
      for (int j = 0; j < (unsigned int)chunk_size; ++j) rotated.push_back(temp[j]);
    }
    else{
//        cout << "hello";
        std::vector<int> temp = RotateRight({vect.begin() + i, vect.end()}, kk);
        for (int j = 0; j < nn; ++j) rotated.push_back(temp[j]);
    }
  }
  return rotated;
}

int main()
{
    std::vector<int> input1 = {};
    std::vector<int> input2 = {1};
    std::vector<int> input3 = {1, 2, 3};
    std::vector<int> input4 = {22, 13, 3, 4, 16};
    std::vector<int> input5 = {22, 13, 3, 4, 16, 6, 7, 32, 9, 10};
    std::vector<int> input6 = {22, 13, 3, 4};

    std::vector<int> input7 = {};
    std::vector<int> input8 = {22, 13, 3, 4};
    std::vector<int> input9 = {22, 13, 3, 4, 16, 6};
    std::vector<int> input0 = {22, 13, 3, 4, 16};
    std::vector<int> input11 = {22, 13, 3, 4, 16, 6};
    std::vector<int> input12 = {22, 13, 3, 4};

    vector <int> ans = RotateChunks(input8, 1, 1);
    for(auto i : ans) cout << i << " ";

    return 0;
}
