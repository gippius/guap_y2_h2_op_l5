#include "array_task.hpp"

#include <algorithm>
#include <numeric>
#include <sstream>
#include <stdexcept>
#include <utility>

PositiveRangeException::PositiveRangeException(std::string message) : message_(std::move(message)) {}

const char* PositiveRangeException::what() const noexcept {
    return message_.c_str();
}

ArrayTask::ArrayTask(const std::vector<double>& data) : data_(data), length_(data.size()) {
    if (length_ != 12) {
        throw std::invalid_argument("Array length must be 12 for this student.");
    }
}

std::size_t ArrayTask::length() const {
    return length_;
}

std::string ArrayTask::sourceArrayAsString() const {
    std::ostringstream output;
    output << "Array: ";
    for (double value : data_) {
        output << value << ' ';
    }
    return output.str();
}

std::string ArrayTask::transformedArrayAsString() const {
    std::ostringstream output;
    output << "Transformed array: ";
    for (double value : data_) {
        output << value << ' ';
    }
    return output.str();
}

double ArrayTask::minElement() const {
    if (data_.empty()) {
        throw std::logic_error("Cannot find minimum of an empty array.");
    }

    return *std::min_element(data_.begin(), data_.end());
}

double ArrayTask::sumBetweenFirstAndLastPositive() const {
    const auto firstPositive = std::find_if(data_.begin(), data_.end(), [](double value) { return value > 0; });
    const auto lastPositive = std::find_if(data_.rbegin(), data_.rend(), [](double value) { return value > 0; });

    if (firstPositive == data_.end() || lastPositive == data_.rend()) {
        throw PositiveRangeException("The array does not contain positive elements.");
    }

    const auto lastPositiveBase = lastPositive.base() - 1;
    if (firstPositive >= lastPositiveBase) {
        throw PositiveRangeException("The array must contain at least two positive elements.");
    }

    return std::accumulate(firstPositive + 1, lastPositiveBase, 0.0);
}

void ArrayTask::moveZerosToFront() {
    std::stable_sort(data_.begin(), data_.end(), [](double left, double right) {
        return left == 0.0 && right != 0.0;
    });
}

double ArrayTask::at(std::size_t index) const {
    if (index >= data_.size()) {
        throw std::out_of_range("Index is outside array bounds.");
    }

    return data_[index];
}

