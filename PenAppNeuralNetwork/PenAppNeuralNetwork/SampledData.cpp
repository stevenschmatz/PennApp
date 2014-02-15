#include "SampledData.h"

inline SampledData::SampledData(int n, CollectedData *cd) {
    for(int i = 0; i < cd->get_x_values().size(); i+=cd->get_x_values().size()/n) {
        SampleVector *ith_vector = new SampleVector(cd->get_x_values()[i], cd->get_y_values()[i]);
        this->get_sample_matrix().push_back(ith_vector);
    }
}

inline std::vector<SampleVector*> SampledData::get_sample_matrix() {
    return this->sample_matrix;
}

inline SampleVector SampleData::sample_at(int k) {
    
}


#endif
