#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

// Funcion para jugar la secuencia de juegos
std::vector<int> juego_secuencia(const std::vector<int>& habilidades, int N, int K) {
    std::vector<int> mesa = { habilidades[0], habilidades[1] };
    std::vector<int> cola(habilidades.begin() + 2, habilidades.end());
    int ganador_actual = -1;
    int juegos_ganados = 0;

    for (int i = 1; i <= K; i++) {
        int perdedor = std::min(mesa[0], mesa[1]);
        int ganador = std::max(mesa[0], mesa[1]);

        if (ganador == ganador_actual) {
            juegos_ganados++;
        } else {
            ganador_actual = ganador;
            juegos_ganados = 1;
        }
