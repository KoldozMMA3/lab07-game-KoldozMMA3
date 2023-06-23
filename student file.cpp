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
// Elimina al perdedor de la mesa
        mesa.erase(std::remove(mesa.begin(), mesa.end(), perdedor), mesa.end());

// Agrega al perdedor a la cola
        cola.push_back(perdedor);
        if (juegos_ganados == N) {
            // Si el ganador actual ha ganado N juegos seguidos, lo saca de la mesa
            mesa.erase(std::remove(mesa.begin(), mesa.end(), ganador), mesa.end());

            // Inserta al ganador actual al inicio de la cola
            cola.insert(cola.begin(), ganador);
        }
        if (mesa.size() < 2) {
            // Si hay menos de 2 personas en la mesa, toma a la primera persona de la cola y la coloca en la mesa
            int persona_cola = cola.front();
            cola.erase(cola.begin());
            mesa.push_back(persona_cola);
        }
         if (i == K) {
            // Si es el juego K, devuelve las habilidades del ganador y perdedor
            return { ganador, perdedor };
        }
    }

    // Si K es mayor que el numero de juegos, devuelve un vector vacio
    return {};
}