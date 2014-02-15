#include "CollectedData.h"

class CollectedData {
private:
    std::vector<int> x_values;
    std::vector<int> y_values;
public:
    CollectedData(std::vector<int> x_values, std::vector<int> y_values);
    SampledData sample(int n);
    std::vector<int> get_x_values();
    std::vector<int> get_y_values();
};

inline std::vector<int> CollectedData::get_x_values() {
    return this->x_values;
}

inline std::vector<int> CollectedData::get_y_values() {
    return this->y_values;
}

inline SampledData *CollectedData::sample(int n) {
    return new SampledData(this, n);
}