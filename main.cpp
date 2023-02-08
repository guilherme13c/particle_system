#include "particles.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <vector>

#define OUTPUT_FILE_EXT ".txt"
#define X_MAX 1000
#define Y_MAX 1000

using std::ifstream;
using std::ofstream;
using std::vector;

inline double drand(double dMin, double dMax) {
    return dMin + ((double)rand() / RAND_MAX) * (dMax - dMin);
}

inline void command_line_usage() {
    std::cout << "main.exe -p <(optional) particle-count> -t <(optional) "
                 "particle-type-count>"
              << std::endl;
}

inline void command_line_manager(int argc, char *const *argv,
                                 unsigned int *particle_count,
                                 unsigned int *particle_type_count,
                                 unsigned int *iterations, char *filename) {
    int c;

    while ((c = getopt(argc, argv, "i:p:t:n:h")) != -1) {
        switch (c) {
        case 'i':
            (*iterations) = atoi(optarg);
            break;
        case 'p':
            (*particle_count) = atoi(optarg);
            break;
        case 't':
            (*particle_type_count) = atoi(optarg);
            break;
        case 'n':
            strcpy(filename, optarg);
            break;
        case 'h':
            command_line_usage();
            exit(1);
            break;
        default:
            abort();
            break;
        }
    }
}

int main(int argc, const char **argv) {

    unsigned int particle_count = 0, particle_type_count = 1, iterations = 0;
    char filename[256] = "simulation_output_data";

    command_line_manager(argc, (char *const *)argv, &particle_count,
                         &particle_type_count, &iterations, filename);

    ofstream outputfile;
    strcat(filename, OUTPUT_FILE_EXT);
    outputfile.open(filename);
    outputfile << filename << std::endl
               << particle_count << " " << particle_type_count << " " << iterations << std::endl;

    vector<Particle> particles = vector<Particle>();

    srand((unsigned)time(nullptr));
    for (int i = 0; i < particle_type_count; ++i) {
        for (int j = 0; j < particle_count; ++j) {
            particles.push_back(
                Particle(Vector2(drand(0, X_MAX), drand(0, Y_MAX)), Vector2(),
                         Vector2(), j));
        }
    }

    for (int i = 0; i <= iterations; ++i) {
        for (auto p : particles) {
            outputfile << p.getPosition().getX() << ";" << p.getPosition().getY()
                      << ";" << p.getType() << " ";
        }
        outputfile << std::endl;
    }

    outputfile.close();

    return 0;
}
