#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int POP_SIZE = 10;
const int CHROM_LENGTH = 5; // Number of bits (represents numbers 0-31)
const int GENERATIONS = 20;
const double CROSS_RATE = 0.7;
const double MUTATE_RATE = 0.01;

// Evaluate fitness: f(x) = x^2
int fitness(const vector<int>& chrom) {
    int x = 0;
    for (int i = 0; i < CHROM_LENGTH; ++i) {
        x = (x << 1) | chrom[i];
    }
    return x * x;
}

// Random bit-string
vector<int> randomChromosome() {
    vector<int> chrom(CHROM_LENGTH);
    for (int i = 0; i < CHROM_LENGTH; ++i)
        chrom[i] = rand() % 2;
    return chrom;
}

// Roulette wheel selection
vector<int> select(const vector<vector<int>>& population, const vector<int>& fit) {
    int sum_fit = 0;
    for (int f : fit) sum_fit += f;
    if (sum_fit == 0) return population[rand() % POP_SIZE];
    double r = ((double)rand()/RAND_MAX) * sum_fit;
    double acc = 0.0;
    for (int i = 0; i < POP_SIZE; ++i) {
        acc += fit[i];
        if (acc >= r)
            return population[i];
    }
    return population[0];
}

// Single-point crossover
pair<vector<int>, vector<int>> crossover(const vector<int>& p1, const vector<int>& p2) {
    int point = rand() % CHROM_LENGTH;
    vector<int> c1 = p1, c2 = p2;
    for (int i = point; i < CHROM_LENGTH; ++i) {
        c1[i] = p2[i];
        c2[i] = p1[i];
    }
    return {c1, c2};
}

// Mutation
void mutate(vector<int>& chrom) {
    for (int i = 0; i < CHROM_LENGTH; ++i) {
        if ((double)rand()/RAND_MAX < MUTATE_RATE)
            chrom[i] = 1 - chrom[i];
    }
}

// Convert chromosome to integer
int decode(const vector<int>& chrom) {
    int x = 0;
    for (int i = 0; i < CHROM_LENGTH; ++i)
        x = (x << 1) | chrom[i];
    return x;
}

int main() {
    srand(time(0));
    vector<vector<int>> population(POP_SIZE);

    // Initial population
    for (int i = 0; i < POP_SIZE; ++i)
        population[i] = randomChromosome();

    for (int gen = 1; gen <= GENERATIONS; ++gen) {
        vector<int> fit(POP_SIZE);
        for (int i = 0; i < POP_SIZE; ++i)
            fit[i] = fitness(population[i]);

        vector<vector<int>> newPop;

        while (newPop.size() < POP_SIZE) {
            // Selection
            auto parent1 = select(population, fit);
            auto parent2 = select(population, fit);
            vector<int> child1 = parent1, child2 = parent2;

            // Crossover
            if ((double)rand()/RAND_MAX < CROSS_RATE) {
                auto children = crossover(parent1, parent2);
                child1 = children.first;
                child2 = children.second;
            }

            // Mutation
            mutate(child1);
            mutate(child2);

            newPop.push_back(child1);
            if (newPop.size() < POP_SIZE)
                newPop.push_back(child2);
        }
        population = newPop;

        // Print best individual of this generation
        int bestFit = fitness(population[0]), bestIdx = 0;
        for (int i = 1; i < POP_SIZE; ++i) {
            int f = fitness(population[i]);
            if (f > bestFit) {
                bestFit = f;
                bestIdx = i;
            }
        }
        cout << "Generation " << gen << ": Best x = " << decode(population[bestIdx])
             << ", fitness = " << bestFit << endl;
    }

    return 0;
}
