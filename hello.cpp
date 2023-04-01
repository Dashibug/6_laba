////////////////////////////
//Цыбикжапов Даши БПМ-21-1//
////////////////////////////
//Генерация размещений с повторениями. 
//n^k

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate_permutations(int n, int k, vector<int>& permutation, vector<vector<int>>& result){
     if (permutation.size() == k) {
        result.push_back(permutation);
        return;
    }
    for (int i = 1; i <= n; i++) {
        permutation.push_back(i);
        generate_permutations(n, k, permutation, result);
        permutation.pop_back();
    }
}

int main()
{
    int n; // Множество из 3 элементов: {1, 2, 3}
    int k; // Размещения длины 2
    cin >> n >> k;
    vector<int> permutation;//вектор будет содержать текущее размещ
    vector<vector<int>> result;// вектор содержащий все сгенер размещ
    generate_permutations(n, k, permutation, result);
    // Выводим все сгенерированные размещения
    for (auto& perm : result) {
        for (auto& elem : perm) {
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
//Этот код использует рекурсию для генерации всех возможных размещений. 
//Мы начинаем с пустой перестановки и добавляем элементы по одному, пока не достигнем нужной длины. Когда мы достигаем нужной длины, 
//сохраняем текущую перестановку в вектор результатов. 
//Затем мы удаляем последний добавленный элемент и продолжаем генерацию перестановок.