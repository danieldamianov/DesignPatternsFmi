#include "RandomNumberProvider.h"

std::shared_ptr<RandomNumberProvider> RandomNumberProvider::instance = nullptr;

RandomNumberProvider::RandomNumberProvider() : rng(dev()) { }

std::weak_ptr<RandomNumberProvider> RandomNumberProvider::getInstance()
{
    if (instance == nullptr)
    {
        // a trick to create shared pointer of a class with private constructor
        struct make_shared_enabler : public RandomNumberProvider {};
        instance = std::make_shared<make_shared_enabler>();
    }

    return std::weak_ptr<RandomNumberProvider>(instance);
}

int RandomNumberProvider::getRandomNumberInRange(int minValue, int limit)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist(minValue, limit);
    return dist(rng);
}
