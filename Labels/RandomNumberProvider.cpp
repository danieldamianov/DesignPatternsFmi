#include "RandomNumberProvider.h"

std::unique_ptr<RandomNumberProvider> RandomNumberProvider::instance = nullptr;

RandomNumberProvider::RandomNumberProvider() : rng(dev()) { }

RandomNumberProvider& RandomNumberProvider::getInstance()
{
    if (instance == nullptr)
    {
        instance = std::make_unique<RandomNumberProvider>();
    }

    return *instance;
}

int RandomNumberProvider::getRandomNumberInRange(int minValue, int limit)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(minValue, limit);
    return dist(rng);
}
