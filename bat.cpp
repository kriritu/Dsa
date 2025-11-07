#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Bat {
    double position;
    double velocity;
    double frequency;
    double loudness;
    double pulseRate;
    double fitness;

    Bat(double pos, double vel, double freq, double loud, double pulse, double fit)
        : position(pos), velocity(vel), frequency(freq), loudness(loud), pulseRate(pulse), fitness(fit) {}
};

const int N = 20;          // Number of bats
const int MAX_GEN = 100;   // Maximum number of generations
const double F_MIN = 0.0;  // Minimum frequency
const double F_MAX = 2.0;  // Maximum frequency
const double LOUD_INIT = 1.0;    // Initial loudness
const double PULSE_INIT = 0.5;   // Initial pulse rate
const double ALPHA = 0.9f;       // Loudness attenuation factor
const double GAMMA = 0.9f;       // Pulse rate increase factor

const double POS_MIN = -10.0;
const double POS_MAX = 10.0;

// Objective function to minimize: f(x) = x^2
double objective(double x) {
    return x * x;
}

// Generate random double in [min, max]
double randDouble(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

int main() {
    srand(time(0));
    vector<Bat> bats;

    // Initialize bats
    for (int i = 0; i < N; ++i) {
        double pos = randDouble(POS_MIN, POS_MAX);
        bats.emplace_back(pos, 0.0, randDouble(F_MIN, F_MAX), LOUD_INIT, PULSE_INIT, objective(pos));
    }

    Bat globalBest = bats[0];
    for (int i = 1; i < N; ++i)
        if (bats[i].fitness < globalBest.fitness)
            globalBest = bats[i];

    for (int t = 0; t < MAX_GEN; ++t) {
        for (int i = 0; i < N; ++i) {
            // Update bat frequency
            bats[i].frequency = randDouble(F_MIN, F_MAX);
            // Update velocity
            bats[i].velocity += (bats[i].position - globalBest.position) * bats[i].frequency;
            // Update position
            bats[i].position += bats[i].velocity;
            // Clamp position to bounds
            bats[i].position = max(POS_MIN, min(POS_MAX, bats[i].position));

            double randPulse = ((double)rand() / RAND_MAX);
            // Local random walk
            if (randPulse > bats[i].pulseRate) {
                bats[i].position = globalBest.position + 0.001 * randDouble(-1.0, 1.0);
            }

            double newFitness = objective(bats[i].position);
            // Accept solution if improved or with some loudness probability
            if (newFitness < bats[i].fitness && randPulse < bats[i].loudness) {
                bats[i].fitness = newFitness;
                bats[i].loudness *= ALPHA;
                bats[i].pulseRate = bats[i].pulseRate * (1 - exp(-GAMMA * t));
            }

            if (bats[i].fitness < globalBest.fitness)
                globalBest = bats[i];
        }

        cout << "Iteration " << t + 1 << ": Global best x = " << globalBest.position
             << " , fitness = " << globalBest.fitness << endl;
    }

    cout << "Final best solution: x = " << globalBest.position << ", f(x) = " << globalBest.fitness << endl;
    return 0;
}
